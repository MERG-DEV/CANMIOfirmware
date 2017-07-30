
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
 * File:   main.c
 * Author: Ian Hogg
 * 
 * This is the main for the Configurable CANMIO module.
 * 
 * Timer usage:
 * TMR0 used in ticktime for symbol times. Used to trigger next set of servo pulses
 * TMR1 Servo outputs 0, 4, 8, 12
 * TMR2 Servo outputs 1, 5, 9, 13
 * TMR3 Servo outputs 2, 6, 10, 14
 * TMR4 Servo outputs 3, 7, 11, 15
 *
 * Created on 10 April 2017, 10:26
 */
/** TODOs
 * Bootloader and handling of OPC_BOOT
 * Flicker LED on CAN activity can18.c
 * Work out what to do if all CANIDs are taken can18.c
 * Check handling of REQEV events.c
 * More validation of NV values
 * Implement ENUM
 * Implement NENRD
 * Implement CANID
 * Consider option to set outputs on or off on powerup in addition to restore previous state
 * Heartbeat message
 * Fix INVERTED for all types
 * Randomise bounce
 * RFID input
 * Analogue inputs for magnetic and current sense detectors
 * 
 * DONES:
 * DONE  Check handling of REVAL events.c
 * DONE  Implement NNRST
 * DONE  Implement NNRSM
 * DONE  needsStarting in Pulse OUTPUT
 * DONE  Change order of Pin Configs 0-7 done. 8-15 need checking
 * DONE  Implement AREQ but doesn't handle default events
 * DONE  Fix saved events when doing SNN - not needed
 * DONE  Flash OUTPUT type
 * DONE  Extend ActionQueue size
 * DONE  Determine how to send lots of CBUS messages without filling TX buffers
 * DONE  Consider a delay action for sequences
 * DONE  Check handling of NERD is correct and produces correct ENRSP events.c
 * DONE  change the START_SOD_EVENT for a learned action/event
 * DONE  consumed event processing
 * DONE  validate NV changes
 * DONE  servo outputs
 * DONE  debounce inputs
 * DONE  invert inputs
 * DONE  invert outputs
 * DONE  multi-position outputs
 * DONE  Fix deleteAction events.c
 * DONE  Pulse outputs
 * DONE  Bounce algorithm for servos
 * DONE  Store output state in EEPROM + restore on powerup
 * DONE  add a max loop count for bounce calculations
 * DONE  Change doAction to properly check for global actions
 * DONE  Move SOD processing to doAction from processEvent
 * DONE  Fix the SOD processing to include mid events
 * DONE  remember output state in EEPROM outputs.c & servo.c
 * DONE  Need more config changes when changing type
 * DONE  NV change callback for type change
 * DONE  add needsStarting and completed for OUTPUT types so can be processed sequentially
 * DONE  sequence servos servo.c
 * 
 * 
 * FCU changes needed
 * The number of event slots used + number of free slots != total number of events
 * Support for CMDERR(NO_EV) when doing REVAL
 * Setting of one NV (type) can effect other NVs. Should read back all NVs after setting one
 * Variable number of EVs per event up to the maximum
 * Event action sequences
 * A module can consume its own events
 * A NN can be upto 65535
 */

/**
 *	The Main CANMIO program supporting configurable I/O.
 */

#include "devincs.h"
#include <stddef.h>
#include "module.h"
#include "canmio.h"
#include "mioFLiM.h"
#include "config.h"
#include "StatusLeds.h"
#include "inputs.h"
#include "mioEEPROM.h"
#include "events.h"
#include "mioNv.h"
#include "FliM.h"
#include "romops.h"
#include "can18.h"
#include "cbus.h"
#include "actionQueue.h"
#ifdef SERVO
#include "servo.h"
#endif


extern void initOutputs(void);
extern void processOutputs(void);

#ifdef NV_CACHE
#include "nvCache.h"
#endif

#ifdef __18CXX
void ISRLow(void);
void ISRHigh(void);
#endif

