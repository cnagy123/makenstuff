/*
 * uart2.c
 *
 *  Created on: Sep 2, 2019
 *      Author: chris
 */

#include "uart2.h"

#define UART2_RX_BUFFER_SIZE	128
#define UART2_QUEUE_LENGTH		1

uint8_t uart2_rxBufferA[UART2_RX_BUFFER_SIZE];
uint8_t uart2_rxBufferB[UART2_RX_BUFFER_SIZE];
uint8_t logBuffer[4000][16];

volatile uint32_t uart2_receivedChars;
volatile uint32_t uart2_bufferReadyflag;
volatile uint32_t uart2_bufferLength;
volatile uint32_t responseFlag;

uint8_t *uart2_pBufferReadyforProcessing;
uint8_t *uart2_pBufferReadyForReception;

UART_HandleTypeDef huart2;

void uart2HandleContinuousReception(void);

void uart2SendData(uint8_t *String, uint32_t Size)
{
  uint32_t index = 0;
  uint8_t *pchar = String;
  /* Send characters one per one, until last char to be sent */
  for (index = 0; index < Size; index++)
  {
    /* Wait for TXE flag to be raised */
    while (!((READ_BIT(USART2->ISR, USART_ISR_TXE) == (USART_ISR_TXE)) ? 1UL : 0UL))
    {
    }
    /* Write character in Transmit Data register.
       TXE flag is cleared by writing data in TDR register */
    USART2->TDR = *pchar;
    pchar++;
  }
  /* Wait for TC flag to be raised for last char */
  while (!((READ_BIT(USART2->ISR, USART_ISR_TC) == (USART_ISR_TC)) ? 1UL : 0UL))
  {
  }
}

void uart2Task(void)
{
  /* Infinite loop */
	uart2HandleContinuousReception();
  /* USER CODE END CmdlineTask */
}
uint8_t quality;
uint8_t startBit;
uint8_t startBitInverse;
uint16_t heading;
uint16_t distance;
uint8_t startFlag = 0;
uint8_t skipFlag = 0;
int increment = 0;
int increment2 = 0;
void uart2CharReceptionCallback(void)
{
	uint8_t *ptemp;
	uint8_t c;
	uint32_t byteswritten;
	uint32_t i,j;

	if(responseFlag == 0){
		if(skipFlag == 0){
			uart2_bufferLength = 7;
		}else{
			uart2_bufferLength = 1;
		}
	}else{
		uart2_bufferLength = 5;//app.response.data_response_length;
	}

	/* Read Received character. RXNE flag is cleared by reading of RDR register */
	c =  (uint8_t)(READ_BIT(USART2->RDR, USART_RDR_RDR));
	uart2_pBufferReadyForReception[uart2_receivedChars++] = c;

	/* Checks if Buffer full indication has been set */
	if ((uart2_receivedChars >= uart2_bufferLength))
	{
		/* Swap buffers for next bytes to be received */
		ptemp = uart2_pBufferReadyforProcessing;
		uart2_pBufferReadyforProcessing = uart2_pBufferReadyForReception;
		uart2_pBufferReadyForReception = ptemp;
		if(skipFlag){
			skipFlag = 0;
		}else{
			if(responseFlag == 0){
				app.response.start_flag1 = uart2_pBufferReadyforProcessing[0];
				app.response.start_flag2 = uart2_pBufferReadyforProcessing[1];
				if((app.response.start_flag1 == LIDAR_START_BYTE && app.response.start_flag2 == LIDAR_RESPONSE_DESCRIPTOR)){
					app.response.data_response_length = ((uart2_pBufferReadyforProcessing[5]<<26) | (uart2_pBufferReadyforProcessing[4]<<16) | (uart2_pBufferReadyforProcessing[3]<<8) | (uart2_pBufferReadyforProcessing[2]));
					app.response.send_mode = (uart2_pBufferReadyforProcessing[5] >> 6);
					app.response.data_type = uart2_pBufferReadyforProcessing[6];
					responseFlag = 1;
				}else{
					app.currentLidarState = LIDAR_ERROR;
					print2Console("Lidar Error\r\n");
				}

			}else{
				if(app.currentLidarState == GET_INFO){
					app.info.model = uart2_pBufferReadyforProcessing[0];
					app.info.firmware_minor = uart2_pBufferReadyforProcessing[1];
					app.info.firmware_major = uart2_pBufferReadyforProcessing[2];
					app.info.hardware = uart2_pBufferReadyforProcessing[3];
					app.info.serial[0] = uart2_pBufferReadyforProcessing[4];
					app.info.serial[1] = uart2_pBufferReadyforProcessing[5];
					app.info.serial[2] = uart2_pBufferReadyforProcessing[6];
					app.info.serial[3] = uart2_pBufferReadyforProcessing[7];
					app.info.serial[4] = uart2_pBufferReadyforProcessing[8];
					app.info.serial[5] = uart2_pBufferReadyforProcessing[9];
					app.info.serial[6] = uart2_pBufferReadyforProcessing[10];
					app.info.serial[7] = uart2_pBufferReadyforProcessing[11];
					app.info.serial[8] = uart2_pBufferReadyforProcessing[12];
					app.info.serial[9] = uart2_pBufferReadyforProcessing[13];
					app.info.serial[10] = uart2_pBufferReadyforProcessing[14];
					app.info.serial[11] = uart2_pBufferReadyforProcessing[15];
					app.info.serial[12] = uart2_pBufferReadyforProcessing[16];
					app.info.serial[13] = uart2_pBufferReadyforProcessing[17];
					app.info.serial[14] = uart2_pBufferReadyforProcessing[18];
					app.info.serial[15] = uart2_pBufferReadyforProcessing[19];
					app.currentLidarState = LIDAR_IDLE;
					responseFlag = 0;
				}else if(app.currentLidarState == SCAN){
//					startBit = (uart2_pBufferReadyforProcessing[0] & 01);
//					startBitInverse = ((uart2_pBufferReadyforProcessing[0] >> 1) & 01);
//					if(startBit == 1 && startBitInverse == 0){
//						startFlag = 1;
//
//						if(increment >= 360){
//							increment = 0;
//						}
//
//						heading = (uart2_pBufferReadyforProcessing[2]);
//	//					app.lidar.heading[increment] = (uint16_t)heading;
//						quality = (uart2_pBufferReadyforProcessing[0] >> 2);
//	//					app.lidar.quality[heading] = quality;
//						distance = (uart2_pBufferReadyforProcessing[4] << 8 | uart2_pBufferReadyforProcessing[3]);
//	//					app.lidar.distance[heading] = (uint16_t)distance >> 2;
//						sprintf(logBuffer[increment2], "%d,%d,%d\n",quality,heading,distance>>2);
//	//					f_write(&MyFile, logBuffer, sizeof(logBuffer), (void *)&byteswritten);
//						increment2++;
//						increment++;
//					}else{
//						if(startBit == 0 && startBitInverse == 1 && startFlag == 1){

							if(increment >= 360){
								increment = 0;
							}
							heading = (uint16_t)(uart2_pBufferReadyforProcessing[2] | (uart2_pBufferReadyforProcessing[1]>>1));
	//						app.lidar.heading[increment] = (uint16_t)heading;
							quality = (uart2_pBufferReadyforProcessing[0] >> 2);
	//						app.lidar.quality[heading] = quality;
							distance = (uart2_pBufferReadyforProcessing[4] << 8 | uart2_pBufferReadyforProcessing[3]);
	//						app.lidar.distance[heading] = (uint16_t)distance >> 2;

	//						f_write(&MyFile, logBuffer, sizeof(logBuffer), (void *)&byteswritten);
							increment++;
							if(increment2 >= 4000){
								increment2 = 0;
								lidarStop();
								startFlag = 0;
								uart2_receivedChars = 0;
								uart2_bufferReadyflag = 0;
								uart2_bufferLength = UART2_RX_BUFFER_SIZE;
								responseFlag = 0;

								for(i=0;i<4000;i++){
									f_write(&MyFile, logBuffer[i], sizeof(logBuffer[i]), (void *)&byteswritten);
//									for(j=0;j<10000;j++){
//										__NOP();
//									}
								}
								f_close(&MyFile);
								f_open(&MyFile, "LIDAR_DATA.TXT", FA_OPEN_APPEND | FA_WRITE);
								secondHeartbeat();
								skipFlag = 1;
								lidarScan();

	//							FATFS_UnLinkDriver(SDPath);
							}else{
								sprintf(logBuffer[increment2],"%d,%d,%d\n",quality,(heading/64),(distance/4));
								increment2++;
							}
						}
//					}
				}
	//			uart2_bufferReadyflag = 1;

		}
		uart2_receivedChars = 0;
	}
}

