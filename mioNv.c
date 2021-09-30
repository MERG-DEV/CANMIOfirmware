
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
#include "config.h"
#include "cbus.h"
#include "analogue.h"

extern void setType(unsigned char i, unsigned char type);
#ifdef __XC8
const ModuleNvDefs moduleNvDefs @AT_NV; // = {    //  Allow 128 bytes for NVs. Declared const so it gets put into Flash
#else
//#pragma romdata myNV=AT_NV
#endif
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

void mioNvInit(void) {

}

/**
 * Validate value of NV based upon bounds and inter-dependencies.
 * @return TRUE is a valid change
 */
BOOL validateNV(unsigned char index, unsigned char oldValue, unsigned char value) {
    // TODO more validations
    unsigned char io;
    if ((index >= NV_IO_START) && IS_NV_TYPE(index)) {
        switch (value) {
#ifdef ANALOGUE
            case TYPE_ANALOGUE_IN:
            case TYPE_MAGNET:
                io = IO_NV(index);
                if (configs[io].an == 0xFF) return FALSE;
                break;
#endif
#ifdef MULTI
            case TYPE_MULTI:
                break;
#endif
#ifdef BOUNCE
            case TYPE_BOUNCE:
                break;
#endif
#ifdef SERVO
            case TYPE_SERVO:
                break;
#endif
            case TYPE_OUTPUT:
            case TYPE_INPUT:
                break;
            default:
                return FALSE;
        }
    }
    return TRUE;
} 

void actUponNVchange(unsigned char index, unsigned char oldValue, unsigned char value) {
    // If the IO type is changed then we need to do a bit or work
    unsigned char io;
    unsigned char nv;
    if (IS_NV_TYPE(index)) {
        io = index-NV_IO_START;
        io /= NVS_PER_IO;
        if (oldValue != value) {
            setType(io, value);
        }
    }
    if (index == NV_PULLUPS) {
        WPUB = value; 
    }
    
    if (index >= NV_IO_START) {
        io = IO_NV(index);
        nv = NV_NV(index);
        switch(NV->io[io].type) {
#ifdef ANALOGUE
            case TYPE_MAGNET:
                // if MAGNET setup is written then do the adc and save the result as the offset
                if (index == NV_IO_MAGNET_SETUP(io)) {
                    //setup variables so that the analogue poll will do the correct thing
                    setupIo = io;
                    setupState = (value & 0x80)?SETUP_REPORT_AND_SAVE:SETUP_REPORT;
                }
                break;
#endif
#ifdef SERVO
            case TYPE_SERVO:
                // if a servo position is changed then move servo to that position
                if (index == NV_IO_SERVO_START_POS(io)) {
                    setServoState(io, ACTION_IO_3);
                    startServoOutput(io, ACTION_IO_3);
                } else if (index == NV_IO_SERVO_END_POS(io)) {
                    setServoState(io, ACTION_IO_2);
                    startServoOutput(io, ACTION_IO_2);
                }
                break;
#endif
#ifdef BOUNCE
            case TYPE_BOUNCE:
                if (index == NV_IO_BOUNCE_LOWER_POS(io)) {
                    setBounceState(io, ACTION_IO_3);
                    startBounceOutput(io, ACTION_IO_3);
                } else if (index == NV_IO_BOUNCE_UPPER_POS(io)) {
                    setBounceState(io, ACTION_IO_2);
                    startBounceOutput(io, ACTION_IO_2);
                }
                break;
#endif
#ifdef MULTI
            case TYPE_MULTI:
                if (index == NV_IO_MULTI_POS1(io)) {
                    setMultiState(io, ACTION_IO_1);
                    startMultiOutput(io, ACTION_IO_1);
                } else if (index == NV_IO_MULTI_POS2(io)) {
                    setMultiState(io, ACTION_IO_2);
                    startMultiOutput(io, ACTION_IO_2);
                } else if (index == NV_IO_MULTI_POS3(io)) {
                    setMultiState(io, ACTION_IO_3);
                    startMultiOutput(io, ACTION_IO_3);
                } else if (index == NV_IO_MULTI_POS4(io)) {
                    setMultiState(io, ACTION_IO_4);
                    startMultiOutput(io, ACTION_IO_4);
                }
                break;
#endif
        }
    }
}


