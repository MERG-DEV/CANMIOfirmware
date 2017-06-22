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


#ifdef	__cplusplus
}
#endif

#endif	/* BOUNCE_H */

