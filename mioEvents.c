
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
#include "analogue.h"

// forward declarations
void clearEvents(unsigned char i);
void doSOD(void);
void doWait(unsigned int duration);

extern void startOutput(unsigned char io, unsigned char action, unsigned char type);
extern void setOutputState(unsigned char io, unsigned char action, unsigned char type);
extern void doAction(unsigned char io, unsigned char state);
extern void inputScan(BOOL report);
extern BOOL sendProducedEvent(unsigned char action, BOOL on);
BOOL sendInvertedProducedEvent(HAPPENING_T action, BOOL state, BOOL invert);
extern BOOL needsStarting(unsigned char io, unsigned char action, unsigned char type);
extern BOOL completed(unsigned char io, unsigned char action, unsigned char type);

extern BYTE outputState[NUM_IO];
extern unsigned char currentPos[NUM_IO];

static TickValue startWait;

void mioEventsInit(void) {
    startWait.Val = 0;
}

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
    WORD en = io+1;
    clearEvents(io); 

    // add the module's default events for this io
    switch(type) {
        
#ifdef BOUNCE
        case TYPE_BOUNCE:
             addEvent(nodeID, 100+en, 0, HAPPENING_IO_OUTPUT(io), TRUE);
            // fall through
#endif 
        case TYPE_OUTPUT:    
            // Consume ACON/ASON and ACOF/ASOF events with en as port number
            addEvent(nodeID, en, 1, ACTION_IO_OUTPUT_EV(io), TRUE);
            // don't produce the event by default any more
            // addEvent(nodeID, 100+en, 0, HAPPENING_IO_OUTPUT(io), TRUE);
            break;
        case TYPE_INPUT:
            // Produce ACON/ASON and ACOF/ASOF events with en as port number
            addEvent(nodeID, en, 0, HAPPENING_IO_INPUT(io), TRUE);
            break;
#ifdef SERVO
        case TYPE_SERVO:
            // Produce ACON/ASON and ACOF/ASOF events with en as port number
            addEvent(nodeID, 100+en, 0, HAPPENING_IO_SERVO_START(io), TRUE);
            addEvent(nodeID, 300+en, 0, HAPPENING_IO_SERVO_MID(io), TRUE);
            addEvent(nodeID, 200+en, 0, HAPPENING_IO_SERVO_END(io), TRUE);
            // Consume ACON/ASON and ACOF/ASOF events with en as port number
            addEvent(nodeID, en, 1, ACTION_IO_SERVO_EV(io), TRUE);
            break;
#endif 
#ifdef MULTI
        case TYPE_MULTI:
            // no defaults for multi
            break;
#endif 
#ifdef ANALOGUE
        case TYPE_ANALOGUE_IN:
            // Produce ACON/ASON and ACOF/ASOF events with en as port number
            addEvent(nodeID, en, 0, HAPPENING_IO_ANALOGUE(io), TRUE);
            break;
        case TYPE_MAGNET:
            // Produce ACON/ASON and ACOF/ASOF events with en as port number
            addEvent(nodeID, en, 0, HAPPENING_IO_MAGNETH(io), TRUE);
            addEvent(nodeID, 100+en, 0, HAPPENING_IO_MAGNETL(io), TRUE);
            break;
#endif 
    }
}

/**
 * This is called by the CBUS library to see if any software generated events are to be sent.
 * Just return false as we no longer want to support this.
 * 
 * @param paction
 * @return false
 */
BOOL getDefaultProducedEvent(HAPPENING_T paction) {
    return FALSE;
}

/**
 * Clear the events for the IO. Called prior to setting the default events.
 * @param i the IO number
 */
