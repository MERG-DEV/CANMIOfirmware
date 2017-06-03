
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
 * File:   module.h
 * Author: Ian
 *
 * The CBUS library files include this module specific header. 
 * This is the means to isolate dependencies between the library and the module
 * specific code. All the dependencies of the library on the module specific code
 * should be defined in this file.
 * 
 * In particular EEPROM, NV and Event definitions should be here or included from here.
 *  
 * Created on 15 April 2017, 21:33
 */

#ifndef MODULE_H
#define	MODULE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
/*********************** MODULE OPTIONS **************************/
// BOOTLOADER
#define BOOTLOADER_PRESENT

    // We'll be using event hash tables for fast access - at the expense of some RAM
#define HASH_TABLE

    // enable servos
//#define SERVO

    // Don't enable MULTI for now
//#define MULTI

    // Don't enable BOUNCE for now
//#define BOUNCE

    // Whether NVs are cached in RAM
#define NV_CACHE
/************************* END OF OPTIONS ************************/
    
 /*
 * NVs
 */
#include "mioNv.h"
#include "mioEEPROM.h"
    
/*
 * EVENTS
 */
#include "mioEvents.h"

#include "canmio.h"

#ifdef	__cplusplus
}
#endif

#endif	/* MODULE_H */

