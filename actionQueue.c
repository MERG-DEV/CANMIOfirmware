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
 * Implemented as two separated queues - a normal and an expedited priority queue.
 */

#include "GenericTypeDefs.h"
#include "mioEvents.h"
#include "actionQueue.h"
#include "queue.h"

// Forward declarations
CONSUMER_ACTION_T pullAction(void);

#define NORMAL_POINTER_MASK 	(ACTION_NORMAL_QUEUE_SIZE-1)
BYTE normalReadIdx;                   // index of the next to read
BYTE normalWriteIdx;                  // index of the next to write
CONSUMER_ACTION_T normalQueueBuf[ACTION_NORMAL_QUEUE_SIZE];   // the actual cyclic buffer space
Queue normalQueue;

#define EXPEDITED_POINTER_MASK 	(ACTION_EXPEDITED_QUEUE_SIZE-1)
BYTE expeditedReadIdx;                   // index of the next to read
BYTE expeditedWriteIdx;                  // index of the next to write
CONSUMER_ACTION_T expeditedQueueBuf[ACTION_EXPEDITED_QUEUE_SIZE];   // the actual cyclic buffer space

Queue expeditedQueue;

static BOOL expedited;

/**
 * Initialise the action queue.
 */
void actionQueueInit(void) {
    normalQueue.size = ACTION_NORMAL_QUEUE_SIZE;
	normalQueue.readIdx = 0;
	normalQueue.writeIdx = 0;
    normalQueue.queue = normalQueueBuf;
    
    expeditedQueue.size = ACTION_EXPEDITED_QUEUE_SIZE;
    expeditedQueue.readIdx = 0;
	expeditedQueue.writeIdx = 0;
    expeditedQueue.queue = expeditedQueueBuf;
    
    expedited = FALSE;
}

/**
 * Put the action onto the list of actions to be processed.
 *
 * @param a the action to be processed
 */
BOOL pushAction(CONSUMER_ACTION_T a) {
    if (expedited) {
        return push(&expeditedQueue, a);
    }
    return push(&normalQueue, a);
}



/**
 * Get the action we need to be progressing.
 *
 * @return the action
 */
CONSUMER_ACTION_T getAction(void) {
	return peekActionQueue(0);
}

/**
 * Pull the next action from the buffer.
 *
 * @return the next action
 */
CONSUMER_ACTION_T popAction(void) {
    CONSUMER_ACTION_T ret;
    ret = pop(&expeditedQueue);
    if (ret != NO_ACTION) return ret;
    ret = pop(&normalQueue);
    return ret;
}



/**
 * Mark as having completed the current action.
 */
void doneAction(void) {
	popAction();
}


/**
 * Peek an item in the queue. Does not remove the item from the queue.
 * @param index the item index within the queue
 * @return the Action or NO_ACTION 
 */
CONSUMER_ACTION_T peekActionQueue(unsigned char index) {
    if (index < quantity(&expeditedQueue)) {
        return peek(&expeditedQueue, index);
    }
    index -= quantity(&expeditedQueue);
    if (index < quantity(&normalQueue)) {
        return peek(&normalQueue, index);
    }
    return NO_ACTION;
}


/**
 * Delete an item in the queue. Replace the item with NO_ACTION.
 * @param index the item index within the queue
 */
void deleteActionQueue(unsigned char index) {
    if (index <= quantity(&expeditedQueue)) {
        delete(&expeditedQueue, index);
    } else {
        index -= quantity(&expeditedQueue);
        delete(&normalQueue, index);
    }
}

/**
 * Set the expedited flag so that subsequent pushes are added to the front of the queue.
 */
void setExpeditedActions(void) {
    expedited = TRUE;
}

/**
 * Clear the expedited flag so that subsequent pushes are added to the end of the queue.
 */
void setNormalActions(void) {
    expedited = FALSE;
}