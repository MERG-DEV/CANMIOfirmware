/*

 Copyright (C) Pete Brownlow 2014-2017   software@upsys.co.uk

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

    This software is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE

**************************************************************************************************************
  Note:   This source code has been written using a tab stop and indentation setting
          of 4 characters. To see everything lined up correctly, please set your
          IDE or text editor to the same settings.
******************************************************************************************************
	
	Original by Pete Bronlow
	23/5/2017 Modified by Ian Hogg for CANMIO
*/
#include <xc.h>
#include "canmio.h"
#include "mioNv.h"
#include "mioEvents.h"
#include "../CBUSlib/devincs.h"

#ifndef __XC8__
#pragma romdata PARAMETERS
#endif

#define PRM_CKSUM MANU_ID+MINOR_VER+MODULE_ID+NUM_EVENTS+EVperEVT+NV_NUM+MAJOR_VER+MODULE_FLAGS+CPU+PB_CAN +(LOAD_ADDRESS>>8)+(LOAD_ADDRESS&0xFF)+CPUM_MICROCHIP+BETA+sizeof(ParamVals)+(MNAME_ADDRESS>>8)+(MNAME_ADDRESS&0xFF)


const rom ParamVals     FLiMparams = { 
    MANU_ID,        // manufacturer
    MINOR_VER,      // minor version
    MODULE_ID,      // module id
    NUM_EVENTS,     // number of events
    EVperEVT,       // number of event variable per event
    NV_NUM,         // number of node variables
    MAJOR_VER,      // Major version
    MODULE_FLAGS,   // flags
    CPU,            // Processor Id 
    PB_CAN,         // Interface protocol
    LOAD_ADDRESS,   //  load address
    P18F25K80,      // processor code
    CPUM_MICROCHIP, // manufacturer code
    BETA           // beta release flag
    // rest of parameters are filled in by doRqnpn in FLiM.c
};
const rom SpareParams   spareparams;
const rom FCUParams     FCUparams   = { 
    sizeof(ParamVals),
    (DWORD)module_type,
    (WORD)PRM_CKSUM
};
const rom char          module_type[] = MODULE_TYPE;


// Node and event variables at a fixed place in ROM, starting on a segment boundary
// so they can be written to as required 
#ifdef __C18__
#pragma romdata	flimdata	// Node and event variables
#endif
          
//const rom EventTableEntry  eventTable[EVT_NUM];
#ifdef __C18__
#pragma romdata
#endif

// Static RAM variables 

#ifdef __C18__
#pragma udata MAIN_VARS
rom     ModuleNvDefs    *NV;          // Pointer to node variables structure
#endif

extern BOOL	NV_changed;


#ifdef __C18__
#pragma udata 
#endif

#ifdef __C18__
#pragma code APP
#endif

void mioFlimInit(void) {
    flimInit();
    
}

//void SaveNodeDetails(WORD Node_id, BOOL	FLiMmode)
//
//{
//    ee_write_short(EE_Node_id, Node_id);
//    ee_write(EE_FlimMode, FLiMmode);
//} // SaveNodeDetails








