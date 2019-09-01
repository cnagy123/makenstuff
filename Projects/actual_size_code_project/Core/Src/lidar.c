/*
 * lidar.c
 *
 *  Created on: Aug 27, 2019
 *      Author: chris [actual_size]
 *
 *      Driver to the Slamtec A1M8 Lidar via UART2
 *
 *
 *      Currently only talks to virtual com
 */
#include "lidar.h"

uint8_t lidar_command[2] = {LIDAR_START_BYTE, LIDAR_CMD_GET_INFO};

uint8_t descriptor[LIDAR_RESPONSE_DESCRIPTOR_SIZE];

uint8_t aRXBufferAX[20];
uint8_t aRXBufferBX[20];

volatile uint32_t     uwNbReceivedCharsX;
volatile uint32_t     uwBufferReadyIndicationX;

uint8_t *pBufferReadyForUserX;
uint8_t *pBufferReadyForReceptionX;

lidar_states lidar_current_state = SM_RESET;

void LidarSendData(uint8_t *String, uint32_t Size);
void LidarInitReception(void);
void HandleContinuousReceptionX(void);
void UserDataTreatmentX(uint8_t *DataBuffer, uint32_t Size);
lidar_states LidarStateMachine(lidar_states state);
lidar_states decide_next_state(uint32_t flags);

uint32_t lidar_flags;

///////////////////////////////////////////////////////////////////////////

#define lidarQUEUE_RECEIVE_TASK_PRIORITY		( tskIDLE_PRIORITY + 2 )
#define	lidarQUEUE_SEND_TASK_PRIORITY			( tskIDLE_PRIORITY + 1 )

#define lidarQUEUE_SEND_FREQUENCY_MS			( 200 / portTICK_PERIOD_MS )
#define lidarQUEUE_LENGTH						( 1 )

QueueHandle_t lidarQueue = NULL;

void LidarTask(void const * argument)
{


	LidarInitReception();

	/* Send Test Command*/
//	LidarSendData(lidar_command, sizeof(lidar_command));
	lidar_flags = 0x00000000;

  /* Infinite loop */
  for(;;)
  {
	  lidar_current_state = LidarStateMachine(lidar_current_state);
  }
  /* USER CODE END CmdlineTask */
}



lidar_states LidarStateMachine(lidar_states state)
{
	lidar_states next_state;
	unsigned long ulReceivedValue;
	switch(state){
		case SM_RESET:
			next_state = IDLE;
			break;
		case IDLE:
			xQueueReceive( lidarQueue, &ulReceivedValue, 0xFFFFFFFF );
			next_state = decide_next_state(ulReceivedValue);
			break;
		case SCAN:
			next_state = state;
			break;
		case MOTOR_ON:
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_SET);
			next_state = IDLE;
			break;
		case MOTOR_OFF:
			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_6,GPIO_PIN_RESET);
			next_state = IDLE;
			break;
		case STOP:
			next_state = state;
			break;
		case START:
			next_state = state;
			break;
		case GET_INFO:
			next_state = state;
			break;
		default:
			next_state = state;
			break;
	}
	return next_state;
}

lidar_states decide_next_state(unsigned long flags){
	lidar_states next_state;
	switch(flags){
	case 0x00000000:
		next_state = IDLE;
		break;
	case 0x00000001:
		next_state = MOTOR_ON;
		break;
	case 0x00000002:
		next_state = MOTOR_OFF;
		break;
	default:
		next_state = IDLE;
		break;
	}
	return next_state;
}

void LidarSendData(uint8_t *String, uint32_t Size)
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

void LidarInitReception(void)
{
  /* Initializes Buffer swap mechanism :
     - 2 physical buffers aRXBufferA and aRXBufferB (RX_BUFFER_SIZE length)
  */
  pBufferReadyForReceptionX = aRXBufferAX;
  pBufferReadyForUserX      = aRXBufferBX;
  uwNbReceivedCharsX = 0;
  uwBufferReadyIndicationX = 0;

  /* create the queue*/
  lidarQueue = xQueueCreate( lidarQUEUE_LENGTH, sizeof( uint32_t ) );

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
  if ((uwNbReceivedCharsX >= LIDAR_RESPONSE_DESCRIPTOR_SIZE)||(c == '\r')||(c == '\n'))
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
    UserDataTreatmentX(pBufferReadyForUserX, LIDAR_RESPONSE_DESCRIPTOR_SIZE);
  }
}
lidarResponse response;
void UserDataTreatmentX(uint8_t *DataBuffer, uint32_t Size)
{


	response.start_flag1 = DataBuffer[0];
	response.start_flag2 = DataBuffer[1];
	response.data_response_length = ((DataBuffer[5]<<26) | (DataBuffer[4]<<16) | (DataBuffer[3]<<8) | (DataBuffer[2]));
	response.send_mode = (DataBuffer[5]<<6);
	response.data_type = DataBuffer[6];
	/* Display info message + buffer content on PC com port */
	LidarSendData(DataBuffer, Size);

	/* Toggle LED */
//	HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);
}

