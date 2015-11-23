  //****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

void I2C_Init(void){
  
  // Enable GPIO Clock I2C Pins
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
  
  // Enable I2C0 Peripheral Clock
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
  
  // Configure Pin Muxing for I2C0 Functions
  ROM_GPIOPinConfigure(GPIO_PB2_I2C0SCL);       // PB2 - I2C0_SCL
  ROM_GPIOPinConfigure(GPIO_PB3_I2C0SDA);       // PB3 - I2C0_SDA
  
  // Configure GPIO Settings for the I2C pins
  ROM_GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
  ROM_GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);
   
  // Set the Bus Speed and Enable the Master Module
  ROM_I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), false);
  
}

void I2C0_Interrupt_Init(void){
  
  // Enable the I2C0 Interrupt
  ROM_IntEnable(INT_I2C0);
  
  // Configure and Turn On the I2C0 Master Interrupt
  ROM_I2CMasterIntEnable(I2C0_BASE);
}

void I2C0_Interrupt_Handler(void){
  
  // Clear the Interrupt
  ROM_I2CMasterIntClear(I2C0_BASE);
}

void I2C_Write(uint32_t slaveID, uint32_t regAddr, uint32_t data){
  
   // Set Device Address for Write
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, slaveID, WRITE);
  
  // Set Address of Register to be Written
  ROM_I2CMasterDataPut(I2C0_BASE, regAddr);
  
  // Send Register Address Byte and Start Burst
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);

  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
  
  // Set Data to be Written
  ROM_I2CMasterDataPut(I2C0_BASE, data);
  
  // Send Data Byte and Stop the Burst
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
  
  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
}

uint32_t I2C_Read(uint32_t slaveID, uint32_t regAddr){

  // Set Device Address for [Dummy] Write
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, slaveID, WRITE);
  
  // Set the Address of the Register to be Read
  ROM_I2CMasterDataPut(I2C0_BASE, regAddr);
  
  // Send the Word Address Byte
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_SEND);
 
  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
  
  // Set Device Address for Read
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, slaveID, READ);
  
  // Read the Register
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
  
  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
  
  // Reada and Return the Data
  return ROM_I2CMasterDataGet(I2C0_BASE);
  
}
