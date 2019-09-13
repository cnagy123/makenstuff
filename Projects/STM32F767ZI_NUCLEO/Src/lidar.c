/*
 * lidar.c
 *
 *  Created on: Sep 3, 2019
 *      Author: chris
 */

#include "lidar.h"

void lidarStop(void);
void lidarReset(void);

void lidarTask(void)
{
    HAL_Delay(1);
}

void lidarMotorOn(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
	app.lidar_motor_state = 1;
}

void lidarMotorOff(void)
{
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
	app.lidar_motor_state = 0;
}

void lidarGetInfo(void)
{
	app.currentLidarState = GET_INFO;
	uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_GET_INFO};
	uart2SendData(lidar_command, sizeof(lidar_command));
}

void lidarScan(void)
{
	uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_SCAN};
	app.currentLidarState = SCAN;
//	lidarReset();
//	lidarStop();
	lidarMotorOn();
	uart2SendData(lidar_command, sizeof(lidar_command));

}

void lidarStop(void){
	uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_STOP};
	uart2SendData(lidar_command, sizeof(lidar_command));
	lidarMotorOff();
}
void lidarReset(void){
	uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_RESET};
	uart2SendData(lidar_command, sizeof(lidar_command));
	lidarMotorOff();
	HAL_Delay(2);
}
