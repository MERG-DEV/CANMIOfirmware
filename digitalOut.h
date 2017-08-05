/* 
 * File:   digitalOut.h
 * Author: Ian
 *
 * Created on 05 August 2017, 16:55
 */

#ifndef DIGITALOUT_H
#define	DIGITALOUT_H

#ifdef	__cplusplus
extern "C" {
#endif

extern void startDigitalOutput(unsigned char io, BOOL state);
extern void setDigitalOutput(unsigned char io, BOOL state);


#ifdef	__cplusplus
}
#endif

#endif	/* DIGITALOUT_H */

