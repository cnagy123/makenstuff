
#include "hd44780.h"

uint8_t displayReg = 0x00;
const uint8_t rowaddr[4] = {0x00, 0x40, 0x14, 0x54};

void LCD_Set_Data(uint8_t data)
{
    if(data & BIT_1){
        LCD_D4 = 1;
    }else{
        LCD_D4 = 0;
    }   
    if(data & BIT_2){
        LCD_D5 = 1;
    }else{
        LCD_D5 = 0;
    }
    if(data & BIT_3){
        LCD_D6 = 1;
    }else{
        LCD_D6 = 0;
    }
    if(data & BIT_4){
        LCD_D7 = 1;
    }else{
        LCD_D7 = 0;
    }
}

void LCD_Write_Cmd(uint8_t cmd)
{
    LCD_RS = 0;
    LCD_Set_Data((uint8_t)(cmd >> 4));
    LCD_EN = 1;
    __delay_ms(1);
    LCD_EN = 0;
    LCD_Set_Data(cmd);
    LCD_EN = 1;
    __delay_ms(1);
    LCD_EN = 0;
}

void LCD_Init(void)
{
    // Configure outputs
	LCD_RS_TRIS = 0;
	LCD_EN_TRIS = 0;
    
    LCD_D4_TRIS = 0;
	LCD_D5_TRIS = 0;
	LCD_D6_TRIS = 0;
	LCD_D7_TRIS = 0;
    
    // Set outputs low
    LCD_D4 = 0;
    LCD_D5 = 0;
    LCD_D6 = 0;
    LCD_D7 = 0;
    
    // Initial Power-up Delay
	__delay_ms(100);
    
    // Initialize LCD
    LCD_Write_Cmd(0x03);
    __delay_ms(5);
    LCD_Write_Cmd(0x03);
    __delay_us(120);
    LCD_Write_Cmd(0x03);
    __delay_us(120);
    LCD_Write_Cmd(0x02);
    __delay_us(120);
    LCD_Write_Cmd(LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x10DOTS);
    __delay_us(50);
    
    // Configure the LCD
    LCD_Write_Cmd(LCD_DISPLAYCONTROL | LCD_DISPLAYOFF);
	__delay_us(50);
	LCD_Write_Cmd(LCD_CLEARDISPLAY);
	__delay_ms(2);
	LCD_Write_Cmd(LCD_ENTRYMODESET | LCD_AUTOSCROLLOFF | LCD_INCREMENTCURSOR);
	__delay_us(50);
}

void LCD_Clear(void)
{
    LCD_Write_Cmd(LCD_CLEARDISPLAY);
	__delay_ms(2);
}

void LCD_Home(void)
{
   LCD_Write_Cmd(LCD_RETURNHOME);
	__delay_ms(2); 
}

void LCD_On(void)
{
    displayReg = displayReg | LCD_DISPLAYON;
    LCD_Write_Cmd(LCD_DISPLAYCONTROL | displayReg);
    __delay_us(50);
}

void LCD_Off(void)
{
    displayReg = displayReg & ~LCD_DISPLAYON;
    LCD_Write_Cmd(LCD_DISPLAYCONTROL | displayReg);
    __delay_us(50);
}

void LCD_Cursor(uint8_t mode)
{
	displayReg = displayReg & 0xFCu;
	displayReg = (uint8_t)(displayReg | mode);
	LCD_Write_Cmd(LCD_DISPLAYCONTROL | displayReg);
	__delay_us(50);
}

void LCD_Set_Cursor(uint8_t row, uint8_t col)
{
    if(row >= LCD_ROWS){
        row = LCD_ROWS - 1;
    }
    if(col >= LCD_COLUMNS){
        col = LCD_COLUMNS - 1;
    }
    LCD_Write_Cmd(LCD_SETDDRAMADDR | (uint8_t)(col + rowaddr[row]));
}

void LCD_Move_Cursor_Left(void)
{
    LCD_Write_Cmd(LCD_CURSORSHIFT | LCD_CURSORMOVE | LCD_MOVELEFT);
	__delay_us(50);
}

void LCD_Move_Cursor_Right(void)
{
    LCD_Write_Cmd(LCD_CURSORSHIFT | LCD_CURSORMOVE | LCD_MOVERIGHT);
	__delay_us(50);
}

void LCD_Scroll_Left(void)
{
    LCD_Write_Cmd(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
	__delay_us(50);
}

void LCD_Scroll_Right(void)
{
    LCD_Write_Cmd(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
	__delay_us(50);
}

void LCD_Autoscroll_On(void)
{
    LCD_Write_Cmd(LCD_ENTRYMODESET | LCD_AUTOSCROLLON | LCD_INCREMENTCURSOR);
	__delay_us(50);
}

void LCD_Autoscroll_Off(void)
{
    LCD_Write_Cmd(LCD_ENTRYMODESET | LCD_AUTOSCROLLOFF | LCD_DECREMENTCURSOR);
	__delay_us(50);
}

void LCD_Write_Char(uint8_t ch)
{
    LCD_RS = 1;
    LCD_EN = 1;
    LCD_Set_Data((uint8_t)(ch >> 4));
    LCD_EN = 0;
    LCD_EN = 1;
    LCD_Set_Data(ch & 0x0Fu);
    LCD_EN = 0;
}

void LCD_Write_String(const char *str)
{
    uint16_t i;
    for(i = 0; str[i] != '\0'; i++){
        LCD_Write_Char(str[i]);
    }
}

void LCD_Write_Integer(int i)
{
    uint8_t buf[8];
    LCD_Write_String(itoa(buf, i, 10));
}

void LCD_Write_Float(float f)
{
    int status;
    LCD_Write_String(ftoa(f, &status));
}

void LCD_Create_Char(uint8_t addr, const uint8_t * data)
{
    uint8_t i;
	addr = addr & 0x07u;
	LCD_Write_Cmd(LCD_SETCGRAMADDR | (uint8_t)(addr << 3));
	for (i = 0; i < 8; i++){
        LCD_Write_Char(data[i]);
    }
}