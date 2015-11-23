//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

void LCD_Reset(void);
void LCD_InitialOptions(void);
void LCD_Exit_Sleep(void);
void Turn_On_DISPLAY(void);

void LCD_Write_Data8(uint32_t data);
void LCD_Write_Data16(uint32_t data);
void LCD_Write_Command(uint32_t cmd);

void LCD_Set_Column_Address(uint32_t colStart, uint32_t colEnd);
void LCD_Set_Row_Address(uint32_t rowStart, uint32_t rowEnd);
void LCD_Set_Address(uint32_t colStart, uint32_t colEnd, uint32_t rowStart, uint32_t rowEnd);
void LCD_Fill_Address(uint32_t colStart, uint32_t colEnd, uint32_t rowStart, uint32_t rowEnd, uint32_t color);


int32_t abs(int32_t n);

// Signal Macros
#define CS(x)           ROM_GPIOPinWrite(ILI9341_CS_GPIO_BASE, ILI9341_CS, x)
#define RST(x)          ROM_GPIOPinWrite(ILI9341_RST_GPIO_BASE, ILI9341_RST, x)
#define DC(x)           ROM_GPIOPinWrite(ILI9341_DC_GPIO_BASE, ILI9341_DC, x)

// Helper Macros
#define COLOR(x)        LCD_Translate_Color_24_16bit(0,x)

// Initialize Display
void LCD_Init(void){
  
  // Enable GPIO Clock for RST and DC lines
  ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  
  // Enable pin PA7 for GPIOOutput - ILI9341 :: DC
  ROM_GPIOPinTypeGPIOOutput(ILI9341_DC_GPIO_BASE, GPIO_PIN_7);
  
  // Enable pin PA6 for GPIOOutput - ILI9341 :: RST
  ROM_GPIOPinTypeGPIOOutput(ILI9341_RST_GPIO_BASE, GPIO_PIN_6);
  
  // Reset Display
  LCD_Reset();
  
  // Enable Chip Select
  CS(CS_ENABLE); 
  
  // Set Initial Options
  LCD_InitialOptions();
  
  // Fill the Background
  LCD_Fill_Display(BLACK);
  
  // Exit Sleep Mode
  LCD_Exit_Sleep();
  
  // Turn ON Display
  Turn_On_DISPLAY();
  
  // Fill Display
  LCD_Fill_Display(BLACK);
  
  // Initialize the Graphics Library Context
  GrContextInit(&App.LCD_Context, &LCD);
  
  // Draw Initial Images
  LCD_DefaultDisplay();
}

void LCD_Clock(void){
  
  static float count = 0.0;
  static float count2 = 0.0;
  float radius = 40.0;
  float angleA = 0.0;
  float angleB = 0.0;
  
  // Set Center
  int32_t x0;
  int32_t y0;
  
  int32_t x1;
  int32_t y1;
  int32_t x2;
  int32_t y2;
  
  x0 = (LCD_WIDTH/2)-1;
  y0 = (((LCD_HEIGHT-20)/2)-1)+20;
  
  // Line
  if(count<360){
    angleA = (count-1)*(0.0174533);
    angleB = count*(0.0174533);
    x1 = x0 + (int32_t)(radius*sinf(angleA));
    y1 = y0 + (int32_t)(radius*cosf(angleA));
    x2 = x0 + (int32_t)(radius*sinf(angleB));
    y2 = y0 + (int32_t)(radius*cosf(angleB));
    // Line
    LCD_Draw_Line(x0,y0,x1,y1,YELLOW);
    LCD_Draw_Line(x0,y0,x1+1,y1+1,YELLOW);
    LCD_Draw_Line(x0,y0,x2,y2,BLUE);
    LCD_Draw_Line(x0,y0,x2+1,y2+1,BLUE);
    count++;
  }else{
    count = 0;
  }
  if(count2>0){
    angleA = (count2-1)*(0.0174533);
    angleB = count2*(0.0174533);
    x1 = x0 + (int32_t)(radius*sinf(angleA));
    y1 = y0 + (int32_t)(radius*cosf(angleA));
    x2 = x0 + (int32_t)(radius*sinf(angleB));
    y2 = y0 + (int32_t)(radius*cosf(angleB));
    // Line
    LCD_Draw_Line(x0,y0,x1,y1,RED);
    LCD_Draw_Line(x0,y0,x1+1,y1+1,RED);
    LCD_Draw_Line(x0,y0,x2,y2,YELLOW);
    LCD_Draw_Line(x0,y0,x2+1,y2+1,YELLOW);
    count2--;
  }else{
    count2 = 360;
  }
  // Circle Outline
  LCD_Draw_Circle((LCD_WIDTH/2)-1,(((LCD_HEIGHT-20)/2)-1)+20,40,WHITE);
  LCD_Draw_Circle((LCD_WIDTH/2)-1,(((LCD_HEIGHT-20)/2)-1)+20,39,WHITE);
  LCD_Draw_Circle((LCD_WIDTH/2)-1,(((LCD_HEIGHT-20)/2)-1)+20,38,WHITE);
  
  
}