void clearEvents(unsigned char io) {
    deleteActionRange(ACTION_IO_BASE(io),                       ACTIONS_PER_IO);
    deleteActionRange(ACTION_IO_BASE(io) | ACTION_SIMULTANEOUS, ACTIONS_PER_IO);
    deleteHappeningRange(HAPPENING_IO_BASE(io),                       HAPPENINGS_PER_IO);
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
#ifdef SAFETY
    if (opc != 0) {
        return; // error getting EVs. Can't report the error so just return
    }
#endif
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
                if ((action&ACTION_MASK) <= NUM_ACTIONS) {
                    // check global consumed actions
#ifdef __18F26K80
    //                if ((action&ACTION_MASK) == ACTION_STOP_PROCESSING) {
    //                    break;
    //                }
#endif
                    if ((action&ACTION_MASK) < BASE_ACTION_IO) {
                        pushAction((ACTION_T)action);
                    } else {
                        io = ACTION_IO(action&ACTION_MASK);
                        ca = ACTION(action&ACTION_MASK);
                        switch (NV->io[io].type) {
                            case TYPE_OUTPUT:
                                if (NV->io[io].flags & FLAG_EXPEDITED_ACTIONS) {
                                    setExpeditedActions();
                                }
                                // fall through
                            case TYPE_SERVO:
                            case TYPE_BOUNCE:
                                if (ca == ACTION_IO_1) {
                                    // action 1 (EV) must be converted to 2(ON)
                                    action++;
                                }
                                if (ca == ACTION_IO_5) {
                                    // action 5 (EV) must be converted to 3(OFF)
                                    action-=2;
                                }
                                pushAction((ACTION_T)action);
                                setNormalActions();
                                break;
                            case TYPE_MULTI:
                                pushAction((ACTION_T)action);
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
        //int nextAction = getEv(tableIndex, EVperEVT-1);
        int nextAction = evs[EVperEVT-1];
        for (e=EVperEVT-1; e>=1 ;e--) { 
            unsigned char nextSimultaneous;
            unsigned char firstAction = NO_ACTION;  // used to determine simultaneous flag for the end of actions
            action = nextAction;  // we don't mask out the SIMULTANEOUS flag so it could be specified in EVs
            

            // get the Simultaneous flag from the next action
            if (e > 1) {
                nextAction = evs[e-1];
                nextSimultaneous = nextAction & ACTION_SIMULTANEOUS;
            } else {
                nextSimultaneous = firstAction & ACTION_SIMULTANEOUS;
            }
            if (action != NO_ACTION) {
                // record the first action we come to - which is actually the last action when doing an ON event
                if (firstAction == NO_ACTION) {
                    firstAction = action;
                }
                action &= ACTION_MASK;
                if (action <= NUM_ACTIONS) {
                    // check global consumed actions
#ifdef __18F26K80
    //                if (action == ACTION_STOP_PROCESSING) {
    //                    break;
    //                }
#endif
                    if ((action < BASE_ACTION_IO) && (action != ACTION_SOD)) {  // Only do SoD on ON events
                        pushAction(action|nextSimultaneous);
                    } else {
                        io = ACTION_IO(action);
                        ca = ACTION(action);
                        switch (NV->io[io].type) {
                            case TYPE_OUTPUT:
                                if (NV->io[io].flags & FLAG_EXPEDITED_ACTIONS) {
                                    setExpeditedActions();
                                }
                                if (ca == ACTION_IO_4) {
                                    // action 4 (Flash) must be converted to 3(OFF)
                                    action--;
                                }
                                // fall through
                            case TYPE_SERVO:
                            case TYPE_BOUNCE:
                                if (ca == ACTION_IO_1) {
                                    // action 1 (EV) must be converted to 3(OFF)
                                    action += 2;
                                }
                                if (ca == ACTION_IO_5) {
                                    // action 5 (EV) must be converted to 3(ON)
                                    action -= 3;
                                }
                                pushAction(action|nextSimultaneous);
                                setNormalActions();
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
//static unsigned char lastAction = NO_ACTION;
/**
 * This needs to be called on a regular basis to see if any
 * actions have finished and the next needs to be started.
 */
void processActions(void) {
    unsigned char io;
    unsigned char type;
    ACTION_T action = getAction();
    ACTION_T ioAction;
    unsigned char simultaneous;
    unsigned char peekItem;
    
    
    if (action == NO_ACTION) {
        doneAction();
        return;
    }
    // Check for SOD
    if (action == ACTION_SOD) {
        // Do the SOD
        doSOD();
        doneAction();
        return;
    }
    if (action == ACTION_WAIT05) {
        doWait(5);
        return;
    }
    if (action == ACTION_WAIT1) {
        doWait(10);
        return;
    }
    if (action == ACTION_WAIT2) {
        doWait(20);
        return;
    }
    if (action == ACTION_WAIT5) {
        doWait(50);
        return;
    }
    simultaneous = action & ACTION_SIMULTANEOUS;
    ioAction = action&ACTION_MASK;
    if ((ioAction >= BASE_ACTION_IO) && (ioAction < NUM_ACTIONS)) {
        // process IO based consumed actions
        
        io = ACTION_IO(ioAction);
        ioAction = ACTION(ioAction);
        type = NV->io[io].type;

        // check if a simultaneous action needs to be started
        setOutputState(io, ioAction, type);
        if (needsStarting(io, ioAction, type)) {
            startOutput(io, ioAction, type);
        }
        // is this the start of a new action?
//        if (lastAction != action) {
//            lastAction = action;
            // now check to see if any others need starting  
            peekItem = 1;
            while (simultaneous) {
                ACTION_T nextAction;
                unsigned char nextIo;
                unsigned char nextType;
            
                nextAction = peekActionQueue(peekItem);
                if (nextAction == NO_ACTION) break;
                simultaneous = nextAction & ACTION_SIMULTANEOUS;
                nextAction &= ACTION_MASK;
                nextIo = ACTION_IO(nextAction);
                if (nextIo == io) {
                    // we shouldn't have 2 actions on the same IO at the same time
                    break;
                }
                nextAction = ACTION(nextAction);
                nextType = NV->io[nextIo].type;
                setOutputState(nextIo, nextAction, nextType);
                if (needsStarting(nextIo, nextAction, nextType)) {
                    startOutput(nextIo, nextAction, nextType);
                }
                if (completed(nextIo, nextAction, nextType)) {
                    deleteActionQueue(peekItem);
                }
                peekItem++;
            }
//        }
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
    
    // Although I agreed with Pete that SOD is only applicable to EV#2 I actually allow it at any EV#

    for (io=0; io < NUM_IO; io++) {
        unsigned char event_inverted = NV->io[io].flags & FLAG_RESULT_EVENT_INVERTED;
        switch(NV->io[io].type) {
            case TYPE_INPUT:
                /* The TRIGGER_INVERTED has already been taken into account when saved in outputState. No need to check again */
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_INPUT(io), outputState[io], event_inverted)) ;
                break;
            case TYPE_OUTPUT:
                state = ee_read(EE_OP_STATE+io);
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_OUTPUT(io), state!=ACTION_IO_3, event_inverted));
                break;
#ifdef SERVO
            case TYPE_SERVO:
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_SERVO_START(io), currentPos[io] == NV->io[io].nv_io.nv_servo.servo_start_pos, event_inverted));
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_SERVO_END(io), currentPos[io] == NV->io[io].nv_io.nv_servo.servo_end_pos, event_inverted));
                // send the last mid
                midway = (NV->io[io].nv_io.nv_servo.servo_end_pos)/2 + 
                         (NV->io[io].nv_io.nv_servo.servo_start_pos)/2;
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_SERVO_MID(io), currentPos[io] >= midway, event_inverted));
                break;
#ifdef BOUNCE
            case TYPE_BOUNCE:
                state = ee_read(EE_OP_STATE+io);
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_BOUNCE(io), state, event_inverted));
                break;
#endif
#ifdef MULTI
            case TYPE_MULTI:
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_MULTI_AT1(io), currentPos[io] == NV->io[io].nv_io.nv_multi.multi_pos1, event_inverted));
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_MULTI_AT2(io), currentPos[io] == NV->io[io].nv_io.nv_multi.multi_pos2, event_inverted));
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_MULTI_AT3(io), currentPos[io] == NV->io[io].nv_io.nv_multi.multi_pos3, event_inverted));
                if (NV->io[io].nv_io.nv_multi.multi_num_pos > 3) {
                    while ( ! sendInvertedProducedEvent(HAPPENING_IO_MULTI_AT4(io), currentPos[io] == NV->io[io].nv_io.nv_multi.multi_pos4, event_inverted));
                }
                break;
#endif
#endif
#ifdef ANALOGUE
            case TYPE_ANALOGUE_IN:
            case TYPE_MAGNET:
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_MAGNETL(io), eventState[io] == ANALOGUE_EVENT_LOWER, event_inverted));
                while ( ! sendInvertedProducedEvent(HAPPENING_IO_MAGNETH(io), eventState[io] == ANALOGUE_EVENT_UPPER, event_inverted));
                break;
#endif
        }
    }
}

BOOL sendInvertedProducedEvent(HAPPENING_T action, BOOL state, BOOL invert) {
    return sendProducedEvent(action, invert?!state:state);
}
