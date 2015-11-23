//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//
// TODO: DETERMINE IF CHANGE IN SWITCH IS PRESS OR RELEASE
// KEEP STATE WHEN ALL SWITCHES ARE PRESSED AFTER RELEASED 

static uint32_t switchStatus = (ALL_SW);
static uint32_t swClockA = 0;
static uint32_t swClockB = 0;

//****************************************************************************//
// LED Initialization                                                         //
//****************************************************************************//
void LED_Init(void){
  
  // Set Clock
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  
  // Setup Pins as Output
  ROM_GPIOPinTypeGPIOOutput(RGB_GPIO_BASE,RGB_LED);
  
  // Write to LED
  ROM_GPIOPinWrite(RGB_GPIO_BASE,RGB_LED,BLUE_LED);
  
}

//****************************************************************************//
// Switch and Push-Button Initalization                                     //
//****************************************************************************//
void Switch_Init(void){
  
  // Set Clock
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  
  // PF0 => Special Case (muxed with NMI)0x40025520
  HWREG(SW_GPIO_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;    // Unlock PF0
  HWREG(SW_GPIO_BASE + GPIO_O_CR) |= 0x01;              // Set as GPIO input
  HWREG(SW_GPIO_BASE + GPIO_O_LOCK) = 0;                // Lock PF0
  
  // Setup Pins as Input
  ROM_GPIODirModeSet(SW_GPIO_BASE, (ALL_SW), GPIO_DIR_MODE_IN);
  // Setup Pins with Pull-Ups
  ROM_GPIOPadConfigSet(SW_GPIO_BASE, (ALL_SW), GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
  
  // Get Initial Button Status
  switchStatus = ROM_GPIOPinRead(SW_GPIO_BASE, ALL_SW);
}

//****************************************************************************//
// Poll Switch [Debounce]                                                     //
//****************************************************************************//
uint32_t poll_switch(uint32_t *pDiff, uint32_t *pRawRead ){
  
  uint32_t data;
  uint32_t diff;
  
  // Read the Switches
  data = ROM_GPIOPinRead(SW_GPIO_BASE, ALL_SW);
  
  // Return the Raw Data if Necessary
  if(pRawRead){
    *pRawRead = ~data; // Flip the Bits so a '1' Means the Switch is Pressed
  }
  
  // XOR the Current Data and switchStatus to Determine what is Different 
  diff = data ^ switchStatus;
  
  // Increment the Bits Representing the Clock for each Switch
  swClockA = (swClockA) ^ (swClockB);   //swClockA updates the difference between itself and swClockB       
  swClockB = ~(swClockB); // Flip the bits to toggle/increment clock
  
  // Reset Clocks that Did Not Change
  swClockA = (swClockA) & (diff);
  swClockB = (swClockB) & (diff);
  
  // Set the New Status
  switchStatus = (switchStatus) & (swClockA | swClockB);
  switchStatus = (switchStatus) | ((~(swClockA|swClockB)) & data);
  
  // Determine what is Different
  diff = (diff) ^ (swClockA|swClockB);
  
  // Return the Difference if Necessary
  if(pDiff){
    *pDiff = diff;
  }
  
  // Return the Button Status (Inverted to Show 1 as Switch Being Depressed)
  return ~switchStatus;
}