void LCD_DefaultDisplay(void){
  
  
  // Header Box with Border
  LCD_Fill_Address(0,(LCD_WIDTH-1),0,11,COLOR(ClrDarkBlue));
  LCD_Draw_Border(0,(LCD_WIDTH-1),0,11,WHITE);
  
  // Header Text
  GrContextForegroundSet(&CONTEXT, ClrWhite);
  GrContextFontSet(&CONTEXT, g_psFontFixed6x8);
  GrStringDrawCentered(&CONTEXT, APP_NAME, -1, GrContextDpyWidthGet(&CONTEXT) / 2, 5, 0);
  
  // Circle
  LCD_Fill_Circle((LCD_WIDTH/2)-1,(((LCD_HEIGHT-20)/2)-1)+20,40,COLOR(ClrYellow));
  
  
  
  // Overlaping Rectangles with Borders
  LCD_Fill_Address(10,75,50,125,COLOR(ClrDeepPink));
  LCD_Draw_Border(10,75,50,125,WHITE);
  LCD_Fill_Address(5,70,45,120,COLOR(ClrGray));
  LCD_Draw_Border(5,70,45,120,WHITE);
  
  // Draw Text
  GrContextForegroundSet(&CONTEXT, ClrWhite);
  GrStringDraw(&CONTEXT, "Hello", -1, 18, 65, 0); 
  GrContextFontSet(&CONTEXT, g_psFontCmtt16);
  GrStringDraw(&CONTEXT, "WORLD!", -1, 12, 83, 0);
  
  GrContextFontSet(&CONTEXT, g_psFontCm48);
  GrContextForegroundSet(&CONTEXT, ClrMediumSeaGreen);
  GrStringDraw(&CONTEXT, "GOOD", -1, 15, 220, 0);
  
  GrContextFontSet(&CONTEXT, g_psFontCm48);
  GrContextForegroundSet(&CONTEXT, ClrMediumVioletRed);
  GrStringDraw(&CONTEXT, "JOB!", -1, 100, 265, 0); 
}

// Reset Display
void LCD_Reset(void){
  
  // Disable Chip Select
  CS(CS_DISABLE);    
  
  // Reset Off
  RST(RST_DISABLE);               // Set Reset High
  ROM_SysCtlDelay(DELAY_50MS);    // Delay for 50ms
  
  // Reset On
  RST(RST_ENABLE);                     // Set Reset Low
  ROM_SysCtlDelay(DELAY_50MS);    // Delay for 50ms
  
  // Reset Off
  RST(RST_DISABLE);               // Set Reset High
  ROM_SysCtlDelay(DELAY_50MS);    // Delay for 50ms
}

// Setup Initial Screen Options
void LCD_InitialOptions(void){
  
  // Note: Pin 1 Marking on PCB Board is Top Right of Screen == (239,0)
  
  // Command: Memory Access Control
  LCD_Write_Command(ILI9341_MEMORY_ACCESS_CONTROL );             
  LCD_Write_Data8(ILI9341_MEMORY_ACCESS_CONTROL_P1_MX_HIGH |
                  //                  ILI9341_MEMORY_ACCESS_CONTROL_P1_MY_HIGH |            // Pixels Scan Top to Bottom
                  ILI9341_MEMORY_ACCESS_CONTROL_P1_BGR_BGR );         // Set Color Order to Bluw-Green-Red [256R.256G.256B]
  
  
  // Command: COLMOD: Pixel Format Set  
  LCD_Write_Command(ILI9341_COLMOD_PIXEL_FORMAT_SET);
  LCD_Write_Data8((ILI9341_COLMOD_PIXEL_FORMAT_SET_P1_RGB_16BIT         // Set RGB to 16-Bit Color (default is 18-bit)
                   | ILI9341_COLMOD_PIXEL_FORMAT_SET_P1_MCU_16BIT));    // Set MCU to 16-bit Color (default is 18-bit)
  
}

