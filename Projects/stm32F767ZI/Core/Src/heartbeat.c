/*
 * heartbeat.c
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#include "heartbeat.h"

osThreadId heartbeatTaskHandle;

void HeartbeatTask(void const * argument)
{
	for(;;)
	{
		HAL_GPIO_TogglePin(LD1_GPIO_Port,LD1_Pin);
		osDelay(500);
	}
}

