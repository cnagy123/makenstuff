/*
 * userSwitch.c
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */
#include "userSwitch.h"

osTimerId debounceTimerHandle;
osSemaphoreId debounceSemHandle;

/* debounceTimerCallback function */
void debounceTimerCallback(void const * argument)
{
  /* USER CODE BEGIN debounceTimerCallback */
	osSemaphoreRelease(debounceSemHandle);
  /* USER CODE END debounceTimerCallback */
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (GPIO_Pin == USER_Btn_Pin){												// check the pin
	  if(osSemaphoreWait(debounceSemHandle,0)==osOK){							// try to get semaphore
		  osTimerStart(debounceTimerHandle, 200);								// start debounce timer
		  HAL_GPIO_TogglePin(LD3_GPIO_Port,LD3_Pin);							// toggle the main LED
		  if(osSemaphoreWait(appSemHandle,0)==osOK){							// enter protection
			  app.mainLED = HAL_GPIO_ReadPin(LD3_GPIO_Port,LD3_Pin);			// get the LED State
			  osSemaphoreRelease(appSemHandle);									// exit protection
		  }
	  }
  }
}
