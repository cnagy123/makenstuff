/*
 * lidar.h
 *
 *  Created on: Sep 3, 2019
 *      Author: chris
 */

#ifndef INC_LIDAR_H_
#define INC_LIDAR_H_

#include "main.h"

#define LIDAR_START_BYTE			0xA5

#define LIDAR_CMD_STOP				0x25
#define LIDAR_CMD_RESET				0x40
#define LIDAR_CMD_SCAN				0x20
#define LIDAR_CMD_EXP_SCAN			0x82
#define LIDAR_CMD_FORCE_SCAN		0x21
#define LIDAR_CMD_GET_INFO			0x50
#define LIDAR_CMD_GET_HEALTH		0x52
#define LIDAR_CMD_GET_SAMPLERATE	0x59
#define LIDAR_CMD_GET_LIDAR_CONF	0x84

#define LIDAR_RESPONSE_DESCRIPTOR	0x5A

#define LIDAR_RESPONSE_SIZE	27

extern osThreadId lidarTaskHandle;
extern osMessageQId lidarQueueHandle;
extern osMutexId lidarMutexHandle;

void LidarTask(void const * argument);
void LidarMotorOn(void);
void LidarMotorOff(void);
void LidarGetInfo(void);
void LidarScan(void);

#endif /* INC_LIDAR_H_ */
