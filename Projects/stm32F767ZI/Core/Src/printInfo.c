/*
 * printInfo.c
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#include "printInfo.h"

osThreadId printInfoTaskHandle;
osMessageQId printInfoQueueHandle;

UART_HandleTypeDef huart3;

// Redirect printf to USART3
int __io_putchar(int ch){
	HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 0xFFFF);
	return ch;
}

void PrintInfoTask(void const * argument)
{
	for(;;)
	{
		if(osSemaphoreWait(appSemHandle,0)==osOK)
		{
			if(app.printBuffer[0] != '\0')
			{
				printf("%s", app.printBuffer);
				memset(app.printBuffer, 0, sizeof(app.printBuffer));
			}else{
				__NOP();
			}
			osSemaphoreRelease(appSemHandle);
		}

	}
}

void print2Console(char * printThis)
{
	if(osSemaphoreWait(appSemHandle,0)==osOK)
	{
		sprintf((char *)app.printBuffer, printThis);
		osSemaphoreRelease(appSemHandle);
	}
}


