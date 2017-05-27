/* 
 * File:   nodeVarables.h
 * Author: 	Ian Hogg
 * Comments:	Definitions for NVs
 * Revision history: 
 */

#ifndef XC_NODE_VARIABLES_H
#define	XC_NODE_VARIABLES_H

/**
 * This is where the module specific NVs are specified.
 * NVs can be accessed either by byte offset (for read/set of NVs in FLiM.c)
 * or by use of a structure with named elements. These two must be kept synchronised.
 * 
 * The following are required by FLiM.c: NV_NUM, AT_NV
 */

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
#include "../CBUSlib/GenericTypeDefs.h"
#include "canmio.h"
    
// Global NVs
#define NV_SOD_DELAY                    1
#define NV_HB_DELAY                     2  
#define NV_SERVO_CUTOFF                 3
#define NV_SERVO_STARTUP_B1             4
#define NV_SERVO_STARTUP_B2             5
#define NV_SERVO_SEQUENTIAL             6
#define NV_SERVO_SPEED                  7   // Used for Multi and Bounce types where there isn't an NV to define speed.
#define NV_SPARE1                       8
#define NV_SPARE2                       9
#define NV_SPARE3                       10
#define NV_SPARE4                       11
#define NV_SPARE5                       12
#define NV_SPARE6                       13
#define NV_SPARE7                       14
#define NV_SPARE8                       15
#define NV_IO_START                     16
#define NVS_PER_IO                      6
    
// NVs per IO
#define NV_IO_TYPE(i)                   (NV_IO_START + NVS_PER_IO*(i))
#define NV_IO_INPUT_ENABLE_OFF(i)       (NV_IO_START + NVS_PER_IO*(i) + 1)
#define NV_IO_INPUT_INVERTED(i)         (NV_IO_START + NVS_PER_IO*(i) + 2)
#define NV_IO_INPUT_ON_DELAY(i)         (NV_IO_START + NVS_PER_IO*(i) + 3)
#define NV_IO_INPUT_OFF_DELAY(i)        (NV_IO_START + NVS_PER_IO*(i) + 4)
#define NV_IO_OUTPUT_PULSE_DURATION(i)  (NV_IO_START + NVS_PER_IO*(i) + 1)
#define NV_IO_OUTPUT_INVERTED(i)        (NV_IO_START + NVS_PER_IO*(i) + 2)
#define NV_IO_SERVO_START_POS(i)        (NV_IO_START + NVS_PER_IO*(i) + 1)
#define NV_IO_SERVO_END_POS(i)          (NV_IO_START + NVS_PER_IO*(i) + 2)
#define NV_IO_SERVO_SE_SPEED(i)         (NV_IO_START + NVS_PER_IO*(i) + 3)
#define NV_IO_SERVO_ES_SPEED(i)         (NV_IO_START + NVS_PER_IO*(i) + 4)
#define NV_IO_BOUNCE_START_POS(i)       (NV_IO_START + NVS_PER_IO*(i) + 1)
#define NV_IO_BOUNCE_END_POS(i)         (NV_IO_START + NVS_PER_IO*(i) + 2)
#define NV_IO_BOUNCE_PROFILE(i)         (NV_IO_START + NVS_PER_IO*(i) + 3)
#define NV_IO_MULTI_NUM_POS(i)          (NV_IO_START + NVS_PER_IO*(i) + 1)
#define NV_IO_MULTI_POS1(i)             (NV_IO_START + NVS_PER_IO*(i) + 2)
#define NV_IO_MULTI_POS2(i)             (NV_IO_START + NVS_PER_IO*(i) + 3)
#define NV_IO_MULTI_POS3(i)             (NV_IO_START + NVS_PER_IO*(i) + 4)
#define NV_IO_MULTI_POS4(i)             (NV_IO_START + NVS_PER_IO*(i) + 5)

#define IS_NV_TYPE(i)                   (((i-NV_IO_START) % NVS_PER_IO) == 0)
#define IO_NV(i)                        ((i-NV_IO_START)/NVS_PER_IO)
  
// the types
#define TYPE_INPUT                  0
#define TYPE_OUTPUT                 1
#define TYPE_SERVO                  2
#define TYPE_BOUNCE                 3
#define TYPE_MULTI                  4

typedef struct {
    unsigned char type;
    union {
        struct {
            unsigned char input_enable_off;
            unsigned char input_inverted;
            unsigned char input_on_delay;
            unsigned char input_off_delay;
        } nv_input;
        struct {
            unsigned char output_pulse_duration;
            unsigned char outout_inverted;
        } nv_output;
        struct {
            unsigned char servo_start_pos;
            unsigned char servo_end_pos;
            unsigned char servo_se_speed;
            unsigned char servo_es_speed;
        } nv_servo;
        struct {
            unsigned char bounce_start_pos;
            unsigned char bounce_end_pos;
            unsigned char bounce_profile;
        } nv_bounce;
        struct {
            unsigned char multi_num_pos;
            unsigned char multi_pos1;
            unsigned char multi_pos2;
            unsigned char multi_pos3;
            unsigned char multi_pos4;
        } nv_multi;
    } nv_io;
} NvIo;

/*
 * This structure is required by FLiM.h
 */
typedef struct {
        BYTE sendSodDelay;               // Time after start in 100mS (plus 2 seconds) to send an automatic SoD. Set to zero for no auto SoD
        BYTE hbDelay;                    // Interval in 100mS for automatic heartbeat. Set to zero for no heartbeat.
        BYTE cutoff;                  // whether servos stop when they reach their destination
        WORD startup;                 // ??
        BYTE sequential;              // whether outputs change sequentially or all together
        BYTE servo_speed;               // default servo speed
        BYTE spare[8];
        NvIo io[NUM_IO];                 // config for each IO
} ModuleNvDefs;

#define NV_NUM  sizeof(ModuleNvDefs)     // Number of node variables
#define AT_NV   0x7F80                  // Where the NVs are stored. (_ROMSIZE - 128)  Size=128 bytes

extern unsigned int getNodeVar(unsigned int index);
extern void setNodeVar(unsigned int index, unsigned int value);
extern BOOL validateNV(BYTE nvIndex, BYTE oldValue, BYTE value);
void actUponNVchange(unsigned char index, unsigned char value);
extern void defaultNVs(unsigned char i, unsigned char type);        


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_NODE_VARAIABLES_H */

