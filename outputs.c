
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

// Forward declarations
void setDigitalOutput(unsigned char io, BOOL state);

// Externs
extern Config configs[NUM_IO];
extern void sendProducedEvent(unsigned char action, BOOL on);
extern void setServoOutput(unsigned char io, unsigned char state);
extern void setBounceOutput(unsigned char io, unsigned char state);
extern void setMultiOutput(unsigned char io, unsigned char state);
extern void setOuputPin(unsigned char io, BOOL state);


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
#ifdef BOUNCE
        case TYPE_BOUNCE:
#endif
#ifdef SERVO
        case TYPE_SERVO:
            setServoOutput(io, action);
            return;
#endif
#ifdef MULTI
        case TYPE_MULTI:
            setMultiOutput(io, action);
            return;
#endif
    }
}

/**
 * Indicates if the action needs to be started.
 * @ return true if needs starting
 */
BOOL needsStarting(unsigned char io, unsigned char action, unsigned char type) {
    switch(type) {
        case TYPE_INPUT:
            // this should never happen
            return FALSE;
        case TYPE_OUTPUT:
            // TODO needs fixing as if doing a pulse we don't need a restart
            return TRUE;
#ifdef SERVO
        case TYPE_SERVO:
#ifdef BOUNCE
        case TYPE_BOUNCE:
#endif
#ifdef MULTI
        case TYPE_MULTI:
#endif
            return (servoState[io] != MOVING);
#endif
    }
    return TRUE;
}

/**
 * Indicates if the action has been completed.
 * @return true if completed
 */
BOOL completed(unsigned char io, unsigned char action, unsigned char type) {
    switch(type) {
        case TYPE_INPUT:
            // this should never happen
            return TRUE;
        case TYPE_OUTPUT:
            // when asked on the MERG forum nobody was bothered whether sequential actions 
            // wait for a pulse to complete. Therefore to make it easy we don't wait.
            return TRUE;
#ifdef SERVO
        case TYPE_SERVO:
#ifdef BOUNCE
        case TYPE_BOUNCE:
#endif
#ifdef MULTI
        case TYPE_MULTI:
#endif
            return (servoState[io] != MOVING);
#endif
    }
    return TRUE;
}
