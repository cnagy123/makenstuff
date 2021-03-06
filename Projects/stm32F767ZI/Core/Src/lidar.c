/*
 * lidar.c
 *
 *  Created on: Sep 3, 2019
 *      Author: chris
 */

#include "lidar.h"

osThreadId lidarTaskHandle;
osMessageQId lidarQueueHandle;
osMutexId lidarMutexHandle;



void LidarTask(void const * argument)
{
  for(;;)
  {
    osDelay(1);
  }
}

void LidarMotorOn(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
	if(osSemaphoreWait(appSemHandle,0)==osOK){
		app.lidar_motor_state = 1;
		osSemaphoreRelease(appSemHandle);
	}
}

void LidarMotorOff(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
	if(osSemaphoreWait(appSemHandle,0)==osOK){
		app.lidar_motor_state = 0;
		osSemaphoreRelease(appSemHandle);
	}
}

void LidarGetInfo(void)
{
	unsigned long val = 27;//LIDAR_RESPONSE_SIZE;
	uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_GET_INFO};
	xQueueSend(uart2QueueIn, &val, 0U );	// send the buffer size
	Uart2SendData(lidar_command, sizeof(lidar_command));
	xQueueReceive(uart2QueueOut, &val, 0xFFFFFFFF );
	if(val == 1){
		if(osSemaphoreWait(uart2SemHandle,0)==osOK){
			if(osSemaphoreWait(appSemHandle,0)==osOK){
				app.response.start_flag1 = uart2_pBufferReadyforProcessing[0];
				app.response.start_flag2 = uart2_pBufferReadyforProcessing[1];
				app.response.data_response_length = ((uart2_pBufferReadyforProcessing[5]<<26) | (uart2_pBufferReadyforProcessing[4]<<16) | (uart2_pBufferReadyforProcessing[3]<<8) | (uart2_pBufferReadyforProcessing[2]));
				app.response.send_mode = (uart2_pBufferReadyforProcessing[5]<<6);
				app.response.data_type = uart2_pBufferReadyforProcessing[6];
				app.info.model = uart2_pBufferReadyforProcessing[7];
				app.info.firmware_minor = uart2_pBufferReadyforProcessing[8];
				app.info.firmware_major = uart2_pBufferReadyforProcessing[9];
				app.info.hardware = uart2_pBufferReadyforProcessing[10];
				app.info.serial[0] = uart2_pBufferReadyforProcessing[11];
				app.info.serial[1] = uart2_pBufferReadyforProcessing[12];
				app.info.serial[2] = uart2_pBufferReadyforProcessing[13];
				app.info.serial[3] = uart2_pBufferReadyforProcessing[14];
				app.info.serial[4] = uart2_pBufferReadyforProcessing[15];
				app.info.serial[5] = uart2_pBufferReadyforProcessing[16];
				app.info.serial[6] = uart2_pBufferReadyforProcessing[17];
				app.info.serial[7] = uart2_pBufferReadyforProcessing[18];
				app.info.serial[8] = uart2_pBufferReadyforProcessing[19];
				app.info.serial[9] = uart2_pBufferReadyforProcessing[20];
				app.info.serial[10] = uart2_pBufferReadyforProcessing[21];
				app.info.serial[11] = uart2_pBufferReadyforProcessing[22];
				app.info.serial[12] = uart2_pBufferReadyforProcessing[23];
				app.info.serial[13] = uart2_pBufferReadyforProcessing[24];
				app.info.serial[14] = uart2_pBufferReadyforProcessing[25];
				app.info.serial[15] = uart2_pBufferReadyforProcessing[26];
				osSemaphoreRelease(appSemHandle);
			}
			osSemaphoreRelease(uart2SemHandle);
		}
	}
}

void LidarScan(void)
{
	unsigned long val = 7;
	uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_SCAN};
	LidarMotorOn();
	xQueueSend(uart2QueueIn, &val, 0U );	// send the buffer size
	Uart2SendData(lidar_command, sizeof(lidar_command));
	xQueueReceive(uart2QueueOut, &val, 0xFFFFFFFF );
	if(val == 1){
		if(osSemaphoreWait(uart2SemHandle,0)==osOK){
			if(osSemaphoreWait(appSemHandle,0)==osOK){
				app.response.start_flag1 = uart2_pBufferReadyforProcessing[0];
				app.response.start_flag2 = uart2_pBufferReadyforProcessing[1];
				app.response.data_response_length = ((uart2_pBufferReadyforProcessing[5]<<26) | (uart2_pBufferReadyforProcessing[4]<<16) | (uart2_pBufferReadyforProcessing[3]<<8) | (uart2_pBufferReadyforProcessing[2]));
				app.response.send_mode = (uart2_pBufferReadyforProcessing[5]<<6);
				app.response.data_type = uart2_pBufferReadyforProcessing[6];
				osSemaphoreRelease(appSemHandle);
			}
			osSemaphoreRelease(uart2SemHandle);
		}
	}
}
