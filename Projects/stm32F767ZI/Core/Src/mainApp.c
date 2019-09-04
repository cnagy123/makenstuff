/*
 * mainApp.c
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#include "mainApp.h"

osThreadId mainAppTaskHandle;
osMutexId mainAppMutexHandle;
osSemaphoreId appSemHandle;

typedef enum {
	IDLE,
	WAIT_FOR_CMD,
	SET_LIDAR_MOTOR_ON,
	SET_LIDAR_MOTOR_OFF,
	GET_LIDAR_INFO,
}states;

struct MainApp app;

void initMainApp(void);
states mainApp(states state);
states executeCommand(commands cmd);

void MainAppTask(void const * argument)
{
	states state = WAIT_FOR_CMD;

	initMainApp();

	for(;;)
	{
		state = mainApp(state);
	}
}

void initMainApp(void)
{
	if(osSemaphoreWait(appSemHandle,0)==osOK){
		app.command	= DO_NOTHING;
		app.mainLED = 0x00;
		memset(app.printBuffer, 0, sizeof(app.printBuffer));
		osSemaphoreRelease(appSemHandle);
	}

	print2Console("Enter a Command:\r\n");
}

states mainApp(states state)
{
	states next_state;
	commands cmd;

	switch(state){
	case IDLE:
		next_state = IDLE;
		break;
	case WAIT_FOR_CMD:
		xQueueReceive( cmdLineQueueHandle, &cmd, 0xFFFFFFFF );
		if(osSemaphoreWait(appSemHandle,0)==osOK){
			app.command = cmd;
			osSemaphoreRelease(appSemHandle);
		}
		next_state = executeCommand(cmd);
		break;
	case SET_LIDAR_MOTOR_ON:
		LidarMotorOn();
		next_state = WAIT_FOR_CMD;
		break;
	case SET_LIDAR_MOTOR_OFF:
		LidarMotorOff();
		next_state = WAIT_FOR_CMD;
		break;
	case GET_LIDAR_INFO:
		next_state = IDLE;
		break;
	default:
		next_state = IDLE;
		break;
	};

	return next_state;

}

states executeCommand(commands cmd)
{
	states next_state = IDLE;
	switch(cmd){
	case DO_NOTHING:
		next_state = WAIT_FOR_CMD;
		break;
	case LIDAR_MOTOR_ON:
		next_state = SET_LIDAR_MOTOR_ON;
		break;
	case LIDAR_MOTOR_OFF:
		next_state = SET_LIDAR_MOTOR_OFF;
		break;
	case LIDAR_GET_INFO:
		next_state = GET_LIDAR_INFO;
		break;
	default:
		break;
	}

	return next_state;
}
