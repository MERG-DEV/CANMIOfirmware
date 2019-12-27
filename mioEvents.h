
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
 * File:   mioEvents.h
 * Author: Ian
 *
 * Created on 17 April 2017, 13:14
 */

#ifndef MIOEVENTS_H
#define	MIOEVENTS_H

#ifdef	__cplusplus
extern "C" {
#endif
    /*
     * This is where all the module specific actions are defined.
     * The following definitions are required by the FLiM code:
     * NUM_PRODUCER_ACTIONS, NUM_CONSUMER_ACTIONS, HASH_LENGTH, EVT_NUM, 
     * EVperEVT, NUM_CONSUMED_EVENTS
     * 
     * For MIO an action is a BYTE (unsigned char). The upperupper bit is used
     * to indicate a sequential action. It would be nice to define:
     * 
     * typedef union {
     *      unsigned char action_byte;
     *      struct {
     *          unsigned char action :7;
     *          unsigned char sequential :1;
     *      }
     * } ACtION_T;
     * but C spec doesn't define what size this would be. Therefore I just use
     * BYTE (unsigned char).
     * 
     * The actions are defined below - but remember consumed actions may also have MSB
     * set indicating sequential.
     */
 
#include "canmio.h"

/* CONSUMED actions */
#define ACTION_SIMULTANEOUS                 0x80    // default is SEQUENTIAL
#define ACTION_MASK                         0x7F
    
    // Global consumed actions first
#define ACTION_CONSUMER_SOD                 1
#define ACTION_CONSUMER_WAIT05              2
#define ACTION_CONSUMER_WAIT1               3
#define ACTION_CONSUMER_WAIT2               4
#define ACTION_CONSUMER_WAIT5               5

        // Now Consumed actions per io
/* VERSION 1*/
#define V1_ACTION_CONSUMER_IO_BASE             8
#define V1_ACTION_IO_CONSUMER_1                0
#define V1_ACTION_IO_CONSUMER_2                1
#define V1_ACTION_IO_CONSUMER_3                2
#define V1_ACTION_IO_CONSUMER_4                3
#define V1_CONSUMER_ACTIONS_PER_IO             4   
#define V1_NUM_CONSUMER_ACTIONS                (V1_ACTION_CONSUMER_IO_BASE + NUM_IO * V1_CONSUMER_ACTIONS_PER_IO)
    
/* Version 2*/
#define ACTION_CONSUMER_IO_BASE             8
#define ACTION_IO_CONSUMER_1                0
#define ACTION_IO_CONSUMER_2                1
#define ACTION_IO_CONSUMER_3                2
#define ACTION_IO_CONSUMER_4                3
#define ACTION_IO_CONSUMER_5                4
#define CONSUMER_ACTIONS_PER_IO             5   
#define NUM_CONSUMER_ACTIONS                (ACTION_CONSUMER_IO_BASE + NUM_IO * CONSUMER_ACTIONS_PER_IO)   
    
/* PRODUCED actions */    
#define ACTION_PRODUCER_BASE                0
    // Global produced actions next
#define ACTION_PRODUCER_SOD                 1
    // produced actions per io
#define ACTION_PRODUCER_IO_BASE             8
#define ACTION_IO_PRODUCER_1                0
#define ACTION_IO_PRODUCER_2                1
#define ACTION_IO_PRODUCER_3                2
#define ACTION_IO_PRODUCER_4                3
#define PRODUCER_ACTIONS_PER_IO             4
#define NUM_PRODUCER_ACTIONS                (ACTION_PRODUCER_IO_BASE + NUM_IO * PRODUCER_ACTIONS_PER_IO)
    

#define ACTION_IO_PRODUCER_BASE(i)          (ACTION_PRODUCER_IO_BASE + PRODUCER_ACTIONS_PER_IO*(i))
#define V1_ACTION_IO_CONSUMER_BASE(i)       (V1_ACTION_CONSUMER_IO_BASE + V1_CONSUMER_ACTIONS_PER_IO*(i))
#define ACTION_IO_CONSUMER_BASE(i)          (ACTION_CONSUMER_IO_BASE + CONSUMER_ACTIONS_PER_IO*(i))
    
/* PRODUCED actions*/
#define ACTION_IO_PRODUCER_INPUT(i)         (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_1)
#define ACTION_IO_PRODUCER_INPUT_TWO_ON(i)  (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_2)
    
#define ACTION_IO_PRODUCER_OUTPUT(i)        (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_1)

#define ACTION_IO_PRODUCER_SERVO_START(i)   (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_1)
#define ACTION_IO_PRODUCER_SERVO_MID(i)     (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_2)
#define ACTION_IO_PRODUCER_SERVO_END(i)     (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_3)

#define ACTION_IO_PRODUCER_BOUNCE(i)        (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_1)
    
#define ACTION_IO_PRODUCER_MULTI_AT1(i)     (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_1)
#define ACTION_IO_PRODUCER_MULTI_AT2(i)     (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_2)
#define ACTION_IO_PRODUCER_MULTI_AT3(i)     (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_3)
#define ACTION_IO_PRODUCER_MULTI_AT4(i)     (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_4)
    
#define ACTION_IO_PRODUCER_ANALOGUE(i)      (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_1)

#define ACTION_IO_PRODUCER_MAGNETL(i)       (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_1)
#define ACTION_IO_PRODUCER_MAGNETH(i)       (ACTION_IO_PRODUCER_BASE(i)+ACTION_IO_PRODUCER_2)
 
#define PRODUCER_ACTION(a)                  (((a)-ACTION_PRODUCER_IO_BASE)%PRODUCER_ACTIONS_PER_IO)
#define PRODUCER_IO(a)                      (((a)-ACTION_PRODUCER_IO_BASE)/PRODUCER_ACTIONS_PER_IO)
    
/* CONSUMED actions*/
#define ACTION_IO_CONSUMER_OUTPUT_EV(i)     (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_1)
#define ACTION_IO_CONSUMER_OUTPUT_ON(i)     (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_2)
#define ACTION_IO_CONSUMER_OUTPUT_OFF(i)    (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_3)
#define ACTION_IO_CONSUMER_OUTPUT_FLASH(i)  (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_4)
#define ACTION_IO_CONSUMER_OUTPUT_NOT_EV(i) (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_5)

#define ACTION_IO_CONSUMER_SERVO_EV(i)      (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_1)
#define ACTION_IO_CONSUMER_SERVO_ON(i)      (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_2)
#define ACTION_IO_CONSUMER_SERVO_OFF(i)     (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_3)


#define ACTION_IO_CONSUMER_BOUNCE_EV(i)     (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_PRODUCER_1)
#define ACTION_IO_CONSUMER_BOUNCE_ON(i)     (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_2)
#define ACTION_IO_CONSUMER_BOUNCE_OFF(i)    (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_3)


#define ACTION_IO_CONSUMER_MULTI_TO1(i)     (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_1)
#define ACTION_IO_CONSUMER_MULTI_TO2(i)     (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_2)
#define ACTION_IO_CONSUMER_MULTI_TO3(i)     (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_3)
#define ACTION_IO_CONSUMER_MULTI_TO4(i)     (ACTION_IO_CONSUMER_BASE(i)+ACTION_IO_CONSUMER_4)
    
#define V1_CONSUMER_ACTION(a)               (((a)-V1_ACTION_CONSUMER_IO_BASE)%V1_CONSUMER_ACTIONS_PER_IO)
#define V1_CONSUMER_IO(a)                   (((a)-V1_ACTION_CONSUMER_IO_BASE)/V1_CONSUMER_ACTIONS_PER_IO)
#define CONSUMER_ACTION(a)                  (((a)-ACTION_CONSUMER_IO_BASE)%CONSUMER_ACTIONS_PER_IO)
#define CONSUMER_IO(a)                      (((a)-ACTION_CONSUMER_IO_BASE)/CONSUMER_ACTIONS_PER_IO)

extern void mioEventsInit(void);
extern void factoryResetGlobalEvents(void);
extern void defaultEvents(unsigned char i, unsigned char type);
extern void clearEvents(unsigned char i);

// These are chosen so we don't use too much memory 32*20 = 640 bytes.
// Used to size the hash table used to lookup events in the events2actions table.
#define HASH_LENGTH     32
#define CHAIN_LENGTH    20

#define NUM_EVENTS              255         // must be less than 256 otherwise loops fail
#define EVENT_TABLE_WIDTH       10          // Width of eventTable
#define EVperEVT                20          // Max number of EVs per event
#ifdef __18F25K80
#define AT_EVENTS               0x6F80      //(AT_NV - sizeof(EventTable)*NUM_EVENTS) Size=256 * 22 = 5632(0x1600) bytes
#endif
#ifdef __18F26K80
#define AT_EVENTS               0xEF80      //(AT_NV - sizeof(EventTable)*NUM_EVENTS) Size=256 * 22 = 5632(0x1600) bytes
#endif

// We'll also be using configurable produced events
#define PRODUCED_EVENTS
#define ConsumedActionType  BYTE;

extern void processEvent(BYTE eventIndex, BYTE* message);
extern void processActions(void);

#include "events.h"

extern BOOL sendInvertedProducedEvent(PRODUCER_ACTION_T action, BOOL state, BOOL invert);

#ifdef	__cplusplus
}
#endif

#endif	/* MIOEVENTS_H */

