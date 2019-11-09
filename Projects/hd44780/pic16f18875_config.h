/* 
 * File:   pic16f18875_config.h
 * Author: chris
 *
 * Created on November 7, 2019, 8:16 PM
 */

#ifndef PIC16F18875_CONFIG_H
#define	PIC16F18875_CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////
//
//	System Config
//
///////////////////////////////////////////////////////////////////////////////

// CONFIG1
#pragma config FEXTOSC = OFF    // External Oscillator mode selection bits->Oscillator not enabled
#pragma config RSTOSC = HFINT1    // Power-up default value for COSC bits->HFINTOSC (1MHz)
#pragma config CLKOUTEN = OFF    // Clock Out Enable bit->CLKOUT function is disabled; i/o or oscillator function on OSC2
#pragma config CSWEN = ON    // Clock Switch Enable bit->Writing to NOSC and NDIV is allowed
#pragma config FCMEN = ON    // Fail-Safe Clock Monitor Enable bit->FSCM timer enabled

// CONFIG2
#pragma config MCLRE = ON    // Master Clear Enable bit->MCLR pin is Master Clear function
#pragma config PWRTE = OFF    // Power-up Timer Enable bit->PWRT disabled
#pragma config LPBOREN = OFF    // Low-Power BOR enable bit->ULPBOR disabled
#pragma config BOREN = ON    // Brown-out reset enable bits->Brown-out Reset Enabled, SBOREN bit is ignored
#pragma config BORV = LO    // Brown-out Reset Voltage Selection->Brown-out Reset Voltage (VBOR) set to 1.9V on LF, and 2.45V on F Devices
#pragma config ZCD = OFF    // Zero-cross detect disable->Zero-cross detect circuit is disabled at POR.
#pragma config PPS1WAY = OFF    // Peripheral Pin Select one-way control->The PPSLOCK bit can be set and cleared repeatedly by software
#pragma config STVREN = ON    // Stack Overflow/Underflow Reset Enable bit->Stack Overflow or Underflow will cause a reset
#pragma config DEBUG = OFF    // Background Debugger->Background Debugger disabled

// CONFIG3
#pragma config WDTCPS = WDTCPS_12    // WDT Period Select bits->Divider ratio 1:131072
#pragma config WDTE = SWDTEN    // WDT operating mode->WDT enabled/disabled by SWDTEN bit in WDTCON0
#pragma config WDTCWS = WDTCWS_7    // WDT Window Select bits->window always open (100%); software control; keyed access not required
#pragma config WDTCCS = HFINTOSC    // WDT input clock selector->WDT reference clock is the 31.25 kHz HFINTOSC

// CONFIG4
#pragma config WRT = OFF    // UserNVM self-write protection bits->Write protection off
#pragma config SCANE = available    // Scanner Enable bit->Scanner module is available for use
#pragma config LVP = ON    // Low Voltage Programming Enable bit->Low Voltage programming enabled. MCLR/Vpp pin function is MCLR.

// CONFIG5
#pragma config CP = OFF    // UserNVM Program memory code protection bit->Program Memory code protection disabled
#pragma config CPD = OFF    // DataNVM code protection bit->Data EEPROM code protection disabled

//////////////////////////////////////////////////////////////////////////////
//
//	Includes
//
///////////////////////////////////////////////////////////////////////////////
    
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <math.h>

//////////////////////////////////////////////////////////////////////////////
//
//	Defines
//
///////////////////////////////////////////////////////////////////////////////

// For delay routines
#define _XTAL_FREQ	500000

#define BIT_C	0x00
#define BIT_1	0x01
#define BIT_2	0x02
#define BIT_3	0x04
#define BIT_4	0x08
#define BIT_5	0x10
#define BIT_6	0x20
#define BIT_7	0x40
#define BIT_8	0x80

//////////////////////////////////////////////////////////////////////////////
//
//	LCD Pins
//
// 		-- HD44780 LCD -- 
//
// 		Vss--> GND
// 		Vdd--> 5V
// 		Vo --> RA0 // connected to pot
// 		RS --> RD2
// 		R/W--> RD1
// 		EN --> RD3
// 		D0 --> Not Connected
// 		D1 --> Not Connected
// 		D2 --> Not Connected
// 		D3 --> Not Connected
// 		D4 --> RD4
// 		D5 --> RD5
// 		D6 --> RD6
// 		D7 --> RD7
// 		A  --> 5V
// 		K  --> GND
//
///////////////////////////////////////////////////////////////////////////////
#define LCD_ROWS         2
#define LCD_COLUMNS     16
    
// LCD Control Pins
#define LCD_RS  RD2      // Register Select (Character or Instruction)
#define LCD_EN  RD3     // LCD Clock Enable PIN, Falling Edge

#define LCD_RS_TRIS TRISDbits.TRISD2
#define LCD_EN_TRIS TRISDbits.TRISD3
    
// LCD Data Pins
#define LCD_D4  RD4     // Bit 4
#define LCD_D5  RD5     // Bit 5
#define LCD_D6  RD6     // Bit 6
#define LCD_D7  RD7     // Bit 7
  
#define LCD_D4_TRIS TRISDbits.TRISD4    
#define LCD_D5_TRIS TRISDbits.TRISD5
#define LCD_D6_TRIS TRISDbits.TRISD6
#define LCD_D7_TRIS TRISDbits.TRISD7
    
#ifdef	__cplusplus
}
#endif

#endif	/* PIC16F18875_CONFIG_H */

