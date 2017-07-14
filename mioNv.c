
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
 * File:   nodeVariables.c
 * Author: Ian Hogg
 *
 * Created on 05 March 2016, 18:14
 */

/**
 * Node variables contain global parameters that need to be persisted to Flash.
 */

#include "devincs.h"
#include "module.h"
#include "mioNv.h"
#include "mioEEPROM.h"
#include "events.h"
#include "romops.h"
#include "FliM.h"
#ifdef NV_CACHE
#include "nvCache.h"
#endif
#include "servo.h"

extern void setType(unsigned char i, unsigned char type);
#ifdef __XC8
const ModuleNvDefs moduleNvDefs @AT_NV; // = {    //  Allow 128 bytes for NVs. Declared const so it gets put into Flash
#else
#pragma romdata myNV=AT_NV
    rom NodeVarTable nodeVarTable; /* = {
        {    
#endif
            0,  // NV data version 
            0,  // sod delay    - delay in sending SOD or zero = no sod
            0,  // hb delay     - heartbeat delay
            5,  // servo speed  - default servo speed
            {0,0,0,0,0,0,0,0,0,0,0,0},  // spare
            {
                { // io[0]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[1]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[2]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[3]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[4]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[5]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[6]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[7]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[8]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[9]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[10]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[11]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[12]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[13]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[14]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                },{ // io[15]
                    0,  // io[0].type
                    0,  // io[0].flags
                    1,  // enable off
                    1,  // on_delay
                    1   // off_delay
                }
            }
        }
    }; */
/*
 Module specific NV routines
 */
#ifdef __XC8
const NodeVarTable nodeVarTable @AT_NV;
ModuleNvDefs * NV = (ModuleNvDefs*)&(moduleNvDefs);    // pointer to the NV structure
#else
#ifdef NV_CACHE
ModuleNvDefs * NV; // = &(nodeVarTable.moduleNVs);
#else
volatile rom near ModuleNvDefs * NV = (volatile rom near ModuleNvDefs*)&(nodeVarTable.moduleNVs);    // pointer to the NV structure
#endif
#endif

void mioNvInit() {
#ifdef NV_CACHE
    NV = loadNvCache(); // replace pointer with the cache
#endif
}

/**
 * Validate value of NV based upon bounds and inter-dependencies.
 * @return TRUE is a valid change
 */
BOOL validateNV(unsigned char index, unsigned char oldValue, unsigned char value) {
    // TODO more validations
    if (IS_NV_TYPE(index)) {
        if (value > TYPE_MULTI) return FALSE;
    }
    return TRUE;
} 

void actUponNVchange(unsigned char index, unsigned char value) {
    // If the IO type is changed then we need to do a bit or work
    if (IS_NV_TYPE(index)) {
        setType(IO_NV(index), value);
    }
    // if a servo position is changed then move servo to that position
    if (index >= NV_IO_START) {
        unsigned char io = IO_NV(index);
        unsigned char nv = NV_NV(index);
        switch(NV_IO_TYPE(io)) {
            case TYPE_SERVO:
                if (index == NV_IO_SERVO_START_POS(io)) {
                    setServoOutput(io, ACTION_IO_CONSUMER_3);
                } else if (index == NV_IO_SERVO_END_POS(io)) {
                    setServoOutput(io, ACTION_IO_CONSUMER_2);
                }
                break;
            case TYPE_BOUNCE:
                if (index == NV_IO_BOUNCE_LOWER_POS(io)) {
                    setBounceOutput(io, ACTION_IO_CONSUMER_3);
                } else if (index == NV_IO_BOUNCE_UPPER_POS(io)) {
                    setBounceOutput(io, ACTION_IO_CONSUMER_2);
                }
                break;
            case TYPE_MULTI:
                if (index == NV_IO_MULTI_POS1(io)) {
                    setMultiOutput(io, ACTION_IO_CONSUMER_1);
                } else if (index == NV_IO_MULTI_POS2(io)) {
                    setMultiOutput(io, ACTION_IO_CONSUMER_2);
                } else if (index == NV_IO_MULTI_POS3(io)) {
                    setMultiOutput(io, ACTION_IO_CONSUMER_3);
                } else if (index == NV_IO_MULTI_POS4(io)) {
                    setMultiOutput(io, ACTION_IO_CONSUMER_4);
                }
        }
    }
}

/**
 * Set NVs back to factory defaults.
 */
void factoryResetGlobalNv(void) {
    writeFlashByte((BYTE*)(AT_NV + NV_VERSION), (BYTE)FLASH_VERSION);
    writeFlashByte((BYTE*)(AT_NV + NV_SOD_DELAY), (BYTE)0);
    writeFlashByte((BYTE*)(AT_NV + NV_HB_DELAY), (BYTE)0);
    writeFlashByte((BYTE*)(AT_NV + NV_SERVO_SPEED), (BYTE)5);
#ifdef NV_CACHE
    loadNvCache();
#endif
}

/**
 * Reset NV for the IO back to default. Flush of the Flash image must be done external to this function.
 * @param i
 */
void defaultNVs(unsigned char i, unsigned char type) {
    // add the module's default nv for this io
    switch(type) {
        case TYPE_INPUT:
            writeFlashByte((BYTE*)(AT_NV+NV_IO_FLAGS(i)), (BYTE)0);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_INPUT_ON_DELAY(i)), (BYTE)4);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_INPUT_OFF_DELAY(i)), (BYTE)4);
            break;
        case TYPE_OUTPUT:
            writeFlashByte((BYTE*)(AT_NV+NV_IO_FLAGS(i)), (BYTE)0);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_OUTPUT_PULSE_DURATION(i)), (BYTE)0);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_OUTPUT_FLASH_PERIOD(i)), (BYTE)0);
            break;
        case TYPE_SERVO:
            writeFlashByte((BYTE*)(AT_NV+NV_IO_FLAGS(i)), (BYTE)(FLAG_CUTOFF));
#ifdef TEST_DEFAULT_NVS
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_START_POS(i)), (BYTE)25);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_END_POS(i)), (BYTE)200);
#else
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_START_POS(i)), (BYTE)128);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_END_POS(i)), (BYTE)128);
#endif
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_SE_SPEED(i)), (BYTE)5);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_ES_SPEED(i)), (BYTE)5);
            break;
        case TYPE_BOUNCE:
            writeFlashByte((BYTE*)(AT_NV+NV_IO_FLAGS(i)), (BYTE)(FLAG_CUTOFF));
#ifdef TEST_DEFAULT_NVS
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_UPPER_POS(i)), (BYTE)200);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_LOWER_POS(i)), (BYTE)30);
#else
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_UPPER_POS(i)), (BYTE)128);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_LOWER_POS(i)), (BYTE)127);
#endif
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_G(i)), (BYTE)3);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_COEFF(i)), (BYTE)50);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_PROFILE(i)), (BYTE)1);
            break;
        case TYPE_MULTI:
            writeFlashByte((BYTE*)(AT_NV+NV_IO_FLAGS(i)), (BYTE)(FLAG_CUTOFF));
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MULTI_NUM_POS(i)), (BYTE)3);
#ifdef TEST_DEFAULT_NVS
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MULTI_POS1(i)), (BYTE)25);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MULTI_POS2(i)), (BYTE)110);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MULTI_POS3(i)), (BYTE)200);
#else
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MULTI_POS1(i)), (BYTE)128);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MULTI_POS2(i)), (BYTE)128);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MULTI_POS3(i)), (BYTE)128);
#endif
            break;
    }
#ifdef NV_CACHE
    loadNvCache();
#endif
}
