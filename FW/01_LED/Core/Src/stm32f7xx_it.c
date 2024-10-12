#include "main.h"
#include "stm32f7xx_it.h"

//------------------------------------------------------------------------------
//           Cortex-M7 Processor Interruption and Exception Handlers
//------------------------------------------------------------------------------
void NMI_Handler(void) {
   while (1) { }
}

void HardFault_Handler(void) {
  while (1) { }
}

void MemManage_Handler(void) {
  while (1) { }
}

void BusFault_Handler(void) {
  while (1) { }
}

void UsageFault_Handler(void) {
  while (1) { }
}

void SVC_Handler(void) { }

void DebugMon_Handler(void) { }

void PendSV_Handler(void) { }

void SysTick_Handler(void) {
  HAL_IncTick();
}

//------------------------------------------------------------------------------
// STM32F7xx Peripheral Interrupt Handlers
// Add here the Interrupt Handlers for the used peripherals.
// For the available peripheral interrupt handler names,
// please refer to the startup file (startup_stm32f7xx.s).
//------------------------------------------------------------------------------

extern UART_HandleTypeDef huart1;
void USART1_IRQHandler(void) {
  HAL_UART_IRQHandler(&huart1);
}
