/*
 * printInfo.c
 *
 *  Created on: Sep 10, 2019
 *      Author: chris
 */


#include "printInfo.h"

void printInfoTask(void){
	if(app.printFlag == 1){
		printf("%s", app.printBuffer);
		memset(app.printBuffer, 0, sizeof(app.printBuffer));
		app.printFlag = 0;
	}
	HAL_GPIO_TogglePin(GPIOB, LD3_Pin);
}

void print2Console(char * printThis){
	sprintf((char *)app.printBuffer, printThis);
	app.printFlag = 1;
}
