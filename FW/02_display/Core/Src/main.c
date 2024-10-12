#include <stdio.h>

#include "main.h"
#include "systemclock.h"
#include "heartbeat.h"
#include "usart1.h"
#include "debug.h"

#include "kaldeslogo.h"

static void Display_DemoDescription(void) {

  BSP_LCD_SelectLayer(LTDC_ACTIVE_LAYER);

  BSP_LCD_SetFont(&Font24);
  BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
  BSP_LCD_Clear(LCD_COLOR_WHITE);
  BSP_LCD_SetTextColor(LCD_COLOR_DARKBLUE);
  BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"STM32F746G BSP", CENTER_MODE);
  BSP_LCD_DisplayStringAt(0, 35, (uint8_t *)"Drivers examples", CENTER_MODE);

  BSP_LCD_DrawBitmap((BSP_LCD_GetXSize() - 80) / 2, 65, (uint8_t *)kaldeslogo);

  BSP_LCD_SetFont(&Font12);
  BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() - 18, (uint8_t *)"Copyright (c) STMicroelectronics 2015", CENTER_MODE);

  BSP_LCD_SetFont(&Font16);
  BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
  BSP_LCD_FillRect(0, BSP_LCD_GetYSize() / 2 + 45, BSP_LCD_GetXSize(), 60);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
  BSP_LCD_DisplayStringAt(0, BSP_LCD_GetYSize() / 2 + 60, (uint8_t *)"Press User Button to start :", CENTER_MODE);
}

int main(void) {
  init();

  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(LTDC_ACTIVE_LAYER, LCD_FRAME_BUFFER);
  Display_DemoDescription();

  printf("Display test\r\n");

  while (1) {
    HeartBeat_Toggle();
    HAL_Delay(250);
  }
}

void init(void) {
  MPU_Config();
  CPU_CACHE_Enable();
  HAL_Init();
  SystemClock_Config();
  HeartBeat_Init();
  USART1_Init();
  Debug_Init(&huart1);
}

void Error_Handler(void) {
  __disable_irq();
  while (1) {
  }
}
