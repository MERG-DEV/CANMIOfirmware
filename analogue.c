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

#ifdef ANALOGUE
static unsigned char portInProgress;
static WORD lastReading[NUM_IO];

void initAnalogue(void) {
    ADCON1bits.VCFG = 0;
    ADCON1bits.TRIGSEL = 0;
    ADCON1bits.CHSN = 0;
    ADCON2bits.ADFM = 1;    // right justified
    ADCON2bits.ACQT = 2;    // Acquisition 4 Tad cycles
    ADCON2bits.ADCS = 6;    // Fosc/64
    
    portInProgress = 0;
    ADCON0bits.ADON = 1;
}

void initAnaloguePort(unsigned char io) {
    // start an ADC
    ADCON0bits.CHS = configs[portInProgress].an;
    ADCON0bits.GO = 1;
    // wait for result
    while (ADCON0bits.NOT_DONE)
           ;
    // get the reading
    lastReading[io] = ADRESH;
    lastReading[io] << 8;
    lastReading[io] |= ADRESL;
}

void pollAnalogue(void) {
    unsigned char io;
    WORD adc;
    WORD lthreshold;
    WORD hthreshold;
    WORD lhysteresis;
    WORD hhysteresis;

    // are we currently doing a conversion on a valid IO?
    if ((NV->io[portInProgress].type == TYPE_ANALOGUE_IN) || (NV->io[portInProgress].type == TYPE_MAGNET)) {
        // is conversion finished?
        if (ADCON0bits.DONE) {
            // get the 12 bit result
            adc = ADRESH;
            adc << 8;
            adc |= ADRESL;
            if (NV->io[portInProgress].type == TYPE_MAGNET) {
                // calculate thresholds
                lthreshold = NV->io[portInProgress].nv_io.nv_magnet.magnet_offset_h;
                lthreshold << 8;
                lthreshold |= NV->io[portInProgress].nv_io.nv_magnet.magnet_offset_l;
                hthreshold = lthreshold;    // the offset
                lthreshold -= NV->io[portInProgress].nv_io.nv_magnet.magnet_threshold;
                hthreshold += NV->io[portInProgress].nv_io.nv_magnet.magnet_threshold;
                lhysteresis = lthreshold - NV->io[portInProgress].nv_io.nv_magnet.magnet_hysteresis;
                hhysteresis = hthreshold - NV->io[portInProgress].nv_io.nv_magnet.magnet_hysteresis;
                // compare with thresholds
                if ((lastReading[portInProgress] < hthreshold) && (adc >= hthreshold)) {
                    //High on
                    sendProducedEvent(ACTION_IO_PRODUCER_MAGNETH(portInProgress), !(NV->io[portInProgress].flags & FLAG_RESULT_EVENT_INVERTED));
                } else if (( lastReading[portInProgress] > hhysteresis) && (adc <= hhysteresis)) {
                    //High Off
                    if ( ! (NV->io[portInProgress].flags & FLAG_DISABLE_OFF)) {
                        sendProducedEvent(ACTION_IO_PRODUCER_MAGNETH(portInProgress), NV->io[portInProgress].flags & FLAG_RESULT_EVENT_INVERTED);
                    }
                }
            } else {
                // TYPE_ANALOGUE
                adc >> 4;   // convert to 8 bit
                lthreshold = NV->io[portInProgress].nv_io.nv_analogue_in.analogue_threshold;
                lhysteresis = lthreshold - NV->io[portInProgress].nv_io.nv_analogue_in.analogue_hysteresis; 
            }
            // This is common between analogue and magnet despite the names
            if ((lastReading[portInProgress] < lthreshold) && (adc >= lthreshold)) {
                // Low on 
                sendProducedEvent(ACTION_IO_PRODUCER_MAGNETL(portInProgress), !(NV->io[portInProgress].flags & FLAG_RESULT_EVENT_INVERTED));
            } else if (( lastReading[portInProgress] > lhysteresis) && (adc <= lhysteresis)) {
                //Low Off
                if ( ! (NV->io[portInProgress].flags & FLAG_DISABLE_OFF)) {
                    sendProducedEvent(ACTION_IO_PRODUCER_MAGNETL(portInProgress), NV->io[portInProgress].flags & FLAG_RESULT_EVENT_INVERTED);
                }
            }
            //save
            lastReading[portInProgress] = adc;
        } else {
            return;
        }
    }
    // try next IO
    portInProgress++;
    if (portInProgress >= NUM_IO) {
        portInProgress = 0;
    }
    if ((NV->io[portInProgress].type == TYPE_ANALOGUE_IN) || (NV->io[portInProgress].type == TYPE_MAGNET)) {
        // start a conversion
        ADCON0bits.CHS = configs[portInProgress].an;
        ADCON0bits.GO = 1;
    }
}

WORD getChannel(unsigned char ch) {
    if ((NV->io[ch].type == TYPE_ANALOGUE_IN) || (NV->io[ch].type == TYPE_MAGNET)) {
        return lastReading[ch];
    }
    return 0;
}
#endif
