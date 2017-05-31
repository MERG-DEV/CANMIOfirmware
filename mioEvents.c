
/*
 Routines for CBUS FLiM operations - part of CBUS libraries for PIC 18F
  This work is licensed under the:
      Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
   To view a copy of this license, visit:
      http://creativecommons.org/licenses/by-nc-sa/4.0/
   or send a letter to Creative Commons, PO Box 1866, Mountain View, CA 94042, USA.
   License summary:
    You are free to:
      Share, copy and redistribute the material in any medium or format
      Adapt, remix, transform, and build upon the material
    The licensor cannot revoke these freedoms as long as you follow the license terms.
    Attribution : You must give appropriate credit, provide a link to the license,
                   and indicate if changes were made. You may do so in any reasonable manner,
                   but not in any way that suggests the licensor endorses you or your use.
    NonCommercial : You may not use the material for commercial purposes. **(see note below)
    ShareAlike : If you remix, transform, or build upon the material, you must distribute
                  your contributions under the same license as the original.
    No additional restrictions : You may not apply legal terms or technological measures that
                                  legally restrict others from doing anything the license permits.
   ** For commercial use, please contact the original copyright holder(s) to agree licensing terms
**************************************************************************************************************
	The FLiM routines have no code or definitions that are specific to any
	module, so they can be used to provide FLiM facilities for any module 
	using these libraries.
	
*/ 
/*
 * File:   mioEvents.c
 * Author: Ian Hogg
 * 
 * Here we deal with the module specific event handling. This covers:
 * <UL>
 * <LI>Setting of default events.</LI>
 * <li>Processing of inbound, consumed events</LI>
 *</UL>
 * 
 * Created on 10 April 2017, 10:26
 */

#include <stddef.h>
#include "../CBUSlib/GenericTypeDefs.h"
#include "../CBUSlib/romops.h"
#include "mioEEPROM.h"
#include "mioNv.h"
#include "mioEvents.h"

// forward declarations
void clearEvents(unsigned char i);

extern void setOutput(unsigned char io, unsigned char state, unsigned char type);
extern void inputScan(BOOL report);
extern void sendProducedEvent(unsigned char action, BOOL on);

/**
 * Reset events for the IO back to default. Called when the Type of the IO
 * is changed.
 * @param i the IO number
 */
void defaultEvents(unsigned char i, unsigned char type) {
    WORD nn = ee_read((WORD)EE_NODE_ID);
    WORD en;
    clearEvents(i);
    // add the module's default events for this io

    switch(type) {
        case TYPE_INPUT:
            en=i+1;
            // Produce ACON/ASON and ACOF/ASOF events with en as port number
            doEvlrn(nn, en, 0, ACTION_IO_PRODUCER_INPUT(i));
             break;
         
        case TYPE_OUTPUT:
        case TYPE_SERVO:
        case TYPE_BOUNCE:
            en=i+1;
            // Consume ACON/ASON and ACOF/ASOF events with en as port number
            doEvlrn(nn, en, 0, ACTION_IO_CONSUMER_OUTPUT(i));
            break;
        case TYPE_MULTI:
            // no defaults for multi
            break;
    }
}


/**
 * Reset all events back to their default based upon their current Type setting.
 */
void defaultAllEvents(void) {
    // add the module's default events
    unsigned char i;
    for (i=0; i<NUM_IO; i++) {
        defaultEvents(i, nodeVarTable.moduleNVs.io[i].type);
    }
}

/**
 * Clear the events for the IO. Called prior to setting the default events.
 * @param i the IO number
 */
void clearEvents(unsigned char i) {
    unsigned char e;
    for (e=0; e<CONSUMER_ACTIONS_PER_IO; e++) {
        deleteAction(ACTION_IO_CONSUMER_BASE(i)+e);
    }
    for (e=0; e<PRODUCER_ACTIONS_PER_IO; e++) {
        deleteAction(ACTION_IO_PRODUCER_BASE(i)+e);
    }
}

/**
 * Process the consumed events. Perform whatever action is requested and based 
 * upon the Type of IO.
 * Current this sets the output immediately but it will need to be queued so
 * the changes are done sequentially.
 * @param tableIndex the required action to be performed.
 * @param msg the full CBUS message so that OPC  and DATA can be retrieved.
 */
void processEvent(BYTE tableIndex, BYTE * msg) {
    // SOD is only applicable to EV#2
    if (getEv(tableIndex, 1) == ACTION_SOD) {
        // Do the SOD
        inputScan(TRUE);
        for (unsigned char io=0; io < NUM_IO; io++) {
            if (NV->io[io].type != TYPE_INPUT) {
                // send current status
                BOOL state = ee_read(EE_OP_STATE+io);
                sendProducedEvent(ACTION_IO_PRODUCER_OUTPUT(io), state);
            }
        }
    }
    // EV#0 is for produced event so start at 1
    for (unsigned char e=1; e<EVperEVT ;e++) { 
        int action = getEv(tableIndex, e);
        if (action >= 0) {
            if (action < NUM_PRODUCER_ACTIONS) {
                unsigned char io = CONSUMER_IO(action);
                action = CONSUMER_ACTION(action);
                unsigned char type = NV->io[io].type;
                setOutput(io, action, type);
            }
        }
    }
}
