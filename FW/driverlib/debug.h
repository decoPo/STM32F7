#ifndef INC_DEBUG_H_
#define INC_DEBUG_H_

typedef struct{
	uint8_t* buf;
	int16_t head;
	int16_t tail;
}RingBuf_t;

extern void Debug_Init(UART_HandleTypeDef *huart);
extern void debugNext(void);
extern void debugSend(uint8_t* dat, uint16_t len);

extern void Debug(char* tag, char* text);

#endif /* INC_DEBUG_H_ */
