//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

void SysTick_Init(void){

  // System Tick :: Timer
  // Example:   Clk*Period [T] = 50MHz/5000 = 10KHz
  // SysCtlClockGet() / Freq = Ticks Per Second
  ROM_SysTickPeriodSet((ROM_SysCtlClockGet()/SYSTEMTICK_FREQ));
  
  // Enable SystemTick
  ROM_SysTickEnable();

}

void SysTick_Interrupt_Init(void){

  // System Tick - Timer
  ROM_SysTickIntEnable();

}

void SysTick_Interrupt_Handler(void){

    app();

}