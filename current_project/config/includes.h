//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

#ifndef __INCLUDES_H__
#define __INCLUDES_H__

// ***************************** //
//      Standard Includes        //
// ***************************** //
#include <stdint.h>
#include <ysizet.h>
#include <stdbool.h>
#include <math.h>

// *****************************//
//      Configuration File[s]   //
// *****************************//
// Main Configuration File
#include "config.h"

// *****************************//
//              TI              //
// *****************************//
#include "tm4c123gh6pm.h"

// TM4C123GH6PM Registers
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_i2c.h"

// TI Driver Library
#include "driverlib/rom.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/ssi.h"
#include "driverlib/udma.h"
#include "driverlib/i2c.h"
#include "driverlib/timer.h"

// TI Graphics Library
#include "grlib/grlib.h"

//*****************************//
//      Project                 //
//*****************************//

//// System
#include "init.h"

// Globals
#include "globals.h"

// Constants
#include "defines.h"
#include "colors.h"

// Application
#include "application.h"

// Protocols
#include "spi.h"
#include "i2c.h"

// Peripherals

// GPIO
//#include "gpio.h"
#include "onBoard.h"

// Timers
#include "systick.h"
#include "timer0.h"
#include "timer1.h"

// LCD
#include "ili9341.h"
#include "lcd.h"

// External Memory
#include "at24.h"

// uDMA [maybe]
#include "uDMA.h"






#endif