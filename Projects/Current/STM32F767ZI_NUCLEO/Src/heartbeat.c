/*
 * heartbeat.c
 *
 *  Created on: Sep 10, 2019
 *      Author: chris
 */

#include "heartbeat.h"


void heartbeatCB(void){
	HAL_GPIO_TogglePin(GPIOB, LD1_Pin);
}

void secondHeartbeat(void){
	HAL_GPIO_TogglePin(GPIOB, LD2_Pin);
}
