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
CONSUMER_ACTION_T pullAction(void);

#define POINTER_MASK 	(ACTION_QUEUE_SIZE-1)


CONSUMER_ACTION_T buffer[ACTION_QUEUE_SIZE];   // the actual cyclic buffer space

BYTE readIdx;                   // index of the next to read
BYTE writeIdx;                  // index of the next to write
CONSUMER_ACTION_T currentAction;

/**
 * Initialise the action queue.
 */
void actionQueueInit(void) {
	readIdx = 0;
	writeIdx = 0;
	currentAction = NO_ACTION;
}

/**
 * Put the action onto the list of actions to be processed.
 *
 * @param a the action to be processed
 */
BOOL pushAction(CONSUMER_ACTION_T a) {
/*	// do we already have an instruction for the IO ?
	BYTE io = CONSUMER_IO(a);
	// check it this IO was already in the buffer
    BYTE i;
	for (i=readIdx; i != writeIdx; i=(i+1)&POINTER_MASK) {
		BYTE thisIo = CONSUMER_IO(buffer[i]);
		if (thisIo == io) {
			// delete this entry
            BYTE j;
			for (j=i; j != writeIdx; j=(j+1)&POINTER_MASK) {
				buffer[j] = buffer[(j+1)&POINTER_MASK];
			}
			if (writeIdx == 0) {
				writeIdx = ACTION_QUEUE_SIZE-1;
			} else {
				writeIdx--;
			}
			i--;
		}
	} */
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
CONSUMER_ACTION_T getAction(void) {
	if (currentAction == NO_ACTION) {
		currentAction = pullAction();
	}
	return currentAction;
}

/**
 * Mark as having completed the current action.
 */
void doneAction(void) {
	currentAction = NO_ACTION;
}

/**
 * Pull the next action from the buffer.
 *
 * @return the next action
 */
CONSUMER_ACTION_T pullAction(void) {
    CONSUMER_ACTION_T ret;
	if (writeIdx == readIdx) {
        return NO_ACTION;	// buffer empty
    }
	ret = buffer[readIdx++];
	readIdx &= POINTER_MASK;
	return ret;
}

/**
 * Peek an item in the queue. Does not remove the item from the queue.
 * @param index the item index within the queue
 * @return the Action or NO_ACTION 
 */
CONSUMER_ACTION_T peekActionQueue(unsigned char index) {
    if (currentAction == NO_ACTION) return NO_ACTION;
    if (index > ACTION_QUEUE_SIZE) return NO_ACTION;
    if (index == 0) return currentAction;
    index += readIdx;
    index -= 1;
    if (index > ACTION_QUEUE_SIZE) {
        index -= ACTION_QUEUE_SIZE;
    }
    return buffer[index];
}

/**
 * Delete an item in the queue. Replace the item with NO_ACTION.
 * @param index the item index within the queue
 */
void deleteActionQueue(unsigned char index) {
    if (index > ACTION_QUEUE_SIZE) return;
    if (index == 0) {
        currentAction = NO_ACTION;
        return;
    }
    index += readIdx;
    index -= 1;
    if (index > ACTION_QUEUE_SIZE) {
        index -= ACTION_QUEUE_SIZE;
    }
    buffer[index] = NO_ACTION;
}

