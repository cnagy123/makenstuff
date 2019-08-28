/*
 * lidar.h
 *
 *  Created on: Aug 27, 2019
 *      Author: chris
 */

#ifndef SRC_LIDAR_H_
#define SRC_LIDAR_H_

#include "includes.h"

#define LIDAR_RX_BUFFER_SIZE   20

void CmdlineTaskX(void const * argument);
void USART_CharReception_CallbackX(void);



#endif /* SRC_LIDAR_H_ */
