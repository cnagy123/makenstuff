/*
 * lidar.c
 *
 *  Created on: Aug 27, 2019
 *      Author: chris
 *
 *      Drive to the Slamtec A1M8 Lidar via UART2
 *
 *
 *      Currently only talks to virtual com
 */


#include "lidar.h"


uint8_t aTextInfoStart[] = "\r\nUSART Example : Enter characters to fill reception buffers.\r\n";
uint8_t aTextInfoSwap1[] = "\r\n- Current RX buffer is full : ";
uint8_t aTextInfoSwap2[] = "\r\n- Reception will go on in alternate buffer\r\n";

uint8_t aRXBufferAX[LIDAR_RX_BUFFER_SIZE];
uint8_t aRXBufferBX[LIDAR_RX_BUFFER_SIZE];
volatile uint32_t     uwNbReceivedCharsX;
volatile uint32_t     uwBufferReadyIndicationX;
uint8_t *pBufferReadyForUserX;
uint8_t *pBufferReadyForReceptionX;

void PrintInfo(uint8_t *String, uint32_t Size);
void StartReceptionX(void);
void HandleContinuousReceptionX(void);
void UserDataTreatmentX(uint8_t *DataBuffer, uint32_t Size);

void CmdlineTaskX(void const * argument)
{
  StartReceptionX();

  /* Infinite loop */
  for(;;)
  {
	  HandleContinuousReceptionX();
  }
  /* USER CODE END CmdlineTask */
}


void PrintInfo(uint8_t *String, uint32_t Size)
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
    LL_USART_TransmitData8(USART2, *pchar++);
  }

  /* Wait for TC flag to be raised for last char */
  while (!LL_USART_IsActiveFlag_TC(USART2))
  {
  }
}

void StartReceptionX(void)
{
  /* Initializes Buffer swap mechanism :
     - 2 physical buffers aRXBufferA and aRXBufferB (RX_BUFFER_SIZE length)

  */
  pBufferReadyForReceptionX = aRXBufferAX;
  pBufferReadyForUserX      = aRXBufferBX;
  uwNbReceivedCharsX = 0;
  uwBufferReadyIndicationX = 0;

  /* Print user info on PC com port */
  PrintInfo(aTextInfoStart, sizeof(aTextInfoStart));

  /* Clear Overrun flag, in case characters have already been sent to USART */
  LL_USART_ClearFlag_ORE(USART2);

  /* Enable RXNE and Error interrupts */
  LL_USART_EnableIT_RXNE(USART2);
  LL_USART_EnableIT_ERROR(USART2);
}

void USART_CharReception_CallbackX(void)
{
	uint8_t *ptemp;
	uint8_t c;
  /* Read Received character. RXNE flag is cleared by reading of RDR register */
	c = LL_USART_ReceiveData8(USART2);
	pBufferReadyForReceptionX[uwNbReceivedCharsX++] = c;

  /* Checks if Buffer full indication has been set */
  if ((uwNbReceivedCharsX >= LIDAR_RX_BUFFER_SIZE)||(c == '\r')||(c == '\n'))
  {
    /* Set Buffer swap indication */
    uwBufferReadyIndicationX = 1;

    /* Swap buffers for next bytes to be received */
    ptemp = pBufferReadyForUserX;
    pBufferReadyForUserX = pBufferReadyForReceptionX;
    pBufferReadyForReceptionX = ptemp;
    uwNbReceivedCharsX = 0;
  }
}

void HandleContinuousReceptionX(void)
{
  /* Checks if Buffer full indication has been set */
  if (uwBufferReadyIndicationX != 0)
  {
    /* Reset indication */
    uwBufferReadyIndicationX = 0;

    /* Call user Callback in charge of consuming data from filled buffer */
    UserDataTreatmentX(pBufferReadyForUserX, LIDAR_RX_BUFFER_SIZE);
  }
}

void UserDataTreatmentX(uint8_t *DataBuffer, uint32_t Size)
{
	/* Display info message + buffer content on PC com port */
	PrintInfo(aTextInfoSwap1, sizeof(aTextInfoSwap1));
	PrintInfo(DataBuffer, Size);
	PrintInfo(aTextInfoSwap2, sizeof(aTextInfoSwap2));

	/* Toggle LED */
//	HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);
}