// Default type is INPUT
#define TYPE_DEFAULT    TYPE_INPUT

// PIN configs
Config configs[NUM_IO] = {
    //PIN, PORT, PORT#, AN#
    // TODO check ordering of 8-15
    {11, 'C', 0, 0xFF},   //0
    {12, 'C', 1, 0xFF},   //1
    {13, 'C', 2, 0xFF},   //2
    {14, 'C', 3, 0xFF},   //3
    {15, 'C', 4, 0xFF},   //4
    {16, 'C', 5, 0xFF},   //5
    {17, 'C', 6, 0xFF},   //6
    {18, 'C', 7, 0xFF},   //7
    {21, 'B', 0, 10},   //8
    {22, 'B', 1, 8},   //9
    {25, 'B', 4, 9},   //10
    {26, 'B', 5, 0xFF},   //11
    {3,  'A', 1, 1},   //12
    {2,  'A', 0, 0},   //13
    {5,  'A', 3, 3},   //14
    {7,  'A', 5, 4}    //15
};

// forward declarations
void inputScan(BOOL report);
void __init(void);
BOOL checkCBUS( void);
void ISRHigh(void);
void initialise(void);
void configIO(unsigned char io);
void factoryReset(void);
void factoryResetGlobalNv(void);
void setType(unsigned char i, unsigned char type);
void setOutput(unsigned char i, unsigned char state, unsigned char type);
BOOL sendProducedEvent(unsigned char action, BOOL on);
void factoryResetEE(void);
void factoryResetFlash(void);

#ifdef __18CXX
void high_irq_errata_fix(void);

/*
 * Interrupt vectors (moved higher when bootloader present)
 */

// High priority interrupt vector

#ifdef BOOTLOADER_PRESENT
    #pragma code high_vector=0x808
#else
    #pragma code high_vector=0x08
#endif


//void interrupt_at_high_vector(void)

void HIGH_INT_VECT(void)
{
    _asm
        CALL high_irq_errata_fix, 1
    _endasm
}

/*
 * See 18F2480 errata
 */
void high_irq_errata_fix(void) {
    _asm
        POP
        GOTO ISRHigh
    _endasm
}

// low priority interrupt vector

#ifdef BOOTLOADER_PRESENT
    #pragma code low_vector=0x818
#else
    #pragma code low_vector=0x18
#endif

void LOW_INT_VECT(void)
{
    _asm GOTO ISRLow _endasm
}
#endif

static TickValue   startTime;
static BOOL        started = FALSE;
static TickValue   lastServoPollTime;
static TickValue   lastServoStartTime;
static unsigned char io;

// MAIN APPLICATION
        
/**
 * It is all run from here.
 * Initialise everything and then loop receiving and processing CAN messages.
 */
