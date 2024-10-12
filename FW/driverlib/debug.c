#include <string.h>
#include <stdio.h>
#include "main.h"
#include "debug.h"

UART_HandleTypeDef *hDebugUart;

#define MAX_BUFF_LEN 2024
//#define MAX_BUFF_LEN 63
uint8_t buffer[MAX_BUFF_LEN];

RingBuf_t ringBuf = {.buf = buffer, .head = 0, .tail = 0};

// UART Tx complete callback
void Debug_TxCpltCallback(UART_HandleTypeDef *huart) {
  debugNext();
}

void Debug_Init(UART_HandleTypeDef *huart) {
  hDebugUart = huart;
  if (HAL_UART_RegisterCallback(huart, HAL_UART_TX_COMPLETE_CB_ID, Debug_TxCpltCallback) != HAL_OK) {
    Error_Handler();
  }
}


void debugNext(void) {
  if(ringBuf.head != ringBuf.tail) {
    if(ringBuf.tail < ringBuf.head) {
      HAL_UART_Transmit_IT(hDebugUart, &ringBuf.buf[ringBuf.tail], ringBuf.head - ringBuf.tail);
      ringBuf.tail = ringBuf.head;
    } else {
      // send rest
      HAL_UART_Transmit_IT(hDebugUart, &ringBuf.buf[ringBuf.tail], MAX_BUFF_LEN - ringBuf.tail);
      ringBuf.tail = 0;
    }
  }
}

void debugSend(uint8_t* dat, uint16_t len) {
  // TODO fix buffer under load

  // send first char if not sending
  uint16_t poi = 0;
  if(hDebugUart->gState == HAL_UART_STATE_READY)	{
    HAL_UART_Transmit_IT(hDebugUart, (uint8_t*)dat, 1);
    poi++;
    len--;
  }

  // fill circular buffer
  for(uint16_t i=0; i<len; i++) {
    ringBuf.buf[ringBuf.head++] = dat[poi++];
    if(ringBuf.head >= MAX_BUFF_LEN)
      ringBuf.head = 0;
  }
}

void Debug(char* tag, char* text) {
  char buf[150];

  if((strlen(tag) + strlen(text) + 8 + 2 + 2) > sizeof(buf)) {
    // TODO fix overload
    return;
  }

  sprintf(buf, "%08ld|%s|%s\r\n", HAL_GetTick(), tag, text);
  debugSend((uint8_t*)buf, strlen(buf));
}

// stdio callback for printf()
int _write(int file, char *ptr, int len) {
  debugSend((uint8_t*)ptr, len);
  return len;
}
