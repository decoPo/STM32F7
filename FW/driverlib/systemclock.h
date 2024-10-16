#ifndef __SYSTEMCLOCK_H__
#define __SYSTEMCLOCK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

extern void SystemClock_Config(void);
extern void CPU_CACHE_Enable(void);
extern void MPU_Config(void);

#ifdef __cplusplus
}
#endif
#endif /* __SYSTEMCLOCK_H__ */