#ifdef __18CXX
void main(void) {
#else
int main(void) @0x800 {
#endif
    initRomOps();
#ifdef NV_CACHE
    // If we are using the cache make sure we get the NVs early in initialisation
    NV = loadNvCache(); // replace pointer with the cache
#endif
    // Both LEDs off to start with during initialisation
    initStatusLeds();
    // The very first ee_write seems to not work so I put a dummy write here
    ee_write((WORD)EE_DUMMY, 0xff);

    initialise(); 
    startTime.Val = tickGet();

    while (TRUE) {
        // Startup delay for CBUS about 2 seconds to let other modules get powered up - ISR will be running so incoming packets processed
        if (!started && (tickTimeSince(startTime) > (NV->sendSodDelay * HUNDRED_MILI_SECOND) + TWO_SECOND)) {
            started = TRUE;
            if (NV->sendSodDelay > 0) {
                sendProducedEvent(ACTION_PRODUCER_SOD, TRUE);
            }
        }
        checkCBUS();    // Consume any CBUS message and act upon it
        FLiMSWCheck();  // Check FLiM switch for any mode changes
        
        if (started) {
            if (tickTimeSince(lastServoStartTime) > 5*ONE_MILI_SECOND) {
#ifdef SERVO
                startServos();  // call every 5ms
#endif
                inputScan(FALSE);    // Strobe inputs for changes
                lastServoStartTime.Val = tickGet();
            }
            if (tickTimeSince(lastServoPollTime) > 100*ONE_MILI_SECOND) {
#ifdef SERVO
                pollServos();
#endif
                processActions();
                processOutputs();
                lastServoPollTime.Val = tickGet();
            }
        }
        // Check for any flashing status LEDs
        checkFlashing();
     } // main loop
} // main
 

/**
 * The order of initialisation is important.
 */
void initialise(void) {
    // enable the 4x PLL
    OSCTUNEbits.PLLEN = 1; 
    // Digital I/O - disable analogue
    ANCON0 = 0;
    ANCON1 = 0;
    
    // check if EEPROM is valid
   if (ee_read((WORD)EE_VERSION) != EEPROM_VERSION) {
        // may need to upgrade of data in the future
        // set EEPROM to default values
        factoryResetEE();
        // set the reset flag to indicate it has been initialised
        ee_write((WORD)EE_VERSION, EEPROM_VERSION);
    }
    // check if FLASH is valid
   if (NV->nv_version != FLASH_VERSION) {
        // may need to upgrade of data in the future
        // set Flash to default values
        factoryResetFlash();
        // set the version number to indicate it has been initialised
        writeFlashByte((BYTE*)(AT_NV + NV_VERSION), (BYTE)FLASH_VERSION);
    }
    initTicker(0);  // set low priority
    // Enable PORT B weak pullups
    INTCON2bits.RBPU = 0;
    // RB bits 0,1,4,5 need pullups
    WPUB = 0x33; 
    actionQueueInit();
    mioFlimInit(); // This will call FLiMinit, which, in turn, calls eventsInit
    // set up io pins based upon type
    // set the ports to the correct type
    for (io=0; io< NUM_IO; io++) {
        configIO(io);
    }
    initInputScan();
#ifdef SERVO
    initServos();
#endif
    initOutputs();
    
    /*
     * Now configure the interrupts.
     * Interrupt priority is enabled with the High priority interrupt used for
     * the servo timers and Low priority interrupt used for CAN and tick timer.
     */
    
    // Enable interrupt priority
    RCONbits.IPEN = 1;
    // enable interrupts, all init now done
    ei(); 
}

/**
 * set EEPROM to default values
 */
void factoryResetEE(void) {
    ee_write((WORD)EE_BOOT_FLAG, 0);
    ee_write((WORD)EE_CAN_ID, DEFAULT_CANID);
    ee_write_short((WORD)EE_NODE_ID, DEFAULT_NN); 
    ee_write((WORD)EE_FLIM_MODE, fsSLiM);
}

/**
 * Set up the EEPROM and Flash.
 * Should get called once on first power up or upon NNRST CBUS command. 
 * Initialise EEPROM and Flash.
 */
void factoryReset(void) {
    factoryResetEE();
    factoryResetFlash();
}

void factoryResetFlash(void) {
    unsigned char io;
    factoryResetGlobalNv();
    factoryResetGlobalEvents();
    clearAllEvents();
    // perform other actions based upon type
    for (io=0; io<NUM_IO; io++) {
        setType(io, TYPE_DEFAULT);
    } 
    flushFlashImage();
}

/**
 * Set the Type of the IO.
 * @param i the IO
 * @param type the new Type
 */
void setType(unsigned char io, unsigned char type) {
    WORD addr;
    addr = AT_NV+NV_IO_TYPE(io);
    writeFlashByte((BYTE*)addr, type);
#ifdef NV_CACHE
    loadNvCache();
#endif
    configIO(io);
    // set to default NVs
    defaultNVs(io, type);
    // set up the default events. 
    defaultEvents(io, type);
}

/**
 * Check to see if a message has been received on the CBUS and process 
 * it if one has been received.
 * @return true if a message has been received.
 */
BOOL checkCBUS( void ) {
    BYTE    msg[20];

    if (cbusMsgReceived( 0, (BYTE *)msg )) {
//        LED2G = BlinkLED( 1 );           // Blink LED on whilst processing messages - to give indication how busy module is
        if (parseCBUSMsg(msg)) {               // Process the incoming message
            return TRUE;
        }
        // handle the CANMIO specifics
        switch (msg[d0]) {
        case OPC_NNRSM: // reset to manufacturer defaults
            factoryReset();
            return TRUE;
        case OPC_NNRST: // restart
            // if we just call main then the stack won't be reset and we'd also want variables to be nullified
            // instead call the RESET vector (0x0000)
            Reset();
        }
    }
    return FALSE;
}


/**
 * Set up an IO based upon the specified type.
 * Set the port to input or output then call setOutput for the currently remembered state.
 * @param i the IO
 */
void configIO(unsigned char i) {
    if (i >= NUM_IO) return;
    // Now actually set it
    switch (configs[i].port) {
        case 'A':
            if (NV->io[i].type == TYPE_INPUT) {
                TRISA |= (1 << configs[i].no);  // input
            } else {
                TRISA &= ~(1 << configs[i].no); // output
            }
            break;
        case 'B':
            if (NV->io[i].type == TYPE_INPUT) {
                TRISB |= (1 << configs[i].no);  // input
            } else {
                TRISB &= ~(1 << configs[i].no); // output
            }
            break;
        case 'C':
            if (NV->io[i].type == TYPE_INPUT) {
                TRISC |= (1 << configs[i].no);  // input
            } else {
                TRISC &= ~(1 << configs[i].no); // output
            }
            break;          
    }
    // If this is an output (OUTPUT, SERVO, BOUNCE) set the value to valued saved in EE
    if (NV->io[i].flags & FLAG_STARTUP) {
        setOutput(i, ee_read((WORD)EE_OP_STATE+i), NV->io[i].type);
    }
}



#ifdef __18CXX
// C intialisation - declare a copy here so the library version is not used as it may link down in bootloader area

void __init(void)
{
}

// Interrupt service routines
#if defined(__18CXX)
#pragma interruptlow ISRLow
void ISRLow(void) {
#elif defined(__dsPIC30F__) || defined(__dsPIC33F__) || defined(__PIC24F__) || defined(__PIC24FK__) || defined(__PIC24H__)
    void _ISRFAST __attribute__((interrupt, auto_psv)) _INT1Interrupt(void)
#elif defined(__PIC32MX__)
    void __ISR(_EXTERNAL_1_VECTOR, ipl4) _INT1Interrupt(void)
#else
    void interrupt low_priority low_isr(void) {
#endif
    tickISR();
    canInterruptHandler();
}

// Interrupt service routines

#if defined(__18CXX)
#pragma interruptlow ISRHigh
void ISRHigh(void) {
#elif defined(__dsPIC30F__) || defined(__dsPIC33F__) || defined(__PIC24F__) || defined(__PIC24FK__) || defined(__PIC24H__)
    void _ISRFAST __attribute__((interrupt, auto_psv)) _INT1Interrupt(void)
#elif defined(__PIC32MX__)
    void __ISR(_EXTERNAL_1_VECTOR, ipl4) _INT1Interrupt(void)
#else 
    void interrupt high_priority high_isr (void) {
#endif

#if defined(SERVO) || defined(BOUNCE) || defined (MULTI)
 /* service the servo pulse width timers */
    if (PIR1bits.TMR1IF) {
        timer1DoneInterruptHandler();
        PIR1bits.TMR1IF = 0;
    }
    if (PIR1bits.TMR2IF) {
        timer2DoneInterruptHandler();
        PIR1bits.TMR2IF = 0;
    }
    if (PIR2bits.TMR3IF) {
        timer3DoneInterruptHandler();
        PIR2bits.TMR3IF = 0;
    }
    if (PIR4bits.TMR4IF) {
        timer4DoneInterruptHandler();
        PIR4bits.TMR4IF = 0;
    }
#endif
}

