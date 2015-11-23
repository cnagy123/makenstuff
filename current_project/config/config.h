//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "grlib/grlib.h"

typedef struct
{
    uint32_t switches;
    tContext LCD_Context;
    
}ApplicationStruct;

// Application
#define APP_NAME        "My Graphics Demo"
#define CONTEXT         App.LCD_Context

// TI Defines for DriverLib
#define ewarm
#define PART_TM4C123GH6PM
#define TARGET_IS_BLIZZARD_RB1

// Delay
#define DELAY_1MS   16650
#define DELAY_5MS   83250
#define DELAY_50MS  833350

// System Tick Timer
#define SYSTEMTICK_FREQ         10000    // 10KHz

// Timer 0_A
#define TIMER0_FREQ             1000   // 1kHz

// Timer 1_A
#define TIMER1_FREQ             100   // 100Hz

// SSI [SPI]
#define SSI0_FREQ               10000000      // 10MHz
#define SSI_BITS                8       // Number of Data Bits

// I2C
#define TX_SIZE         16
#define RX_SIZE         16

// LEDs
#define LED_RED_GPIO_BASE       GPIO_PORTF_BASE
#define LED_BLUE_GPIO_BASE      GPIO_PORTF_BASE
#define LED_GREEN_GPIO_BASE     GPIO_PORTF_BASE
#define RGB_GPIO_BASE       GPIO_PORTF_BASE

#define RED_LED                 BIT_1
#define BLUE_LED                BIT_2
#define GREEN_LED               BIT_3
#define RGB_LED                 BIT_1|BIT_2|BIT_3

// Switches and Pushbuttons
#define SW_GPIO_BASE            GPIO_PORTF_BASE
#define SW1                     BIT_4  // Left PushButton
#define SW2                     BIT_0  // Right PushButton
#define ALL_SW                  (SW1|SW2)

//// LCD
#define LCD_PIXELS      76800
#define LCD_WIDTH       240
#define LCD_HEIGHT      320

#define ILI9341_SPI_BASE        SSI0_BASE

#define ILI9341_CS_GPIO_BASE    GPIO_PORTA_BASE
#define ILI9341_CS              BIT_3
#define CS_ENABLE               CLEAR
#define CS_DISABLE              ILI9341_CS

#define ILI9341_DC_GPIO_BASE    GPIO_PORTA_BASE
#define ILI9341_DC              BIT_7
#define DC_DATA                 ILI9341_DC
#define DC_CMD                  CLEAR

#define ILI9341_RST_GPIO_BASE   GPIO_PORTA_BASE
#define ILI9341_RST             BIT_6
#define RST_ENABLE              CLEAR
#define RST_DISABLE             ILI9341_RST

// LCD_TESTING
#define SPACE_BETWEEN_LINES     1       // Fancy Lines

// AT24 
#define AT24_DEVICE_ADDR         0x50    



#endif