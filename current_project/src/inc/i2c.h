//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

#ifndef __I2C_H__
#define __I2C_H__

extern void I2C0_Init(void);
extern void I2C0_Interrupt_Init(void);
extern void I2C0_Interrupt_Handler(void);

extern void I2C0_Write(uint32_t deviceAddr, uint32_t regAddr, uint32_t* data, uint32_t size);
extern void I2C0_Read(uint32_t deviceAddr, uint32_t regAddr, uint32_t* data);
extern void I2C0_ReadMultiple(uint32_t deviceAddr, uint32_t regAddr, uint32_t* data, uint32_t size);
#endif