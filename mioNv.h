
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
 * File:   nodeVarables.h
 * Author: 	Ian Hogg
 * Comments:	Definitions for NVs
 * Revision history: 
 * 
 * ---
 *
 * Revision by Greg Palmer
 * 15 April 2021
 *
 *	Added flag FLAG_INPUT_DISABLE_SOD_RESPONSE value 0x20
 *  This flag overlays FLAG_STARTUP which has no meaning for input types 
 *  Enables a feature that exists in CANACE8C
 *	Applicable to Input types - input, analogue, and magnet to allow users to supress SOD messages
 *    for the channel.
 *
 * --
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
    
#include "GenericTypeDefs.h"
#include "canmio.h"

#define FLASH_VERSION   0x02U        // Version 2 introduced when Actions were changed to have 5 per channel
    
// Global NVs
#define NV_VERSION                      0U
#define NV_SOD_DELAY                    1U
#define NV_HB_DELAY                     2U  
#define NV_SERVO_SPEED                  3U   // Used for Multi and Bounce types where there isn't an NV to define speed.
#define NV_PULLUPS                      4U
#define NV_RESPONSE_DELAY               5U
#define NV_SPARE3                       6U
#define NV_SPARE4                       7U
#define NV_SPARE5                       8U
#define NV_SPARE6                       9U
#define NV_SPARE7                       10U
#define NV_SPARE8                       11U
#define NV_SPARE9                       12U
#define NV_SPARE10                      13U
#define NV_SPARE11                      14U
#define NV_SPARE12                      15U
#define NV_IO_START                     16U
#define NVS_PER_IO                      7U
    
// NVs per IO
#define NV_IO_TYPE_OFFSET               0U
#define NV_IO_FLAGS_OFFSET              1U
#define NV_IO_TYPE(i)                   (NV_IO_START + NVS_PER_IO*(i) + NV_IO_TYPE_OFFSET)		// TYPE and FLAGS always at the start
#define NV_IO_FLAGS(i)                  (NV_IO_START + NVS_PER_IO*(i) + NV_IO_FLAGS_OFFSET)

// Other NVs depend upon type
#define NV_IO_INPUT_ON_DELAY_OFFSET     2U
#define NV_IO_INPUT_OFF_DELAY_OFFSET    3U
#define NV_IO_INPUT_ON_DELAY(i)         (NV_IO_START + NVS_PER_IO*(i) + NV_IO_INPUT_ON_DELAY_OFFSET)	// units of 5ms
#define NV_IO_INPUT_OFF_DELAY(i)        (NV_IO_START + NVS_PER_IO*(i) + NV_IO_INPUT_OFF_DELAY_OFFSET)	// units of 5ms

#define NV_IO_OUTPUT_PULSE_DURATION_OFFSET 2U
#define NV_IO_OUTPUT_FLASH_PERIOD_OFFSET 3U
#define NV_IO_OUTPUT_PULSE_DURATION(i)  (NV_IO_START + NVS_PER_IO*(i) + NV_IO_OUTPUT_PULSE_DURATION_OFFSET)	// units of 0.1 seconds
#define NV_IO_OUTPUT_FLASH_PERIOD(i)    (NV_IO_START + NVS_PER_IO*(i) + NV_IO_OUTPUT_FLASH_PERIOD_OFFSET)	// units of 0.1 seconds

#define NV_IO_SERVO_START_POS_OFFSET    2U
#define NV_IO_SERVO_END_POS_OFFSET      3U
#define NV_IO_SERVO_SE_SPEED_OFFSET     4U
#define NV_IO_SERVO_ES_SPEED_OFFSET     5U
#define NV_IO_SERVO_START_POS(i)        (NV_IO_START + NVS_PER_IO*(i) + NV_IO_SERVO_START_POS_OFFSET)
#define NV_IO_SERVO_END_POS(i)          (NV_IO_START + NVS_PER_IO*(i) + NV_IO_SERVO_END_POS_OFFSET)
#define NV_IO_SERVO_SE_SPEED(i)         (NV_IO_START + NVS_PER_IO*(i) + NV_IO_SERVO_SE_SPEED_OFFSET)	// position moved every 100ms
#define NV_IO_SERVO_ES_SPEED(i)         (NV_IO_START + NVS_PER_IO*(i) + NV_IO_SERVO_ES_SPEED_OFFSET)	// position moved every 100ms

