/*
 * lidar.c
 *
 *  Created on: Sep 3, 2019
 *      Author: chris
 */

#include "lidar.h"

osThreadId lidarTaskHandle;
osMessageQId lidarQueueHandle;
osMutexId lidarMutexHandle;

void LidarTask(void const * argument)
{
  for(;;)
  {
    osDelay(1);
  }
}

void LidarMotorOn(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
}

void LidarMotorOff(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
}
