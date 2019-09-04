/*
 * imu.h
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#ifndef INC_IMU_H_
#define INC_IMU_H_

#include "main.h"

extern osThreadId imuTaskHandle;

void IMUTask(void const * argument);


#endif /* INC_IMU_H_ */
