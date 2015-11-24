//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

//****************************************************************************//
//              Board Initialization                                          //
//****************************************************************************//
void initBoard(void){

  // Enable the use of the floating-point unit
  ROM_FPUEnable();

  // Enable "Lazy Stacking" for handling floating-point in interrupts
  ROM_FPULazyStackingEnable();

  // System Control
  // "When using the PLL, the VCO frequency of 400 MHz is predivided by 2 before the divisor is applied."
  // 400MHz/2 = 200MHz ::: 200MHz/4 = 50Mhz. Using External 16MHz Crystal as Source
  ROM_SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

}

//****************************************************************************//
//              Peripheral Initialization                                     //
//****************************************************************************//
void initPeriph(void){

  // System Tick - Timer
  SysTick_Init();

  // Timer 0A
  Timer0A_Init();

    // Timer 0B
  Timer1A_Init();
  
  // LED
  LED_Init();
  
  // Buttons
  Switch_Init();

  // SPI
  SPI_Init();
  
  // I2C
  I2C0_Init();

  // Initialize the ILI9341
  LCD_Init();
  
}

//****************************************************************************//
//              Interrupt Initialization                                      //
//****************************************************************************//
void initInterrupts(void){

  // System Tick - Timer
  SysTick_Interrupt_Init();

  // Timer 0A
  Timer0A_Interrupt_Init();
  
  // Timer 0B
  Timer1A_Interrupt_Init();
  
  // SPI
  SPI_Interrupt_Init();

  // I2C
  I2C0_Interrupt_Init();
  
  // Enable Master Interrupt
  ROM_IntMasterEnable();
}

//****************************************************************************//
//              Application Initialization                                    //
//****************************************************************************//
void initApp(void){

  // Turn Off the LEDs
  ROM_GPIOPinWrite(RGB_GPIO_BASE, RGB_LED, CLEAR);
  
  // Clear the Switch Data
  App.switches = CLEAR;
  
}