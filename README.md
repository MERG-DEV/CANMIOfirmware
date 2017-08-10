# CANMIOfirmware
PIC firmware for CANMIO with configurable IO. Uses the CBUSlib https://github.com/MERG-DEV/CBUSlib.

Currently work in progress.
ToDos and DONEs:
TODOs
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

DONES:
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

# To compile this code:
Please check that you are using the C18Ian branch from git.

The other important thing to know is the project setup in MPLAB. I create a separate MPLAB project within the usual MPLAB workspace and then import the files from the git directory. I create logical folders thus:
CANMIOfirmware
  * Header files
    - CANMIOfirmware
    - CBUSlib
  * Source files
    - CANMIOfirmware
    - CBUSlib

In the project properties you need to put in the header file include paths under C18 Global Options -> mcc18 -> General -> Include directories = ../../githib/CANMIOfirmware; ../../github/CBUSlib

The actual CBUSlib files needed by the project are:
  * callbacks.h
  * can18.h
  * cbus.h
  * cbusconfig.h
  * cbusdefs8n.h
  * cbuslib.h
  * devincs.h
  * EEPROM.h
  * events.h
  * Flim.h
mioSLiM.inc (I don't think this is required nor be in the library but I seem to have it included)
  * MoreTypes.h
  * romops.h
  * StatusLeds.h
  * TickTime.h
  * can18.c
  * cbus.c
  * events.c
  * Flim.c
  * romops.c
  * StatusLeds.c
  * ticktime.c

You will also need to ensure you are using the correct linker script. 

I found I had a bit of difficulty with uppercase/lowercase of filenames. In particular the Flim.[ch] were troublesome.
Also if building on linux the C18 compiler needs the 18F26K80_e.lib copied to 18f26K80_e.lib for the library to be found correctly.
