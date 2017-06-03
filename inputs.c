
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

#include <xc.h>

#include "mioNv.h"
#include "../CBUSlib/FliM.h"
#include "canmio.h"
#include "config.h"
#include "mioEvents.h"
#include "../CBUSlib/cbus.h"

extern Config configs[NUM_IO];
extern __rom const ModuleNvDefs * NV;
/**
 * The current state of the inputs. This may not be the actual read state uas we
 * could still be doing the debounce. Instead this is the currently reported input state.
 */
static BYTE inputState[NUM_IO];
/*
 * Counts the number of cycles since the input changed state.
 */
static BYTE delayCount[NUM_IO];

// forward declarations
BOOL readInput(unsigned char io);

static unsigned char io;

/**
 * Initialise the input scan.
 * Initialise using the current input state so that we don't generate state 
 * change events on power up.
 */
void initInputScan(void) {
    for (io=0; io<NUM_IO; io++) {
        inputState[io] = readInput(io);
    }
}

/**
 * Called regularly to check for changes on the inputs.
 * Generate Produced events upon input change.
 * 
 * @param report always send current status if report is TRUE otherwise send only on change
 *   
 */
void inputScan(BOOL report) {
    for (io=0; io< NUM_IO; io++) {
        if (NV->io[io].type == TYPE_INPUT) {
            BYTE input = readInput(io);
            if (input != inputState[io]) {
                BOOL change = report;
                // check if we have reached the debounce count
                if (inputState[io] && (delayCount[io] == NV->io[io].nv_io.nv_input.input_on_delay)) {
                    change = TRUE;
                }
                if (!inputState[io] && (delayCount[io] == NV->io[io].nv_io.nv_input.input_off_delay)) {
                    change = TRUE;
                }
                if (change) {
                    delayCount[io] = 0;
                    inputState[io] = input;
                    // check if input is inverted
                    if (NV->io[io].flags & FLAG_INVERTED) {
                        input = !input;
                    }
                    // send the changed Produced event
                    if (input) {
                        cbusSendEvent( 0, -1, ACTION_IO_PRODUCER_INPUT(io), TRUE);
                    } else {
                        // check if OFF events are enabled
                        if (NV->io[io].nv_io.nv_input.input_enable_off) {
                            cbusSendEvent( 0, -1, ACTION_IO_PRODUCER_INPUT(io), FALSE);
                        }
                    }
                }
                delayCount[io]++;
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
            case 'a':
                return TRISA & (1<<configs[io].no);
            case 'b':
                return TRISB & (1<<configs[io].no);
            case 'c':
                return TRISA & (1<<configs[io].no);
            }
        }
    return FALSE;
}