#define NV_IO_BOUNCE_UPPER_POS_OFFSET   2U
#define NV_IO_BOUNCE_LOWER_POS_OFFSET   3U
#define NV_IO_BOUNCE_COEFF_OFFSET       4U
#define NV_IO_BOUNCE_PULL_SPEED_OFFSET  5U
#define NV_IO_BOUNCE_PULL_PAUSE_OFFSET  6U
#define NV_IO_BOUNCE_UPPER_POS(i)       (NV_IO_START + NVS_PER_IO*(i) + NV_IO_BOUNCE_UPPER_POS_OFFSET)
#define NV_IO_BOUNCE_LOWER_POS(i)       (NV_IO_START + NVS_PER_IO*(i) + NV_IO_BOUNCE_LOWER_POS_OFFSET)
#define NV_IO_BOUNCE_COEFF(i)           (NV_IO_START + NVS_PER_IO*(i) + NV_IO_BOUNCE_COEFF_OFFSET)	// Starting speed in other direction
#define NV_IO_BOUNCE_PULL_SPEED(i)         (NV_IO_START + NVS_PER_IO*(i) + NV_IO_BOUNCE_PULL_SPEED_OFFSET)
#define NV_IO_BOUNCE_PULL_PAUSE(i)         (NV_IO_START + NVS_PER_IO*(i) + NV_IO_BOUNCE_PULL_PAUSE_OFFSET)

#define NV_IO_MULTI_NUM_POS_OFFSET      2U
#define NV_IO_MULTI_POS1_OFFSET         3U
#define NV_IO_MULTI_POS2_OFFSET         4U
#define NV_IO_MULTI_POS3_OFFSET         5U
#define NV_IO_MULTI_POS4_OFFSET         6U
#define NV_IO_MULTI_NUM_POS(i)          (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MULTI_NUM_POS_OFFSET)
#define NV_IO_MULTI_POS1(i)             (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MULTI_POS1_OFFSET)
#define NV_IO_MULTI_POS2(i)             (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MULTI_POS2_OFFSET)
#define NV_IO_MULTI_POS3(i)             (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MULTI_POS3_OFFSET)
#define NV_IO_MULTI_POS4(i)             (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MULTI_POS4_OFFSET)
 
#define NV_IO_ANALOGUE_THRESHOLD        3U
#define NV_IO_ANALOGUE_HYSTERESIS       4U
#define NV_IO_ANALOGUE_THRES(i)         (NV_IO_START + NVS_PER_IO*(i) + NV_IO_ANALOGUE_THRESHOLD)
#define NV_IO_ANALOGUE_HYST(i)          (NV_IO_START + NVS_PER_IO*(i) + NV_IO_ANALOGUE_HYSTERESIS)
 
#define NV_IO_MAGNET_DOSETUP          2U
#define NV_IO_MAGNET_THRESHOLD        3U
#define NV_IO_MAGNET_HYSTERESIS       4U
#define NV_IO_MAGNET_OFFSET_H         5U
#define NV_IO_MAGNET_OFFSET_L         6U
#define NV_IO_MAGNET_SETUP(i)         (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MAGNET_DOSETUP)
#define NV_IO_MAGNET_THRES(i)         (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MAGNET_THRESHOLD)
#define NV_IO_MAGNET_HYST(i)          (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MAGNET_HYSTERESIS)
#define NV_IO_MAGNET_OFFSETH(i)       (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MAGNET_OFFSET_H)
#define NV_IO_MAGNET_OFFSETL(i)       (NV_IO_START + NVS_PER_IO*(i) + NV_IO_MAGNET_OFFSET_L)
    
#define IS_NV_TYPE(i)                   (((i-NV_IO_START) % NVS_PER_IO) == 0)
#define IO_NV(i)                        ((unsigned char)((i-NV_IO_START)/NVS_PER_IO))
#define NV_NV(i)                        ((unsigned char)((i-NV_IO_START) % NVS_PER_IO))
  
