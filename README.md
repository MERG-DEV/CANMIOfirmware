# CANMIOfirmware

The Universal firmware for CANMIO, CANBIP, CANFLIMIO E/F/FF/O and CANVxxxxx boards with PIC18F25K80 and PIC18F26K80 processors and 16MHz clocks.

# Version 3a

See CANMIO wiki page for full details of changes and bug fixes in this version
Version 3a is the released version of version 3a BETA 3 - the only additional changes are the option to build for the CANBIP as well as CANMIO
CANMIO version 3a uses CBUSLIB version 2j


# Description

The Universal firmware allows the 16 I/O channels of the CANMIO to be individually configured for:

  * INPUT digital input (default for all I/O channels on CANMIO and channels 9 to 16 on CANBIP)
  * OUTPUT including relays (default for channels 1 to 8 on CANBIP)
  * SERVO for turnouts
  * BOUNCE servo for semaphore signals
  * MULTI multiple position servo for US signals and other uses (as suggested by Keith Norgrove)
  * ANALOGUE analogue input threshold. (Available on channels 9,10,11,13,14,15,16 supported on PIC18F26K80 only)
  * MAGNET for magnet detectors. (Available on channels 9,10,11,13,14,15,16 supported on PIC18F26K80 only)

Documentation on MERG wiki https://www.merg.org.uk/merg_wiki/doku.php?id=cbus:canmio_fw

# To compile this code:
This code is written for the Microchip C18 toolchain.

Uses the CBUSlib https://github.com/MERG-DEV/CBUSlib.

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
  * CBUSlib header files
    - callbacks.h
    - can18.h
    - cbus.h
    - cbuslib.h
    - devincs.h
    - EEPROM.h
    - events.h
    - FliM.h
    - romops.h
    - StatusLeds.h
    - TickTime.h
  * CBUSlib source files
    - Bootloader.asm
    - c018.c
    - can18.c
    - cbus.c
    - events.c
    - FliM.c
    - romops.c
    - StatusLeds.c
    - ticktime.c
  * CBUSdefs header files
    - cbusdefs.h

You will also need to ensure you are using the correct linker script from this repo depending upon target processor type. 

I found I had a bit of difficulty with uppercase/lowercase of filenames. In particular the Flim.[ch] were troublesome.
Also if building on linux the C18 compiler needs the 18F26K80_e.lib copied to 18f26K80_e.lib for the library to be found correctly.

# TODOs
  * Work out what to do if all CANIDs are taken can18.c
  * Heartbeat message
  * Randomise bounce
  * RFID input - PNB now taken on this task - branch PNB
