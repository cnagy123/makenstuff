
#include "cmdline.h"
#include "main.h"
#include "cmsis_os.h"
#include "lwip.h"
#include <string.h>
#include "lidar.h"

/* Buffer used for reception */
uint8_t aRXBufferA[RX_BUFFER_SIZE];
uint8_t aRXBufferB[RX_BUFFER_SIZE];
volatile uint32_t     uwNbReceivedChars;
volatile uint32_t     uwBufferReadyIndication;
uint8_t *pBufferReadyForUser;
uint8_t *pBufferReadyForReception;

void StartReception(void);
void HandleContinuousReception(void);
void UserDataTreatment(uint8_t *DataBuffer, uint32_t Size);
void CmdlineTask(void const * argument)
{
  StartReception();

  /* Infinite loop */
  for(;;)
  {
	  HandleContinuousReception();
  }
  /* USER CODE END CmdlineTask */
}

void StartReception(void)
{
  /* Initializes Buffer swap mechanism :
     - 2 physical buffers aRXBufferA and aRXBufferB (RX_BUFFER_SIZE length)

  */
  pBufferReadyForReception = aRXBufferA;
  pBufferReadyForUser      = aRXBufferB;
  uwNbReceivedChars = 0;
  uwBufferReadyIndication = 0;

  /* Print user info on PC com port */
  printf("\r\nEnter command: \r\n");
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
extern QueueHandle_t lidarQueue;
#define LIDAR_MOTOR_ON_FLAG		0x00000001
#define LIDAR_MOTOR_OFF_FLAG	0x00000002
void UserDataTreatment(uint8_t *DataBuffer, uint32_t Size)
{
unsigned long flag;
	if(!strcmp("lidar_motor_on\r", (char *)DataBuffer)){
		flag = LIDAR_MOTOR_ON_FLAG;
		xQueueSend( lidarQueue, &flag, 0U );
//		printf((char *)DataBuffer);
	}else if(!strcmp("lidar_motor_off\r", (char *)DataBuffer)){
		flag = LIDAR_MOTOR_OFF_FLAG;
		xQueueSend( lidarQueue, &flag, 0U );
	}else{
		printf("\r\nCommand: \n");
		printf((char *)DataBuffer);
		printf("\r\n is an INVALID command.\r\n");
	}
	/* Toggle LED */
//	HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);
}
