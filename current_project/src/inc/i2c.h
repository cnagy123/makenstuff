//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

#ifndef __I2C_H__
#define __I2C_H__

extern void I2C_Init(void);
extern void I2C0_Interrupt_Init(void);
extern void I2C0_Interrupt_Handler(void);

extern void I2C_Write(uint32_t slaveID, uint32_t regAddr, uint32_t data);
extern uint32_t I2C_Read(uint32_t slaveID, uint32_t regAddr);

#endif