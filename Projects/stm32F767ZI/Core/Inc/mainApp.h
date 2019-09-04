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
}commands;

struct MainApp{
	commands	command;
	uint32_t	mainLED;
	uint8_t		printBuffer[50];
};

extern struct MainApp app;

void MainAppTask(void const * argument);

#endif /* INC_MAINAPP_H_ */
