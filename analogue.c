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
 * File:   analogue.c
 * Author: Ian
 *
 * Created on 16 August 2017, 13:14
 *
 * Process the analogue inputs (include magnet)
 */
#include "module.h"
#include "config.h"
#include "analogue.h"
#include "cbus.h"
#include "romops.h"
#include "happeningsActions.h"

#ifdef ANALOGUE
static unsigned char portInProgress;
AnalogueStates  analogueState[NUM_IO];

unsigned char setupIo;
unsigned char setupState;
static unsigned char haveRequestedAdc;    // indicates if the software has requested an ADC so that when ADCON0.GO is clear then a result is available

void initAnalogue(void) {
    ADCON1bits.VCFG = 0;    // AVdd + reference
    ADCON1bits.VNCFG = 0;   // AVss - reference
    ADCON1bits.TRIGSEL = 1; // special trigger CTMU (not used))
    ADCON1bits.CHSN = 0;    // Negative channel AVss
    ADCON2bits.ADFM = 1;    // right justified  values 0 ~ 0x0FFF
    ADCON2bits.ACQT = 2;    // Acquisition 4 Tad cycles 
    ADCON2bits.ADCS = 6;    // Fosc/64 : Tad = 1us
    
    portInProgress = 0;
    ADCON0bits.ADON = 1;
    
    setupState = SETUP_NONE;
    haveRequestedAdc = 0;
}

void initAnaloguePort(unsigned char io) {
    analogueState[io].eventState = ANALOGUE_EVENT_OFF;
    analogueState[io].portState = ANALOGUE_PORT_INITIALISING;
}


