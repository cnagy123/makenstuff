//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

//****************************************************************************//
// Handle the Switches                                                        //
//****************************************************************************//
void switchHandler(void){
  
  static uint32_t count = 0;

  // Determine which Switch/Button was Pressed
  switch(App.switches & ALL_SW){
    
  case SW1:
    if(count < 3){
      count++;
    }else{
      ROM_GPIOPinWrite(RGB_GPIO_BASE, RGB_LED, RED_LED);
      LCD_Fill_Display(GREEN);
      LCD_DefaultDisplay();
      count = 0;
    }
    break;
  case SW2:
    if(count < 3){
      count++;
    }else{
      ROM_GPIOPinWrite(RGB_GPIO_BASE, RGB_LED, BLUE_LED);
      LCD_Fill_Display(BLACK);
      LCD_DefaultDisplay();
      count = 0;
    }
    break;
  case ALL_SW:
    if(count < 3){
      count++;
    }else{
      ROM_GPIOPinWrite(RGB_GPIO_BASE, RGB_LED, GREEN_LED);
      LCD_FancyLines();
      LCD_DefaultDisplay();
      count = 0;
    }
    break;
  default:
    count = 0;
    break;
    
  }
}



void app(void){
  
}

