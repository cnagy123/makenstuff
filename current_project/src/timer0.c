//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

void Timer0A_Init(void){

  // Enable the Timer 0 Periph
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);

  // Configure Timer as Periodic
  ROM_TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC );

  // Set Timer A0 to Frequency
  ROM_TimerLoadSet(TIMER0_BASE, TIMER_A, (ROM_SysCtlClockGet()/TIMER0_FREQ));

  // Enable Timer 0A
  ROM_TimerEnable(TIMER0_BASE, TIMER_A);

}

void Timer0A_Interrupt_Init(void){

  //Set Timer0A to Produce Interrupt
  ROM_TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

  // Enable Timer0A Interrupt
  ROM_IntEnable(INT_TIMER0A);

}

void Timer0A_Interrupt_Handler(void){

  // Clear the timer interrupt.
  ROM_TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);

  // Poll the Switches
  App.switches = poll_switch(0,0);

  // Handle any Changes in Switch (Change Mode)
  switchHandler();
  
}