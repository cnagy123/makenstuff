/*
 * lidar.h
 *
 *  Created on: Sep 3, 2019
 *      Author: chris
 */

#ifndef INC_LIDAR_H_
#define INC_LIDAR_H_

#include "main.h"

extern osThreadId lidarTaskHandle;
extern osMessageQId lidarQueueHandle;
extern osMutexId lidarMutexHandle;

void LidarTask(void const * argument);
void LidarMotorOn(void);
void LidarMotorOff(void);

#endif /* INC_LIDAR_H_ */
