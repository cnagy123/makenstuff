/*
 * uart2.h
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#ifndef INC_UART2_H_
#define INC_UART2_H_

#include "main.h"

#define UART2_RX_BUFFER_SIZE	128
#define UART2_QUEUE_LENGTH		1

extern osThreadId uart2Handle;
extern osSemaphoreId uart2SemHandle;
extern QueueHandle_t uart2QueueIn;
extern QueueHandle_t uart2QueueOut;
extern uint8_t *uart2_pBufferReadyforProcessing;

void Uart2Task(void const * argument);
void Uart2CharReceptionCallback(void);
void Uart2SendData(uint8_t *String, uint32_t Size);


#endif /* INC_UART2_H_ */
