
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
 * File:   digitalOut.c
 * Author: Ian
 * 
 * Handle simple digital outputs. Including pulsed outputs and
 * generate Produced events.
 *
 * Created on 1 June 2017, 13:14
 */

#include "mioNv.h"
#include "mioEvents.h"
#include "FliM.h"
#include "config.h"
#include "GenericTypeDefs.h"
#include "TickTime.h"
#include "romops.h"
#include "mioEEPROM.h"
#include "config.h"

// Forward declarations
unsigned char pulseDelays[NUM_IO];
void setOutputPin(unsigned char io, BOOL state);

// Externs
extern void sendProducedEvent(unsigned char io, BOOL state);
extern Config configs[NUM_IO];
extern __rom const ModuleNvDefs * NV;
/**
 * Initialise the IO digital outputs.
 * Set up the pulse data structures.
 */
void initOutputs() {
    // probably initialised to 0 by the compiler but make sure here
    for (unsigned char io=0; io<NUM_IO; io++) {
       pulseDelays[io] = 0;
    }
}

/**
 * Set a digital output. Handles inverted outputs and pulsed outputs. Sends the
 * produced events.
 * 
 * @param io
 * @param action
 */
void setDigitalOutput(unsigned char io, BOOL state) {
    if (NV->io[io].flags & FLAG_INVERTED) {
        state = state ? 0:1;
    }
    setOutputPin(io, state);
    ee_write(EE_OP_STATE-io, state);
    sendProducedEvent(ACTION_IO_PRODUCER_OUTPUT(io), state);
    // Was this a ON and we have a pulse duration defined?
    if (state && NV->io[io].nv_io.nv_output.output_pulse_duration) {
        pulseDelays[io] = NV->io[io].nv_io.nv_output.output_pulse_duration;
    }
}

void processOutputs() {
    unsigned char state;
    for (unsigned char io=0; io<NUM_IO; io++) {
        if (pulseDelays[io] == 1) {
            // time to go off
            state = ee_read(EE_OP_STATE-io);
            state = state?0:1;
            setOutputPin(io, state);
            ee_write(EE_OP_STATE-io, state);
            sendProducedEvent(ACTION_IO_PRODUCER_OUTPUT(io), state);
        }
        if (pulseDelays[io] != 0) {
            pulseDelays[io]--;
        }
    }
}


/**
 * Set a particular output pin to the given state.
 * @param io
 * @param state
 */
void setOutputPin(unsigned char io, BOOL state) {
    switch (configs[io].port) {
        case 'A':
            if (state) {
                // set it
               LATA |= (1<<configs[io].no);
            } else {
                // clear it
                LATA &= ~(1<<configs[io].no);
            }
            break;
        case 'B':
            if (state) {
                // set it
                LATB |= (1<<configs[io].no);
            } else {
                // clear it
                LATB &= ~(1<<configs[io].no);
            }
            break;
        case 'C':
            if (state) {
                // set it
                LATC |= (1<<configs[io].no);
            } else {
                // clear it
                LATC &= ~(1<<configs[io].no);
            }
            break;
    }
}

