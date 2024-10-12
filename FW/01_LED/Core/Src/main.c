#include <stdio.h>

#include "main.h"
#include "systemclock.h"
#include "heartbeat.h"
#include "usart1.h"
#include "debug.h"

int main(void) {
  init();

  printf("Hallo!\r\n");

  while (1) {
    HeartBeat_Toggle();
    HAL_Delay(250);
  }
}

void init(void) {
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
