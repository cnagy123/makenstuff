/*
 * imu.c
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#include "imu.h"

osThreadId imuTaskHandle;

void IMUTask(void const * argument)
{
  /* USER CODE BEGIN IMUTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END IMUTask */
}
