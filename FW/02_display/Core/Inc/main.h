#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f7xx_hal.h"

#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_sdram.h"

#define RGB565_BYTE_PER_PIXEL     2
#define ARBG8888_BYTE_PER_PIXEL   4

#define LCD_FRAME_BUFFER             SDRAM_DEVICE_ADDR
#define CAMERA_FRAME_BUFFER          ((uint32_t)(LCD_FRAME_BUFFER + (RK043FN48H_WIDTH * RK043FN48H_HEIGHT * ARBG8888_BYTE_PER_PIXEL)))
#define SDRAM_WRITE_READ_ADDR        ((uint32_t)(CAMERA_FRAME_BUFFER + (CAMERA_RES_MAX_X * CAMERA_RES_MAX_Y * RGB565_BYTE_PER_PIXEL)))
#define SDRAM_WRITE_READ_ADDR_OFFSET ((uint32_t)0x0800)
#define SRAM_WRITE_READ_ADDR_OFFSET  SDRAM_WRITE_READ_ADDR_OFFSET


void init(void);
void Error_Handler(void);

#define LED_HEARTBEAT_Pin          GPIO_PIN_1
#define LED_HEARTBEAT_GPIO_Port    GPIOI
#define LED_HEARTBEAT_CLK_ENABLE() __HAL_RCC_GPIOI_CLK_ENABLE()

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
