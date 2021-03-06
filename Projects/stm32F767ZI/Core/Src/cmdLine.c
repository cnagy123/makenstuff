/*
 * cmdLine.c
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#include "cmdLine.h"

osThreadId cmdlineTaskHandle;
osMessageQId cmdLineQueueHandle;

uint8_t aRXBufferA[RX_BUFFER_SIZE];
uint8_t aRXBufferB[RX_BUFFER_SIZE];

volatile uint32_t     uwNbReceivedChars;
volatile uint32_t     uwBufferReadyIndication;

uint8_t *pBufferReadyForUser;
uint8_t *pBufferReadyForReception;

void InitCmdLine(void);
void HandleContinuousReception(void);
void UserDataTreatment(uint8_t *DataBuffer, uint32_t Size);

void CmdlineTask(void const * argument)
{
	InitCmdLine();

	for(;;)
	{
		HandleContinuousReception();
	}
}

void InitCmdLine(void){

	// Get the Buffers Ready
	pBufferReadyForReception = aRXBufferA;
	pBufferReadyForUser      = aRXBufferB;
	uwNbReceivedChars = 0;
	uwBufferReadyIndication = 0;

	/* Clear Overrun flag, in case characters have already been sent to USART */
	LL_USART_ClearFlag_ORE(USART3);

	/* Enable RXNE and Error interrupts */
	LL_USART_EnableIT_RXNE(USART3);
	LL_USART_EnableIT_ERROR(USART3);
}

void USART_CharReception_Callback(void)
{
	uint8_t *ptemp;
	uint8_t c;

  /* Read Received character. RXNE flag is cleared by reading of RDR register */
	c = LL_USART_ReceiveData8(USART3);
	pBufferReadyForReception[uwNbReceivedChars++] = c;

  /* Checks if Buffer full indication has been set */
  if ((uwNbReceivedChars >= RX_BUFFER_SIZE)||(c == '\r')||(c == '\n'))
  {
    /* Set Buffer swap indication */
    uwBufferReadyIndication = 1;

    /* Swap buffers for next bytes to be received */
    ptemp = pBufferReadyForUser;
    pBufferReadyForUser = pBufferReadyForReception;
    pBufferReadyForReception = ptemp;
    memset(pBufferReadyForReception, 0, RX_BUFFER_SIZE);
    uwNbReceivedChars = 0;
  }
}

void HandleContinuousReception(void)
{
  /* Checks if Buffer full indication has been set */
  if (uwBufferReadyIndication != 0)
  {
    /* Reset indication */
    uwBufferReadyIndication = 0;

    /* Call user Callback in charge of consuming data from filled buffer */
    UserDataTreatment(pBufferReadyForUser, sizeof(*pBufferReadyForUser));
  }
}

void UserDataTreatment(uint8_t *DataBuffer, uint32_t Size)
{
	commands cmd;

	if(!strcmp("lidar_motor_on\r", (char *)DataBuffer)){
		cmd = LIDAR_MOTOR_ON;
		xQueueSend( cmdLineQueueHandle, &cmd, 0U );
		print2Console("lidar_motor_on\r\n");
	}else if(!strcmp("lidar_motor_off\r", (char *)DataBuffer)){
		cmd = LIDAR_MOTOR_OFF;
		xQueueSend( cmdLineQueueHandle, &cmd , 0U );
		print2Console("lidar_motor_off\r\n");
	}else if(!strcmp("lidar_get_info\r", (char *)DataBuffer)){
		cmd = LIDAR_GET_INFO;
		xQueueSend( cmdLineQueueHandle, &cmd , 0U );
		print2Console("lidar_get_info\r\n");
	}else if(!strcmp("lidar_start_scan\r", (char *)DataBuffer)){
		cmd = LIDAR_START_SCAN;
		xQueueSend( cmdLineQueueHandle, &cmd , 0U );
	 	print2Console("lidar_start_scan\r\n");
	}else{
		printf("\r\nCommand: \n");
		printf((char *)DataBuffer);
		printf("\r\n is an INVALID command.\r\n");
	}

}
