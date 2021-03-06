/*
 * cmdLine.h
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#ifndef INC_CMDLINE_H_
#define INC_CMDLINE_H_

#include "main.h"

#define RX_BUFFER_SIZE			64

extern osThreadId cmdlineTaskHandle;
extern osMessageQId cmdLineQueueHandle;

void CmdlineTask(void const * argument);
void USART_CharReception_Callback(void);

#endif /* INC_CMDLINE_H_ */
