
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
 * File:   bounce.c
 * Author: Ian
 * 
 * Handle the servo outputs. The output signal is a pulse between 1ms and 2ms where the width of the
 * pulse results in the servo moving to an angle. The outputs are driven by Timers to ensure that the
 * pulse width is accurate - although if interrupts are disabled then the width could be longer than
 * intended.
 * Pulses are output approximately every 20ms. Therefore we need more than 1 timer for all 16 possible 
 * servo outputs (16 * 2ms = 32ms which is greater than the 20ms available). A minimum of 2 timers 
 * (each handling 8 servos) is required but if we allow overdrive beyond 2ms then 3 (6 servos) or 
 * 4 (4 servos) timers is better.
 * Here we use 4 timers. Timer1..Timer4.
 * 
 * The timers are driven from Fosc/4 and use a 1:4 prescalar. With a 16MHz resonator and 4x PLL this 
 * equates to a timer increment every 0.25us. We require counts from 1ms to 2ms or 4000 - 8000 timer ticks.
 * We have an 8 bit position value and actually want to allow a bit of overdrive of the servo 0.9ms - 2.1ms.
 * (3600 ticks - 8400 ticks). This gives a range of 4800 ticks over the 8 bit range. Therefore each value
 * of the position is equivalent to 18.75 ticks - let's call it 19. The 3600 ticks at position 0 so to 
 * convert from position to ticks we need to use:
 *    Ticks = 3600 + 19 * position 
 * This is fine for the 16bit Timer1 and Timer3 but the 8 bit timers Timer2 and Timer4 need a bit more work.
 * 
 *
 * Created on 1 June 2017, 13:14
 */
#include <xc.h>
#include "module.h"
#ifdef BOUNCE
#include "GenericTypeDefs.h"
#include "servo.h"

extern ServoState  servoState[NUM_IO];
extern unsigned char currentPos[NUM_IO];
extern unsigned char targetPos[NUM_IO];
extern char speed[NUM_IO];

typedef enum {
    FIRST_PULL,
    BOUNCE
} BounceState;
BounceState bounceState[NUM_IO];


/**
 * A constant force pulling the signal down.
 */
#define G	3	
/**
 * The amount of velocity preserved after a bounce. Units are percent.
 */
#define BOUNCE_COEFF 50
/**
 * Used to determine when the signal position is 'good enough' to stop. If this is too small 
 * the due to integer arithmetic rounding errors this can cause the bouncing to repeat for ever.
 */
#define BOUNDS 3
/**
 * Indicates how fast the virtual signal operator pulls the signal on.
 */
#define PULL_SPEED 12

void initBounce(unsigned char io) {
    bounceState[io] = FIRST_PULL;
}

/**
 * Implement the signal bounce when the signal is released.
 * This implementation assumes that the signal is released and falls under a constant force
 * and the bounce is against a hard stop. This should work well for upper quadrant signals
 * where the end stop is at the horizontal position but maybe not quite correct for lower 
 * quadrant signals.
 * 
 * @return true if finished moving
 */
BOOL bounceDown(unsigned char io) {
    // check if we still need to move the signal
    if ((currentPos[io]>targetPos[io]+BOUNDS) || (currentPos[io]<targetPos[io]-BOUNDS) || (speed[io]>BOUNDS) || (speed[io]<-BOUNDS)) {
        // acceleration due to gravity
        speed[io] += G;
        // move position
        currentPos[io] -= speed[io];
        // check for bounce at bottom of signal movement
        if (currentPos[io] < targetPos[io]) {
            currentPos[io] = targetPos[io]-(currentPos[io]-targetPos[io]);
            speed[io] = -speed[io];
            speed[io] = ((int)speed[io] * BOUNCE_COEFF)/100;	// be careful that this doesn't overflow - use int internally
        }
        return FALSE;    // still moving
    }         
    return TRUE;    // finished moving
}

/**
 * Emulate the signal operator pulling the signal on to a line clear state.
 * This assumes the virtual operator pulls at a constant rate until they hit the end stop
 * whereupon the signal bounces a little.
 * In reality the operator is likely to release the latch and pull halfway then give the signal
 * lever a final pull to get it latched in the on position. 
 * 
 * @return true if finished moving
 */

BOOL bounceUp(unsigned char io) {
    switch(bounceState[io]) {
    case FIRST_PULL:
        // first just move to the targetPos[io]
        currentPos[io] -= speed[io];
        if (currentPos[io]>=targetPos[io]-BOUNDS) {
            bounceState[io] = BOUNCE;
        }
        break;
    case BOUNCE:
        if ((currentPos[io]>targetPos[io]+BOUNDS) || (currentPos[io]<targetPos[io]-BOUNDS) || (speed[io]>BOUNDS) || (speed[io]<-BOUNDS)) {
            // acceleration due to pull using G but really this is wrong maybe a function of PULL_SPEED would be better
            speed[io] -= G;
            // move position
            currentPos[io] -= speed[io];
            // check for bounce
            if (currentPos[io] > targetPos[io]) {
                currentPos[io] = targetPos[io]-(currentPos[io]-targetPos[io]);
                speed[io] = -speed[io];
                speed[io] = ((int)speed[io] * BOUNCE_COEFF)/100;	// be careful that this doesn't overflow - use int internally
            }
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

#endif