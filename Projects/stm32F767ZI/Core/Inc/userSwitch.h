/*
 * userSwitch.h
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#ifndef INC_USERSWITCH_H_
#define INC_USERSWITCH_H_

#include "main.h"

extern osTimerId debounceTimerHandle;
extern osSemaphoreId debounceSemHandle;

void debounceTimerCallback(void const * argument);

#endif /* INC_USERSWITCH_H_ */
