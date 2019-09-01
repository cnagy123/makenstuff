/*
 * lidar.h
 *
 *  Created on: Aug 27, 2019
 *      Author: chris
 */

#ifndef SRC_LIDAR_H_
#define SRC_LIDAR_H_

#include "includes.h"

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

#define LIDAR_RESPONSE_DESCRIPTOR_SIZE	7

typedef struct {
	uint8_t start_flag1;
	uint8_t start_flag2;
	unsigned data_response_length : 30;
	unsigned send_mode: 2;
	uint8_t data_type;
}lidarResponse;


typedef enum {
	SM_RESET,
	IDLE,
	SCAN,
	MOTOR_ON,
	MOTOR_OFF,
	STOP,
	START,
	GET_INFO,
}lidar_states;

#define LIDAR_ACTION_FLAG_DO_NOTHING		0x00000000
#define LIDAR_ACTION_FLAG_TURN_ON_MOTOR		0x00000001

void LidarTask(void const * argument);
void USART_CharReception_CallbackX(void);



#endif /* SRC_LIDAR_H_ */
