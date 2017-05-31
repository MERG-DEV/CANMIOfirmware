
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

#include "xc.h"
#include "mioNv.h"
#include "mioEEPROM.h"
#include "../../CBUSlib/events.h"

extern void setType(unsigned char i, unsigned char type);

const NodeVarTable nodeVarTable @AT_NV = {    //  Allow 128 bytes for NVs. Declared const so it gets put into Flash
    0,  // sod delay
    0,  // hb delay
    0,  // cutoff
    0,  // startup1
    0,  // startup2
    0,  // sequential
    5,  // servo speed
    0,0,0,0,0,0,0,0,  // spare
    0,  // io[0].type
    0,0,0,0,0,  // io[0]
    0,  // io[1].type
    0,0,0,0,0,  // io[1]
    0,  // io[2].type
    0,0,0,0,0,  // io[2]
    0,  // io[3].type
    0,0,0,0,0,  // io[3]
    0,  // io[4].type
    0,0,0,0,0,  // io[4]
    0,  // io[5].type
    0,0,0,0,0,  // io[5]
    0,  // io[6].type
    0,0,0,0,0,  // io[6]
    0,  // io[7].type
    0,0,0,0,0,  // io[7]
    0,  // io[8].type
    0,0,0,0,0,  // io[8]
    0,  // io[9].type
    0,0,0,0,0,  // io[9]
    0,  // io[10].type
    0,0,0,0,0,  // io[10]
    0,  // io[11].type
    0,0,0,0,0,  // io[11]
    0,  // io[12].type
    0,0,0,0,0,  // io[12]
    0,  // io[13].type
    0,0,0,0,0,  // io[13]
    0,  // io[14].type
    0,0,0,0,0,  // io[14]
    0,  // io[15].type
    0,0,0,0,0,  // io[15]
};
/*
 Module specific NV routines
 */


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
    if (IS_NV_TYPE(index)) {
        // TODO more settings to be done
        setType(IO_NV(index), value);
    }
}

/**
 * Reset NV for the IO back to default. Flush of the Flash image must be done external to this function.
 * @param i
 */
void defaultNVs(unsigned char i, unsigned char type) {
    // add the module's default nv for this io
    switch(type) {
        case TYPE_INPUT:
            writeFlashImage((BYTE*)(AT_NV+NV_IO_INPUT_ENABLE_OFF(i)), 0);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_INPUT_INVERTED(i)), 0);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_INPUT_ON_DELAY(i)), 0);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_INPUT_OFF_DELAY(i)), 0);
            break;
        case TYPE_OUTPUT:
            writeFlashImage((BYTE*)(AT_NV+NV_IO_OUTPUT_PULSE_DURATION(i)), 0);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_OUTPUT_INVERTED(i)), 0);
            break;
        case TYPE_SERVO:
            writeFlashImage((BYTE*)(AT_NV+NV_IO_SERVO_START_POS(i)), 25);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_SERVO_END_POS(i)), 200);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_SERVO_SE_SPEED(i)), 5);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_SERVO_ES_SPEED(i)), 5);
            break;
        case TYPE_BOUNCE:
            writeFlashImage((BYTE*)(AT_NV+NV_IO_BOUNCE_START_POS(i)), 0);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_BOUNCE_END_POS(i)), 90);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_BOUNCE_PROFILE(i)), 1);
            break;
        case TYPE_MULTI:
            writeFlashImage((BYTE*)(AT_NV+NV_IO_MULTI_NUM_POS(i)), 3);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_MULTI_POS1(i)), 25);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_MULTI_POS2(i)), 110);
            writeFlashImage((BYTE*)(AT_NV+NV_IO_MULTI_POS3(i)), 200);
            break;
    }
}
