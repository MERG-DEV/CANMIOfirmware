#ifndef  __SERVO_H__
#define  __SERVO_H__

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
 * File:   servo.h
 * Author: Ian
 * 
 * Created on 1 June 2017, 13:14
 */
#include "devincs.h"
#include "canmio.h"
#include "actionQueue.h"

typedef enum {
    OFF,            // not generating any pulses
    STOPPED,        // pulse width fixed, reached desired destination
    MOVING,         // pulse width changing
    STARTING
} ServoState;

extern ServoState servoState[NUM_IO];
extern unsigned char currentPos[NUM_IO];
extern unsigned char targetPos[NUM_IO];
extern unsigned char stepsPerPollSpeed[NUM_IO];
extern int speed[NUM_IO];

extern void startServos(void);
extern void initServos(void);
extern void pollServos(void);
extern void timer1DoneInterruptHandler(void);
extern void timer2DoneInterruptHandler(void);
extern void timer3DoneInterruptHandler(void);
extern void timer4DoneInterruptHandler(void);

extern void setServoState(unsigned char io, CONSUMER_ACTION_T action);
extern void setBounceState(unsigned char io, CONSUMER_ACTION_T action);
extern void setMultiState(unsigned char io, CONSUMER_ACTION_T action);

extern void setServoPosition(unsigned char io, unsigned char pos);

extern void startServoOutput(unsigned char io, CONSUMER_ACTION_T action);
extern void startBounceOutput(unsigned char io, CONSUMER_ACTION_T action);
extern void startMultiOutput(unsigned char io, CONSUMER_ACTION_T action);

#define PIVOT                   234     // the value at which we switch from steps per poll to polls per step

#endif  //__SERVO_H__
