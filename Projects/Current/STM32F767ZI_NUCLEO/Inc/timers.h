/*
 * timers.h
 *
 *  Created on: Sep 14, 2019
 *      Author: chris
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "includes.h"

void timersInit(void);
void timersIntEnable(void);
void TIM1_UP_TIM10_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void TIM6_DAC_IRQHandler(void);
void TIM7_IRQHandler(void);

#endif /* TIMERS_H_ */