// Exit Sleep Mode
void LCD_Exit_Sleep(void){
  
  LCD_Write_Command(ILI9341_SLEEP_OUT);       // Recover from SLEEP MODE
  ROM_SysCtlDelay(DELAY_5MS);                 // Delay for 5ms
}

// Turn ON Display
void Turn_On_DISPLAY(void){
  LCD_Write_Command(ILI9341_DISPLAY_ON);    // Turn ON Display
}

// Write 8-bit value; DC = DATA 
void LCD_Write_Data8(uint32_t data){
  while(ROM_SSIBusy(ILI9341_SPI_BASE)){
  }
  DC(DC_DATA);
  SPI_Write(ILI9341_SPI_BASE, &data);
}

// Write 16-bit value; DC = DATA
void LCD_Write_Data16(uint32_t data){
  while(ROM_SSIBusy(ILI9341_SPI_BASE)){
  }
  DC(DC_DATA);
  uint32_t tmp= (data >> 8);
  SPI_Write(ILI9341_SPI_BASE, &tmp);
  SPI_Write(ILI9341_SPI_BASE, &data);
}

// Write 8-bit command; DC = CMD
void LCD_Write_Command(uint32_t cmd){
  while(ROM_SSIBusy(ILI9341_SPI_BASE)){
  }
  DC(DC_CMD);
  SPI_Write(ILI9341_SPI_BASE, &cmd);
}

// Set Column Address
void LCD_Set_Column_Address(uint32_t colStart, uint32_t colEnd){ 
  LCD_Write_Command(ILI9341_COLUMN_ADDRESS_SET);
  LCD_Write_Data16(colStart);
  LCD_Write_Data16(colEnd);
}

// Set Page Address
void LCD_Set_Row_Address(uint32_t rowStart, uint32_t rowEnd){
  
  LCD_Write_Command(ILI9341_PAGE_ADDRESS_SET);
  LCD_Write_Data16(rowStart);
  LCD_Write_Data16(rowEnd);
}

// Set Area Address
void LCD_Set_Address(uint32_t colStart, uint32_t colEnd, uint32_t rowStart, uint32_t rowEnd){
  LCD_Set_Column_Address(colStart,colEnd);        // set columns
  LCD_Set_Row_Address(rowStart,rowEnd);          // set rows
  LCD_Write_Command(ILI9341_MEMORY_WRITE);    // reset to colStart, rowStart
}

// Fill a specified area
void LCD_Fill_Address(uint32_t colStart, uint32_t colEnd, uint32_t rowStart, uint32_t rowEnd, uint32_t color){
  
  // get total number of pixels to traverse
  uint32_t pixelTotal = ((colEnd - colStart) + 1)*((rowEnd - rowStart) + 1);
  
  // set the bounding area address
  LCD_Set_Address(colStart,colEnd,rowStart,rowEnd);
  
  // traverse through the pixels, writing color to each
  for(int32_t pixelID=0; pixelID < pixelTotal; pixelID++){
    LCD_Write_Data16(color);
  }
  
}

// Fill Maximum Area of Display
void LCD_Fill_Display(uint32_t color){
  LCD_Fill_Address( (0),(LCD_WIDTH-1),(0),(LCD_HEIGHT-1), color);
}

// Translate 24-Bit RGB to 16-Bit
uint32_t LCD_Translate_Color_24_16bit(void *pData, uint32_t color24){
  return ( ((color24 & 0x00F80000) >> 8) |    // select the 5msb of Red              
          ((color24 & 0x0000FC00) >> 5) |   // 6msb of Green  
            ((color24 & 0x000000F8) >> 3) ); // 5msb of Blue
}

// Flush (part of TI graphic Library API)
void LCD_Flush(void *pData){
  // N/A
}

// Draw a Horizontal Line
void LCD_Draw_LineHorz(void *pData, int32_t colStart, int32_t colEnd, int32_t row, uint32_t color){
  if((colEnd < LCD_WIDTH) && (row < LCD_HEIGHT)){
    LCD_Fill_Address( (colStart), (colEnd), (row), (row), color );
  }
}

