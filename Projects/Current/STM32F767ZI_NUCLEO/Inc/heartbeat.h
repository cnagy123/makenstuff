/*
 * heartbeat.h
 *
 *  Created on: Sep 10, 2019
 *      Author: chris
 */

#ifndef HEARTBEAT_H_
#define HEARTBEAT_H_

#include "includes.h"

#define TIMx_CLK_ENABLE()              __HAL_RCC_TIM3_CLK_ENABLE()
#define TIMx_IRQn                      TIM3_IRQn

extern TIM_HandleTypeDef    timerHandle;

void heartbeatInit(void);
void heartbeatCB(void);
void secondHeartbeat(void);

#endif /* HEARTBEAT_H_ */
