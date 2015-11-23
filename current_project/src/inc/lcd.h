//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

#ifndef __LCD_H__
#define __LCD_H__

extern void LCD_Init(void);
extern void LCD_Fill_Display(uint32_t color);
extern uint32_t LCD_Translate_Color_24_16bit(void *pData, uint32_t color24);
extern void LCD_Flush(void *pData);
extern void LCD_Draw_LineHorz(void *pData, int32_t colStart, int32_t colEnd, int32_t row, uint32_t color);
extern void LCD_Draw_LineVert(void *pData, int32_t column, int32_t rowStart, int32_t rowEnd, uint32_t color);
extern void LCD_Fill_Pixel(void *pData,int32_t x, int32_t y, uint32_t color);
extern void LCD_Fill_LineHorz_wData(void *pData, int32_t x, int32_t y, int32_t subOff, int32_t pxCount, int32_t bitsPerPx, const uint8_t *pPxData, const uint8_t *pPalette);
extern void LCD_Fill_Rectangle(void *pData,const tRectangle *pRect, uint32_t color);

extern void LCD_Fill_Display(uint32_t color);
extern void LCD_Draw_Line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint32_t color);
extern void LCD_Draw_Border(uint32_t colStart, uint32_t colEnd, uint32_t rowStart, uint32_t rowEnd, uint32_t color);   
extern void LCD_Fill_Circle(int32_t x0, int32_t y0, int32_t radius, uint32_t color);
extern void LCD_Draw_Circle(int32_t x0, int32_t y0, int32_t radius, uint32_t color);

extern void LCD_Fill_With_Image(uint32_t colStart, uint32_t colEnd, uint32_t rowStart, uint32_t rowEnd, uint32_t size, uint16_t *pColor);

extern void LCD_DefaultDisplay(void);
extern void LCD_Clock(void);
extern void LCD_FancyLines(void);
#endif