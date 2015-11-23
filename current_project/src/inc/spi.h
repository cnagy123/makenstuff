//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

#ifndef __SPI_H__
#define __SPI_H__

extern void SPI_Init(void);
extern void SPI_Interrupt_Init(void);
extern void SPI_Interrupt_Handler(void);

extern void SPI_Write(uint32_t SPI_base, uint32_t *value);

#endif