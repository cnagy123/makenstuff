/*
 * lidar.c
 *
 *  Created on: Sep 3, 2019
 *      Author: chris
 */

#include "lidar.h"


void lidarReset(void);

void lidarInit(void){

	uint32_t byteswritten;
	uint8_t wtext[] = "Quality,Heading,Distance\r\n"; /* File write buffer */

	/*##-1- Link the SD disk I/O driver ########################################*/
	FATFS_LinkDriver(&SD_Driver, SDPath);
	/*##-2- Register the file system objec*/
	f_mount(&SDFatFs, (TCHAR const*)SDPath, 0);
	/*##-3- Create a FAT file system (format) on the logical drive #########*/
	f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, workBuffer, sizeof(workBuffer));
	/*##-4- Create and Open a new text file object with write access #####*/
	f_open(&MyFile, "LIDAR_DATA.TXT", FA_CREATE_ALWAYS | FA_WRITE);
	/*##-5- Write data to the text file ################################*/
	f_write(&MyFile, wtext, sizeof(wtext), (void *)&byteswritten);

}

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
	uint32_t i;
	uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_SCAN};
	app.currentLidarState = SCAN;
	lidarMotorOn();
	uart2InitReception();
	for(i=0;i<10000;i++){
		__NOP();
	}
	uart2SendData(lidar_command, sizeof(lidar_command));

}

void lidarStop(void){
	uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_STOP};
	uart2SendData(lidar_command, sizeof(lidar_command));
//	lidarMotorOff();
}
void lidarReset(void){
	uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_RESET};
	uart2SendData(lidar_command, sizeof(lidar_command));
	lidarMotorOff();
	HAL_Delay(2);
}
