//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

void Timer1A_Init(void){
  
  // Enable the Timer 1 Periph
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
  
  // Configure Timer as Periodic
  ROM_TimerConfigure(TIMER1_BASE, TIMER_CFG_PERIODIC );
  
  // Set Timer 1A to Frequency
  ROM_TimerLoadSet(TIMER1_BASE, TIMER_A, (ROM_SysCtlClockGet()/TIMER1_FREQ));
  
  // Enable Timer 1A
  ROM_TimerEnable(TIMER1_BASE, TIMER_A);
  
}

void Timer1A_Interrupt_Init(void){
  
  ROM_TimerIntEnable(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
  
  ROM_IntEnable(INT_TIMER1A);
  
}


void Timer1A_Interrupt_Handler(void){
  
  // Clear the timer interrupt.
  ROM_TimerIntClear(TIMER1_BASE, TIMER_TIMA_TIMEOUT);
  
  // Spin the Clock Face
  LCD_Clock();
}
