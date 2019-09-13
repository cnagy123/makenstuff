/*
 * uart2.c
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#include "uart2.h"

uint8_t uart2_rxBufferA[UART2_RX_BUFFER_SIZE];
uint8_t uart2_rxBufferB[UART2_RX_BUFFER_SIZE];

volatile uint32_t uart2_receivedChars;
volatile uint32_t uart2_bufferReadyflag;
volatile uint32_t uart2_bufferLength;
volatile uint32_t flag;

uint8_t *uart2_pBufferReadyforProcessing;
uint8_t *uart2_pBufferReadyForReception;

osThreadId uart2Handle;
osSemaphoreId uart2SemHandle;

QueueHandle_t uart2QueueIn = NULL;
QueueHandle_t uart2QueueOut = NULL;

void Uart2InitReception(void);
void Uart2HandleContinuousReception(void);

void Uart2SendData(uint8_t *String, uint32_t Size)
{
  uint32_t index = 0;
  uint8_t *pchar = String;
  /* Send characters one per one, until last char to be sent */
  for (index = 0; index < Size; index++)
  {
    /* Wait for TXE flag to be raised */
    while (!LL_USART_IsActiveFlag_TXE(USART2))
    {
    }
    /* Write character in Transmit Data register.
       TXE flag is cleared by writing data in TDR register */
    LL_USART_TransmitData8(USART2, *pchar);
    pchar++;
  }
  /* Wait for TC flag to be raised for last char */
  while (!LL_USART_IsActiveFlag_TC(USART2))
  {
  }
}

void Uart2Task(void const * argument)
{
	unsigned long val;
	Uart2InitReception();

  /* Infinite loop */
	for(;;)
	{
		if(flag == 0){
		  xQueueReceive(uart2QueueIn, &val, 0xFFFFFFFF );
		  uart2_bufferLength = val;
		  Uart2HandleContinuousReception();
		  flag = 1;
		}else{
		  Uart2HandleContinuousReception();
		}
	}
  /* USER CODE END CmdlineTask */
}

void Uart2CharReceptionCallback(void)
{
	uint8_t *ptemp;
	uint8_t c;

	/* Read Received character. RXNE flag is cleared by reading of RDR register */
	c =  LL_USART_ReceiveData8(USART2);
	uart2_pBufferReadyForReception[uart2_receivedChars++] = c;

	/* Checks if Buffer full indication has been set */
	if ((uart2_receivedChars >= uart2_bufferLength) || (c = '\0'))
	{
		/* Set Buffer swap indication */
		uart2_bufferReadyflag = 1;

		/* Swap buffers for next bytes to be received */
		ptemp = uart2_pBufferReadyforProcessing;
		if(osSemaphoreWait(uart2SemHandle,0)==osOK){
			uart2_pBufferReadyforProcessing = uart2_pBufferReadyForReception;
			osSemaphoreRelease(uart2SemHandle);
		}
		uart2_pBufferReadyForReception = ptemp;
		uart2_receivedChars = 0;
	}
}

void Uart2InitReception(void)
{
	uart2_pBufferReadyForReception 	= uart2_rxBufferA;
	if(osSemaphoreWait(uart2SemHandle,0)==osOK){
		uart2_pBufferReadyforProcessing = uart2_rxBufferB;
		osSemaphoreRelease(uart2SemHandle);
	}
	uart2_receivedChars = 0;
	uart2_bufferReadyflag = 0;
	uart2_bufferLength = UART2_RX_BUFFER_SIZE;

	uart2QueueIn = xQueueCreate( UART2_QUEUE_LENGTH, sizeof( uint32_t ) );
	uart2QueueOut = xQueueCreate( UART2_QUEUE_LENGTH, sizeof( uint32_t ) );

	flag = 0;

	LL_USART_ClearFlag_ORE(USART2);
	LL_USART_EnableIT_RXNE(USART2);
	LL_USART_EnableIT_ERROR(USART2);
}

void Uart2HandleContinuousReception(void)
{

	/* Checks if Buffer full indication has been set */
	if (uart2_bufferReadyflag != 0)
	{
		xQueueSend(uart2QueueOut, &uart2_bufferReadyflag , 0U );
		/* Reset indication */
		  uart2_bufferReadyflag = 0;
		  flag = 0;

		/* Do something with the data */


	}else{

	}
}
