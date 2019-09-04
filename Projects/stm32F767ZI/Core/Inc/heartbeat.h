/*
 * heartbeat.h
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#ifndef INC_HEARTBEAT_H_
#define INC_HEARTBEAT_H_

#include "main.h"

extern osThreadId heartbeatTaskHandle;
void HeartbeatTask(void const * argument);

#endif /* INC_HEARTBEAT_H_ */
