//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

// Application Status Information
ApplicationStruct App;

// This Struct Links My LCD code to the TI Graphics Library
const tDisplay LCD = {
    sizeof(tDisplay),
    0,
    240,
    320,
    LCD_Fill_Pixel,
    LCD_Fill_LineHorz_wData,
    LCD_Draw_LineHorz,
    LCD_Draw_LineVert,
    LCD_Fill_Rectangle,
    LCD_Translate_Color_24_16bit,
    LCD_Flush
};

uint32_t I2C_TX[TX_SIZE];
uint32_t I2C_RX[RX_SIZE];