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
 * File:   actionQueue.c
 * Author: Ian
 *
 * Created on 1 June 2017, 13:14
 *
 * A queue of actions waiting to be processed by the main loop.
 * This is actually implemented as a cyclic buffer and a current action.
 * Items in the buffer can be replaced by other actions on the same IO
 * but the current action will be finished in its entirity.
 */

#include "GenericTypeDefs.h"
#include "mioEvents.h"
#include "actionQueue.h"

// Forward declarations
ACTION_T pullAction();

#define BUFFER_SIZE 	32		// The size needs to be big enough to store all the pending actions 
					// for CANMIO 16 should be enough but need +1 to separate the ends
					// of the cyclic buffer so need to move the next power of two since
					// cyclic wrapping is done with a bitmask.
#define POINTER_MASK 	(BUFFER_SIZE-1)


ACTION_T buffer[BUFFER_SIZE];

BYTE readIdx;			// index of the next to read
BYTE writeIdx;			// index of the next to write
ACTION_T currentAction;

/**
 * Initialise the action queue.
 */
void actionQueueInit() {
	readIdx = 0;
	writeIdx = 0;
	currentAction = NO_ACTION;
}

/**
 * Put the action onto the list of actions to be processed.
 *
 * @param a the action to be processed
 */
BOOL pushAction(ACTION_T a) {
	// do we already have an instruction for the IO ?
	BYTE io = CONSUMER_IO(a);
	// check it this IO was already in the buffer
	for (BYTE i=readIdx; i != writeIdx; i=(i+1)&POINTER_MASK) {
		BYTE thisIo = CONSUMER_IO(buffer[i]);
		if (thisIo == io) {
			// delete this entry
			for (BYTE j=i; j != writeIdx; j=(j+1)&POINTER_MASK) {
				buffer[j] = buffer[(j+1)&POINTER_MASK];
			}
			if (writeIdx == 0) {
				writeIdx = BUFFER_SIZE-1;
			} else {
				writeIdx--;
			}
			i--;
		}
	}
	if (((writeIdx+1)&POINTER_MASK) == readIdx) return FALSE;	// buffer full
	buffer[writeIdx++] = a;
	writeIdx &= POINTER_MASK;
	return TRUE;
}

/**
 * Get the action we need to be progressing.
 *
 * @return the action
 */
ACTION_T getAction() {
	if (currentAction == NO_ACTION) {
		currentAction = pullAction();
	}
	return currentAction;
}

/**
 * Mark as having completed the current action.
 */
void doneAction() {
	currentAction = NO_ACTION;
}

/**
 * Pull the next action from the buffer.
 *
 * @return the next action
 */
ACTION_T pullAction() {
	if (writeIdx == readIdx) return NO_ACTION;	// buffer empty
	ACTION_T ret = buffer[readIdx++];
	readIdx &= POINTER_MASK;
	return ret;
}

