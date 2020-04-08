
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
 * File:   inputs.c
 * Author: Ian
 * 
 * Handle in input Type variant of the IO. Scan for changes in state and 
 * generate Produced events.
 *
 * Created on 17 April 2017, 13:14
 */

#include <stddef.h>
#include "devincs.h"
#include "mioNv.h"
#include "FliM.h"
#include "canmio.h"
#include "config.h"
#include "mioEvents.h"
#include "cbus.h"

/**
 * The current state of the input pins. This may not be the actual read state uas we
 * could still be doing the debounce. Instead this is the currently reported input state.
 */
static BYTE inputState[NUM_IO];
/**
 * The effective state of the inputs after handling toggle. 
 */
BYTE outputState[NUM_IO];
/*
 * Counts the number of cycles since the input changed state.
 */
static BYTE delayCount[NUM_IO];

// forward declarations
BOOL readInput(unsigned char io);
// externs

static unsigned char io;

/**
 * Initialise the input scan.
 * Initialise using the current input state so that we don't generate state 
 * change events on power up.
 */
void initInputScan(void) {
    for (io=0; io<NUM_IO; io++) {
        BYTE input = readInput(io);
        inputState[io] = input;
        if (!(NV->io[io].flags & FLAG_TRIGGER_INVERTED)) {
            input = !input;
        }
        outputState[io] = input;
        delayCount[io] = 0;
    }
}

/**
 * Called regularly to check for changes on the inputs.
 * Generate Produced events upon input change.
 * Handles:
 * * Input pin invert
 * * Toggle
 * * Output OFF event disable
 * * Output event invert
 *   
 */
void inputScan(void) {
    volatile rom near Event * ev;
    for (io=0; io< NUM_IO; io++) {
        if (NV->io[io].type == TYPE_INPUT) {
            BYTE input = readInput(io);
            if (input != inputState[io]) {
                BOOL change = FALSE;
                // check if we have reached the debounce count
                if (inputState[io] && (delayCount[io] == NV->io[io].nv_io.nv_input.input_on_delay)) {
                    change = TRUE;
                }
                if (!inputState[io] && (delayCount[io] == NV->io[io].nv_io.nv_input.input_off_delay)) {
                    change = TRUE;
                }
                if (change) {
                    // input been steady long enough to be treated as a real change
                    delayCount[io] = 0;
                    inputState[io] = input;
                    // check if input pin is inverted
                    if (!(NV->io[io].flags & FLAG_TRIGGER_INVERTED)) {
                        input = !input;
                    }
                    // Check if toggle
                    if (NV->io[io].flags & FLAGS_TOGGLE) {
                        if (input) {
                            outputState[io] = ! outputState[io];
                        } else {
                            continue;
                        }
                     } else {
                        outputState[io] = input;
                    }
                    
                    // check if OFF events are enabled
                    if (NV->io[io].flags & FLAG_DISABLE_OFF) {
                        if (outputState[io]) {
                            // only ON
                            // check if produced event is inverted
                            if (NV->io[io].flags & FLAG_RESULT_EVENT_INVERTED) {
                                sendProducedEvent(HAPPENING_IO_INPUT(io), FALSE);
                            } else {
                                sendProducedEvent(HAPPENING_IO_INPUT(io), TRUE);
                            }
                        } else {
                            if (NV->io[io].flags & FLAG_RESULT_EVENT_INVERTED) {
                                sendProducedEvent(HAPPENING_IO_INPUT_TWO_ON(io), FALSE);
                            } else {
                                sendProducedEvent(HAPPENING_IO_INPUT_TWO_ON(io), TRUE);
                            }
                        }
                    } else {
                        // check if produced event is inverted
                        if (NV->io[io].flags & FLAG_RESULT_EVENT_INVERTED) {
                            sendProducedEvent(HAPPENING_IO_INPUT(io), !outputState[io]);
                        } else {
                            sendProducedEvent(HAPPENING_IO_INPUT(io), outputState[io]);
                        }
                    }
                } else {
                    delayCount[io]++;
                }
            } else {
                delayCount[io] = 0;
            }
        }
    }
}

/**
 * Read the input state from the IO pins.
 * @param io the IO number
 * @return Non zero is the input is high or FALSE if the input is low
 */
BOOL readInput(unsigned char io) {
    if (NV->io[io].type == TYPE_INPUT) {
            switch(configs[io].port) {
            case 'A':
                return PORTA & (1<<configs[io].no);
            case 'B':
                return PORTB & (1<<configs[io].no);
            case 'C':
                return PORTC & (1<<configs[io].no);
            }
        }
    return FALSE;
}