// Draw a Vertical Line
void LCD_Draw_LineVert(void *pData, int32_t column, int32_t rowStart, int32_t rowEnd, uint32_t color){
  if((column < LCD_WIDTH) && (rowEnd < LCD_HEIGHT)){
    LCD_Fill_Address( (column), (column), (rowStart), (rowEnd), color );
  }
}

// Fill Minimum Area of Display
void LCD_Fill_Pixel(void *pData,int32_t x, int32_t y, uint32_t color){
  if((x < LCD_WIDTH) && (y < LCD_HEIGHT)){
    LCD_Fill_Address( (x),(x),(y),(y), color);
  }
}

// Fill Horz Line with Data
void LCD_Fill_LineHorz_wData(void *pData, int32_t x, int32_t y, int32_t subOff, int32_t pxCount, int32_t bitsPerPx, const uint8_t *pPxData, const uint8_t *pPalette){
  
  uint32_t color;
  uint32_t data;
  uint32_t pixelID=0;
  
  // set the bounding area address
  LCD_Set_Address(x,x+(pxCount-1),y,y+(pxCount-1));
  
  // Fill Based on How Many Bits in One Byte Equal One Pixel
  switch(bitsPerPx){
    
    // Each Bit of Each Byte Represents A Color
  case 1:
    // traverse through the pixels
    for(int32_t pixelID=0; pixelID < pxCount; pixelID++){
      // get the next byte
      data = *pPxData++;
      // traverse the byte of data
      for(; ((subOff < 8) && pxCount); subOff++, pxCount--){
        color = ((uint32_t *)pPalette)[((data >> (7 - subOff)) & BIT_0)];
        // write the color
        LCD_Write_Data16(color);
      }
      // Reset the SubOffset
      subOff = 0;
    }
    break;
    
  case 4:
    // SubOff is either a 1 [b0000] or a 4 [b0100]
    // Check the first bit to determine 1 or 4 sub offset
    switch(subOff & BIT_0){
      // SubOff = 4
    case 0:
      // traverse through the pixels
      for(; pixelID < pxCount; pixelID++){
        // get the upper 4-bits [nibble] of next data byte
        data = (*pPxData >> 4) * 3;
        // translate raw data to palette color
        data = *(uint32_t *)(pPalette + data);
        // translate 24 bit data to 16 bit color
        color = LCD_Translate_Color_24_16bit(pData,data);
        // write the color
        LCD_Write_Data16(color);
        // lower Pixel Count
        pxCount--;
        // Check for Another Pixel
        if(pxCount){
        case 1:         
          // get the lower 4-bits [nibble] of next data byte
          data = (*pPxData >> 15) * 3;
          // translate raw data to palette color
          data = *(uint32_t *)(pPalette + data);
          // translate 24 bit data to 16 bit color
          color = LCD_Translate_Color_24_16bit(pData,data);
          // write the color
          LCD_Write_Data16(color);
          // lower Pixel Count
          pxCount--;
        }
      }
    }
    break;
    
    // Each Byte Represents A Color
  case 8:
    // traverse through the pixels, writing color to each
    for(int32_t pixelID=0; pixelID < pxCount; pixelID++){
      // get the next byte
      data = *pPxData++ * 3;
      // translate raw data to palette color
      data = *(uint32_t *)(pPalette + data);
      // translate 24 bit data to 16 bit color
      color = LCD_Translate_Color_24_16bit(pData,data);
      // write the color
      LCD_Write_Data16(color);
    }
    break;
    
  default:
    break;
  }
}

// Fill a Rectangle
void LCD_Fill_Rectangle(void *pData,const tRectangle *pRect, uint32_t color){
  LCD_Fill_Address(pRect->i16XMin,pRect->i16XMax,pRect->i16YMin,pRect->i16YMax,color);
}

// Absolute Value
int32_t abs(int32_t n){
  return (n * ((n>0) - (n<0)));
}

