/*
 * cmdLine.c
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#include "cmdLine.h"

uint8_t aRXBufferA[RX_BUFFER_SIZE];
uint8_t aRXBufferB[RX_BUFFER_SIZE];

volatile uint32_t     uwNbReceivedChars;
volatile uint32_t     uwBufferReadyIndication;

uint8_t *pBufferReadyForUser;
uint8_t *pBufferReadyForReception;

void HandleContinuousReception(void);
void UserDataTreatment(uint8_t *DataBuffer, uint32_t Size);

void cmdLineTask(void){
	HandleContinuousReception();
}

void cmdLineInit(void){

	// Get the Buffers Ready
	pBufferReadyForReception = aRXBufferA;
	pBufferReadyForUser      = aRXBufferB;
	uwNbReceivedChars = 0;
	uwBufferReadyIndication = 0;

	/* Clear Overrun flag, in case characters have already been sent to USART */
	WRITE_REG(USART3->ICR, USART_ICR_ORECF);

	/* Enable RXNE and Error interrupts */
	SET_BIT(USART3->CR1, USART_CR1_RXNEIE);		//	Enable IT RXNE
	SET_BIT(USART3->CR3, USART_CR3_EIE);		//	Enable IT ERROR
}

void USART_CharReception_Callback(void)
{
	uint8_t *ptemp;
	uint8_t c;

  /* Read Received character. RXNE flag is cleared by reading of RDR register */
	c = (uint8_t)(READ_BIT(USART3->RDR, USART_RDR_RDR));
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
	if(!strcmp("lidar_motor_on\r", (char *)DataBuffer)){
		app.command = LIDAR_MOTOR_ON;
		print2Console("lidar_motor_on\r\n");
	}else if(!strcmp("lidar_motor_off\r", (char *)DataBuffer)){
		app.command = LIDAR_MOTOR_OFF;
		print2Console("lidar_motor_off\r\n");
	}else if(!strcmp("lidar_get_info\r", (char *)DataBuffer)){
		app.command = LIDAR_GET_INFO;
		print2Console("lidar_get_info\r\n");
	}else if(!strcmp("lidar_start_scan\r", (char *)DataBuffer)){
		app.command = LIDAR_START_SCAN;
		print2Console("lidar_start_scan\r\n");
	}else{
		app.command = DO_NOTHING;
		app.printFlag = 1;
		printf((char *)DataBuffer);
		app.printFlag = 0;
		print2Console("\r\n is an INVALID command.\r\n");
	}

}
