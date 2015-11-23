//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

void SPI_Init(void){

  // Enable GPIO Clock for RST and DC lines
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  
  // Enable SSI0 Peripheral Clock
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);

  // Configure Pin Muxing for SSI0 Functions
  ROM_GPIOPinConfigure(GPIO_PA2_SSI0CLK);       // PA2 - SSI0_CLK
  ROM_GPIOPinConfigure(GPIO_PA3_SSI0FSS);       // PA3 - SSI0_Fss
  ROM_GPIOPinConfigure(GPIO_PA4_SSI0RX);        // PA4 - SSI0_Rx
  ROM_GPIOPinConfigure(GPIO_PA5_SSI0TX);        // PA5 - SSI0_Tx

  // Configure GPIO Settings for the SSI pins
  ROM_GPIOPinTypeSSI(GPIO_PORTA_BASE, (GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5));

  // Initalize SSI Module, Using Mode 0 and 8 Bit Data
  ROM_SSIConfigSetExpClk(SSI0_BASE, SysCtlClockGet(), SSI_FRF_MOTO_MODE_0, SSI_MODE_MASTER, SSI0_FREQ, SSI_BITS);

  // Enable SSI
  SSIEnable(SSI0_BASE);

}

void SPI_Interrupt_Init(void){

  // Enable Interrupt
  ROM_IntEnable(INT_SSI0);

}

void SPI_Interrupt_Handler(void){

  // Interrupt Source ID
  unsigned long ID;

  // Read the asserted interrupt sources.
  ID = ROM_SSIIntStatus(SSI0_BASE, true);

  // Clear the asserted interrupt sources.
  ROM_SSIIntClear(SSI0_BASE, ID);
  
}

void SPI_Write(uint32_t SPI_base, uint32_t *value){
  ROM_SSIDataPutNonBlocking(SPI_base, *value);
}
