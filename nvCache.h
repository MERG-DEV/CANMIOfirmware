/* 
 * File:   nvCache.h
 * Author: Ian
 *
 * Created on 03 June 2017, 01:39
 */

#ifndef NVCACHE_H
#define	NVCACHE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "module.h"
#include "mioNv.h"
    
extern ModuleNvDefs * NVC;

extern void loadCache();

extern void writeCache();


#ifdef	__cplusplus
}
#endif

#endif	/* NVCACHE_H */

