/*
 * mainApp.h
 *
 *  Created on: Sep 10, 2019
 *      Author: chris
 */

#ifndef MAINAPP_H_
#define MAINAPP_H_

#include "includes.h"

typedef enum {
	DO_NOTHING,
	LIDAR_MOTOR_ON,
	LIDAR_MOTOR_OFF,
	LIDAR_GET_INFO,
	LIDAR_START_SCAN,
}commands;

typedef enum {
	STOP,
	LIDAR_IDLE,
	LIDAR_ERROR,
	GET_INFO,
	SCAN,
}lidarState;

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

typedef struct {
	uint16_t distance[360];
	uint16_t heading[360];
	uint8_t	quality[360];
}lidarScanData;

struct MainApp{
	uint32_t 		printFlag;
	uint8_t			printBuffer[50];
	uint32_t		lidar_motor_state;
	commands		command;
	lidarState		currentLidarState;
	lidarResponse 	response;
	lidarInfo 		info;
	lidarScanData	lidar;
};

extern struct MainApp app;
extern FATFS SDFatFs;  /* File system object for SD disk logical drive */
extern FIL MyFile;     /* File object */
extern char SDPath[4]; /* SD disk logical drive path */
extern uint8_t workBuffer[_MAX_SS];

void mainAppInit(void);
void mainAppTask(void);

#endif /* MAINAPP_H_ */
