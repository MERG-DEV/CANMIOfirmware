# CANMIOfirmware
PIC firmware for CANMIO with configurable IO. Uses the CBUSlib https://github.com/spikyian/CBUSlib.

Currently work in progress.
ToDos:
 * Bootloader and handling of OPC_BOOT
 * DONE change the START_SOD_EVENT for a learned action/event
 * DONE consumed event processing
 * DONE validate NV changes
 * DONE servo outputs
 * DONE debounce inputs
 * DONE invert inputs
 * DONE invert outputs
 * digital output pulse output.c
 * bounce profiles  
 * DONE multi-position outputs
 * sequence servos servo.c
 * remember output state in EEPROM outputs.c & servo.c
 * Flicker LED on CAN activity can18.c
 * Work out what to do if all CANIDs are taken can18.c
 * Check handling of NERD is correct and produces correct ENRSP events.c
 * Check handling of REVAL events.c
 * Check handling of REQEV events.c
 * DONE Fix deleteAction events.c
