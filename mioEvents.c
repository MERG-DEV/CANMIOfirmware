
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
#include "module.h"
#include "GenericTypeDefs.h"
#include "romops.h"
#include "mioEEPROM.h"
#include "mioNv.h"
#include "mioEvents.h"
#include "cbus.h"
#include "actionQueue.h"
#include "FliM.h" 

// forward declarations
void clearEvents(unsigned char i);
void doSOD(void);
void doWait(unsigned int duration);

extern void startOutput(unsigned char io, unsigned char action, unsigned char type);
extern void setOutput(unsigned char io, unsigned char action, unsigned char type);
extern void doAction(unsigned char io, unsigned char state);
extern void inputScan(BOOL report);
extern BOOL sendProducedEvent(unsigned char action, BOOL on);
extern BOOL needsStarting(unsigned char io, unsigned char action, unsigned char type);
extern BOOL completed(unsigned char io, unsigned char action, unsigned char type);

extern BYTE inputState[NUM_IO];
extern unsigned char currentPos[NUM_IO];

static TickValue startWait;

/**
 * Set Global Events back to factory defaults.
 */
void factoryResetGlobalEvents(void) {
    // we don't create a default SOD event
}

/**
 * Reset events for the IO back to default. Called when the Type of the IO
 * is changed.
 * @param io the IO number
 */
void defaultEvents(unsigned char io, unsigned char type) {
    WORD nn = ee_read_short((WORD)EE_NODE_ID);
    WORD en = io+1;
    clearEvents(io); 
#ifdef TEST_DEFAULT_EVENTS
    // add the module's default events for this io
    switch(type) {
        case TYPE_OUTPUT:
        case TYPE_BOUNCE:
            /*
             * We create both a Produced and a Consumed event here.
             */
            // Consume ACON/ASON and ACOF/ASOF events with en as port number
            addEvent(nn, en, 1, ACTION_IO_CONSUMER_OUTPUT_EV(io), TRUE);
            addEvent(nn, 200+en, 1, ACTION_IO_CONSUMER_OUTPUT_FLASH(io), TRUE);
//            addEvent(nn, 100+en, 0, ACTION_IO_PRODUCER_OUTPUT(io), TRUE);
            break;
        case TYPE_INPUT:
            // Produce ACON/ASON and ACOF/ASOF events with en as port number
 //           addEvent(nn, en, 0, ACTION_IO_PRODUCER_INPUT(io), TRUE);
            break;
        case TYPE_SERVO:
            // Produce ACON/ASON and ACOF/ASOF events with en as port number
//            addEvent(nn, 100+en, 0, ACTION_IO_PRODUCER_SERVO_START(io), TRUE);
//            addEvent(nn, 300+en, 0, ACTION_IO_PRODUCER_SERVO_MID(io), TRUE);
//            addEvent(nn, 200+en, 0, ACTION_IO_PRODUCER_SERVO_END(io), TRUE);
            // Consume ACON/ASON and ACOF/ASOF events with en as port number
            addEvent(nn, en, 1, ACTION_IO_CONSUMER_SERVO_EV(io), TRUE);
            break;
        case TYPE_MULTI:
            // no defaults for multi
            break;
        case TYPE_ANALOGUE_IN:
            // Produce ACON/ASON and ACOF/ASOF events with en as port number
 //           addEvent(nn, en, 0, ACTION_IO_PRODUCER_ANALOGUE(io), TRUE);
            break;
        case TYPE_MAGNET:
            // Produce ACON/ASON and ACOF/ASOF events with en as port number
 //           addEvent(nn, en, 0, ACTION_IO_PRODUCER_MAGNETH(io), TRUE);
 //           addEvent(nn, 100+en, 0, ACTION_IO_PRODUCER_MAGNETL(io), TRUE);
            break;
    }
#endif
}

/**
 * If we don't define default produced actions in the eventTable above then
 * we can generate the event using code. This was requested by PeteB so that
 * eventTable space isn't used unnecessarily. The downside is that NERD won't
 * list these events.
 * If a default event is defined here then it should be written to the global
 * producedEvent variable.
 * 
 * @param action
 * @return true if there is an event
 */
