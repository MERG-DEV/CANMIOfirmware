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
#define SETUP_NONE              0
#define SETUP_REPORT            1
#define SETUP_REPORT_AND_SAVE   2

// Event states
extern unsigned char eventState[NUM_IO];
#define ANALOGUE_EVENT_OFF      0
#define ANALOGUE_EVENT_LOWER    1
#define ANALOGUE_EVENT_UPPER    2


#ifdef	__cplusplus
}
#endif

#endif	/* ANALOGUE_H */

