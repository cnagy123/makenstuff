#ifndef HD44780_H
#define	HD44780_H

#include <xc.h>
#include <stdint.h>
#include "pic16f18875_config.h"

// Control Commands
#define LCD_CLEARDISPLAY    0x01u
#define LCD_RETURNHOME      0x02u
#define LCD_ENTRYMODESET    0x04u
#define LCD_DISPLAYCONTROL  0x08u
#define LCD_CURSORSHIFT     0x10u
#define LCD_FUNCTIONSET     0x20u
#define LCD_SETCGRAMADDR    0x40u
#define LCD_SETDDRAMADDR    0x80u

// Entry Mode Control
#define LCD_ENTRYRIGHT          0x00u
#define LCD_ENTRYLEFT           0x02u
#define LCD_ENTRYSHIFTINCREMENT 0x01u
#define LCD_ENTRYSHIFTDECREMENT 0x00u
#define LCD_INCREMENTCURSOR     0x02u
#define LCD_DECREMENTCURSOR     0x00u
#define LCD_AUTOSCROLLON        0x01u
#define LCD_AUTOSCROLLOFF       0x00u

// Display On/Off Control
#define LCD_DISPLAYON   0x04u
#define LCD_DISPLAYOFF  0x00u
#define LCD_CURSORON    0x02u
#define LCD_CURSOROFF   0x00u
#define LCD_BLINKON     0x01u
#define LCD_BLINKOFF    0x00u

// Display/Cursor Shift
#define LCD_DISPLAYMOVE 0x08u
#define LCD_CURSORMOVE  0x00u
#define LCD_MOVERIGHT   0x04u
#define LCD_MOVELEFT    0x00u

// Function Set
#define LCD_8BITMODE    0x10u
#define LCD_4BITMODE    0x00u
#define LCD_2LINE       0x08u
#define LCD_1LINE       0x00u
#define LCD_5x10DOTS    0x04u
#define LCD_5x8DOTS     0x00u

void LCD_Set_Data(uint8_t data);    
void LCD_Write_Cmd(uint8_t cmd);
void LCD_Init(void);
void LCD_Clear(void);
void LCD_Home(void);
void LCD_On(void);
void LCD_Off(void);
void LCD_Cursor(uint8_t mode);
void LCD_Set_Cursor(uint8_t row, uint8_t col);
void LCD_Move_Cursor_Left(void);
void LCD_Move_Cursor_Right(void);
void LCD_Scroll_Left(void);
void LCD_Scroll_Right(void);
void LCD_Autoscroll_On(void);
void LCD_Autoscroll_Off(void);
void LCD_Write_Char(uint8_t ch);
void LCD_Write_String(const char *str);
void LCD_Write_Integer(int i);
void LCD_Write_Float(float f);
void LCD_Create_Char(uint8_t addr, const uint8_t * data);


#endif