void pollAnalogue(void) {
    WORD adc;   // used to store the latest voltage reading (calling it current voltage would be confusing!))
    // these are signed since if the offset is small then lthreshold and lhysteresis can be negative
    short lthreshold;
    short hthreshold;
    short lhysteresis;
    short hhysteresis;
    
    if (ADCON0bits.GO) {
        // awaiting ADC to complete
        return;
    }

    // are we currently doing a conversion on a valid IO?
    if ((NV->io[portInProgress].type == TYPE_ANALOGUE_IN) || (NV->io[portInProgress].type == TYPE_MAGNET)) {
        // has conversion finished?
        if (haveRequestedAdc) {
            // get the 12 bit result
            adc = ADRESH;
            adc = adc << 8;
            adc |= ADRESL;
            /*
             * Adc readings are 12 bit 0 to 0x0FFF
             */
            if ((setupState == SETUP_NONE) || (portInProgress != setupIo)) {
                if (NV->io[portInProgress].type == TYPE_MAGNET) {
                    // TYPE MAGNET
                    // calculate thresholds
                    lthreshold = NV->io[portInProgress].nv_io.nv_magnet.magnet_offset_h;
                    lthreshold = lthreshold << 8;
                    lthreshold |= NV->io[portInProgress].nv_io.nv_magnet.magnet_offset_l;
                    hthreshold = lthreshold; // the offset
                    lthreshold -= NV->io[portInProgress].nv_io.nv_magnet.magnet_threshold;
                    hthreshold += NV->io[portInProgress].nv_io.nv_magnet.magnet_threshold;
                    lhysteresis = lthreshold + NV->io[portInProgress].nv_io.nv_magnet.magnet_hysteresis;
                    hhysteresis = hthreshold - NV->io[portInProgress].nv_io.nv_magnet.magnet_hysteresis;
                    // compare with thresholds
                    if ((analogueState[portInProgress].eventState != ANALOGUE_EVENT_UPPER) && (adc >= hthreshold)) {
                        //High on
                        if (analogueState[portInProgress].portState == ANALOGUE_PORT_READY) {
                            sendProducedEvent(HAPPENING_IO_MAGNETH(portInProgress), !(NV->io[portInProgress].flags & FLAG_RESULT_EVENT_INVERTED));
                        }
                        analogueState[portInProgress].eventState = ANALOGUE_EVENT_UPPER;
                    } else if ((analogueState[portInProgress].eventState == ANALOGUE_EVENT_UPPER) && (adc <= hhysteresis)) {
                        //High Off
                        if (analogueState[portInProgress].portState == ANALOGUE_PORT_READY) {
                            if (!(NV->io[portInProgress].flags & FLAG_DISABLE_OFF)) {
                                sendProducedEvent(HAPPENING_IO_MAGNETH(portInProgress), NV->io[portInProgress].flags & FLAG_RESULT_EVENT_INVERTED);
                            }
                        }
                        analogueState[portInProgress].eventState = ANALOGUE_EVENT_OFF;
                    }
                } else {
                    // TYPE_ANALOGUE
                    // calculate threshold
                    adc = adc >> 4; // convert to 8 bit
                    lthreshold = NV->io[portInProgress].nv_io.nv_analogue_in.analogue_threshold;
                    lhysteresis = lthreshold - NV->io[portInProgress].nv_io.nv_analogue_in.analogue_hysteresis;
                }
                // This is common between analogue and magnet despite the names
                if ((analogueState[portInProgress].eventState != ANALOGUE_EVENT_LOWER) && (adc <= lthreshold)) {
                    // Low on 
                    if (analogueState[portInProgress].portState == ANALOGUE_PORT_READY) {
                        sendProducedEvent(HAPPENING_IO_MAGNETL(portInProgress), !(NV->io[portInProgress].flags & FLAG_RESULT_EVENT_INVERTED));
                    }
                    analogueState[portInProgress].eventState = ANALOGUE_EVENT_LOWER;
                } else if ((analogueState[portInProgress].eventState == ANALOGUE_EVENT_LOWER) && (adc >= lhysteresis)) {
                    //Low Off
                    if (analogueState[portInProgress].portState == ANALOGUE_PORT_READY) {
                        if (!(NV->io[portInProgress].flags & FLAG_DISABLE_OFF)) {
                            sendProducedEvent(HAPPENING_IO_MAGNETL(portInProgress), NV->io[portInProgress].flags & FLAG_RESULT_EVENT_INVERTED);
                        }
                    }
                    analogueState[portInProgress].eventState = ANALOGUE_EVENT_OFF;
                }
            } else {
                // we are setting up this channel
                // report adc value
                cbusMsg[d3] = 0;
                cbusMsg[d4] = portInProgress + 1;
                cbusMsg[d5] = portInProgress + 1;
                cbusMsg[d7] = adc & 0xFF;
                cbusMsg[d6] = adc >> 8;
                cbusSendOpcNN(ALL_CBUS, OPC_ARSON3, -1, cbusMsg);
                if (setupState == SETUP_REPORT_AND_SAVE) {
                    // save the offset
                    writeFlashByte((BYTE*) (AT_NV + NV_IO_MAGNET_OFFSETH(portInProgress)), cbusMsg[d6]);
                    writeFlashByte((BYTE*) (AT_NV + NV_IO_MAGNET_OFFSETL(portInProgress)), cbusMsg[d7]);
                }
                setupState = SETUP_NONE;
            }
            analogueState[portInProgress].portState = ANALOGUE_PORT_READY;
        }
    }
    // try next IO
    portInProgress++;
    if (portInProgress >= NUM_IO) {
        portInProgress = 0;
    }
    // If necessary start a conversion
    if ((NV->io[portInProgress].type == TYPE_ANALOGUE_IN) || (NV->io[portInProgress].type == TYPE_MAGNET)) {
        // start a conversion
        ADCON0bits.CHS = configs[portInProgress].an;
        ADCON0bits.GO = 1;
        haveRequestedAdc = 1;
    }
}
/*
WORD getChannel(unsigned char ch) {
    if ((NV->io[ch].type == TYPE_ANALOGUE_IN) || (NV->io[ch].type == TYPE_MAGNET)) {
        return lastReading[ch];
    }
    return 0;
}
*/
#endif
