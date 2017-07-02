/* 
 * File:   bounce.h
 * Author: Ian
 *
 * Created on 22 June 2017, 21:49
 */

#ifndef BOUNCE_H
#define	BOUNCE_H

#ifdef	__cplusplus
extern "C" {
#endif

extern void initBounce(unsigned char io);
extern BOOL bounceDown(unsigned char io);
extern BOOL bounceUp(unsigned char io);
/**
 * Indicates how fast the virtual signal operator pulls the signal on.
 */
#define PULL_SPEED 12

#ifdef	__cplusplus
}
#endif

#endif	/* BOUNCE_H */

