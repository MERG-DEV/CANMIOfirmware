
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
/* File:   canmio.h
 * Author: Ian Hogg
 * 
 * This file contain general definitions for the CANMIO module.
 *
 * Created on 17 April 2017, 14:02
 */

#ifndef CANMIO_H
#define	CANMIO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h> // include processor files - each processor file is guarded.  

#ifdef __XC8__
#define AT_NAME_ADDRESS @0x810
#define AT_PARAM_ADDRESS @0x820
    // XC8 compiler doesn't use rom
#define rom /* NO ROM */
#else
// defined in the linker scripts in the C8 compiler
#endif

/*******************************************************************
 * IO pin configuration
 */
// Number of IO pins
#define NUM_IO 16
// look in mioNv as the IO pin config is stored in NVs
    
/*******************************************************************
 * Module parameters
 */ 
#define MAJOR_VER 	1
#define MINOR_VER 	'a'        // Minor version character
#define BETA        1

#include "GenericTypeDefs.h"
#include "cbusdefs8n.h"

#define MANU_ID         MANU_MERG
#define MODULE_ID       MTYP_CANMIO
#define MODULE_TYPE     "MIO"
#define MODULE_FLAGS    PF_COMBI+PF_BOOT  // Producer, consumer, boot
#define BUS_TYPE        PB_CAN
#define LOAD_ADDRESS    0x0800      // Need to put in parameter block at compile time, only known to linker so hard code here
#define MNAME_ADDRESS   LOAD_ADDRESS + 0x20 + sizeof(ParamBlock)   // Put module type string above params so checksum can be calculated at compile time
#define START_SOD_EVENT      0x81

// Time delays 
#define CBUS_START_DELAY    TWO_SECOND

#ifdef	__cplusplus
}
#endif

#endif	/* CANMIO_H */

