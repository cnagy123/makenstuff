/*
 * mainApp.c
 *
 *  Created on: Sep 10, 2019
 *      Author: chris
 */

#include "mainApp.h"

typedef enum {
	IDLE,
	WAIT_FOR_CMD,
	SET_LIDAR_MOTOR_ON,
	SET_LIDAR_MOTOR_OFF,
	GET_LIDAR_INFO,
	LIDAR_SCAN_START,
}states;

states state = WAIT_FOR_CMD;
struct MainApp app;

states executeCommand(commands cmd);
states mainApp(states state);

void mainAppInit(void){

	memset(app.printBuffer, 0, sizeof(app.printBuffer));
	app.printFlag = 0;

	app.command = DO_NOTHING;
}


void mainAppTask(void){
	state = mainApp(state);
   }

states mainApp(states state)
{
	states next_state;

	switch(state){
	case IDLE:
		next_state = IDLE;
		break;
	case WAIT_FOR_CMD:
		if (app.command != DO_NOTHING){
			next_state = executeCommand(app.command);
		}else{
			next_state = WAIT_FOR_CMD;
		}
		break;
	case SET_LIDAR_MOTOR_ON:
		lidarMotorOn();
		app.command = DO_NOTHING; // reset command
		next_state = WAIT_FOR_CMD;
		break;
	case SET_LIDAR_MOTOR_OFF:
		lidarMotorOff();
		app.command = DO_NOTHING; // reset command
		next_state = WAIT_FOR_CMD;
		break;
	case GET_LIDAR_INFO:
		lidarGetInfo();
		app.command = DO_NOTHING; // reset command
		next_state = WAIT_FOR_CMD;
		break;
	case LIDAR_SCAN_START:
		lidarScan();
		app.command = DO_NOTHING; // reset command
		next_state = WAIT_FOR_CMD;
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
	case LIDAR_START_SCAN:
		next_state = LIDAR_SCAN_START;
		break;

	default:
		break;
	}

	return next_state;
}