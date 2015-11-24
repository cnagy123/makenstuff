//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

// Initialize the I2C0 Module [as Master]
void I2C0_Init(void){
  
  // Enable GPIO-B Peripheral Clock [For Pins PB2 and PB3]
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
  
  // Enable I2C0 Peripheral Clock
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
  
  // Configure Pin Muxing for I2C0 Functions
  ROM_GPIOPinConfigure(GPIO_PB2_I2C0SCL);       // PB2 - I2C0_SCL
  ROM_GPIOPinConfigure(GPIO_PB3_I2C0SDA);       // PB3 - I2C0_SDA
  
  // Configure GPIO Settings for the I2C pins
  ROM_GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);   // PB2 - I2C0_SCL - Output
  ROM_GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);      // PB3 - I2C0_SDA - IN/OUT
  
  // Set the Bus Speed [100K] and Enable the Master Module
  ROM_I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), false);  // Set to True for 400K
  
}

// Initialize the I2C0 Interrupt[s]
void I2C0_Interrupt_Init(void){
  
  // Enable the I2C0 Interrupt
  ROM_IntEnable(INT_I2C0);
  
  // Configure and Turn On the I2C0 Master Interrupt
  ROM_I2CMasterIntEnable(I2C0_BASE);
}

// I2C0 Interrupt Handler
void I2C0_Interrupt_Handler(void){
  
  // Clear the Interrupt
  ROM_I2CMasterIntClear(I2C0_BASE);
  
}

// Write Data Bytes to a Register of a Slave I2C0 Device
void I2C0_Write(uint32_t deviceAddr, uint32_t regAddr, uint32_t* data, uint32_t size){
  
  // Set Device Address for Write
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, deviceAddr, WRITE);
  
  // Set Address of Register to be Written
  ROM_I2CMasterDataPut(I2C0_BASE, regAddr);
  
  // Send Register Address Byte and Start Burst
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);
  
  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
  
  // Write the Data Except for the Last Byte
  for (uint32_t count=0;count<size-1;count++){
    
    // Set Data to be Written
    ROM_I2CMasterDataPut(I2C0_BASE, *data);
    
    // Send Data Byte and Continue the Burst
    ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);
    
    // Increment to Next "Byte" of Data
    data++;
  }
  
  // Set Data to be Written
  ROM_I2CMasterDataPut(I2C0_BASE, *data);
  
  // Send Data Byte and Stop the Burst
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
  
  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
}

// Read Data from a Register
void I2C0_Read(uint32_t deviceAddr, uint32_t regAddr, uint32_t* data){
  
  // Set Device Address for [Dummy] Write
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, deviceAddr, WRITE);
  
  // Set the Address of the Register to be Read
  ROM_I2CMasterDataPut(I2C0_BASE, regAddr);
  
  // Send the Word Address Byte
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_SEND);
  
  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
  
  // Set Device Address for Read
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, deviceAddr, READ);
  
  // Read the Register
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);
  
  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
  
  // Reads and Returns the Data
  *data = ROM_I2CMasterDataGet(I2C0_BASE);
  
}

void I2C0_ReadMultiple(uint32_t deviceAddr, uint32_t regAddr, uint32_t* data, uint32_t size){
  
  // Set Device Address for [Dummy] Write
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, deviceAddr, WRITE);
  
  // Set the Address of the Register to be Read
  ROM_I2CMasterDataPut(I2C0_BASE, regAddr);
  
  // Send the Word Address Byte
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_SEND);
  
  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
  
  // Set Device Address for Read
  ROM_I2CMasterSlaveAddrSet(I2C0_BASE, deviceAddr, READ);
  
  // Get the First Data Byte
  ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_START);
  
  // Wait for Master to Complete
  while(ROM_I2CMasterBusy(I2C0_BASE));
  
  // Read the Data Byte
  *data = ROM_I2CMasterDataGet(I2C0_BASE);
  data++;
  
  // Cycle through the remaining reads except the last one.
  for(uint32_t count=1;count<(size-1);count++){
    
      // Get the Data Byte
    ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_CONT);
    
    // Wait for Master to Complete
    while(ROM_I2CMasterBusy(I2C0_BASE));
    
    // Read the Data Byte
    *data = ROM_I2CMasterDataGet(I2C0_BASE);
    data++;
  }
  
  if (size > 1){
    // Read the Register
    ROM_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_RECEIVE_FINISH);
    
    // Wait for Master to Complete
    while(ROM_I2CMasterBusy(I2C0_BASE));
    
    // Reads and Returns the Data
    *data = ROM_I2CMasterDataGet(I2C0_BASE);
  }
}