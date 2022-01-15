# CANMIOfirmware

The Universal firmware for CANMIO, CANBIP, CANFLIMIO E/F/FF/O and CANVxxxxx boards with PIC18F25K80 and PIC18F26K80 processors and 16MHz clocks.



# Version 3C beta 1

See CANMIO wiki page for full details of changes and bug fixes in this version

Version 3C BETA 1 includes some bug fixes and the option for the user to set a delay between response messages to SoD or NERD.
See the commit comments for full details of the changes.



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

Uses the CBUSlib verion 2M  https://github.com/MERG-DEV/CBUSlib.

It also uses CBUSDefs  https://github.com/MERG-DEV/cbusdefs

The other important thing to know is the project setup in MPLAB. I create a separate MPLAB project within the usual MPLAB workspace and then import the files from the git directory. I create logical folders thus:
CANMIOfirmware
  * Header files
    - CANMIOfirmware
    - CBUSlib
	- CBUSDefs
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
	- happeningsActions.h
    - romops.h
    - StatusLeds.h
    - TickTime.h
	- timedResponse.h
  * CBUSlib source files
    - Bootloader.asm
    - c018.c
    - can18.c
    - cbus.c
    - events.c
	- FliM.c
	- happeningsActions.c
    - romops.c
    - StatusLeds.c
    - ticktime.c
	- timedResponse.c
  * CBUSdefs header files
    - cbusdefs.h

You will also need to ensure you are using the correct linker script from this repo depending upon target processor type. 

I found I had a bit of difficulty with uppercase/lowercase of filenames. In particular the Flim.[ch] were troublesome.
Also if building on linux the C18 compiler needs the 18F26K80_e.lib copied to 18f26K80_e.lib for the library to be found correctly.

# Possible enhancements
  * Work out what to do if all CANIDs are taken can18.c
  * Heartbeat message
  * Randomise bounce
  * RFID input - PNB now taken on this task - branch PNB
