/*
 * mainApp.h
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#ifndef INC_MAINAPP_H_
#define INC_MAINAPP_H_

#include "main.h"

extern osThreadId mainAppTaskHandle;
extern osMutexId mainAppMutexHandle;
extern osSemaphoreId appSemHandle;

typedef enum {
	DO_NOTHING,
	LIDAR_MOTOR_ON,
	LIDAR_MOTOR_OFF,
	LIDAR_GET_INFO,
	LIDAR_START_SCAN,
}commands;

typedef struct {
	uint8_t start_flag1;
	uint8_t start_flag2;
	unsigned data_response_length : 30;
	unsigned send_mode: 2;
	uint8_t data_type;
}lidarResponse;

typedef struct {
	uint8_t model;
	uint8_t firmware_minor;
	uint8_t firmware_major;
	uint8_t hardware;
	uint8_t serial[16];
}lidarInfo;

struct MainApp{

	uint8_t		printBuffer[50];
	uint32_t	lidar_motor_state;
	uint32_t	mainLED;
	commands	command;
	lidarResponse response;
	lidarInfo info;
};

extern struct MainApp app;

void MainAppTask(void const * argument);

#endif /* INC_MAINAPP_H_ */