BOOL getDefaultProducedEvent(PRODUCER_ACTION_T paction) {
    if (paction >= ACTION_PRODUCER_IO_BASE) {
        unsigned char io = PRODUCER_IO(paction);
        producedEvent.NN = nodeID;
        
        switch (NV->io[io].type) {
            case TYPE_MAGNET:
                if (paction == ACTION_IO_PRODUCER_MAGNETH(io)) {
                    producedEvent.EN = io + 101;
                    return TRUE;
                }
                // fall through
            case TYPE_INPUT:
            case TYPE_ANALOGUE_IN:
                // Also ACTION_IO_PRODUCER_MAGNETL(io) and ACTION_IO_PRODUCER_ANALOGUE(io))
                if (paction == ACTION_IO_PRODUCER_INPUT(io)) {
                    producedEvent.EN = io + 1;
                    return TRUE;
                }
                break;
            case TYPE_BOUNCE:
            case TYPE_OUTPUT:
                if (paction == ACTION_IO_PRODUCER_OUTPUT(io)) {
                    producedEvent.EN = io + 101;
                    return TRUE;
                }
                break;
            case TYPE_SERVO:
                if (paction == ACTION_IO_PRODUCER_SERVO_START(io)) {
                    producedEvent.EN = io + 101;
                    return TRUE;
                }
                if (paction == ACTION_IO_PRODUCER_SERVO_MID(io)) {
                    producedEvent.EN = io + 301;
                    return TRUE;
                }
                if (paction == ACTION_IO_PRODUCER_SERVO_END(io)) {
                    producedEvent.EN = io + 201;
                    return TRUE;
                }
                break;
        }
    } 
    return FALSE;
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
 * Process the consumed events. Extract the actions from the EVs. 
 * The actions are pushed onto the actionQueue for subsequent processing in
 * sequence.
 * 
 * If an event is defined to have actions A1, A2, A3, A4 and A2 has the SIMULANEOUS 
 * flag set then the sequence will be executed for ON event: A1, A2&A3, A4 and
 * we therefore put:
 *  A1 (sequential), A2 (simultaneous), A3 (sequential, A4 (sequential) 
 * into the action queue.
 * 
 * For an OFF event we want the sequence: A4, A3&A2, A1 and therefore we put:
 *  A4 (sequential), A3 (simultaneous), A2 (sequential), A1 (sequential)
 * into the action queue. Therefore when doing an OFF Event we need to fiddle
 * with the SIMULTANEOUS bit.
 * 
 * @param tableIndex the required action to be performed.
 * @param msg the full CBUS message so that OPC  and DATA can be retrieved.
 */
void processEvent(BYTE tableIndex, BYTE * msg) {
    unsigned char e;
    unsigned char io;
    unsigned char ca;
    int action;

    BYTE opc = getEVs(tableIndex);
    if (opc != 0) {
        return; // error getting EVs. Can't report the error so just return
    }
    opc=msg[d0];
    // check the OPC if this is an ON or OFF event
    if ( ! (opc&EVENT_ON_MASK)) {
        // ON events work up through the EVs
        // EV#0 is for produced event so start at 1
        // TODO would be more efficient to get all the EVs in one go and then work through them. getEV() isn't quick)
        for (e=1; e<EVperEVT ;e++) { 
            action = evs[e];  // we don't mask out the SEQUENTIAL flag so it could be specified in EVs
            if (action != NO_ACTION) {
                // check this is a consumed action
                if ((action&ACTION_MASK) <= NUM_CONSUMER_ACTIONS) {
                    // check global consumed actions
                    if ((action&ACTION_MASK) < ACTION_CONSUMER_IO_BASE) {
                        pushAction((CONSUMER_ACTION_T)action);
                    } else {
                        io = CONSUMER_IO(action&ACTION_MASK);
                        ca = CONSUMER_ACTION(action&ACTION_MASK);
                        switch (NV->io[io].type) {
                            case TYPE_OUTPUT:
                            case TYPE_SERVO:
                            case TYPE_BOUNCE:
                                if (ca == ACTION_IO_CONSUMER_1) {
                                    // action 1 (EV) must be converted to 2(ON)
                                    action++;
                                }
                                pushAction((CONSUMER_ACTION_T)action);
                                break;
                            case TYPE_MULTI:
                                pushAction((CONSUMER_ACTION_T)action);
                                break;
                            default:
                                // shouldn't happen - just ignore
                                break;
                        }
                    }
                }
            }
        } 
    } else {
	// OFF events work down through the EVs
        // TODO would be more efficient to get all the EVs in one go and then work through them. getEV() isn't quick)
        int nextAction = getEv(tableIndex, EVperEVT-1);
        for (e=EVperEVT-1; e>=1 ;e--) { 
            unsigned char nextSimultaneous;
            action = nextAction;  // we don't mask out the SIMULTANEOUS flag so it could be specified in EVs
            

            // get the Simultaneous flag from the next action
            nextSimultaneous = ACTION_SIMULTANEOUS;
            if (e > 1) {
                nextAction = evs[e-1];
                    nextSimultaneous = nextAction & ACTION_SIMULTANEOUS;
            }
            if (action != NO_ACTION) {
                action &= ACTION_MASK;
                if (action <= NUM_CONSUMER_ACTIONS) {
                    // check global consumed actions
                    if (action < ACTION_CONSUMER_IO_BASE) {
                        pushAction(action|nextSimultaneous);
                    } else {
                        io = CONSUMER_IO(action);
                        ca = CONSUMER_ACTION(action);
                        switch (NV->io[io].type) {
                            case TYPE_OUTPUT:
                            case TYPE_SERVO:
                            case TYPE_BOUNCE:
                                if (ca == ACTION_IO_CONSUMER_1) {
                                    // action 1 (EV) must be converted to 3(OFF)
                                    action += 2;
                                }
                                pushAction(action|nextSimultaneous);
                                break;
                            case TYPE_MULTI:
                                pushAction(action|nextSimultaneous);
                                break;
                            default:
                                // shouldn't happen - just ignore
                                break;
                        }
                    }
                }
            }
        } // ignore getEv errors as we expect CMDERR_NO_EV
    }
}

// record the last action started so we can tell if we are starting a new action 
static unsigned char lastAction = NO_ACTION;
/**
 * This needs to be called on a regular basis to see if any
 * actions have finished and the next needs to be started.
 */
void processActions(void) {
    unsigned char io;
    unsigned char type;
    CONSUMER_ACTION_T action = getAction();
    CONSUMER_ACTION_T ioAction;
    unsigned char simultaneous;
    unsigned char peekItem;
    
    
    if (action == NO_ACTION) return;
    // Check for SOD
    if (action == ACTION_CONSUMER_SOD) {
        // Do the SOD
        doSOD();
        doneAction();
        return;
    }
    if (action == ACTION_CONSUMER_WAIT05) {
        doWait(5);
        return;
    }
    if (action == ACTION_CONSUMER_WAIT1) {
        doWait(10);
        return;
    }
    if (action == ACTION_CONSUMER_WAIT2) {
        doWait(20);
        return;
    }
    if (action == ACTION_CONSUMER_WAIT5) {
        doWait(50);
        return;
    }
    simultaneous = action & ACTION_SIMULTANEOUS;
    ioAction = action&ACTION_MASK;
    if ((ioAction >= ACTION_CONSUMER_IO_BASE) && (ioAction < NUM_CONSUMER_ACTIONS)) {
        // process IO based consumed actions
        
        io = CONSUMER_IO(ioAction);
        ioAction = CONSUMER_ACTION(ioAction);
        type = NV->io[io].type;

        // check if a simultaneous action needs to be started
        setOutput(io, ioAction, type);
        if (needsStarting(io, ioAction, type)) {
            startOutput(io, ioAction, type);
        }
        // is this the start of a new action?
        if (lastAction != action) {
            lastAction = action;
            // now check to see if any others need starting  
            peekItem = 1;
            while (simultaneous) {
                CONSUMER_ACTION_T nextAction;
                unsigned char nextIo;
                unsigned char nextType;
            
                nextAction = peekActionQueue(peekItem);
                if (nextAction == NO_ACTION) break;
                simultaneous = nextAction & ACTION_SIMULTANEOUS;
                nextAction &= ACTION_MASK;
                nextIo = CONSUMER_IO(nextAction);
                if (nextIo == io) {
                    // we shouldn't have 2 actions on the same IO at the same time
                    break;
                }
                nextAction = CONSUMER_ACTION(nextAction);
                nextType = NV->io[nextIo].type;
                setOutput(nextIo, nextAction, nextType);
                if (needsStarting(nextIo, nextAction, nextType)) {
                    startOutput(nextIo, nextAction, nextType);
                }
                if (completed(nextIo, nextAction, nextType)) {
                    deleteActionQueue(peekItem);
                }
                peekItem++;
            }
        }
        // check if this current action has been completed
        if (completed(io, ioAction, type)) {
            doneAction();
        }
    } else {
        // shouldn't get here as this is an unknown action
        // In case we do get here make sure we do the action to prevent endless loop
        doneAction();
    }
}

/**
 * Stop processing actions for a while.
 * 
 * @param duration in 0.1second units
 */
void doWait(unsigned int duration) {
    // start the timer
    if (startWait.Val == 0) {
        startWait.Val = tickGet();
        return;
    } else {
        // check if timer expired
        if ((tickTimeSince(startWait) > ((long)duration * (long)HUNDRED_MILI_SECOND))) {
            doneAction();
            startWait.Val = 0;
            return;
        } 
    }
}
/**
 * Do the consumed SOD action. This sends events to indicate current state of the system.
 */
void doSOD(void) {
    unsigned char midway;
    BOOL state;
    unsigned char io;
    
    // Agreed with Pete that SOD is only applicable to EV#2 but I actually allow it at any EV#
    inputScan(TRUE);    // ensure we have current input status
    for (io=0; io < NUM_IO; io++) {
        switch(NV->io[io].type) {
            case TYPE_INPUT:
                while ( ! sendProducedEvent(ACTION_IO_PRODUCER_OUTPUT(io), inputState[io])) ;
                break;
            case TYPE_OUTPUT:
                state = ee_read(EE_OP_STATE+io);
                while ( ! sendProducedEvent(ACTION_IO_PRODUCER_OUTPUT(io), state));
                break;
            case TYPE_SERVO:
                while ( ! sendProducedEvent(ACTION_IO_PRODUCER_SERVO_START(io), currentPos[io] == NV->io[io].nv_io.nv_servo.servo_start_pos));
                while ( ! sendProducedEvent(ACTION_IO_PRODUCER_SERVO_END(io), currentPos[io] == NV->io[io].nv_io.nv_servo.servo_end_pos));
                // send the last mid
                midway = (NV->io[io].nv_io.nv_servo.servo_end_pos)/2 + 
                         (NV->io[io].nv_io.nv_servo.servo_start_pos)/2;
                while ( ! sendProducedEvent(ACTION_IO_PRODUCER_SERVO_MID(io), currentPos[io] >= midway));
                break;
            case TYPE_BOUNCE:
                state = ee_read(EE_OP_STATE+io);
                while ( ! sendProducedEvent(ACTION_IO_PRODUCER_BOUNCE(io), state));
                break;
            case TYPE_MULTI:
                while ( ! sendProducedEvent(ACTION_IO_PRODUCER_MULTI_AT1(io), currentPos[io] == NV->io[io].nv_io.nv_multi.multi_pos1));
                while ( ! sendProducedEvent(ACTION_IO_PRODUCER_MULTI_AT2(io), currentPos[io] == NV->io[io].nv_io.nv_multi.multi_pos2));
                while ( ! sendProducedEvent(ACTION_IO_PRODUCER_MULTI_AT3(io), currentPos[io] == NV->io[io].nv_io.nv_multi.multi_pos3));
                if (NV->io[io].nv_io.nv_multi.multi_num_pos > 3) {
                    while ( ! sendProducedEvent(ACTION_IO_PRODUCER_MULTI_AT4(io), currentPos[io] == NV->io[io].nv_io.nv_multi.multi_pos4));
                }
                break;
        }
    }
}