void uart2InitReception(void)
{
	uart2_pBufferReadyForReception 	= uart2_rxBufferA;
	uart2_pBufferReadyforProcessing = uart2_rxBufferB;

	uart2_receivedChars = 0;
	uart2_bufferReadyflag = 0;
	uart2_bufferLength = UART2_RX_BUFFER_SIZE;

	responseFlag = 0;

	WRITE_REG(USART2->ICR, USART_ICR_ORECF);	//ClearFlag;
	__HAL_UART_SEND_REQ(&huart2, UART_RXDATA_FLUSH_REQUEST);
	SET_BIT(USART2->CR1, USART_CR1_RXNEIE);		//Enable IT RXNE;
	SET_BIT(USART2->CR3, USART_CR3_EIE);		//Enable IT ERROR;
}

void uart2HandleContinuousReception(void)
{
	/* Checks if Buffer full indication has been set */
	if (uart2_bufferReadyflag != 0)
	{
		/* Reset indication */
		 uart2_bufferReadyflag = 0;

		/* Do something with the data */
//		 for(i=0;i<360;i++){
//			 sprintf(logBuffer,"\r%d,%d,%d\r\n",app.lidar.quality[i],app.lidar.heading[i],app.lidar.distance[i]);
//			 f_write(&MyFile, logBuffer, sizeof(logBuffer), (void *)&byteswritten);
//		 }
//		 f_close(&MyFile); for(i=0;i<360;i++){
//			 sprintf(logBuffer,"\r%d,%d,%d\r\n",app.lidar.quality[i],app.lidar.heading[i],app.lidar.distance[i]);
//			 f_write(&MyFile, logBuffer, sizeof(logBuffer), (void *)&byteswritten);
//		 }
//		 f_close(&MyFile);
//			responseFlag = 0;
	}else{

	}
}
