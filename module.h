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
    
    
/*
 * BOOTLOADER
 */
#define BOOTLOADER_PRESENT


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

