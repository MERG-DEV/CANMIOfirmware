/* 
 * File:   config.h
 * Author: Ian
 * 
 * This file contains the structure definition for a pin configuration. It 
 * provides the mapping between IO, Pin, Port/bit no.
 *
 * Created on 10 April 2017, 19:31
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

 // General purpose pin usage
typedef struct {
    unsigned char pin;
    char port;
    unsigned char no;
} Config;

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

