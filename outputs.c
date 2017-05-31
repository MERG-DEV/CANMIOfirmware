
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
 * File:   outputs.c
 * Author: Ian
 * 
 * Handle the various types of outputs. Generate the output signals and  
 * generate Produced events.
 *
 * Created on 17 April 2017, 13:14
 */

#include "mioNv.h"
#include "mioEvents.h"
#include "FliM.h"
#include "config.h"
#include "GenericTypeDefs.h"
#include "TickTime.h"
#include "romops.h"
#include "mioEEPROM.h"

// Forward declarations
void setDigitalOutput(unsigned char io, BOOL state);

// Externs
extern Config configs[NUM_IO];
extern void sendProducedEvent(unsigned char action, BOOL on);
extern void setServoOutput(unsigned char io, unsigned char state);
extern void setBounceOutput(unsigned char io, unsigned char state);
extern void setMultiOutput(unsigned char io, unsigned char state);
extern void setOuputPin(unsigned char io, BOOL state);

// future state changes
struct {
    DWORD when;
    BOOL state;
    BOOL active;
} futures[NUM_IO];


/**
 * Set an output to the requested state.
 *  
 * @param i the IO
 * @param state on/off or position
 * @param type type of output
 */
void setOutput(unsigned char io, unsigned char action, unsigned char type) {
    switch(type) {
        case TYPE_INPUT:
            // this should never happen
            return;
        case TYPE_OUTPUT:
            setDigitalOutput(io, action);
            return;
        case TYPE_SERVO:
            setServoOutput(io, action);
            return;
        case TYPE_BOUNCE:
            setBounceOutput(io, action);
            return;
        case TYPE_MULTI:
            setMultiOutput(io, action);
            return;
    }
}

/**
 * Set a particular output pin to the given state.
 * @param io
 * @param state
 */
void setOutputPin(unsigned char io, BOOL state) {
    switch (configs[io].port) {
        case 'A':
            if (state) {
                // set it
                LATA |= (1<<configs[io].no);
            } else {
                // clear it
                LATA &= ~(1<<configs[io].no);
            }
            break;
        case 'B':
            if (state) {
                // set it
                LATB |= (1<<configs[io].no);
            } else {
                // clear it
                LATB &= ~(1<<configs[io].no);
            }
            break;
        case 'C':
            if (state) {
                // set it
                LATC |= (1<<configs[io].no);
            } else {
                // clear it
                LATC &= ~(1<<configs[io].no);
            }
            break;
    }
}

/**
 * Set a digital output. Handles inverted outputs and pulsed outputs. Sends the
 * produced events.
 * 
 * TODO pulsed outputs
 * 
 * @param io
 * @param action
 */
void setDigitalOutput(unsigned char io, BOOL state) {
    if (NV->io[io].nv_io.nv_output.outout_inverted) {
        state = state ? 0:1;
    }
    setOutputPin(io, state);
    ee_write(EE_OP_STATE+io, state);
    sendProducedEvent(ACTION_IO_PRODUCER_OUTPUT(io), state);
    // Was this a ON and we have a pulse duration defined?
    if (state && nodeVarTable.moduleNVs.io[io].nv_io.nv_output.output_pulse_duration) {
        // schedule a automatic off
        futures[io].state = FALSE;
        futures[io].when = tickGet() + nodeVarTable.moduleNVs.io[io].nv_io.nv_output.output_pulse_duration;
        futures[io].active = TRUE;
    }
}