// Draw a Line
void LCD_Draw_Line(uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1, uint32_t color){
  
  // Implements Bresenham's line algorithm 
  // From Pseudocode found at: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
  
  int32_t width = (x1 - x0);
  int32_t height = (y1 - y0);
  int32_t longest = abs(width);
  int32_t shortest = abs(height);
  int32_t numerator;
  int32_t dx0 = 0;
  int32_t dy0 = 0; 
  int32_t dx1 = 0; 
  int32_t dy1 = 0;
  
  
  // Translation Logic for Octant
  // Reference: http://tech-algorithm.com/articles/drawing-line-using-bresenham-algorithm
  if (width<0) {
    dx0 = -1 ; 
  }else if (width>0) {
    dx0 = 1 ;
  }
  
  if (width<0){ 
    dx1 = -1 ; 
  } else if (width>0){
    dx1 = 1 ;
  }
  
  if (height<0) {
    dy0 = -1 ; 
  } else if (height>0) {
    dy0 = 1 ;
  }
  
  if (!(longest>shortest)) {
    longest = abs(height) ;
    shortest = abs(width) ;
    if (height<0) dy1 = -1 ; else if (height>0) dy1 = 1 ;
    dx1 = 0 ;            
  }
  
  // Output Line
  numerator = longest >> 1 ;
  for (int32_t i=0;i<=longest;i++) {
    LCD_Fill_Pixel(0,x0,y0,color) ;
    numerator += shortest ;
    if (!(numerator<longest)) {
      numerator -= longest ;
      x0 += dx0 ;
      y0 += dy0 ;
    } else {
      x0 += dx1 ;
      y0 += dy1 ;
    }
  }
  //  }
}

// Draw a Border
void LCD_Draw_Border(uint32_t colStart, uint32_t colEnd, uint32_t rowStart, uint32_t rowEnd, uint32_t color){
  if((colEnd < LCD_WIDTH) && (rowEnd < LCD_HEIGHT)){
    LCD_Draw_LineHorz(0,colStart,colEnd,rowStart,color);
    LCD_Draw_LineHorz(0,colStart,colEnd,rowEnd,color);
    LCD_Draw_LineVert(0,colStart,rowStart,rowEnd,color);
    LCD_Draw_LineVert(0,colEnd,rowStart,rowEnd,color);
  }
}

// Draw a Circle
void LCD_Draw_Circle(int32_t x0, int32_t y0, int32_t radius, uint32_t color){
  
  // Implements Bresenham's Circle Algorithm 
  // Variant with Integer-Based Arithmetic
  // https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
  int32_t x;                            // Declare X
  int32_t y;                            // Declare Y
  int32_t decision;                     // Declare Decision
  int32_t radErr;                       // Declare Radius Error
  int32_t yChange;                      // Declare Y-Change
  int32_t xChange;                      // Declare X-Change
  
  x = radius;                           // Set Initial X Value
  y = 0;                                // Set Initial Y Value
  
  for(; y<=x; y++ ){                    // Traverse the Y-Axis
    
    LCD_Fill_Pixel(0,(x+x0),(y+y0),color);        // Draw Pixel in Octant 0   
    LCD_Fill_Pixel(0,(y+x0),(x+y0),color);        // Draw Pixel in Octant 1
    LCD_Fill_Pixel(0,(-y+x0),(x+y0),color);       // Draw Pixel in Octant 2
    LCD_Fill_Pixel(0,(-x+x0),(y+y0),color);       // Draw Pixel in Octant 3
    LCD_Fill_Pixel(0,(-x+x0),(-y+y0),color);      // Draw Pixel in Octant 4
    LCD_Fill_Pixel(0,(-y+x0),(-x+y0),color);      // Draw Pixel in Octant 5
    LCD_Fill_Pixel(0,(y+x0),(-x+y0),color);       // Draw Pixel in Octant 6
    LCD_Fill_Pixel(0,(x+x0),(-y+y0),color);        // Draw Pixel in Octant 7   
    
    radErr = (x*x)+(y*y)-(radius*radius);       // Calculate Radius Error
    yChange = ((2*y)+1);                        // Calculate Y-Change
    xChange = (1-(2*x));                        // Calculate X-Change
    decision = (radErr + yChange) + xChange;    // Calculate Decision
    if (decision > 0){                          // Check Sign of Decision
      x--;                                      // If Positive, Decrease X by 1
    }
  }
}

