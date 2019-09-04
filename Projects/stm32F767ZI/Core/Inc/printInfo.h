/*
 * printInfo.h
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#ifndef INC_PRINTINFO_H_
#define INC_PRINTINFO_H_

#include "main.h"

extern osThreadId printInfoTaskHandle;
extern osMessageQId printInfoQueueHandle;

extern UART_HandleTypeDef huart3;

void PrintInfoTask(void const * argument);
void print2Console(char * printThis);

#endif /* INC_PRINTINFO_H_ */
