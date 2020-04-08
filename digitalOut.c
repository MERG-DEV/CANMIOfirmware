
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
#include "actionQueue.h"

// Forward declarations
unsigned char pulseDelays[NUM_IO];
char flashDelays[NUM_IO];
void setOutputPin(unsigned char io, BOOL state);

// Externs

/* 
 * Dimming only takes place when the output is 'ON', this will be LOW if ACTION_INVERTED is set
 * The output is ON under the following conditions:
 *  o last action (after TRIGGER_INVERT) was ON and output_pulse_duration == 0
 *  o last action (after TRIGGER_INVERT) was ON and output_pulse_duration > 0 and pulseDelay > 0
 *  o last action was FLASH and output_flash_period > 0 and flashDelay > 0
 * If any of the above are true then the output needs to be dimmed.
 * every 5ms increment dimCounter
 * if dimCounter < dim_setting turn pin ON else turn pin OFF
 * if (dimCount >= 20) dimCount = 0
 * 
/**
 * Initialise the IO digital outputs.
 * Set up the pulse data structures.
 */
void initOutputs(void) {
    // probably initialised to 0 by the compiler but make sure here
    unsigned char io;
    for (io=0; io<NUM_IO; io++) {
       pulseDelays[io] = 0;
       flashDelays[io] = 0;
    }
}
/**
 * Start a digital output. Handles inverted outputs and pulsed outputs. Sends the
 * produced events.
 * Handles:
 * * Onput event invert
 * * Output OFF event disable
 * * Output event invert
 * * Flash
 * * Pulse
 * 
 * @param io
 * @param action
 */
void startDigitalOutput(unsigned char io, unsigned char state) {
    BOOL pinState;
    // State ACTION_IO_1 is Change. This is not used here and state will have been changed to on or off
    // State ACTION_IO_2 is ON
    // State ACTION_IO_3 is OFF
    // State ACTION_IO_4 is Flash
    // State ACTION_IO_5 is Change inverted. This is not used here and state will have been changed to on or off
    if (state == ACTION_IO_4) {
        flashDelays[io] = NV->io[io].nv_io.nv_output.output_flash_period;
        pulseDelays[io] = 0;
        setOutputPin(io, TRUE);
        ee_write(EE_OP_STATE+io, state);	// save the current state of output
        sendInvertedProducedEvent(HAPPENING_IO_INPUT(io), TRUE, NV->io[io].flags & FLAG_RESULT_EVENT_INVERTED);
        return;
    }
    // state is either ACTION_IO_2(on) or )ACTION_IO_3(off))
    // Check if the input event is inverted
    pinState = (state == ACTION_IO_2);
    if (NV->io[io].flags & FLAG_TRIGGER_INVERTED) {
        pinState = pinState?0:1;
    }
    flashDelays[io] = 0;	// turn flash off
    // Was this a ON and we have a pulse duration defined?
    if ((pinState) && NV->io[io].nv_io.nv_output.output_pulse_duration) {
        if (pulseDelays[io] == 0) {
            pulseDelays[io] = NV->io[io].nv_io.nv_output.output_pulse_duration;
            ee_write(EE_OP_STATE+io, ACTION_IO_3);	// save the current state of output as OFF so 
                                                            // we don't power up with ON outputs
        }
    } else {
        ee_write(EE_OP_STATE+io, state);	// save the current state of output
    }    
    if (NV->io[io].flags & FLAG_RESULT_ACTION_INVERTED) {
        setOutputPin(io, ! pinState);
    } else {
        setOutputPin(io, pinState);
    }
    // check if OFF events are enabled
    if (NV->io[io].flags & FLAG_DISABLE_OFF) {
        if (pinState) {
            // only ON
            // check if produced event is inverted
            sendInvertedProducedEvent(HAPPENING_IO_INPUT(io), pinState, NV->io[io].flags & FLAG_RESULT_EVENT_INVERTED);
        }
    } else {
        // check if produced event is inverted
        sendInvertedProducedEvent(HAPPENING_IO_INPUT(io), pinState, NV->io[io].flags & FLAG_RESULT_EVENT_INVERTED);
    }
}

/**
 * Called regularly to handle pulse and flash.
 */
void processOutputs(void) {
    BOOL state;
    unsigned char io;
    for (io=0; io<NUM_IO; io++) {
        if (NV->io[io].type == TYPE_OUTPUT) {
            // Handle the FLASH toggle
            if (flashDelays[io] == 1) {
                setOutputPin(io, NV->io[io].flags & FLAG_RESULT_ACTION_INVERTED);
                flashDelays[io] = NV->io[io].nv_io.nv_output.output_flash_period;
                flashDelays[io] = - flashDelays[io];
            }
            if (flashDelays[io] == -1) {
                setOutputPin(io, ! NV->io[io].flags & FLAG_RESULT_ACTION_INVERTED);
                flashDelays[io] = NV->io[io].nv_io.nv_output.output_flash_period;
            }
            if (flashDelays[io] > 1) {
                flashDelays[io]--;
            } else if (flashDelays[io] < -1) {
                flashDelays[io]++;
            }
            // Handle PULSEd outputs
            if (pulseDelays[io] == 1) {
                // time to go off
                if (NV->io[io].flags & FLAG_RESULT_ACTION_INVERTED) {
                    setOutputPin(io, TRUE);
                } else {
                    setOutputPin(io, FALSE);
                }
                // check if OFF events are enabled
                if ( ! (NV->io[io].flags & FLAG_DISABLE_OFF)) {
                    // check if produced event is inverted
                    sendProducedEvent(HAPPENING_IO_INPUT(io), !NV->io[io].flags & FLAG_RESULT_EVENT_INVERTED);
                }
                doneAction();
            }
            if (pulseDelays[io] != 0) {
                pulseDelays[io]--;
            }
        }
    }
}

/**
 * Set a digital output. Handles inverted outputs and pulsed outputs. Sends the
 * produced events.
 * 
 * @param io
 * @param action
 */
void setDigitalOutput(unsigned char io, unsigned char state) {
    BOOL pinState;
    switch (state) {
        default: // After TYPE change could be invalid
            state = ACTION_IO_3;   // default OFF
            // fall through
        case ACTION_IO_2:
        case ACTION_IO_3:
            pinState = (state == ACTION_IO_2);
            if (NV->io[io].flags & FLAG_TRIGGER_INVERTED) {
                pinState = pinState?0:1;
            }
            if (NV->io[io].flags & FLAG_RESULT_ACTION_INVERTED) {
                setOutputPin(io, ! pinState);
            } else {
                setOutputPin(io, pinState);
            }
            break;
        case ACTION_IO_4:
            flashDelays[io] = NV->io[io].nv_io.nv_output.output_flash_period;
            setOutputPin(io, TRUE);
            break;
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

