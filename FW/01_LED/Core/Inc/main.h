#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f7xx_hal.h"

void init(void);
void Error_Handler(void);

#define LED_HEARTBEAT_Pin          GPIO_PIN_1
#define LED_HEARTBEAT_GPIO_Port    GPIOI
#define LED_HEARTBEAT_CLK_ENABLE() __HAL_RCC_GPIOI_CLK_ENABLE()

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
