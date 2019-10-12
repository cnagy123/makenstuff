/*
 * uart2.h
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#ifndef INC_UART2_H_
#define INC_UART2_H_

#include "includes.h"

extern UART_HandleTypeDef huart2;
extern uint8_t *uart2_pBufferReadyforProcessing;

void uart2Task(void);
void uart2CharReceptionCallback(void);
void uart2SendData(uint8_t *String, uint32_t Size);
void uart2InitReception(void);


#endif /* INC_UART2_H_ */
