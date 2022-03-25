/* 
 * File:   analogue.h
 * Author: Ian
 *
 * Created on 17 August 2017, 06:58
 */

#ifndef ANALOGUE_H
#define	ANALOGUE_H

#ifdef	__cplusplus
extern "C" {
#endif

extern void initAnalogue(void);   
extern void initAnaloguePort(unsigned char io);
extern void pollAnalogue(void);

extern unsigned char setupIo;
extern unsigned char setupState;

//setup states
#define SETUP_NONE              0U
#define SETUP_REPORT            1U
#define SETUP_REPORT_AND_SAVE   2U

// Analogue states
typedef struct {
    unsigned char eventState:2;
    unsigned char portState:1;
} AnalogueStates;
extern AnalogueStates analogueState[NUM_IO]; 
// Event state
#define ANALOGUE_EVENT_OFF      0U
#define ANALOGUE_EVENT_LOWER    1U
#define ANALOGUE_EVENT_UPPER    2U
// Port state
#define ANALOGUE_PORT_INITIALISING      0U   // Just after port is set to analogue so we don't report event due to analogue vaue changing
#define ANALOGUE_PORT_READY             1U   // report changes in analogue voltage 


#ifdef	__cplusplus
}
#endif

#endif	/* ANALOGUE_H */