// the types
#define TYPE_INPUT                  0U
#define TYPE_OUTPUT                 1U
#define TYPE_SERVO                  2U
#define TYPE_BOUNCE                 3U
#define TYPE_MULTI                  4U
#define TYPE_ANALOGUE_IN            5U
#define TYPE_MAGNET                 6U

// the flags
#define	FLAG_TRIGGER_INVERTED       0x01U	// Whether the sense of this input or output inverted
#define	FLAG_CUTOFF                 0x02U	// Whether the servo cut off after 1 second once it has reached its target position
#define	FLAG_STARTUP                0x04U	// Whether this output be changed on module start to match values in EE_OP_STATE
#define FLAG_DISABLE_OFF            0x08U   // Whether off events are generated
#define FLAGS_TOGGLE                0x10U   // whether an INPUT operates as a pushbutton toggle
#define FLAG_PULLUP                 0x10U   // Start servos high or low. Reuse Toggle flag
#define FLAG_RESULT_ACTION_INVERTED 0x20U   // whether the resulting action is inverted
#define	FLAG_INPUT_DISABLE_SOD_RESPONSE 0x20U// Whether this input, magnet or analogue channel responds to SOD
#define FLAG_RESULT_EVENT_INVERTED  0x40U   // whether the generated event is inverted
#define FLAG_EXPEDITED_ACTIONS      0x80U   // whether consumed actions are expedited

typedef struct {
    unsigned char type;
    unsigned char flags;
    union {
        struct {
            unsigned char input_on_delay;
            unsigned char input_off_delay;
        } nv_input;
        struct {
            unsigned char output_pulse_duration;
            unsigned char output_flash_period;
        } nv_output;
        struct {
            unsigned char servo_start_pos;
            unsigned char servo_end_pos;
            unsigned char servo_se_speed;
            unsigned char servo_es_speed;
        } nv_servo;
        struct {
            unsigned char bounce_upper_pos;
            unsigned char bounce_lower_pos;
            unsigned char bounce_coeff;
            unsigned char bounce_pull_speed;
            unsigned char bounce_pull_pause;
        } nv_bounce;
        struct {
            unsigned char multi_num_pos;
            unsigned char multi_pos1;
            unsigned char multi_pos2;
            unsigned char multi_pos3;
            unsigned char multi_pos4;
        } nv_multi;
        struct {
            unsigned char analogue_unused;
            unsigned char analogue_threshold;
            unsigned char analogue_hysteresis;
        } nv_analogue_in;
        struct {
            unsigned char magnet_setup;
            unsigned char magnet_threshold;
            unsigned char magnet_hysteresis;
            unsigned char magnet_offset_h;
            unsigned char magnet_offset_l;
        } nv_magnet;
    } nv_io;
} NvIo;

/*
 * This structure is required by FLiM.h
 */
typedef struct {
        BYTE nv_version;                // version of NV structure
        BYTE sendSodDelay;               // Time after start in 100mS (plus 2 seconds) to send an automatic SoD. Set to zero for no auto SoD
        BYTE hbDelay;                    // Interval in 100mS for automatic heartbeat. Set to zero for no heartbeat.
        BYTE servo_speed;               // default servo speed
        BYTE pullups;                   // weak pullup resistors
        BYTE responseDelay;             // timing of multiple responses
        BYTE spare[10];
        NvIo io[NUM_IO];                 // config for each IO
} ModuleNvDefs;

#define NV_NUM  sizeof(ModuleNvDefs)     // Number of node variables
#ifdef __18F25K80
#define AT_NV   0x7F80U                  // Where the NVs are stored. (_ROMSIZE - 128)  Size=128 bytes
#endif
#ifdef __18F26K80
#define AT_NV   0xFF80U                  // Where the NVs are stored. (_ROMSIZE - 128)  Size=128 bytes
#endif

extern void mioNvInit(void);
extern unsigned int getNodeVar(unsigned int index);
extern void setNodeVar(unsigned int index, unsigned int value);
extern BOOL validateNV(BYTE nvIndex, BYTE oldValue, BYTE value);
void actUponNVchange(unsigned char index, unsigned char oldValue, unsigned char value);
extern void defaultNVs(unsigned char i, unsigned char type);        


#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_NODE_VARAIABLES_H */

