/* 
 * File:   CDU.h
 * Author: Pete Brownlow
 *
 * Created on 28 January 2024
 */

#ifndef CDU_H
#define	CDU_H

#ifdef	__cplusplus
extern "C" {
#endif

    
extern void initCDU(void);
extern void processCDU(void);
extern void startCDU(unsigned char io, BOOL state);
extern void setCDUOutput(unsigned char io, BOOL state);
extern void setCDUOutputPin(unsigned char io, BOOL state);

#ifdef	__cplusplus
}
#endif

#endif	/* DIGITALOUT_H */