// Draw a Circle
void LCD_Fill_Circle(int32_t x0, int32_t y0, int32_t radius, uint32_t color){
  
  // Implements Bresenham's Circle Algorithm 
  // Variant with Integer-Based Arithmetic
  // https://en.wikipedia.org/wiki/Midpoint_circle_algorithm 
  int32_t x;                            // Declare X
  int32_t y;                            // Declare Y
  int32_t decision;                     // Declare Decision
  int32_t radErr;                       // Declare Radius Error
  int32_t yChange;                      // Declare Y-Change
  int32_t xChange;                      // Declare X-Change
  
  x = radius;                           // Set Initial X Value
  y = 0;                                // Set Initial Y Value
  
  for(; y<=x; y++ ){                    // Traverse the Y-Axis
    // Draw Lines Instead of Points
    LCD_Draw_LineHorz(0,(-x+x0),(x+x0),(y+y0),color);  // O4x -> O7x; row = O4|O7y
    LCD_Draw_LineHorz(0,(-x+x0),(x+x0),(-y+y0),color);  // O1x -> O6x; row = O1|O6y
    LCD_Draw_LineVert(0,(y+x0),(-x+y0),(x+y0),color);  // O2y -> O5y; col = O2|O5x
    LCD_Draw_LineVert(0,(-y+x0),(-x+y0),(x+y0),color);  // O3y -> O0y; col = O3|O0x
    
    radErr = (x*x)+(y*y)-(radius*radius);       // Calculate Radius Error
    yChange = ((2*y)+1);                        // Calculate Y-Change
    xChange = (1-(2*x));                        // Calculate X-Change
    decision = (radErr + yChange) + xChange;    // Calculate Decision
    if (decision > 0){                          // Check Sign of Decision
      x--;                                      // If Positive, Decrease X by 1
    }
  }
}

// Fill a Specified Area with an Image
void LCD_Fill_With_Image(uint32_t colStart, uint32_t colEnd, uint32_t rowStart, uint32_t rowEnd, uint32_t size, uint16_t *pColor){
  // get total number of pixels to traverse
  uint32_t pixelTotal = size-1;
  
  // set the bounding area address
  LCD_Set_Address(colStart,colEnd,rowStart,rowEnd);
  
  // traverse through the pixels, writing color to each
  for(int32_t pixelID=0; pixelID < pixelTotal; pixelID++){
    LCD_Write_Data16(*pColor);
    pColor++;
  }
}

void LCD_FancyLines(void){
  
  uint32_t header_margin=20;
  uint32_t Ox = (LCD_WIDTH/2)-1;
  uint32_t Oy = (((LCD_HEIGHT-header_margin)/2)-1)+header_margin;
  // Fancy Lines
  uint32_t index;
  for(index = ((LCD_HEIGHT-header_margin)/SPACE_BETWEEN_LINES); index > 0 ; index--){
    GrContextForegroundSet( &CONTEXT,( ((((300-index)*127)/300) << ClrGreenShift) | ((((index)*127)/300) << ClrRedShift)  ));
    LCD_Draw_Line(Ox, Oy, 0, header_margin + (index*SPACE_BETWEEN_LINES),App.LCD_Context.ui32Foreground);
  }
  for(index = 0; index < ((LCD_WIDTH)/SPACE_BETWEEN_LINES); index++){
    GrContextForegroundSet( &CONTEXT,( ((((300-index)*127)/300) << ClrGreenShift) | ((((index)*127)/300) << ClrGreenShift)  ));
    LCD_Draw_Line(Ox, Oy,(index*SPACE_BETWEEN_LINES),header_margin,App.LCD_Context.ui32Foreground);
  }
  for(index = 0; index < ((LCD_HEIGHT-header_margin)/SPACE_BETWEEN_LINES); index++){
    GrContextForegroundSet( &CONTEXT,( ((((300-index)*127)/300) << ClrGreenShift) | ((((index)*127)/300) << ClrBlueShift)  ));
    LCD_Draw_Line(Ox, Oy, LCD_WIDTH-1, header_margin + (index*SPACE_BETWEEN_LINES),App.LCD_Context.ui32Foreground);
  }
  for(index = 0; index < ((LCD_WIDTH)/SPACE_BETWEEN_LINES); index++){
    GrContextForegroundSet( &CONTEXT,( ((((300-index)*127)/300) << ClrBlueShift) | ((((index)*127)/300) << ClrRedShift)  ));
    LCD_Draw_Line( Ox, Oy,LCD_WIDTH-(index*SPACE_BETWEEN_LINES),(LCD_HEIGHT-1),App.LCD_Context.ui32Foreground);
  }
  
}