/**
 * Set NVs back to factory defaults.
 */
void factoryResetGlobalNv(void) {
    writeFlashByte((BYTE*)(AT_NV + NV_SOD_DELAY), (BYTE)0);
    writeFlashByte((BYTE*)(AT_NV + NV_HB_DELAY), (BYTE)0);
    writeFlashByte((BYTE*)(AT_NV + NV_SERVO_SPEED), (BYTE)PIVOT);
    writeFlashByte((BYTE*)(AT_NV + NV_PULLUPS), (BYTE)0x33);
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
    writeFlashByte((BYTE*)(AT_NV+NV_IO_FLAGS(i)), (BYTE)(FLAG_CUTOFF | FLAG_STARTUP));
    switch(type) {
        case TYPE_INPUT:
            writeFlashByte((BYTE*)(AT_NV+NV_IO_INPUT_ON_DELAY(i)), (BYTE)4);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_INPUT_OFF_DELAY(i)), (BYTE)4);
            break;
        case TYPE_OUTPUT:
            writeFlashByte((BYTE*)(AT_NV+NV_IO_OUTPUT_PULSE_DURATION(i)), (BYTE)0);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_OUTPUT_FLASH_PERIOD(i)), (BYTE)0);
            break;
#ifdef SERVO
        case TYPE_SERVO:
#ifdef TEST_DEFAULT_NVS
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_START_POS(i)), (BYTE)25);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_END_POS(i)), (BYTE)200);
#else
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_START_POS(i)), (BYTE)128);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_END_POS(i)), (BYTE)128);
#endif
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_SE_SPEED(i)), (BYTE)PIVOT+1);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_SERVO_ES_SPEED(i)), (BYTE)PIVOT+1);
            break;
#endif
#ifdef BOUNCE
        case TYPE_BOUNCE:
#ifdef TEST_DEFAULT_NVS
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_UPPER_POS(i)), (BYTE)200);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_LOWER_POS(i)), (BYTE)30);
#else
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_UPPER_POS(i)), (BYTE)128);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_LOWER_POS(i)), (BYTE)127);
#endif
            writeFlashByte((BYTE*)(AT_NV+NV_IO_BOUNCE_COEFF(i)), (BYTE)64);
            writeFlashByte((BYTE*)(AT_NV + NV_IO_BOUNCE_PULL_SPEED(i)), (BYTE)3);
            writeFlashByte((BYTE*)(AT_NV + NV_IO_BOUNCE_PULL_PAUSE(i)), (BYTE)60);
            break;
#endif
#ifdef MULTI      
        case TYPE_MULTI:
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
#endif
#ifdef ANALOGUE
        case TYPE_ANALOGUE_IN:  // use 8 bit ADC
            writeFlashByte((BYTE*)(AT_NV+NV_IO_ANALOGUE_THRES(i)), (BYTE)0x80);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_ANALOGUE_HYST(i)), (BYTE)0x10);
            break;
        case TYPE_MAGNET:   // use 12 bit ADC
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MAGNET_SETUP(i)), (BYTE)0);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MAGNET_THRES(i)), (BYTE)123);    // 150mV
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MAGNET_HYST(i)), (BYTE)32);      // 39mV
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MAGNET_OFFSETH(i)), (BYTE)0x07);
            writeFlashByte((BYTE*)(AT_NV+NV_IO_MAGNET_OFFSETL(i)), (BYTE)0xFF);
            break;
#endif
    }
#ifdef NV_CACHE
    loadNvCache();
#endif
}
