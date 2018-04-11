
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
 * Handle the various types of outputs. 
 * Call specific functions for the different output types.
 * This should really be an Interface or a super class but this is C
 *
 * Created on 17 April 2017, 13:14
 */

#include "module.h"
#include "mioNv.h"
#include "mioEvents.h"
#include "FliM.h"
#include "config.h"
#include "GenericTypeDefs.h"
#include "TickTime.h"
#include "romops.h"
#include "mioEEPROM.h"
#include "servo.h"
#include "actionQueue.h"
#include "digitalOut.h"

// Forward declarations


// Externs
extern void setOuputPin(unsigned char io, BOOL state);

extern unsigned char pulseDelays[NUM_IO];


/**
 * Set an output to the requested state.
 *  
 * @param i the IO
 * @param state on/off or position
 * @param type type of output
 */
void startOutput(unsigned char io, CONSUMER_ACTION_T action, unsigned char type) {
    switch(type) {
        case TYPE_INPUT:
            // this should never happen
            return;
        case TYPE_OUTPUT:
            startDigitalOutput(io, action);
            return;
#ifdef BOUNCE
        case TYPE_BOUNCE:
            startBounceOutput(io, action);
            return;
#endif
#ifdef SERVO
        case TYPE_SERVO:
            startServoOutput(io, action);
            return;
#endif
#ifdef MULTI
        case TYPE_MULTI:
            startMultiOutput(io, action);
            return;
#endif
    }
}

/**
 * Set an output to the requested state.
 *  
 * @param i the IO
 * @param state on/off or position
 * @param type type of output
 */
void setOutputState(unsigned char io, CONSUMER_ACTION_T action, unsigned char type) {
    switch(type) {
        case TYPE_INPUT:
        case TYPE_ANALOGUE_IN:
        case TYPE_MAGNET:
            // this should never happen
            return;
        case TYPE_OUTPUT:
//            setDigitalOutput(io, action);
            return;
#ifdef BOUNCE
        case TYPE_BOUNCE:
            setBounceState(io, action);
            return;
#endif
#ifdef SERVO
        case TYPE_SERVO:
            setServoState(io, action);
            return;
#endif
#ifdef MULTI
        case TYPE_MULTI:
            setMultiState(io, action);
            return;
#endif
    }
}

/**
 * Set an output to the requested position Called during initialisation
 *  
 * @param i the IO
 * @param state on/off or position
 * @param type type of output
 */
void setOutputPosition(unsigned char io, unsigned char pos, unsigned char type) {
    switch(type) {
        case TYPE_INPUT:
        case TYPE_ANALOGUE_IN:
        case TYPE_MAGNET:
            // this should never happen
            return;
        case TYPE_OUTPUT:
            setDigitalOutput(io, pos);
            return;
#ifdef BOUNCE
        case TYPE_BOUNCE:
#endif
#ifdef MULTI
        case TYPE_MULTI:
#endif
#ifdef SERVO
        case TYPE_SERVO:
            setServoPosition(io, pos);
            setOutputPin(io, NV->io[io].flags & FLAG_RESULT_ACTION_INVERTED);
            return;
#endif

    }
}

/**
 * Indicates if the action needs to be started.
 * @ return true if needs starting
 */
BOOL needsStarting(unsigned char io, CONSUMER_ACTION_T action, unsigned char type) {
    switch(type) {
        case TYPE_INPUT:
            // this should never happen
            return FALSE;
        case TYPE_OUTPUT:
            // Normal outputs will complete immediately.
            // Flashing outputs will complete immediately
            // pulsed output will complete after pulse has finished
            // but we need to start them all
            return (pulseDelays[io] == 0);
#ifdef SERVO
        case TYPE_SERVO:
#ifdef BOUNCE
            
        case TYPE_BOUNCE:
#endif
#ifdef MULTI
        case TYPE_MULTI:
#endif
            if (targetPos[io] == currentPos[io]) {
                servoState[io] = OFF;
                return FALSE;
            }
            return (servoState[io] != MOVING);
#endif
    }
    return TRUE;
}

/**
 * Indicates if the action has been completed.
 * @return true if completed
 */
BOOL completed(unsigned char io, CONSUMER_ACTION_T action, unsigned char type) {
    switch(type) {
        case TYPE_INPUT:
            // this should never happen
            return TRUE;
        case TYPE_OUTPUT:
            // wait for a pulse to complete. 
            return pulseDelays[io] == 0;
#ifdef SERVO
        case TYPE_SERVO:
#ifdef BOUNCE
        case TYPE_BOUNCE:
#endif
#ifdef MULTI
        case TYPE_MULTI:
#endif
            return (targetPos[io] == currentPos[io]) && ((servoState[io] == STOPPED) || (servoState[io] == OFF));
#endif
    }
    return TRUE;
}
