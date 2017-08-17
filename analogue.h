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


#ifdef	__cplusplus
}
#endif

#endif	/* ANALOGUE_H */

