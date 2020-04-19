# CANMIOfirmware
PIC firmware for CANMIO with configurable IO. Uses the CBUSlib https://github.com/MERG-DEV/CBUSlib.
Also Known as Universal firmware.
Documentation on MERG wiki https://www.merg.org.uk/merg_wiki/doku.php?id=cbus:canmio_fw

#TODOs
  * Work out what to do if all CANIDs are taken can18.c
  * Heartbeat message
  * Randomise bounce
  * RFID input - PNB now taken on this task - branch PNB

# To compile this code:
This code is written for the Microchip C18 toolchain.

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
  * cbusdefs8r.h
  * cbuslib.h
  * devincs.h
  * EEPROM.h
  * events.h
  * FliM.h
  * romops.h
  * StatusLeds.h
  * TickTime.h

  * Bootloader.asm
  * c018.c
  * can18.c
  * cbus.c
  * events.c
  * FliM.c
  * romops.c
  * StatusLeds.c
  * ticktime.c

You will also need to ensure you are using the correct linker script from this repo depending upon target processor type. 

I found I had a bit of difficulty with uppercase/lowercase of filenames. In particular the Flim.[ch] were troublesome.
Also if building on linux the C18 compiler needs the 18F26K80_e.lib copied to 18f26K80_e.lib for the library to be found correctly.
