/* 
 * File:   mioEEPROM.h
 * Author: Ian
 *
 * Created on 17 April 2017, 16:56
 */

#ifndef MIOEEPROM_H
#define	MIOEEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../../CBUSlib/EEPROM.h"
    /*
     * Any additional EEPROM storage requirements above that required by the CBUS library
     * is defined here. I.e. module specific storage.
     */

    /**
     * Record the current output state for all the IO.
     */
#define EE_OP_STATE         EE_TOP-6    // Space to store current state of up to 16 outputs
    

#ifdef	__cplusplus
}
#endif

#endif	/* MIOEEPROM_H */

