/*
 * mainApp.c
 *
 *  Created on: Sep 10, 2019
 *      Author: chris
 */

#include "mainApp.h"

typedef enum {
	IDLE,
	WAIT_FOR_CMD,
	SET_LIDAR_MOTOR_ON,
	SET_LIDAR_MOTOR_OFF,
	GET_LIDAR_INFO,
	LIDAR_SCAN_START,
}states;

states state = WAIT_FOR_CMD;
struct MainApp app;

states executeCommand(commands cmd);
states mainApp(states state);

/********************************
 *
 * FATFS Stuff
 *
 ********************************/
FATFS SDFatFs;  /* File system object for SD disk logical drive */
FIL MyFile;     /* File object */
char SDPath[4]; /* SD disk logical drive path */
uint8_t workBuffer[_MAX_SS];

void mainAppInit(void){

//	FRESULT res;                                          /* FatFs function common result code */
//	uint32_t byteswritten, bytesread;                     /* File write/read counts */
//	uint8_t wtext[] = "This is STM32 working with FatFs"; /* File write buffer */
//	uint8_t rtext[100];                                   /* File read buffer */
//	/*##-1- Link the SD disk I/O driver ########################################*/
//	if(FATFS_LinkDriver(&SD_Driver, SDPath) == 0)
//	{
//	 /*##-2- Register the file system object to the FatFs module ##############*/
//	 if(f_mount(&SDFatFs, (TCHAR const*)SDPath, 0) != FR_OK)
//	 {
//	   /* FatFs Initialization Error */
//	   BSP_LED_On(LED_RED);
//	   Error_Handler();
//	 }
//	 else
//	 {
//	   /*##-3- Create a FAT file system (format) on the logical drive #########*/
//	   if(f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, workBuffer, sizeof(workBuffer)) != FR_OK)
//	   {
//		 BSP_LED_On(LED_RED);
//		 Error_Handler();
//	   }
//	   else
//	   {
//		 /*##-4- Create and Open a new text file object with write access #####*/
//		 if(f_open(&MyFile, "STM32.TXT", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
//		 {
//		   /* 'STM32.TXT' file Open for write Error */
//		   BSP_LED_On(LED_RED);
//		   Error_Handler();
//		 }
//		 else
//		 {
//		   /*##-5- Write data to the text file ################################*/
//		   res = f_write(&MyFile, wtext, sizeof(wtext), (void *)&byteswritten);
//
//		   if((byteswritten == 0) || (res != FR_OK))
//		   {
//			 /* 'STM32.TXT' file Write or EOF Error */
//			 BSP_LED_On(LED_RED);
//			 Error_Handler();
//		   }
//		   else
//		   {
//			 /*##-6- Close the open text file #################################*/
//			 f_close(&MyFile);
//
//			 /*##-7- Open the text file object with read access ###############*/
//			 if(f_open(&MyFile, "STM32.TXT", FA_READ) != FR_OK)
//			 {
//			   /* 'STM32.TXT' file Open for read Error */
//			   BSP_LED_On(LED_RED);
//			   Error_Handler();
//			 }
//			 else
//			 {
//			   /*##-8- Read data from the text file ###########################*/
//			   res = f_read(&MyFile, rtext, sizeof(rtext), (UINT*)&bytesread);
//
//			   if((bytesread == 0) || (res != FR_OK)) /* EOF or Error */
//			   {
//				 /* 'STM32.TXT' file Read or EOF Error */
//				 BSP_LED_On(LED_RED);
//				 Error_Handler();
//			   }
//			   else
//			   {
//				 /*##-9- Close the open text file #############################*/
//				 f_close(&MyFile);
//
//				 /*##-10- Compare read data with the expected data ############*/
//				 if ((bytesread != byteswritten))
//				 {
//				   /* Read data is different from the expected data */
//				   BSP_LED_On(LED_RED);
//				   Error_Handler();
//				 }
//				 else
//				 {
//				   /* Success of the demo: no error occurrence */
//				   BSP_LED_On(LED_GREEN);
//				 }
//			   }
//			 }
//		   }
//		 }
//	   }
//	 }
//	}
//
//	/*##-11- Unlink the SD disk I/O driver ####################################*/
//	FATFS_UnLinkDriver(SDPath);


	memset(app.printBuffer, 0, sizeof(app.printBuffer));
	app.printFlag = 0;

	app.command = DO_NOTHING;


}


void mainAppTask(void){
	state = mainApp(state);
   }

states mainApp(states state)
{
	states next_state;

	switch(state){
	case IDLE:
		next_state = IDLE;
		break;
	case WAIT_FOR_CMD:
		if (app.command != DO_NOTHING){
			next_state = executeCommand(app.command);
		}else{
			next_state = WAIT_FOR_CMD;
		}
		break;
	case SET_LIDAR_MOTOR_ON:
		lidarMotorOn();
		app.command = DO_NOTHING; // reset command
		next_state = WAIT_FOR_CMD;
		break;
	case SET_LIDAR_MOTOR_OFF:
		lidarMotorOff();
		app.command = DO_NOTHING; // reset command
		next_state = WAIT_FOR_CMD;
		break;
	case GET_LIDAR_INFO:
		lidarGetInfo();
		app.command = DO_NOTHING; // reset command
		next_state = WAIT_FOR_CMD;
		break;
	case LIDAR_SCAN_START:
		lidarScan();
		app.command = DO_NOTHING; // reset command
		next_state = WAIT_FOR_CMD;
		break;
	default:
		next_state = IDLE;
		break;
	};

	return next_state;

}

states executeCommand(commands cmd)
{
	states next_state = IDLE;

	switch(cmd){
	case DO_NOTHING:
		next_state = WAIT_FOR_CMD;
		break;
	case LIDAR_MOTOR_ON:
		next_state = SET_LIDAR_MOTOR_ON;
		break;
	case LIDAR_MOTOR_OFF:
		next_state = SET_LIDAR_MOTOR_OFF;
		break;
	case LIDAR_GET_INFO:
		next_state = GET_LIDAR_INFO;
		break;
	case LIDAR_START_SCAN:
		next_state = LIDAR_SCAN_START;
		break;

	default:
		break;
	}

	return next_state;
}
