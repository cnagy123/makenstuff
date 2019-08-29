/*
 * lidar.h
 *
 *  Created on: Aug 27, 2019
 *      Author: chris
 */

#ifndef SRC_LIDAR_H_
#define SRC_LIDAR_H_

#include "includes.h"

#define LIDAR_RX_BUFFER_SIZE   		7

#define LIDAR_START_BYTE			0xA5
#define LIDAR_RESPONSE_DESCRIPTOR	0x5A

#define LIDAR_CMD_STOP				0x25
#define LIDAR_CMD_RESET				0x40
#define LIDAR_CMD_SCAN				0x20
#define LIDAR_CMD_EXP_SCAN			0x82
#define LIDAR_CMD_FORCE_SCAN		0x21
#define LIDAR_CMD_GET_INFO			0x50
#define LIDAR_CMD_GET_HEALTH		0x52
#define LIDAR_CMD_GET_SAMPLERATE	0x59
#define LIDAR_CMD_GET_LIDAR_CONF	0x84

void CmdlineTaskX(void const * argument);
void USART_CharReception_CallbackX(void);



#endif /* SRC_LIDAR_H_ */
