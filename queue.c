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
 * Created on 04 December 2017, 21:45
 *
 * A queue of consumed actions.
 */

#include "module.h"
#include "queue.h"

/**
 * Push an item onto the action queue.
 * @param q
 * @param a
 * @return 
 */
BOOL push(Queue * q, CONSUMER_ACTION_T a) {
    if (((q->writeIdx+1)&((q->size)-1)) == q->readIdx) return FALSE;	// buffer full
    q->queue[q->writeIdx++] = a;
    if (q->writeIdx >= q->size) q->writeIdx = 0;
    return TRUE;
}


/**
 * Pull the next action from the buffer.
 *
 * @return the next action
 */
CONSUMER_ACTION_T pop(Queue * q) {
    CONSUMER_ACTION_T ret;
	if (q->writeIdx == q->readIdx) {
        return NO_ACTION;	// buffer empty
    }
	ret = q->queue[q->readIdx++];
	if (q->readIdx >= q->size) q->readIdx = 0;
	return ret;
}

/**
 * Peek into the buffer.
 *
 * @return the action
 */
CONSUMER_ACTION_T peek(Queue * q, unsigned char index) {
    if (q->readIdx == q->writeIdx) return NO_ACTION;    // empty
    index += q->readIdx;
//    index -= 1;
    if (index >= q->size) {
        index -= q->size;
    }
    if (index == q->writeIdx) return NO_ACTION; // at end
    return q->queue[index];
}


/**
 * Return number of items in the queue.
 */
unsigned char quantity(Queue * q) {
    return (q->writeIdx - q->readIdx) & (q->size -1);
}

/**
 * Delete an item in the queue. Replace the item with NO_ACTION.
 * @param index the item index within the queue
 */
void delete(Queue * q, unsigned char index) {
    if (index >= q->size) return;

    index += q->readIdx;
    //index -= 1;
    if (index >= q->size) {
        index -= q->size;
    }
    q->queue[index] = NO_ACTION;
}