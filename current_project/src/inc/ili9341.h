//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

#ifndef __ILI9341_H__
#define __ILI9341_H__

//****************************************************************************//
//                                                                            //
//                      ILI9341 COMMAND LIST                                  //
//                      for ILITEK Small Driver IC ILI9341                    //
//                      Nagy, D. Chris               						  //
//                                                                            //
//****************************************************************************//

//**********   REGULATIVE COMMAND SET   **********//
//**********    [LEVEL 1 COMMANDS]      **********//

//************************************************//
//*************   NOP  ***************//
//************************************************//
// Command: NOP
// Description: Empty Command
#define ILI9341_NOP                                     0x00U
// No Parmeters

//************************************************//
//*************   Software Reset  ***************//
//************************************************//
// Command: Software Reset
// Description: Causes a Software Reset
#define ILI9341_SOFTWARE_RESET                          0x01U
// No Parmeters

//************************************************//
//****  Read Display Identification Information  *****//
//************************************************//
// Command: Read Display Identification Information
// Description: Returns 24 bits Display ID Info
#define ILI9341_READ_DISPLAY_ID                         0x04U
// 1st Parameter: Dummy Data
// 2nd Paramter:  LCD Manufacturer ID
// 3rd Parameter: LCD Driver Version
// 4th Parameter: LCD Driver ID

//************************************************//
//**  Read Display Status   **//
//************************************************//
// Command: Read Display Identification Information
// Description: Returns 24 bits Display ID Info
#define ILI9341_READ_DISPLAY_STATUS                     0x09U
// 1st Parameter: Dummy Data

// 2nd Paramter:  [D31:D25]
// D31 Booster voltage status: 		0 	-	Booster OFF
//									1 	-	Booster On
// D30 Row address order: 			0 	- 	Top to Bottom (When MADCTL B7=’0’)
//									1  	- 	Bottom to Top (When MADCTL B7=’1’)
// D29 Column address order: 		0	- 	Left to Right (When MADCTL B6=’0’)
//									1 	-	Right to Left (When MADCTL B6=’1’)
// D28 Row/column exchange:			0	- 	Normal Mode (When MADCTL B5=’0’)
//									1 	-	Reverse Mode (When MADCTL B5=’1’).
// D27 Vertical refresh:			0	- 	LCD Refresh Top to Bottom (When MADCTL B4=’0’)
//									1 	-	LCD Refresh Bottom to Top (When MADCTL B4=’1’)
// D26 RGB/BGR order				0 	-	RGB (When MADCTL B3=’0’)
// 									1	- 	BGR (When MADCTL B3=’1’)
// D25 Horizontal refresh order		0 	-	LCD Refresh Left to Right (When MADCTL B2=’0’)
// 									1	- 	LCD Refresh Right to Left (When MADCTL B2=’1’)

// 3rd Parameter: [D24:D16]
// D24 - Not Used
// D23 - Not Used							16-bit/pixel		18-bit/pixel
// D22 											1			-		1
// D21 Interface Color Pixel Format Definition	0			-		1
// D20											1			-		0
//
// D19 Idle mode ON/OFF				0 	-	Idle Mode OFF
//	 								1 	-	Idle Mode ON
// D18 Partial mode ON/OFF			0 	-	Partial Mode OFF
// 									1	- 	Partial Mode ON
// D17 Sleep IN/OUT					0 	-	Sleep IN Mode
// 									1 	-	Sleep OUT Mode
// D16 Display normal mode ON/OFF	0	- 	Display Normal Mode OFF
// 									1	-	Display Normal Mode ON

// 4th Parameter:  [D15:D8]
// D15 Vertical scrolling status 	0	- 	Scroll OFF
// D14 Not used 					0
// D13 Inversion status 			0 	-	Not defined
// D12 All pixel ON 				0 	-	Not defined
// D11 All pixel OFF 				0 	-	Not defined
// D10 Display ON/OFF				0 	-	Display is OFF
// 									1 	-	Display is ON
// D9 Tearing effect line ON/OFF	0 	-	Tearing Effect Line OFF
// 									1	-	Tearing Effect ON
// D8 Gamma curve selection*		000 - GC0

// 5th Parameter:  [D7:D0]
// D7,D6 *Gamma curve selection		000 - GC0
// D5 Tearing effect line mode		0	-	Mode 1, V-Blanking only
// 									1 	-	Mode 2, both H-Blanking and V-Blanking.
// D4 Not used 0
// D3 Not used 0
// D2 Not used 0
// D1 Not used 0
// D0 Not used 0


//************************************************//
//*************   Read Display Power Mode  *******//
//************************************************//
// Command: Read Display Power Mode
// Description: Indicates the Current Status of the Display
#define ILI9341_READ_DISPLAY_POWER_MODE                 0x0AU
// 1st Parameter: Dummy Data

// 2nd Paramter:
// D7	0 	-	Booster Off or has a fault
//		1 	-	Booster On and working OK
// D6	0 	-	Idle Mode Off
// 		1 	-	Idle Mode On.
// D5	0 	-	Partial Mode Off
// 		1 	-	Partial Mode On.
// D4	0 	-	Sleep In Mode
// 		1 	-	Sleep Out Mode
// D3	0 	-	Display Normal Mode Off
// 		1 	-	Display Normal Mode On
// D2	0 	-	Display is Off
// 		1 	-	Display is On
// D1 	- 	-	Not Defined :: Set to ‘0’
// D0 	- 	-	Not Defined :: Set to ‘0’

//************************************************//
//*************   Read Display MADCTL  *******//
//************************************************//
// Command: Read Display MADCTL
// Description: Indicates the Current Status
#define ILI9341_READ_DISPLAY_MADCTL                     0x0BU
// 1st Parameter: Dummy Data

// 2nd Paramter:
// D7	0 	-	Top to Bottom (When MADCTL B7=’0’)
//		1 	-	Bottom to Top (When MADCTL B7=’1’)
// D6	0 	-	Left to Right (When MADCTL B6=’0’)
// 		1 	-	Right to Left (When MADCTL B6=’1’)
// D5	0 	-	Normal Mode (When MADCTL B5=’0’)
// 		1 	-	Reverse Mode (When MADCTL B5=’1’)
// D4	0 	-	LCD Refresh Top to Bottom (When MADCTL B4=’0’)
// 		1 	-	LCD Refresh Bottom to Top (When MADCTL B4=’1’)
// D3	0 	-	RGB (When MADCTL B3=’0’)
// 		1 	-	BGR (When MADCTL B3=’1’)
// D2	0 	-	LCD Refresh Left to Right (When MADCTL B2=’0’)
// 		1 	-	LCD Refresh Right to Left (When MADCTL B2=’1’)
// D1 	- 	-	Switching between Segment outputs and RAM :: Set to ‘0’
// D0 	- 	-	Switching between Segment outputs and RAM :: Set to ‘0’

//************************************************//
//*************   Read Display Pixel Format  *******//
//************************************************//
// Command: Read Display Pixel Format
// Description: Indicates the Current Status
#define ILI9341_READ_DISPLAY_PIXEL_FORMAT               0x0CU
// 1st Parameter: Dummy Data

// 2nd Paramter:
// D[7:4]
// RIM 		DPI[2:0]
//	0		101		- 	16 bits / pixel
//	0		110		-	18 bits / pixel
//	1		101		-	16 bits / pixel (6-bit 3 times data transfer)
//	1		110		-	18 bits / pixel (6-bit 3 times data transfer)
// D[3:0]
//	D3		DBI [2:0]
//	0		101		-	16 bits / pixel
//	0		110		-	18 bits / pixel


//************************************************//
//*************   Read Display Image Format  *******//
//************************************************//
// Command: Read Display Image Format
// Description: Indicates the Current Status
#define ILI9341_READ_DISPLAY_IMAGE_FORMAT               0x0DU
// 1st Parameter: Dummy Read

// 2nd Paramter:
//	D[7:3]	D[2:0]
//	00000	000		-	Gamma Curve 1 (G2.2)
//	00000	001		-	---
//	00000	010		-	---
//	00000	011		-	---

//************************************************//
//*************   Read Display Signal Mode  *******//
//************************************************//
// Command: Read Display Signal Mode
// Description: Indicates the Current Status
#define ILI9341_READ_DISPLAY_SIGNAL_MODE                0x0EU
// 1st Parameter: Dummy Read

// 2nd Paramter:
// D7	0 	-	Tearing effect line OFF
//		1 	-	Tearing effect line ON
// D6	0 	-	Tearing effect line mode 1
// 		1 	-	Tearing effect line mode 2
// D5	0 	-	Horizontal sync. (RGB interface) OFF
// 		1 	-	Horizontal sync. (RGB interface) ON
// D4	0 	-	Vertical sync. (RGB interface) OFF
// 		1 	-	Vertical sync. (RGB interface) ON
// D3	0 	-	Pixel clock (DOTCLK, RGB interface) OFF
// 		1 	-	Pixel clock (DOTCLK, RGB interface) ON
// D2	0 	-	Data enable (DE, RGB interface) OFF
// 		1 	-	Data enable (DE, RGB interface) ON
// D1 	0 	-	Reserved
// D0 	0 	-	Reserved

//************************************************//
//*************   Read Display Self-Diagnostic Result  *******//
//************************************************//
// Command: Read Display Self-Diagnostic Result
// Description: Indicates the Current Status
#define ILI9341_READ_DISPLAY_SELF_DIAGNOSTIC_RESULT     0x0FU
// 1st Parameter: Dummy Read

// 2nd Paramter:
// D7	Register Loading Detection 	-	Invert the D7 bit if register values loading work properly.
// D6	Functionality Detection 	-	Invert the D6 bit if the display is functionality

//************************************************//
//*************   Enter Sleep Mode  ***************//
//************************************************//
// Command: Enter Sleep Mode
// Description: Enter the Minimum Power Consumption Mode
#define ILI9341_ENTER_SLEEP_MODE                                0x10U
// No Parmeters

//************************************************//
//*************   Sleep Out  ***************//
//************************************************//
// Command: Sleep Out
// Description: Turn Off Sleep Mode
#define ILI9341_SLEEP_OUT                               0x11U
// No Parmeters

//************************************************//
//*************   Partial Mode ON  ***************//
//************************************************//
// Command: Partial Mode ON
// Description: Turn ON Partial Mode
#define ILI9341_SPARTIAL_MODE_ON                         0x12U
// To leave Partial mode, the Normal Display Mode ON Command (0x13) Should be Written
// No Parmeters

//************************************************//
//*************   Normal Display Mode ON  ***************//
//************************************************//
// Command: Normal Display Mode ON
// Description: Returns the Display to Normal Mode
#define ILI9341_SNORMAL_DISPLAY_MODE_ON                  0x13U
// No Parmeters

//************************************************//
//*************   Display Inversion OFF  ***************//
//************************************************//
// Command: Display Inversion OFF
// Description: Recover from Display Inversion Mode.
#define ILI9341_SDISPLAY_INVERSION_OFF                   0x20U
// No Parmeters

//************************************************//
//*************   Display Inversion ON  ***************//
//************************************************//
// Command: Display Inversion ON
// Description: Enter Display Inversion Mode.
#define ILI9341_SDISPLAY_INVERSION_ON                    0x21U
// No Parmeters

//************************************************//
//*************   Gamma Set  ***************//
//************************************************//
// Command: Gamma Set
// Description: Select the Desired Gamma curve
#define ILI9341_GAMMA_SET								0x26U
// 1st Parameter: GC
#define ILI9341_GAMMA_SET_P1_GAMMA_CURVE_1				0x01U	// b0000.0001


//************************************************//
//*************   Display OFF  ***************//
//************************************************//
// Command: Display OFF
// Description: Enter DISPLAY OFF Mode
#define ILI9341_DISPLAY_OFF                             0x28U
// No Parmeters

//************************************************//
//*************   Display ON  ***************//
//************************************************//
// Command: Display ON
// Description: Recover from DISPLAY OFF Mode
#define ILI9341_DISPLAY_ON                              0x29U
// No Parmeters

//************************************************//
//*************   Column Address Set  ***************//
//************************************************//
// Command: Column Address Set
// Description: define area of frame memory where MCU can access
#define ILI9341_COLUMN_ADDRESS_SET              0x2AU
// 1st Parameter: SC_High   [Start Column]
// 2nd Parameter: SC_Low
// 3rd Parameter: EC_High   [End Column]
// 4th Parameter: EC_Low

//************************************************//
//*************   Page Address Set  ***************//
//************************************************//
// Command: Page Address Set
// Description: Define Area of Frame Memory Where MCU can Access
#define ILI9341_PAGE_ADDRESS_SET                        0x2BU
// 1st Parameter: SP_High   [Start Page]
// 2nd Parameter: SP_Low
// 3rd Parameter: EP_High   [End Page]
// 4th Parameter: EP_Low

//************************************************//
//*************   Memory Write  ***************//
//************************************************//
// Command: Memory Write
// Description: Transfers Image Data form MCU to Frame Memory
#define ILI9341_MEMORY_WRITE                            0x2CU
// 1st Parameter: D1 [17:0]
// 2nd Parameter: D2 [17:0]
// ...
// (N+1)th Parameter: Dn [17:0]

//************************************************//
//*************   Color Set  ***************//
//************************************************//
// Command: Color Set
// Description: Defines the LUT for 16-bit to 18-bit Color Depth Conversion
#define ILI9341_COLOR_SET                               0x2DU
// 1st Parameter: 			R00 [5:0]
// ...
// (N+1)th Parameter: 		Rnn [5:0]
// ...
// 32nd Parameter:			R31 [5:0]
// 33rd Parameter:			G00 [5:0]
// ...
// (N+1)th Parameter: 		Gnn [5:0]
// ...
// 96th Parameter:			G31 [5:0]
// 97th Parameter:			B00 [5:0]
// ...
// (N+1)th Parameter: 		Bnn [5:0]
// ...
// 128th Parameter:			B31 [5:0]

//************************************************//
//*************   Memory Read  ***************//
//************************************************//
// Command: Memory Read
// Description: Transfers Image Data form Frame Memory to MCU
#define ILI9341_MEMORY_READ                             0x2EU
// B5 of Mem Access Control == 0 :: SC -> EC; P++
// B5 of Mem Access Control == 1 :: SP -> EP; C++
// 1st Parameter: D1 [17:0]
// 2nd Parameter: D2 [17:0]
// ...
// (N+1)th Parameter: Dn [17:0]

//************************************************//
//*************   Partial Area  ***************//
//************************************************//
// Command: Partial Area
// Description: Define the Partial Mode Display Area
#define ILI9341_PARTIAL_AREA                            0x30U
// 1st Parameter: Start Row - SR [15:8]
// 2nd Parameter: Start Row - SR [7:0]
// 3rd Parameter: End Row - ER [15:8]
// 4th Parameter: End Row - ER [7:0]

//************************************************//
//*************   Vertical Scrolling Definition  ********//
//************************************************//
// Command: Vertical Scrolling Definition
// Description: Defines the Vertical Scrolling Area
#define ILI9341_VERTICAL_SCROLLING_DEFINITION           0x33U
// 1st Parameter: Top Fixed Area - TFA [15:8]
// 2nd Parameter: Top Fixed Area - TFA [7:0]
// 3rd Parameter: Vertical Scrolling Area - VSA [15:8]
// 4th Parameter: Vertical Scrolling Area - VSA [7:0]
// 5th Parameter: Bottom Fixed Area - BFA [15:8]
// 6th Parameter: Bottom Fixed Area - BFA [7:0]

//************************************************//
//*************   Tearing Effect Line OFF  ********//
//************************************************//
// Command: Tearing Effect Line OFF
// Description: Turn OFF the Tearing Effect Output Signal
#define ILI9341_TEARING_EFFECT_LINE_OFF                 0x34U
// No Parmeters

//************************************************//
//*************   Tearing Effect Line ON  ***************//
//************************************************//
// Command: Tearing Effect Line ON
// Description: Turn ON the Tearing Effect Output Signal
#define ILI9341_TEARING_EFFECT_LINE_ON                          0x35U
// 1st Parameter: M
#define ILI9341_TEARING_EFFECT_LINE_ON_P1_VBLANK_ONLY	        0x00U
#define ILI9341_TEARING_EFFECT_LINE_ON_P1_VH_BLANK		0x01U

//************************************************//
//***********   Memory Access Control  ***********//
//************************************************//
// Command: Memory Access Control
// Description: Defines Read/Write Scanning Direction of Frame Memory
#define ILI9341_MEMORY_ACCESS_CONTROL                           0x36U

// 1st Parameter: [ MY | MX | MV | ML | BGR | MH ]
// MY : Row Address Order
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_MY_LOW			0x00U
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_MY_HIGH		0x80U
// MX : Column Address Order
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_MX_LOW			0x00U
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_MX_HIGH		0x40U
// MV : Row / Column Exchange
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_MV__DIRECT		0x00U
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_MV_OVERLEFT	0x20U
// ML
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_ML_UP2DOWN		0x00U
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_ML_DOWN2UP		0x10U
// BGR
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_BGR_RGB		0x00U
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_BGR_BGR		0x08U
// MH
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_MH_LFT2RHT		0x00U
#define ILI9341_MEMORY_ACCESS_CONTROL_P1_MH_RHT2LFT		0x04U

//************************************************//
//*****   Vertical Scrolling Start Address  *********//
//************************************************//
// Command: Vertical Scrolling Start Address
// Description: Describe the Scrolling Area and the Scrolling Sode
#define ILI9341_VERICAL_SCROLLING_START_ADDRESS         0x37U
// 1st Parameter: Vertical Start Page - VSP [15:8]
// 2nd Parameter: Vertical Start Page - VSP [7:0]

//************************************************//
//*****   Idle Mode OFF  *********//
//************************************************//
// Command: Idle Mode OFF
// Description: Recover from Idle Mode ON
#define ILI9341_IDLE_MODE_OFF                           0x38U
// No Parameters

//************************************************//
//*****   Idle Mode ON  *********//
//************************************************//
// Command: Idle Mode ON
// Description: Enter Idle Mode ON
#define ILI9341_IDLE_MODE_ON                            0x39U
// No Parameters

//************************************************//
//*************  COLMOD: Pixel Format Set     ****//
//************************************************//
// Command: COLMOD: Pixel Format Set
// Sets Pixel Format for RGB Image Data used by MCU
#define ILI9341_COLMOD_PIXEL_FORMAT_SET                 0x3AU

// 1st Parameter: [ RGB | MCU ]
//RGB
#define ILI9341_COLMOD_PIXEL_FORMAT_SET_P1_RGB_16BIT    0x50U
#define ILI9341_COLMOD_PIXEL_FORMAT_SET_P1_RGB_18BIT    0x60U
//MCU
#define ILI9341_COLMOD_PIXEL_FORMAT_SET_P1_MCU_16BIT    0x05U
#define ILI9341_COLMOD_PIXEL_FORMAT_SET_P1_MCU_18BIT    0x06U



/*****************************************************************************************/

#define ILI9341_WRITE_MEMORY_CONTINUE                   0x3CU
#define ILI9341_READ_MEMORY_CONTINUE                    0x3EU
#define SILI9341_ET_TEAR_SCANLINE                       0x44U
#define ILI9341_GET_SCANLINE                            0x45U
#define ILI9341_WRITE_DISPLAY_BRIGHTNESS                0x51U
#define ILI9341_READ_DISPLAY_BRIGHTNESS                 0x52U
#define ILI9341_WRITE_CTRL_DISPLAY                      0x53U
#define ILI9341_READ_CTRL_DISPLAY                       0x54U
#define ILI9341_WRITE_CONTENT_ADAPTIVE_BRIGHT_CTRL      0x55U
#define ILI9341_READ_CONTENT_ADAPTIVE_BRIGHT_CRTL       0x56U
#define ILI9341_WRITE_CABC_MINIMUM_BRIGHTNESS           0x5EU
#define ILI9341_READ_CABC_MINIMUM_BRIGHTNESS            0x5FU
#define ILI9341_READ_ID1                                0xDAU
#define ILI9341_READ_ID2                                0xDBU
#define ILI9341_READ_ID3                                0xDCU

//**********   REGULATIVE COMMAND SET   **********//
//**********    [LEVEL 2 COMMANDS]      **********//

#define ILI9341_RGB_INTERFACE_SIGNANL_CTRL              0xB0U
#define ILI9341_FRAME_RATE_CTRL_NORMAL_FULL_COLOR       0xB1U
#define ILI9341_FRAME_RATE_CTRL_IDLE_8_COLOR            0xB2U
#define ILI9341_FRAME_RATE_CTRL_PARTIAL_FULL_COLOR      0xB3U
#define ILI9341_DISPLAY_INVERSION_CTRL                  0xB4U
#define ILI9341_BLANKING_PORCH_CONTROL                  0xB5U
#define ILI9341_DISPLAY_FUNCTION_CTRL                   0xB6U
#define ILI9341_ENTRY_MODE_SET                          0xB7U
#define ILI9341_BACKLIGHT_CTRL_1                        0xB8U
#define ILI9341_BACKLIGHT_CTRL_2                        0xB9U
#define ILI9341_BACKLIGHT_CTRL_3                        0xBAU
#define ILI9341_BACKLIGHT_CTRL_4                        0xBBU
#define ILI9341_BACKLIGHT_CTRL_5                        0xBCU
#define ILI9341_BACKLIGHT_CTRL_7                        0xBEU
#define ILI9341_BACKLIGHT_CTRL_8                        0xBFU

/*****************************************************************************************/
//************************************************//
//*************  Power Control 1   ***************//
//************************************************//
// Command: Power Control 1
#define ILI9341_PWR_CTRL_1                            	0xC0U

// 1st Parameter: GVVD :: Reference Level for the VCOM Level and the Grayscale Voltage Level.
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_00					0x03U	// b0000.0011
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_05					0x04U	// b0000.0100
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_10					0x05U	// b0000.0101
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_15					0x06U	// b0000.0110
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_20					0x07U	// b0000.0111
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_25					0x08U	// b0000.1000
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_30					0x09U	// b0000.1001
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_35					0x0AU	// b0000.1010
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_40					0x0BU	// b0000.1011
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_45					0x0CU	// b0000.1100
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_50					0x0DU	// b0000.1101
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_55					0x0EU	// b0000.1110
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_60					0x0FU	// b0000.1111
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_65					0x10U	// b0001.0000
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_70					0x11U	// b0001.0001
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_75					0x12U	// b0001.0010
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_80					0x13U	// b0001.0011
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_85					0x14U	// b0001.0100
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_90					0x15U	// b0001.0101
#define ILI9341_PWR_CTRL_1_P1_GVVD_3_95					0x16U	// b0001.0110
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_00					0x17U	// b0001.0111
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_05					0x18U	// b0001.1000
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_10					0x19U	// b0001.1001
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_15					0x1AU	// b0001.1010
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_20					0x1BU	// b0001.1011
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_25					0x1CU	// b0001.1100
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_30					0x1DU	// b0001.1101
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_35					0x1EU	// b0001.1110
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_40					0x1FU	// b0001.1111
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_45					0x20U	// b0010.0000
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_50					0x21U	// b0010.0001
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_55					0x22U	// b0010.0010
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_60					0x23U	// b0010.0011
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_65					0x24U	// b0010.0100
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_70					0x25U	// b0010.0101
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_75					0x26U	// b0010.0110
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_80					0x27U	// b0010.0111
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_85					0x28U	// b0010.1000
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_90					0x29U	// b0010.1001
#define ILI9341_PWR_CTRL_1_P1_GVVD_4_95					0x2AU	// b0010.1010
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_00					0x2BU	// b0010.1011
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_05					0x2CU	// b0010.1100
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_10					0x2DU	// b0010.1101
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_15					0x2EU	// b0010.1110
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_20					0x2FU	// b0010.1111
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_25					0x30U	// b0011.0000
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_30					0x31U	// b0011.0001
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_35					0x32U	// b0011.0010
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_40					0x33U	// b0011.0011
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_45					0x34U	// b0011.0001
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_50					0x35U	// b0011.0101
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_55					0x36U	// b0011.0110
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_60					0x37U	// b0011.0111
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_65					0x38U	// b0011.1000
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_70					0x39U	// b0011.1001
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_75					0x3AU	// b0011.1010
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_80					0x3BU	// b0011.1011
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_85					0x3CU	// b0011.1100
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_90					0x3DU	// b0011.1101
#define ILI9341_PWR_CTRL_1_P1_GVVD_5_95					0x3EU	// b0011.1110
#define ILI9341_PWR_CTRL_1_P1_GVVD_6_00					0x3FU	// b0011.1111

//************************************************//
//*************  Power Control 2   ***************//
//************************************************//
// Command: Power Control 2
#define ILI9341_PWR_CTRL_2                            	                0xC1

// 1st Parameter: BT :: Factor Used in the Step-Up Circuits
#define ILI9341_PWR_CTRL_2_P1_VCI7_negVCI4				0x00	//b0000.0000
#define ILI9341_PWR_CTRL_2_P1_VCI7_negVCI3				0x01	//b0000.0001
#define ILI9341_PWR_CTRL_2_P1_VCI6_negVCI4				0x02	//b0000.0010
#define ILI9341_PWR_CTRL_2_P1_VCI6_negVCI3				0x03	//b0000.0011


//************************************************//
//*************   VCOM Control 1  ****************//
//************************************************//
// Command: VCOM Control 1
#define ILI9341_VCOM_CTRL_1                             0xC5

// 1st Parameter: VMH :: VCOMH Voltage
#define ILI9341_VCOMH_P1_2_700 							0x00	// b0000.0000
#define ILI9341_VCOMH_P1_2_725 							0x01	// b0000.0001
#define ILI9341_VCOMH_P1_2_750 							0x02	// b0000.0010
#define ILI9341_VCOMH_P1_2_775 							0x03	// b0000.0011
#define ILI9341_VCOMH_P1_2_800 							0x04	// b0000.0100
#define ILI9341_VCOMH_P1_2_825 							0x05	// b0000.0101
#define ILI9341_VCOMH_P1_2_850 							0x06	// b0000.0110
#define ILI9341_VCOMH_P1_2_875 							0x07	// b0000.0111
#define ILI9341_VCOMH_P1_2_900 							0x08	// b0000.1000
#define ILI9341_VCOMH_P1_2_925 							0x09	// b0000.1001
#define ILI9341_VCOMH_P1_2_950 							0x0A	// b0000.1010
#define ILI9341_VCOMH_P1_2_975 							0x0B	// b0000.1011
#define ILI9341_VCOMH_P1_3_000 							0x0C	// b0000.1100
#define ILI9341_VCOMH_P1_3_025 							0x0D	// b0000.1101
#define ILI9341_VCOMH_P1_3_050 							0x0E	// b0000.1110
#define ILI9341_VCOMH_P1_3_075 							0x0F	// b0000.1111
#define ILI9341_VCOMH_P1_3_100 							0x10	// b0001.0000
#define ILI9341_VCOMH_P1_3_125 							0x11	// b0001.0001
#define ILI9341_VCOMH_P1_3_150 							0x12	// b0001.0010
#define ILI9341_VCOMH_P1_3_175 							0x13	// b0001.0011
#define ILI9341_VCOMH_P1_3_200 							0x14	// b0001.0100
#define ILI9341_VCOMH_P1_3_225 							0x15	// b0001.0101
#define ILI9341_VCOMH_P1_3_250 							0x16	// b0001.0110
#define ILI9341_VCOMH_P1_3_275 							0x17	// b0001.0111
#define ILI9341_VCOMH_P1_3_300 							0x18	// b0001.1000
#define ILI9341_VCOMH_P1_3_325 							0x19	// b0001.1001
#define ILI9341_VCOMH_P1_3_350 							0x1A	// b0001.1010
#define ILI9341_VCOMH_P1_3_375 							0x1B	// b0001.1011
#define ILI9341_VCOMH_P1_3_400 							0x1C	// b0001.1100
#define ILI9341_VCOMH_P1_3_425 							0x1D	// b0001.1101
#define ILI9341_VCOMH_P1_3_450 							0x1E	// b0001.1110
#define ILI9341_VCOMH_P1_3_475 							0x1F	// b0001.1111
#define ILI9341_VCOMH_P1_3_500 							0x20	// b0010.0000
#define ILI9341_VCOMH_P1_3_525 							0x21	// b0010.0001
#define ILI9341_VCOMH_P1_3_550 							0x22	// b0010.0010
#define ILI9341_VCOMH_P1_3_575 							0x23	// b0010.0011
#define ILI9341_VCOMH_P1_3_600 							0x24	// b0010.0100
#define ILI9341_VCOMH_P1_3_625 							0x25	// b0010.0101
#define ILI9341_VCOMH_P1_3_650 							0x26	// b0010.0110
#define ILI9341_VCOMH_P1_3_675 							0x27	// b0010.0111
#define ILI9341_VCOMH_P1_3_700 							0x28	// b0010.1000
#define ILI9341_VCOMH_P1_3_725 							0x29	// b0010.1001
#define ILI9341_VCOMH_P1_3_750 							0x2A	// b0010.1010
#define ILI9341_VCOMH_P1_3_775 							0x2B	// b0010.1011
#define ILI9341_VCOMH_P1_3_800 							0x2C	// b0010.1100
#define ILI9341_VCOMH_P1_3_825 							0x2D	// b0010.1101
#define ILI9341_VCOMH_P1_3_850 							0x2E	// b0010.1110
#define ILI9341_VCOMH_P1_3_875 							0x2F	// b0010.1111
#define ILI9341_VCOMH_P1_3_900 							0x30	// b0011.0000
#define ILI9341_VCOMH_P1_3_925 							0x31	// b0011.0001
#define ILI9341_VCOMH_P1_3_950 							0x32	// b0011.0010
#define ILI9341_VCOMH_P1_3_975 							0x33	// b0011.0011
#define ILI9341_VCOMH_P1_4_000 							0x34	// b0011.0100
#define ILI9341_VCOMH_P1_4_025 							0x35	// b0011.0101
#define ILI9341_VCOMH_P1_4_050 							0x36	// b0011.0110
#define ILI9341_VCOMH_P1_4_075 							0x37	// b0011.0111
#define ILI9341_VCOMH_P1_4_100 							0x38	// b0011.1000
#define ILI9341_VCOMH_P1_4_125 							0x39	// b0011.1001
#define ILI9341_VCOMH_P1_4_150 							0x3A	// b0011.1010
#define ILI9341_VCOMH_P1_4_175 							0x3B	// b0011.1011
#define ILI9341_VCOMH_P1_4_200 							0x3C	// b0011.1100
#define ILI9341_VCOMH_P1_4_225 							0x3D	// b0011.1101
#define ILI9341_VCOMH_P1_4_250 							0x3E	// b0011.1110
#define ILI9341_VCOMH_P1_4_275 							0x3F	// b0011.1111
#define ILI9341_VCOMH_P1_4_300 							0x40	// b0100.0000
#define ILI9341_VCOMH_P1_4_325 							0x41	// b0100.0001
#define ILI9341_VCOMH_P1_4_350							0x42	// b0100.0010
#define ILI9341_VCOMH_P1_4_375 							0x43	// b0100.0011
#define ILI9341_VCOMH_P1_4_400 							0x44	// b0100.0100
#define ILI9341_VCOMH_P1_4_425 							0x45	// b0100.0101
#define ILI9341_VCOMH_P1_4_450 							0x46	// b0100.0110
#define ILI9341_VCOMH_P1_4_475 							0x47	// b0100.0111
#define ILI9341_VCOMH_P1_4_500 							0x48	// b0100.1000
#define ILI9341_VCOMH_P1_4_525 							0x49	// b0100.1001
#define ILI9341_VCOMH_P1_4_550 							0x4A	// b0100.1010
#define ILI9341_VCOMH_P1_4_575 							0x4B	// b0100.1011
#define ILI9341_VCOMH_P1_4_600 							0x4C	// b0100.1100
#define ILI9341_VCOMH_P1_4_625							0x4D	// b0100.1101
#define ILI9341_VCOMH_P1_4_650 							0x4E	// b0100.1110
#define ILI9341_VCOMH_P1_4_675 							0x4F	// b0100.1111
#define ILI9341_VCOMH_P1_4_700 							0x50	// b0101.0000
#define ILI9341_VCOMH_P1_4_725 							0x51	// b0101.0001
#define ILI9341_VCOMH_P1_4_750 							0x52	// b0101.0010
#define ILI9341_VCOMH_P1_4_775 							0x53	// b0101.0011
#define ILI9341_VCOMH_P1_4_800 							0x54	// b0101.0100
#define ILI9341_VCOMH_P1_4_825 							0x55	// b0101.0101
#define ILI9341_VCOMH_P1_4_850 							0x56	// b0101.0110
#define ILI9341_VCOMH_P1_4_875 							0x57	// b0101.0111
#define ILI9341_VCOMH_P1_4_900 							0x58	// b0101.1000
#define ILI9341_VCOMH_P1_4_925 							0x59	// b0101.1001
#define ILI9341_VCOMH_P1_4_950 							0x5A	// b0101.1010
#define ILI9341_VCOMH_P1_4_975 							0x5B	// b0101.1011
#define ILI9341_VCOMH_P1_5_000 							0x5C	// b0101.1100
#define ILI9341_VCOMH_P1_5_025							0x5D	// b0101.1101
#define ILI9341_VCOMH_P1_5_050 							0x5E	// b0101.1110
#define ILI9341_VCOMH_P1_5_075 							0x5F	// b0101.1111
#define ILI9341_VCOMH_P1_5_100 							0x60	// b0110.0000
#define ILI9341_VCOMH_P1_5_125 							0x61	// b0110.0001
#define ILI9341_VCOMH_P1_5_150 							0x62	// b0110.0010
#define ILI9341_VCOMH_P1_5_175 							0x63	// b0110.0011
#define ILI9341_VCOMH_P1_5_200 							0x64	// b0110.0100
#define ILI9341_VCOMH_P1_5_225 							0x65	// b0110.0101
#define ILI9341_VCOMH_P1_5_250 							0x66	// b0110.0110
#define ILI9341_VCOMH_P1_5_275 							0x67	// b0110.0111
#define ILI9341_VCOMH_P1_5_300 							0x68	// b0110.1000
#define ILI9341_VCOMH_P1_5_325 							0x69	// b0110.1001
#define ILI9341_VCOMH_P1_5_350							0x6A	// b0110.1010
#define ILI9341_VCOMH_P1_5_375 							0x6B	// b0110.1011
#define ILI9341_VCOMH_P1_5_400 							0x6C	// b0110.1100
#define ILI9341_VCOMH_P1_5_425 							0x6D	// b0110.1101
#define ILI9341_VCOMH_P1_5_450 							0x6E	// b0110.1110
#define ILI9341_VCOMH_P1_5_475 							0x6F	// b0110.1111
#define ILI9341_VCOMH_P1_5_500 							0x70	// b0111.0000
#define ILI9341_VCOMH_P1_5_525 							0x71	// b0111.0001
#define ILI9341_VCOMH_P1_5_550 							0x72	// b0111.0010
#define ILI9341_VCOMH_P1_5_575 							0x73	// b0111.0011
#define ILI9341_VCOMH_P1_5_600							0x74	// b0111.0100
#define ILI9341_VCOMH_P1_5_625 							0x75	// b0111.0101
#define ILI9341_VCOMH_P1_5_650 							0x76	// b0111.0110
#define ILI9341_VCOMH_P1_5_675 							0x77	// b0111.0111
#define ILI9341_VCOMH_P1_5_700							0x78	// b0111.1000
#define ILI9341_VCOMH_P1_5_725							0x79	// b0111.1001
#define ILI9341_VCOMH_P1_5_750							0x7A	// b0111.1010
#define ILI9341_VCOMH_P1_5_775							0x7B	// b0111.1011
#define ILI9341_VCOMH_P1_5_800 							0x7C	// b0111.1100
#define ILI9341_VCOMH_P1_5_825 							0x7D	// b0111.1101
#define ILI9341_VCOMH_P1_5_850							0x7E	// b0111.1110
#define ILI9341_VCOMH_P1_5_875							0x7F	// b0111.1111

// 2nd Parameter: VML :: VCOML Voltage
#define ILI9341_VCOML_P2_neg2_500						0x00	// b0000.0000
#define ILI9341_VCOML_P2_neg2_475						0x01	// b0000.0001
#define ILI9341_VCOML_P2_neg2_450						0x02	// b0000.0010
#define ILI9341_VCOML_P2_neg2_425						0x03	// b0000.0011
#define ILI9341_VCOML_P2_neg2_400						0x04	// b0000.0100
#define ILI9341_VCOML_P2_neg2_375						0x05	// b0000.0101
#define ILI9341_VCOML_P2_neg2_350						0x06	// b0000.0110
#define ILI9341_VCOML_P2_neg2_325						0x07	// b0000.0111
#define ILI9341_VCOML_P2_neg2_300						0x08	// b0000.1000
#define ILI9341_VCOML_P2_neg2_275						0x09	// b0000.1001
#define ILI9341_VCOML_P2_neg2_250						0x0A	// b0000.1010
#define ILI9341_VCOML_P2_neg2_225						0x0B	// b0000.1011
#define ILI9341_VCOML_P2_neg2_200						0x0C	// b0000.1100
#define ILI9341_VCOML_P2_neg2_175						0x0D	// b0000.1101
#define ILI9341_VCOML_P2_neg2_150						0x0E	// b0000.1110
#define ILI9341_VCOML_P2_neg2_125						0x0F	// b0000.1111
#define ILI9341_VCOML_P2_neg2_100						0x10	// b0001.0000
#define ILI9341_VCOML_P2_neg2_075						0x11	// b0001.0001
#define ILI9341_VCOML_P2_neg2_050						0x12	// b0001.0010
#define ILI9341_VCOML_P2_neg2_025						0x13	// b0001.0011
#define ILI9341_VCOML_P2_neg2_000						0x14	// b0001.0100
#define ILI9341_VCOML_P2_neg1_975						0x15	// b0001.0101
#define ILI9341_VCOML_P2_neg1_950						0x16	// b0001.0110
#define ILI9341_VCOML_P2_neg1_925						0x17	// b0001.0111
#define ILI9341_VCOML_P2_neg1_900						0x18	// b0001.1000
#define ILI9341_VCOML_P2_neg1_875						0x19	// b0001.1001
#define ILI9341_VCOML_P2_neg1_850						0x1A	// b0001.1010
#define ILI9341_VCOML_P2_neg1_825						0x1B	// b0001.1011
#define ILI9341_VCOML_P2_neg1_800						0x1C	// b0001.1100
#define ILI9341_VCOML_P2_neg1_775						0x1D	// b0001.1101
#define ILI9341_VCOML_P2_neg1_750						0x1E	// b0001.1110
#define ILI9341_VCOML_P2_neg1_725						0x1F	// b0001.1111
#define ILI9341_VCOML_P2_neg1_700						0x20	// b0010.0000
#define ILI9341_VCOML_P2_neg1_675						0x21	// b0010.0001
#define ILI9341_VCOML_P2_neg1_650						0x22	// b0010.0010
#define ILI9341_VCOML_P2_neg1_625						0x23	// b0010.0011
#define ILI9341_VCOML_P2_neg1_600						0x24	// b0010.0100
#define ILI9341_VCOML_P2_neg1_575						0x25	// b0010.0101
#define ILI9341_VCOML_P2_neg1_550						0x26	// b0010.0110
#define ILI9341_VCOML_P2_neg1_525						0x27	// b0010.0111
#define ILI9341_VCOML_P2_neg1_500						0x28	// b0010.1000
#define ILI9341_VCOML_P2_neg1_475						0x29	// b0010.1001
#define ILI9341_VCOML_P2_neg1_450						0x2A	// b0010.1010
#define ILI9341_VCOML_P2_neg1_425						0x2B	// b0010.1011
#define ILI9341_VCOML_P2_neg1_400						0x2C	// b0010.1100
#define ILI9341_VCOML_P2_neg1_375						0x2D	// b0010.1101
#define ILI9341_VCOML_P2_neg1_350						0x2E	// b0010.1110
#define ILI9341_VCOML_P2_neg1_325						0x2F	// b0010.1111
#define ILI9341_VCOML_P2_neg1_300						0x30	// b0011.0000
#define ILI9341_VCOML_P2_neg1_275						0x31	// b0011.0001
#define ILI9341_VCOML_P2_neg1_250						0x32	// b0011.0010
#define ILI9341_VCOML_P2_neg1_225						0x33	// b0011.0011
#define ILI9341_VCOML_P2_neg1_200						0x34	// b0011.0100
#define ILI9341_VCOML_P2_neg1_175						0x35	// b0011.0101
#define ILI9341_VCOML_P2_neg1_150						0x36	// b0011.0110
#define ILI9341_VCOML_P2_neg1_125						0x37	// b0011.0111
#define ILI9341_VCOML_P2_neg1_100						0x38	// b0011.1000
#define ILI9341_VCOML_P2_neg1_075						0x39	// b0011.1001
#define ILI9341_VCOML_P2_neg1_050						0x3A	// b0011.1010
#define ILI9341_VCOML_P2_neg1_025						0x3B	// b0011.1011
#define ILI9341_VCOML_P2_neg1_000						0x3C	// b0011.1100
#define ILI9341_VCOML_P2_neg0_975						0x3D	// b0011.1101
#define ILI9341_VCOML_P2_neg0_950						0x3E	// b0011.1110
#define ILI9341_VCOML_P2_neg0_925						0x3F	// b0011.1111
#define ILI9341_VCOML_P2_neg0_900						0x40	// b0100.0000
#define ILI9341_VCOML_P2_neg0_875						0x41	// b0100.0001
#define ILI9341_VCOML_P2_neg0_850						0x42	// b0100.0010
#define ILI9341_VCOML_P2_neg0_825						0x43	// b0100.0011
#define ILI9341_VCOML_P2_neg0_800						0x44	// b0100.0100
#define ILI9341_VCOML_P2_neg0_775						0x45	// b0100.0101
#define ILI9341_VCOML_P2_neg0_750						0x46	// b0100.0110
#define ILI9341_VCOML_P2_neg0_725						0x47	// b0100.0111
#define ILI9341_VCOML_P2_neg0_700						0x48	// b0100.1000
#define ILI9341_VCOML_P2_neg0_675						0x49	// b0100.1001
#define ILI9341_VCOML_P2_neg0_650						0x4A	// b0100.1010
#define ILI9341_VCOML_P2_neg0_625						0x4B	// b0100.1011
#define ILI9341_VCOML_P2_neg0_600						0x4C	// b0100.1100
#define ILI9341_VCOML_P2_neg0_575						0x4D	// b0100.1101
#define ILI9341_VCOML_P2_neg0_550						0x4E	// b0100.1110
#define ILI9341_VCOML_P2_neg0_525						0x4F	// b0100.1111
#define ILI9341_VCOML_P2_neg0_500						0x50	// b0101.0000
#define ILI9341_VCOML_P2_neg0_475						0x51	// b0101.0001
#define ILI9341_VCOML_P2_neg0_450						0x52	// b0101.0010
#define ILI9341_VCOML_P2_neg0_425						0x53	// b0101.0011
#define ILI9341_VCOML_P2_neg0_400						0x54	// b0101.0100
#define ILI9341_VCOML_P2_neg0_375						0x55	// b0101.0101
#define ILI9341_VCOML_P2_neg0_350						0x56	// b0101.0110
#define ILI9341_VCOML_P2_neg0_325						0x57	// b0101.0111
#define ILI9341_VCOML_P2_neg0_300						0x58	// b0101.1000
#define ILI9341_VCOML_P2_neg0_275						0x59	// b0101.1001
#define ILI9341_VCOML_P2_neg0_250						0x5A	// b0101.1010
#define ILI9341_VCOML_P2_neg0_225						0x5B	// b0101.1011
#define ILI9341_VCOML_P2_neg0_200						0x5C	// b0101.1100
#define ILI9341_VCOML_P2_neg0_175						0x5D	// b0101.1101
#define ILI9341_VCOML_P2_neg0_150						0x5E	// b0101.1110
#define ILI9341_VCOML_P2_neg0_125						0x5F	// b0101.1111
#define ILI9341_VCOML_P2_neg0_100						0x60	// b0110.0000
#define ILI9341_VCOML_P2_neg0_075						0x61	// b0110.0001
#define ILI9341_VCOML_P2_neg0_050						0x62	// b0110.0010
#define ILI9341_VCOML_P2_neg0_025						0x63	// b0110.0011
#define ILI9341_VCOML_P2_neg0_000						0x64	// b0110.0100


//************************************************//
//*************   VCOM Control 2  ****************//
//************************************************//
// Command: VCOM Control 2
#define ILI9341_VCOM_CTRL_2                             0xC7

// 1st Parameter:	[ NVM | VMF ]
// NVM :: LOW: after Power On Reset and VCOM Offset == MTP Value.
// NVM :: HIGH: VMF is Valid and VCOM can be Agjusted
#define ILI9341_VCOM_CTRL_2_P1_NVM_VMF_INVAILD			0x00
#define ILI9341_VCOM_CTRL_2_P1_NVM_VMF_VALID			0x80

//VMF: VCOM Offset Voltage
#define ILI9341_VCOM_CTRL_2_P1_VMF_00					0x00	// b0000.0000
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg63				0x01	// b0000.0001
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg62				0x02	// b0000.0010
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg61				0x03	// b0000.0011
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg60				0x04	// b0000.0100
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg59				0x05	// b0000.0101
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg58				0x06	// b0000.0110
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg57				0x07	// b0000.0111
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg56				0x08	// b0000.1000
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg55				0x09	// b0000.1001
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg54				0x0A	// b0000.1010
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg53				0x0B	// b0000.1011
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg52				0x0C	// b0000.1100
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg51				0x0D	// b0000.1101
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg50				0x0E	// b0000.1110
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg49				0x0F	// b0000.1111
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg48				0x10	// b0001.0000
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg47				0x11	// b0001.0001
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg46				0x12	// b0001.0010
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg45				0x13	// b0001.0011
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg44				0x14	// b0001.0100
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg43				0x15	// b0001.0101
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg42				0x16	// b0001.0110
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg41				0x17	// b0001.0111
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg40				0x18	// b0001.1000
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg39				0x19	// b0001.1001
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg38				0x1A	// b0001.1010
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg37				0x1B	// b0001.1011
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg36				0x1C	// b0001.1100
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg35				0x1D	// b0001.1101
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg34				0x1E	// b0001.1110
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg33				0x1F	// b0001.1111
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg32				0x20	// b0010.0000
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg31				0x21	// b0010.0001
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg30				0x22	// b0010.0010
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg29				0x23	// b0010.0011
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg28				0x24	// b0010.0100
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg27				0x25	// b0010.0101
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg26				0x26	// b0010.0110
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg25				0x27	// b0010.0111
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg24				0x28	// b0010.1000
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg23				0x29	// b0010.1001
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg22				0x2A	// b0010.1010
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg21				0x2B	// b0010.1011
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg20				0x2C	// b0010.1100
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg19				0x2D	// b0010.1101
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg18				0x2E	// b0010.1110
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg17				0x2F	// b0010.1111
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg16				0x30	// b0011.0000
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg15				0x31	// b0011.0001
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg14				0x32	// b0011.0010
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg13				0x33	// b0011.0011
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg12				0x34	// b0011.0100
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg11				0x35	// b0011.0101
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg10				0x36	// b0011.0110
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg09				0x37	// b0011.0111
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg08				0x38	// b0011.1000
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg07				0x39	// b0011.1001
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg06				0x3A	// b0011.1010
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg05				0x3B	// b0011.1011
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg04				0x3C	// b0011.1100
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg03				0x3D	// b0011.1101
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg02				0x3E	// b0011.1110
#define ILI9341_VCOM_CTRL_2_P1_VMF_neg01				0x3F	// b0011.1111
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos01				0x40	// b0100.0000
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos02				0x41	// b0100.0001
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos03				0x42	// b0100.0010
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos04				0x43	// b0100.0011
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos05				0x44	// b0100.0100
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos06				0x45	// b0100.0101
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos07				0x46	// b0100.0110
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos08				0x47	// b0100.0111
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos09				0x48	// b0100.1000
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos10				0x49	// b0100.1001
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos11				0x4A	// b0100.1010
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos12				0x4B	// b0100.1011
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos13				0x4C	// b0100.1100
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos14				0x4D	// b0100.1101
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos15				0x4E	// b0100.1110
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos16				0x4F	// b0100.1111
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos17				0x50	// b0101.0000
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos18				0x51	// b0101.0001
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos19				0x52	// b0101.0010
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos20				0x53	// b0101.0011
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos21				0x54	// b0101.0100
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos22				0x55	// b0101.0101
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos23				0x56	// b0101.0110
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos24				0x57	// b0101.0111
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos25				0x58	// b0101.1000
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos26				0x59	// b0101.1001
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos27				0x5A	// b0101.1010
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos28				0x5B	// b0101.1011
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos29				0x5C	// b0101.1100
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos30				0x5D	// b0101.1101
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos31				0x5E	// b0101.1110
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos32				0x5F	// b0101.1111
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos33				0x60	// b0110.0000
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos34				0x61	// b0110.0001
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos35				0x62	// b0110.0010
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos36				0x63	// b0110.0011
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos37				0x64	// b0110.0100
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos38				0x65	// b0110.0101
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos39				0x66	// b0110.0110
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos40				0x67	// b0110.0111
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos41				0x68	// b0110.1000
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos42				0x69	// b0110.1001
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos43				0x6A	// b0110.1010
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos44				0x6B	// b0110.1011
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos45				0x6C	// b0110.1100
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos46				0x6D	// b0110.1101
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos47				0x6E	// b0110.1110
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos48				0x6F	// b0110.1111
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos49				0x70	// b0111.0000
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos50				0x71	// b0111.0001
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos51				0x72	// b0111.0010
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos52				0x73	// b0111.0011
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos53				0x74	// b0111.0100
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos54				0x75	// b0111.0101
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos55				0x76	// b0111.0110
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos56				0x77	// b0111.0111
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos57				0x78	// b0111.1000
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos58				0x79	// b0111.1001
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos59				0x7A	// b0111.1010
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos60				0x7B	// b0111.1011
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos61				0x7C	// b0111.1100
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos62				0x7D	// b0111.1101
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos63				0x7E	// b0111.1110
#define ILI9341_VCOM_CTRL_2_P1_VMF_pos64				0x7F	// b0111.1111


//************************************************//
//***************   NV Memory Write  *************//
//************************************************//
// Command: NV Memory Write
// Description: This command is used to program the NV memory data
#define ILI9341_NV_MEM_WRITE                         	0xD0

// 1st Parameter: PGM_ADR
// Description: Select Bits of ID1, ID2, ID3 and VMF Programming
#define ILI9341_NV_MEM_WRITE_P1_PGM_ADR_ID1				0x00	// b0000.0000
#define ILI9341_NV_MEM_WRITE_P1_PGM_ADR_ID2				0x01	// b0000.0001
#define ILI9341_NV_MEM_WRITE_P1_PGM_ADR_ID3				0x02	// b0000.0010
#define ILI9341_NV_MEM_WRITE_P1_PGM_ADR_VMF				0x04	// b0000.0100

// 2nd Parameter: PGM_DATA
// Description: 8-Bit [7:0] User or Default Programmed Data
// Default: MTP Value


//************************************************//
//***********   NV Memory Protection Key  ********//
//************************************************//
// Command:  NV Memory Protection Key
// Description: KEY [23:0]: NV Memory Programming Protection Key
// This Register Must be Set to 0x55AA66 to Enable MTP Programming
#define ILI9341_NV_MEMORY_PROTECTION_KEY                0xD1

// 1st Parameter: KEY [23:16]
#define ILI9341_NV_MEMORY_PROTECTION_KEY_P1				0x55

// 2nd Parameter: KEY [15:8]
#define ILI9341_NV_MEMORY_PROTECTION_KEY_P2				0xAA

// 3rd Parameter: KEY [7:0]
#define ILI9341_NV_MEMORY_PROTECTION_KEY_P3				0x66


//************************************************//
//************   NV Memory Status Read  **********//
//************************************************//
// Command:  NV Memory Status Read
// Description: ID1_CNT / ID2_CNT / ID3_CNT / VMF_CNT : NV Memory Program Record
// The Bits Will Increase “+1” Automatically After Writing the PGM_DATA [7:0] to NV Memory
#define ILI9341_NV_MEM_STAT_READ                   		0xD2

// 1st Parameter:
#define ILI9341_NV_MEM_STAT_READ_P1_DUMMY_READ			0x00	// b0000.0000

// 2nd Parameter: [ ID2_CNT | ID1_CNT ]
// ID2_CNT
#define ILI9341_NV_MEM_STAT_READ_P2_ID2_CNT_NO_PROG		0x00	// b0000.0000
#define ILI9341_NV_MEM_STAT_READ_P2_ID2_CNT_PROG_1		0x10	// b0001.0000
#define ILI9341_NV_MEM_STAT_READ_P2_ID2_CNT_PROG_2		0x30	// b0011.0000
#define ILI9341_NV_MEM_STAT_READ_P2_ID2_CNT_PROG_3		0x70	// b0111.0000
// ID1_CNT
#define ILI9341_NV_MEM_STAT_READ_P2_ID1_CNT_NO_PROG		0x00	// b0000.0000
#define ILI9341_NV_MEM_STAT_READ_P2_ID1_CNT_PROG_1		0x01	// b0000.0001
#define ILI9341_NV_MEM_STAT_READ_P2_ID1_CNT_PROG_2		0x03	// b0000.0011
#define ILI9341_NV_MEM_STAT_READ_P2_ID1_CNT_PROG_3		0x07	// b0000.0111

// 3rd Parameter: [ BUSY | VMF_CNT | ID3_CNT ]
// BUSY: Status Bit of NV Memory Programming
#define ILI9341_NV_MEM_STAT_READ_P3_BUSY_IDLE			0x00	// b0000.0000
#define ILI9341_NV_MEM_STAT_READ_P3_BUSY_BUSY			0x80	// b1000.0000
// VMF_CNT
#define ILI9341_NV_MEM_STAT_READ_P3_VMF_CNT_NO_PROG		0x00	// b0000.0000
#define ILI9341_NV_MEM_STAT_READ_P3_VMF_CNT_PROG_1		0x10	// b0001.0000
#define ILI9341_NV_MEM_STAT_READ_P3_VMF_CNT_PROG_2		0x30	// b0011.0000
#define ILI9341_NV_MEM_STAT_READ_P3_VMF_CNT_PROG_3		0x70	// b0111.0000
// ID3_CNT
#define ILI9341_NV_MEM_STAT_READ_P3_ID3_CNT_NO_PROG		0x00	// b0000.0000
#define ILI9341_NV_MEM_STAT_READ_P3_ID3_CNT_PROG_1		0x01	// b0000.0001
#define ILI9341_NV_MEM_STAT_READ_P3_ID3_CNT_PROG_2		0x03	// b0000.0011
#define ILI9341_NV_MEM_STAT_READ_P3_ID3_CNT_PROG_3		0x07	// b0000.0111


//************************************************//
//*****************   Read ID4   *****************//
//************************************************//
// Command:  Read ID4
// Description: Read IC device code
#define ILI9341_READ_ID4                                0xD3

// 1st Parameter: Dummy Read Period
#define ILI9341_READ_ID4_P1_DUMMY_READ					0x00	// b0000.0000

// 2nd Parameter: IC Version
#define ILI9341_READ_ID4_P2_IC_VERSION					0x00	// b0000.0000

// 3rd Parameter: IC Model Name
#define ILI9341_READ_ID4_P3_IC_NAME						0x93	// b1001.0011

// 4th Parameter: IC Model Name
#define ILI9341_READ_ID4_P4_IC_NAME						0x41	// b0100.0001


//************************************************//
//********   Positive Gamma Correction   *********//
//************************************************//
// Command:  Positive Gamma Correction
// Description: Set the Gray Scale Voltage to Adjust the Gamma Characteristics of the TFT Panel
#define ILI9341_POSITIVE_GAMMA_CORRECTION               0xE0

// 1st Parameter: VP63
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P1_VP63_0F	0x0F	// b0000.1111

// 2nd Parameter: VP62
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_0F	0x0F	// b0000.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_10	0x10	// b0001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_11	0x11	// b0001.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_12	0x12	// b0001.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_13	0x13	// b0001.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_14	0x14	// b0001.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_15	0x15	// b0001.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_16	0x16	// b0001.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_17	0x17	// b0001.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_18	0x18	// b0001.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_19	0x19	// b0001.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_1A	0x1A	// b0001.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_1B	0x1B	// b0001.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_1C	0x1C	// b0001.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_1D	0x1D	// b0001.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_1E	0x1E	// b0001.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_1F	0x1F	// b0001.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_20	0x20	// b0010.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_21	0x21	// b0010.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_22	0x22	// b0010.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_23	0x23	// b0010.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_24	0x24	// b0010.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_25	0x25	// b0010.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_26	0x26	// b0010.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_27	0x27	// b0010.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_28	0x28	// b0010.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_29	0x29	// b0010.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_2A	0x2A	// b0010.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_2B	0x2B	// b0010.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_2C	0x2C	// b0010.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_2D	0x2D	// b0010.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_2E	0x2E	// b0010.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_2F	0x2F	// b0010.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_30	0x30	// b0011.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_31	0x31	// b0011.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_32	0x32	// b0011.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_33	0x33	// b0011.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_34	0x34	// b0011.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_35	0x35	// b0011.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_36	0x36	// b0011.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_37	0x37	// b0011.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_38	0x38	// b0011.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_39	0x39	// b0011.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_3A	0x3A	// b0011.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_3B	0x3B	// b0011.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_3C	0x3C	// b0011.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_3D	0x3D	// b0011.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_3E	0x3E	// b0011.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P2_VP62_3F	0x3F	// b0011.1111

// 3rd Parameter: VP61
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_0F	0x0F	// b0000.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_10	0x10	// b0001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_11	0x11	// b0001.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_12	0x12	// b0001.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_13	0x13	// b0001.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_14	0x14	// b0001.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_15	0x15	// b0001.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_16	0x16	// b0001.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_17	0x17	// b0001.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_18	0x18	// b0001.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_19	0x19	// b0001.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_1A	0x1A	// b0001.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_1B	0x1B	// b0001.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_1C	0x1C	// b0001.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_1D	0x1D	// b0001.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_1E	0x1E	// b0001.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_1F	0x1F	// b0001.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_20	0x20	// b0010.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_21	0x21	// b0010.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_22	0x22	// b0010.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_23	0x23	// b0010.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_24	0x24	// b0010.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_25	0x25	// b0010.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_26	0x26	// b0010.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_27	0x27	// b0010.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_28	0x28	// b0010.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_29	0x29	// b0010.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_2A	0x2A	// b0010.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_2B	0x2B	// b0010.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_2C	0x2C	// b0010.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_2D	0x2D	// b0010.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_2E	0x2E	// b0010.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_2F	0x2F	// b0010.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_30	0x30	// b0011.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_31	0x31	// b0011.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_32	0x32	// b0011.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_33	0x33	// b0011.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_34	0x34	// b0011.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_35	0x35	// b0011.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_36	0x36	// b0011.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_37	0x37	// b0011.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_38	0x38	// b0011.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_39	0x39	// b0011.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_3A	0x3A	// b0011.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_3B	0x3B	// b0011.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_3C	0x3C	// b0011.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_3D	0x3D	// b0011.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_3E	0x3E	// b0011.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P3_VP61_3F	0x3F	// b0011.1111

// 4th Parameter: VP59
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P4_VP59_0F	0x0F	// b0000.1111

// 5th Parameter: VP57
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_0F	0x0F	// b0000.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_10	0x10	// b0001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_11	0x11	// b0001.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_12	0x12	// b0001.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_13	0x13	// b0001.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_14	0x14	// b0001.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_15	0x15	// b0001.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_16	0x16	// b0001.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_17	0x17	// b0001.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_18	0x18	// b0001.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_19	0x19	// b0001.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_1A	0x1A	// b0001.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_1B	0x1B	// b0001.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_1C	0x1C	// b0001.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_1D	0x1D	// b0001.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_1E	0x1E	// b0001.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P5_VP57_1F	0x1F	// b0001.1111

// 6th Parameter: VP50
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P6_VP50_0F	0x0F	// b0000.1111

// 7th Parameter: VP43
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_0F	0x0F	// b0000.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_10	0x10	// b0001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_11	0x11	// b0001.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_12	0x12	// b0001.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_13	0x13	// b0001.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_14	0x14	// b0001.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_15	0x15	// b0001.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_16	0x16	// b0001.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_17	0x17	// b0001.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_18	0x18	// b0001.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_19	0x19	// b0001.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_1A	0x1A	// b0001.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_1B	0x1B	// b0001.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_1C	0x1C	// b0001.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_1D	0x1D	// b0001.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_1E	0x1E	// b0001.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_1F	0x1F	// b0001.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_20	0x20	// b0010.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_21	0x21	// b0010.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_22	0x22	// b0010.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_23	0x23	// b0010.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_24	0x24	// b0010.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_25	0x25	// b0010.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_26	0x26	// b0010.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_27	0x27	// b0010.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_28	0x28	// b0010.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_29	0x29	// b0010.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_2A	0x2A	// b0010.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_2B	0x2B	// b0010.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_2C	0x2C	// b0010.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_2D	0x2D	// b0010.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_2E	0x2E	// b0010.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_2F	0x2F	// b0010.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_30	0x30	// b0011.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_31	0x31	// b0011.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_32	0x32	// b0011.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_33	0x33	// b0011.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_34	0x34	// b0011.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_35	0x35	// b0011.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_36	0x36	// b0011.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_37	0x37	// b0011.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_38	0x38	// b0011.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_39	0x39	// b0011.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_3A	0x3A	// b0011.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_3B	0x3B	// b0011.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_3C	0x3C	// b0011.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_3D	0x3D	// b0011.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_3E	0x3E	// b0011.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_3F	0x3F	// b0011.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_40	0x40	// b0100.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_41	0x41	// b0100.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_42	0x42	// b0100.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_43	0x43	// b0100.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_44	0x44	// b0100.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_45	0x45	// b0100.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_46	0x46	// b0100.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_47	0x47	// b0100.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_48	0x48	// b0100.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_49	0x49	// b0100.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_4A	0x4A	// b0100.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_4B	0x4B	// b0100.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_4C	0x4C	// b0100.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_4D	0x4D	// b0100.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_4E	0x4E	// b0100.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_4F	0x4F	// b0100.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_50	0x50	// b0101.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_51	0x51	// b0101.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_52	0x52	// b0101.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_53	0x53	// b0101.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_54	0x54	// b0101.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_55	0x55	// b0101.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_56	0x56	// b0101.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_57	0x57	// b0101.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_58	0x58	// b0101.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_59	0x59	// b0101.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_5A	0x5A	// b0101.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_5B	0x5B	// b0101.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_5C	0x5C	// b0101.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_5D	0x5D	// b0101.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_5E	0x5E	// b0101.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_5F	0x5F	// b0101.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_60	0x60	// b0110.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_61	0x61	// b0110.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_62	0x62	// b0110.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_63	0x63	// b0110.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_64	0x64	// b0110.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_65	0x65	// b0110.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_66	0x66	// b0110.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_67	0x67	// b0110.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_68	0x68	// b0110.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_69	0x69	// b0110.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_6A	0x6A	// b0110.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_6B	0x6B	// b0110.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_6C	0x6C	// b0110.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_6D	0x6D	// b0110.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_6E	0x6E	// b0110.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_6F	0x6F	// b0110.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_70	0x70	// b0111.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_71	0x71	// b0111.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_72	0x72	// b0111.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_73	0x73	// b0111.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_74	0x74	// b0111.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_75	0x75	// b0111.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_76	0x76	// b0111.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_77	0x77	// b0111.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_78	0x78	// b0111.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_79	0x79	// b0111.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_7A	0x7A	// b0111.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_7B	0x7B	// b0111.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_7C	0x7C	// b0111.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_7D	0x7D	// b0111.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_7E	0x7E	// b0111.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P7_VP43_7F	0x7F	// b0111.1111

// 8th Parameter: [ VP27 | VP36 ]
// VP36
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_01	0x10	// b0001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_02	0x20	// b0010.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_03	0x30	// b0011.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_04	0x40	// b0100.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_05	0x50	// b0101.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_06	0x60	// b0110.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_07	0x70	// b0111.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_08	0x80	// b1000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_09	0x90	// b1001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_0A	0xA0	// b1010.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_0B	0xB0	// b1011.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_0C	0xC0	// b1100.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_0D	0xD0	// b1101.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_0E	0xE0	// b1110.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP27_0F	0xF0	// b1111.0000
// VP27
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P8_VP36_0F	0x0F	// b0000.1111

// 9th Parameter: VP20
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_0F	0x0F	// b0000.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_10	0x10	// b0001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_11	0x11	// b0001.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_12	0x12	// b0001.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_13	0x13	// b0001.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_14	0x14	// b0001.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_15	0x15	// b0001.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_16	0x16	// b0001.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_17	0x17	// b0001.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_18	0x18	// b0001.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_19	0x19	// b0001.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_1A	0x1A	// b0001.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_1B	0x1B	// b0001.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_1C	0x1C	// b0001.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_1D	0x1D	// b0001.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_1E	0x1E	// b0001.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_1F	0x1F	// b0001.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_20	0x20	// b0010.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_21	0x21	// b0010.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_22	0x22	// b0010.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_23	0x23	// b0010.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_24	0x24	// b0010.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_25	0x25	// b0010.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_26	0x26	// b0010.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_27	0x27	// b0010.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_28	0x28	// b0010.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_29	0x29	// b0010.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_2A	0x2A	// b0010.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_2B	0x2B	// b0010.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_2C	0x2C	// b0010.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_2D	0x2D	// b0010.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_2E	0x2E	// b0010.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_2F	0x2F	// b0010.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_30	0x30	// b0011.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_31	0x31	// b0011.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_32	0x32	// b0011.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_33	0x33	// b0011.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_34	0x34	// b0011.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_35	0x35	// b0011.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_36	0x36	// b0011.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_37	0x37	// b0011.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_38	0x38	// b0011.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_39	0x39	// b0011.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_3A	0x3A	// b0011.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_3B	0x3B	// b0011.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_3C	0x3C	// b0011.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_3D	0x3D	// b0011.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_3E	0x3E	// b0011.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_3F	0x3F	// b0011.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_40	0x40	// b0100.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_41	0x41	// b0100.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_42	0x42	// b0100.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_43	0x43	// b0100.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_44	0x44	// b0100.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_45	0x45	// b0100.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_46	0x46	// b0100.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_47	0x47	// b0100.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_48	0x48	// b0100.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_49	0x49	// b0100.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_4A	0x4A	// b0100.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_4B	0x4B	// b0100.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_4C	0x4C	// b0100.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_4D	0x4D	// b0100.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_4E	0x4E	// b0100.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_4F	0x4F	// b0100.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_50	0x50	// b0101.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_51	0x51	// b0101.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_52	0x52	// b0101.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_53	0x53	// b0101.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_54	0x54	// b0101.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_55	0x55	// b0101.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_56	0x56	// b0101.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_57	0x57	// b0101.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_58	0x58	// b0101.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_59	0x59	// b0101.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_5A	0x5A	// b0101.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_5B	0x5B	// b0101.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_5C	0x5C	// b0101.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_5D	0x5D	// b0101.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_5E	0x5E	// b0101.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_5F	0x5F	// b0101.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_60	0x60	// b0110.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_61	0x61	// b0110.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_62	0x62	// b0110.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_63	0x63	// b0110.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_64	0x64	// b0110.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_65	0x65	// b0110.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_66	0x66	// b0110.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_67	0x67	// b0110.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_68	0x68	// b0110.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_69	0x69	// b0110.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_6A	0x6A	// b0110.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_6B	0x6B	// b0110.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_6C	0x6C	// b0110.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_6D	0x6D	// b0110.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_6E	0x6E	// b0110.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_6F	0x6F	// b0110.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_70	0x70	// b0111.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_71	0x71	// b0111.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_72	0x72	// b0111.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_73	0x73	// b0111.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_74	0x74	// b0111.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_75	0x75	// b0111.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_76	0x76	// b0111.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_77	0x77	// b0111.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_78	0x78	// b0111.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_79	0x79	// b0111.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_7A	0x7A	// b0111.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_7B	0x7B	// b0111.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_7C	0x7C	// b0111.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_7D	0x7D	// b0111.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_7E	0x7E	// b0111.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P9_VP20_7F	0x7F	// b0111.1111

// 10th Parameter: VP13
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P10_VP13_0F	0x0F	// b0000.1111

// 11th Parameter: VP06
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_0F	0x0F	// b0000.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_10	0x10	// b0001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_11	0x11	// b0001.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_12	0x12	// b0001.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_13	0x13	// b0001.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_14	0x14	// b0001.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_15	0x15	// b0001.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_16	0x16	// b0001.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_17	0x17	// b0001.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_18	0x18	// b0001.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_19	0x19	// b0001.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_1A	0x1A	// b0001.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_1B	0x1B	// b0001.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_1C	0x1C	// b0001.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_1D	0x1D	// b0001.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_1E	0x1E	// b0001.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P11_VP06_1F	0x1F	// b0001.1111

// 12th Parameter: VP04
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P12_VP04_0F	0x0F	// b0000.1111

// 13th Parameter: VP02
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_0F	0x0F	// b0000.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_10	0x10	// b0001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_11	0x11	// b0001.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_12	0x12	// b0001.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_13	0x13	// b0001.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_14	0x14	// b0001.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_15	0x15	// b0001.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_16	0x16	// b0001.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_17	0x17	// b0001.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_18	0x18	// b0001.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_19	0x19	// b0001.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_1A	0x1A	// b0001.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_1B	0x1B	// b0001.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_1C	0x1C	// b0001.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_1D	0x1D	// b0001.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_1E	0x1E	// b0001.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_1F	0x1F	// b0001.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_20	0x20	// b0010.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_21	0x21	// b0010.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_22	0x22	// b0010.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_23	0x23	// b0010.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_24	0x24	// b0010.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_25	0x25	// b0010.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_26	0x26	// b0010.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_27	0x27	// b0010.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_28	0x28	// b0010.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_29	0x29	// b0010.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_2A	0x2A	// b0010.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_2B	0x2B	// b0010.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_2C	0x2C	// b0010.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_2D	0x2D	// b0010.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_2E	0x2E	// b0010.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_2F	0x2F	// b0010.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_30	0x30	// b0011.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_31	0x31	// b0011.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_32	0x32	// b0011.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_33	0x33	// b0011.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_34	0x34	// b0011.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_35	0x35	// b0011.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_36	0x36	// b0011.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_37	0x37	// b0011.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_38	0x38	// b0011.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_39	0x39	// b0011.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_3A	0x3A	// b0011.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_3B	0x3B	// b0011.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_3C	0x3C	// b0011.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_3D	0x3D	// b0011.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_3E	0x3E	// b0011.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P13_VP02_3F	0x3F	// b0011.1111

// 14th Parameter: VP01
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_0F	0x0F	// b0000.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_10	0x10	// b0001.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_11	0x11	// b0001.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_12	0x12	// b0001.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_13	0x13	// b0001.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_14	0x14	// b0001.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_15	0x15	// b0001.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_16	0x16	// b0001.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_17	0x17	// b0001.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_18	0x18	// b0001.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_19	0x19	// b0001.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_1A	0x1A	// b0001.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_1B	0x1B	// b0001.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_1C	0x1C	// b0001.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_1D	0x1D	// b0001.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_1E	0x1E	// b0001.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_1F	0x1F	// b0001.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_20	0x20	// b0010.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_21	0x21	// b0010.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_22	0x22	// b0010.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_23	0x23	// b0010.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_24	0x24	// b0010.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_25	0x25	// b0010.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_26	0x26	// b0010.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_27	0x27	// b0010.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_28	0x28	// b0010.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_29	0x29	// b0010.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_2A	0x2A	// b0010.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_2B	0x2B	// b0010.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_2C	0x2C	// b0010.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_2D	0x2D	// b0010.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_2E	0x2E	// b0010.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_2F	0x2F	// b0010.1111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_30	0x30	// b0011.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_31	0x31	// b0011.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_32	0x32	// b0011.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_33	0x33	// b0011.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_34	0x34	// b0011.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_35	0x35	// b0011.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_36	0x36	// b0011.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_37	0x37	// b0011.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_38	0x38	// b0011.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_39	0x39	// b0011.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_3A	0x3A	// b0011.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_3B	0x3B	// b0011.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_3C	0x3C	// b0011.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_3D	0x3D	// b0011.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_3E	0x3E	// b0011.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P14_VP01_3F	0x3F	// b0011.1111

// 15th Parameter: VP00
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_00	0x00	// b0000.0000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_01	0x01	// b0000.0001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_02	0x02	// b0000.0010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_03	0x03	// b0000.0011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_04	0x04	// b0000.0100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_05	0x05	// b0000.0101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_06	0x06	// b0000.0110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_07	0x07	// b0000.0111
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_08	0x08	// b0000.1000
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_09	0x09	// b0000.1001
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_0A	0x0A	// b0000.1010
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_0B	0x0B	// b0000.1011
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_0C	0x0C	// b0000.1100
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_0D	0x0D	// b0000.1101
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_0E	0x0E	// b0000.1110
#define ILI9341_POSITIVE_GAMMA_CORRECTION_P15_VP00_0F	0x0F	// b0000.1111


//************************************************//
//********   Negative Gamma Correction   *********//
//************************************************//
// Command:  Negative Gamma Correction
#define ILI9341_NEGATIVE_GAMMA_CORRECTION               0xE1

// Description: Set the Gray Scale Voltage to Adjust the Gamma Characteristics of the TFT Panel
// 1st Parameter: VN63
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P1_VN63_0F	0x0F	// b0000.1111

// 2nd Parameter: VN62
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_0F	0x0F	// b0000.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_10	0x10	// b0001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_11	0x11	// b0001.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_12	0x12	// b0001.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_13	0x13	// b0001.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_14	0x14	// b0001.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_15	0x15	// b0001.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_16	0x16	// b0001.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_17	0x17	// b0001.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_18	0x18	// b0001.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_19	0x19	// b0001.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_1A	0x1A	// b0001.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_1B	0x1B	// b0001.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_1C	0x1C	// b0001.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_1D	0x1D	// b0001.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_1E	0x1E	// b0001.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_1F	0x1F	// b0001.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_20	0x20	// b0010.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_21	0x21	// b0010.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_22	0x22	// b0010.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_23	0x23	// b0010.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_24	0x24	// b0010.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_25	0x25	// b0010.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_26	0x26	// b0010.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_27	0x27	// b0010.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_28	0x28	// b0010.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_29	0x29	// b0010.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_2A	0x2A	// b0010.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_2B	0x2B	// b0010.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_2C	0x2C	// b0010.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_2D	0x2D	// b0010.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_2E	0x2E	// b0010.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_2F	0x2F	// b0010.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_30	0x30	// b0011.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_31	0x31	// b0011.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_32	0x32	// b0011.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_33	0x33	// b0011.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_34	0x34	// b0011.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_35	0x35	// b0011.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_36	0x36	// b0011.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_37	0x37	// b0011.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_38	0x38	// b0011.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_39	0x39	// b0011.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_3A	0x3A	// b0011.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_3B	0x3B	// b0011.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_3C	0x3C	// b0011.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_3D	0x3D	// b0011.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_3E	0x3E	// b0011.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P2_VN62_3F	0x3F	// b0011.1111

// 3rd Parameter: VN61
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_0F	0x0F	// b0000.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_10	0x10	// b0001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_11	0x11	// b0001.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_12	0x12	// b0001.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_13	0x13	// b0001.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_14	0x14	// b0001.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_15	0x15	// b0001.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_16	0x16	// b0001.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_17	0x17	// b0001.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_18	0x18	// b0001.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_19	0x19	// b0001.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_1A	0x1A	// b0001.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_1B	0x1B	// b0001.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_1C	0x1C	// b0001.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_1D	0x1D	// b0001.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_1E	0x1E	// b0001.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_1F	0x1F	// b0001.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_20	0x20	// b0010.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_21	0x21	// b0010.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_22	0x22	// b0010.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_23	0x23	// b0010.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_24	0x24	// b0010.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_25	0x25	// b0010.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_26	0x26	// b0010.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_27	0x27	// b0010.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_28	0x28	// b0010.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_29	0x29	// b0010.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_2A	0x2A	// b0010.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_2B	0x2B	// b0010.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_2C	0x2C	// b0010.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_2D	0x2D	// b0010.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_2E	0x2E	// b0010.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_2F	0x2F	// b0010.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_30	0x30	// b0011.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_31	0x31	// b0011.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_32	0x32	// b0011.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_33	0x33	// b0011.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_34	0x34	// b0011.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_35	0x35	// b0011.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_36	0x36	// b0011.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_37	0x37	// b0011.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_38	0x38	// b0011.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_39	0x39	// b0011.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_3A	0x3A	// b0011.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_3B	0x3B	// b0011.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_3C	0x3C	// b0011.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_3D	0x3D	// b0011.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_3E	0x3E	// b0011.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P3_VN61_3F	0x3F	// b0011.1111

// 4th Parameter: VN59
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P4_VN59_0F	0x0F	// b0000.1111


// 5th Parameter: VN57
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_0F	0x0F	// b0000.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_10	0x10	// b0001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_11	0x11	// b0001.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_12	0x12	// b0001.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_13	0x13	// b0001.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_14	0x14	// b0001.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_15	0x15	// b0001.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_16	0x16	// b0001.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_17	0x17	// b0001.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_18	0x18	// b0001.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_19	0x19	// b0001.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_1A	0x1A	// b0001.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_1B	0x1B	// b0001.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_1C	0x1C	// b0001.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_1D	0x1D	// b0001.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_1E	0x1E	// b0001.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P5_VN57_1F	0x1F	// b0001.1111

// 6th Parameter: VN50
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P6_VN50_0F	0x0F	// b0000.1111

// 7th Parameter: VN43
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_0F	0x0F	// b0000.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_10	0x10	// b0001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_11	0x11	// b0001.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_12	0x12	// b0001.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_13	0x13	// b0001.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_14	0x14	// b0001.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_15	0x15	// b0001.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_16	0x16	// b0001.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_17	0x17	// b0001.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_18	0x18	// b0001.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_19	0x19	// b0001.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_1A	0x1A	// b0001.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_1B	0x1B	// b0001.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_1C	0x1C	// b0001.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_1D	0x1D	// b0001.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_1E	0x1E	// b0001.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_1F	0x1F	// b0001.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_20	0x20	// b0010.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_21	0x21	// b0010.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_22	0x22	// b0010.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_23	0x23	// b0010.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_24	0x24	// b0010.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_25	0x25	// b0010.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_26	0x26	// b0010.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_27	0x27	// b0010.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_28	0x28	// b0010.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_29	0x29	// b0010.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_2A	0x2A	// b0010.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_2B	0x2B	// b0010.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_2C	0x2C	// b0010.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_2D	0x2D	// b0010.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_2E	0x2E	// b0010.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_2F	0x2F	// b0010.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_30	0x30	// b0011.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_31	0x31	// b0011.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_32	0x32	// b0011.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_33	0x33	// b0011.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_34	0x34	// b0011.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_35	0x35	// b0011.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_36	0x36	// b0011.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_37	0x37	// b0011.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_38	0x38	// b0011.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_39	0x39	// b0011.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_3A	0x3A	// b0011.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_3B	0x3B	// b0011.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_3C	0x3C	// b0011.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_3D	0x3D	// b0011.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_3E	0x3E	// b0011.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_3F	0x3F	// b0011.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_40	0x40	// b0100.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_41	0x41	// b0100.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_42	0x42	// b0100.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_43	0x43	// b0100.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_44	0x44	// b0100.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_45	0x45	// b0100.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_46	0x46	// b0100.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_47	0x47	// b0100.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_48	0x48	// b0100.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_49	0x49	// b0100.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_4A	0x4A	// b0100.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_4B	0x4B	// b0100.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_4C	0x4C	// b0100.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_4D	0x4D	// b0100.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_4E	0x4E	// b0100.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_4F	0x4F	// b0100.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_50	0x50	// b0101.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_51	0x51	// b0101.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_52	0x52	// b0101.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_53	0x53	// b0101.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_54	0x54	// b0101.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_55	0x55	// b0101.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_56	0x56	// b0101.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_57	0x57	// b0101.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_58	0x58	// b0101.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_59	0x59	// b0101.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_5A	0x5A	// b0101.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_5B	0x5B	// b0101.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_5C	0x5C	// b0101.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_5D	0x5D	// b0101.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_5E	0x5E	// b0101.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_5F	0x5F	// b0101.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_60	0x60	// b0110.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_61	0x61	// b0110.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_62	0x62	// b0110.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_63	0x63	// b0110.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_64	0x64	// b0110.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_65	0x65	// b0110.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_66	0x66	// b0110.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_67	0x67	// b0110.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_68	0x68	// b0110.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_69	0x69	// b0110.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_6A	0x6A	// b0110.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_6B	0x6B	// b0110.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_6C	0x6C	// b0110.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_6D	0x6D	// b0110.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_6E	0x6E	// b0110.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_6F	0x6F	// b0110.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_70	0x70	// b0111.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_71	0x71	// b0111.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_72	0x72	// b0111.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_73	0x73	// b0111.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_74	0x74	// b0111.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_75	0x75	// b0111.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_76	0x76	// b0111.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_77	0x77	// b0111.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_78	0x78	// b0111.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_79	0x79	// b0111.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_7A	0x7A	// b0111.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_7B	0x7B	// b0111.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_7C	0x7C	// b0111.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_7D	0x7D	// b0111.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_7E	0x7E	// b0111.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P7_VN43_7F	0x7F	// b0111.1111

// 8th Parameter: [ VN36 | VN27 ]
// VN36
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_01	0x10	// b0001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_02	0x20	// b0010.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_03	0x30	// b0011.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_04	0x40	// b0100.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_05	0x50	// b0101.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_06	0x60	// b0110.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_07	0x70	// b0111.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_08	0x80	// b1000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_09	0x90	// b1001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_0A	0xA0	// b1010.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_0B	0xB0	// b1011.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_0C	0xC0	// b1100.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_0D	0xD0	// b1101.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_0E	0xE0	// b1110.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN36_0F	0xF0	// b1111.0000
// VN27
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P8_VN27_0F	0x0F	// b0000.1111

// 9th Parameter: VN20
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_0F	0x0F	// b0000.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_10	0x10	// b0001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_11	0x11	// b0001.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_12	0x12	// b0001.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_13	0x13	// b0001.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_14	0x14	// b0001.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_15	0x15	// b0001.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_16	0x16	// b0001.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_17	0x17	// b0001.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_18	0x18	// b0001.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_19	0x19	// b0001.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_1A	0x1A	// b0001.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_1B	0x1B	// b0001.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_1C	0x1C	// b0001.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_1D	0x1D	// b0001.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_1E	0x1E	// b0001.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_1F	0x1F	// b0001.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_20	0x20	// b0010.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_21	0x21	// b0010.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_22	0x22	// b0010.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_23	0x23	// b0010.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_24	0x24	// b0010.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_25	0x25	// b0010.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_26	0x26	// b0010.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_27	0x27	// b0010.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_28	0x28	// b0010.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_29	0x29	// b0010.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_2A	0x2A	// b0010.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_2B	0x2B	// b0010.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_2C	0x2C	// b0010.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_2D	0x2D	// b0010.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_2E	0x2E	// b0010.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_2F	0x2F	// b0010.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_30	0x30	// b0011.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_31	0x31	// b0011.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_32	0x32	// b0011.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_33	0x33	// b0011.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_34	0x34	// b0011.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_35	0x35	// b0011.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_36	0x36	// b0011.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_37	0x37	// b0011.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_38	0x38	// b0011.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_39	0x39	// b0011.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_3A	0x3A	// b0011.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_3B	0x3B	// b0011.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_3C	0x3C	// b0011.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_3D	0x3D	// b0011.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_3E	0x3E	// b0011.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_3F	0x3F	// b0011.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_40	0x40	// b0100.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_41	0x41	// b0100.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_42	0x42	// b0100.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_43	0x43	// b0100.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_44	0x44	// b0100.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_45	0x45	// b0100.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_46	0x46	// b0100.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_47	0x47	// b0100.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_48	0x48	// b0100.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_49	0x49	// b0100.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_4A	0x4A	// b0100.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_4B	0x4B	// b0100.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_4C	0x4C	// b0100.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_4D	0x4D	// b0100.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_4E	0x4E	// b0100.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_4F	0x4F	// b0100.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_50	0x50	// b0101.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_51	0x51	// b0101.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_52	0x52	// b0101.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_53	0x53	// b0101.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_54	0x54	// b0101.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_55	0x55	// b0101.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_56	0x56	// b0101.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_57	0x57	// b0101.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_58	0x58	// b0101.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_59	0x59	// b0101.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_5A	0x5A	// b0101.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_5B	0x5B	// b0101.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_5C	0x5C	// b0101.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_5D	0x5D	// b0101.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_5E	0x5E	// b0101.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_5F	0x5F	// b0101.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_60	0x60	// b0110.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_61	0x61	// b0110.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_62	0x62	// b0110.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_63	0x63	// b0110.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_64	0x64	// b0110.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_65	0x65	// b0110.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_66	0x66	// b0110.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_67	0x67	// b0110.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_68	0x68	// b0110.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_69	0x69	// b0110.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_6A	0x6A	// b0110.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_6B	0x6B	// b0110.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_6C	0x6C	// b0110.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_6D	0x6D	// b0110.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_6E	0x6E	// b0110.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_6F	0x6F	// b0110.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_70	0x70	// b0111.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_71	0x71	// b0111.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_72	0x72	// b0111.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_73	0x73	// b0111.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_74	0x74	// b0111.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_75	0x75	// b0111.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_76	0x76	// b0111.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_77	0x77	// b0111.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_78	0x78	// b0111.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_79	0x79	// b0111.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_7A	0x7A	// b0111.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_7B	0x7B	// b0111.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_7C	0x7C	// b0111.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_7D	0x7D	// b0111.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_7E	0x7E	// b0111.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P9_VN20_7F	0x7F	// b0111.1111

// 10th Parameter: VN13
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P10_VN13_0F	0x0F	// b0000.1111

// 11th Parameter: VN06
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_0F	0x0F	// b0000.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_10	0x10	// b0001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_11	0x11	// b0001.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_12	0x12	// b0001.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_13	0x13	// b0001.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_14	0x14	// b0001.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_15	0x15	// b0001.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_16	0x16	// b0001.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_17	0x17	// b0001.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_18	0x18	// b0001.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_19	0x19	// b0001.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_1A	0x1A	// b0001.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_1B	0x1B	// b0001.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_1C	0x1C	// b0001.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_1D	0x1D	// b0001.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_1E	0x1E	// b0001.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P11_VN06_1F	0x1F	// b0001.1111

// 12th Parameter: VN04
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P12_VN04_0F	0x0F	// b0000.1111

// 13th Parameter: VN02
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_0F	0x0F	// b0000.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_10	0x10	// b0001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_11	0x11	// b0001.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_12	0x12	// b0001.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_13	0x13	// b0001.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_14	0x14	// b0001.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_15	0x15	// b0001.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_16	0x16	// b0001.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_17	0x17	// b0001.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_18	0x18	// b0001.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_19	0x19	// b0001.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_1A	0x1A	// b0001.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_1B	0x1B	// b0001.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_1C	0x1C	// b0001.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_1D	0x1D	// b0001.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_1E	0x1E	// b0001.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_1F	0x1F	// b0001.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_20	0x20	// b0010.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_21	0x21	// b0010.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_22	0x22	// b0010.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_23	0x23	// b0010.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_24	0x24	// b0010.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_25	0x25	// b0010.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_26	0x26	// b0010.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_27	0x27	// b0010.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_28	0x28	// b0010.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_29	0x29	// b0010.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_2A	0x2A	// b0010.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_2B	0x2B	// b0010.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_2C	0x2C	// b0010.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_2D	0x2D	// b0010.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_2E	0x2E	// b0010.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_2F	0x2F	// b0010.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_30	0x30	// b0011.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_31	0x31	// b0011.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_32	0x32	// b0011.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_33	0x33	// b0011.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_34	0x34	// b0011.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_35	0x35	// b0011.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_36	0x36	// b0011.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_37	0x37	// b0011.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_38	0x38	// b0011.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_39	0x39	// b0011.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_3A	0x3A	// b0011.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_3B	0x3B	// b0011.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_3C	0x3C	// b0011.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_3D	0x3D	// b0011.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_3E	0x3E	// b0011.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P13_VN02_3F	0x3F	// b0011.1111

// 14th Parameter: VN01
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_0F	0x0F	// b0000.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_10	0x10	// b0001.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_11	0x11	// b0001.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_12	0x12	// b0001.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_13	0x13	// b0001.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_14	0x14	// b0001.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_15	0x15	// b0001.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_16	0x16	// b0001.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_17	0x17	// b0001.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_18	0x18	// b0001.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_19	0x19	// b0001.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_1A	0x1A	// b0001.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_1B	0x1B	// b0001.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_1C	0x1C	// b0001.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_1D	0x1D	// b0001.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_1E	0x1E	// b0001.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_1F	0x1F	// b0001.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_20	0x20	// b0010.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_21	0x21	// b0010.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_22	0x22	// b0010.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_23	0x23	// b0010.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_24	0x24	// b0010.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_25	0x25	// b0010.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_26	0x26	// b0010.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_27	0x27	// b0010.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_28	0x28	// b0010.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_29	0x29	// b0010.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_2A	0x2A	// b0010.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_2B	0x2B	// b0010.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_2C	0x2C	// b0010.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_2D	0x2D	// b0010.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_2E	0x2E	// b0010.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_2F	0x2F	// b0010.1111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_30	0x30	// b0011.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_31	0x31	// b0011.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_32	0x32	// b0011.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_33	0x33	// b0011.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_34	0x34	// b0011.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_35	0x35	// b0011.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_36	0x36	// b0011.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_37	0x37	// b0011.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_38	0x38	// b0011.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_39	0x39	// b0011.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_3A	0x3A	// b0011.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_3B	0x3B	// b0011.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_3C	0x3C	// b0011.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_3D	0x3D	// b0011.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_3E	0x3E	// b0011.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P14_VN01_3F	0x3F	// b0011.1111

// 15th Parameter: VN00
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_00	0x00	// b0000.0000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_01	0x01	// b0000.0001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_02	0x02	// b0000.0010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_03	0x03	// b0000.0011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_04	0x04	// b0000.0100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_05	0x05	// b0000.0101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_06	0x06	// b0000.0110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_07	0x07	// b0000.0111
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_08	0x08	// b0000.1000
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_09	0x09	// b0000.1001
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_0A	0x0A	// b0000.1010
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_0B	0x0B	// b0000.1011
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_0C	0x0C	// b0000.1100
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_0D	0x0D	// b0000.1101
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_0E	0x0E	// b0000.1110
#define ILI9341_NEGATIVE_GAMMA_CORRECTION_P15_VN00_0F	0x0F	// b0000.1111


//************************************************//
//*********   Digital Gamma Control 1   **********//
//************************************************//

// Command: Digital Gamma Control 2
#define ILI9341_DIGITAL_GAMMA_CTRL_1                    0xE2
// 1st Parameter
// RFA: Gamma Micro-Adjustment Register for Red Gamma Curve
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_0000		0x00	// b0000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_0001		0x10	// b0001.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_0010		0x20	// b0010.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_0011		0x30	// b0011.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_0100		0x40	// b0100.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_0101		0x50	// b0101.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_0110		0x60	// b0110.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_0111		0x70	// b0111.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_1000		0x80	// b1000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_1001		0x90	// b1001.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_1010		0xA0	// b1010.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_1011		0xB0	// b1011.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_1100		0xC0	// b1100.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_1101		0xD0	// b1101.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_1110		0xE0	// b1110.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_RED_1111		0xF0	// b1111.0000
// BFA: Gamma Micro-Adjustment Register for Red Gamma Curve
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_0000		0x00	// b0000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_0001		0x01	// b0000.0001
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_0010		0x02	// b0000.0010
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_0011		0x03	// b0000.0011
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_0100		0x04	// b0000.0100
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_0101		0x05	// b0000.0101
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_0110		0x06	// b0000.0110
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_0111		0x07	// b0000.0111
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_1000		0x08	// b0000.1000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_1001		0x09	// b0000.1001
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_1010		0x0A	// b0000.1010
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_1011		0x0B	// b0000.1011
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_1100		0x0C	// b0000.1100
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_1101		0x0D	// b0000.1101
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_1110		0x0E	// b0000.1110
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P1_BLUE_1111		0x0F	// b0000.1111
// ...
// // X Parameter :: Where 'X' is '2'-'15'
// // RFA: Gamma Micro-Adjustment Register for Red Gamma Curve
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_0000			0x00	// b0000.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_0001			0x10	// b0001.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_0010			0x20	// b0010.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_0011			0x30	// b0011.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_0100			0x40	// b0100.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_0101			0x50	// b0101.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_0110			0x60	// b0110.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_0111			0x70	// b0111.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_1000			0x80	// b1000.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_1001			0x90	// b1001.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_1010			0xA0	// b1010.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_1011			0xB0	// b1011.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_1100			0xC0	// b1100.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_1101			0xD0	// b1101.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_1110			0xE0	// b1110.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_RED_1111			0xF0	// b1111.0000
// // BFA: Gamma Micro-Adjustment Register for Red Gamma Curve
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_0000		0x00	// b0000.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_0001		0x01	// b0000.0001
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_0010		0x02	// b0000.0010
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_0011		0x03	// b0000.0011
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_0100		0x04	// b0000.0100
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_0101		0x05	// b0000.0101
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_0110		0x06	// b0000.0110
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_0111		0x07	// b0000.0111
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_1000		0x08	// b0000.1000
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_1001		0x09	// b0000.1001
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_1010		0x0A	// b0000.1010
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_1011		0x0B	// b0000.1011
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_1100		0x0C	// b0000.1100
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_1101		0x0D	// b0000.1101
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_1110		0x0E	// b0000.1110
// #define ILI9341_DIGITAL_GAMMA_CTRL_1_PX_BLUE_1111		0x0F	// b0000.1111
// ...
// 16th Parameter
// RFA: Gamma Micro-Adjustment Register for Red Gamma Curve
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_0000		0x00	// b0000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_0001		0x10	// b0001.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_0010		0x20	// b0010.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_0011		0x30	// b0011.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_0100		0x40	// b0100.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_0101		0x50	// b0101.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_0110		0x60	// b0110.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_0111		0x70	// b0111.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_1000		0x80	// b1000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_1001		0x90	// b1001.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_1010		0xA0	// b1010.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_1011		0xB0	// b1011.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_1100		0xC0	// b1100.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_1101		0xD0	// b1101.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_1110		0xE0	// b1110.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_RED_1111		0xF0	// b1111.0000
// BFA: Gamma Micro-Adjustment Register for Red Gamma Curve
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_0000		0x00	// b0000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_0001		0x01	// b0000.0001
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_0010		0x02	// b0000.0010
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_0011		0x03	// b0000.0011
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_0100		0x04	// b0000.0100
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_0101		0x05	// b0000.0101
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_0110		0x06	// b0000.0110
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_0111		0x07	// b0000.0111
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_1000		0x08	// b0000.1000
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_1001		0x09	// b0000.1001
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_1010		0x0A	// b0000.1010
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_1011		0x0B	// b0000.1011
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_1100		0x0C	// b0000.1100
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_1101		0x0D	// b0000.1101
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_1110		0x0E	// b0000.1110
#define ILI9341_DIGITAL_GAMMA_CTRL_1_P16_BLUE_1111		0x0F	// b0000.1111

//************************************************//
//*********   Digital Gamma Control 2   **********//
//************************************************//

// Command: Digital Gamma Control 2
#define ILI9341_DIGITAL_GAMMA_CTRL_2                    0xE3
// 1st Parameter
// RFA: Gamma Micro-Adjustment Register for Red Gamma Curve
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_0000		0x00	// b0000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_0001		0x10	// b0001.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_0010		0x20	// b0010.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_0011		0x30	// b0011.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_0100		0x40	// b0100.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_0101		0x50	// b0101.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_0110		0x60	// b0110.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_0111		0x70	// b0111.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_1000		0x80	// b1000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_1001		0x90	// b1001.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_1010		0xA0	// b1010.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_1011		0xB0	// b1011.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_1100		0xC0	// b1100.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_1101		0xD0	// b1101.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_1110		0xE0	// b1110.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_RED_1111		0xF0	// b1111.0000
// BFA: Gamma Micro-Adjustment Register for Red Gamma Curve
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_0000		0x00	// b0000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_0001		0x01	// b0000.0001
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_0010		0x02	// b0000.0010
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_0011		0x03	// b0000.0011
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_0100		0x04	// b0000.0100
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_0101		0x05	// b0000.0101
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_0110		0x06	// b0000.0110
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_0111		0x07	// b0000.0111
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_1000		0x08	// b0000.1000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_1001		0x09	// b0000.1001
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_1010		0x0A	// b0000.1010
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_1011		0x0B	// b0000.1011
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_1100		0x0C	// b0000.1100
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_1101		0x0D	// b0000.1101
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_1110		0x0E	// b0000.1110
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P1_BLUE_1111		0x0F	// b0000.1111
// ...
// // X Parameter :: Where 'X' is '2'-'63'
// // RFA: Gamma Micro-Adjustment Register for Red Gamma Curve
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_0000			0x00	// b0000.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_0001			0x10	// b0001.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_0010			0x20	// b0010.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_0011			0x30	// b0011.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_0100			0x40	// b0100.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_0101			0x50	// b0101.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_0110			0x60	// b0110.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_0111			0x70	// b0111.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_1000			0x80	// b1000.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_1001			0x90	// b1001.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_1010			0xA0	// b1010.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_1011			0xB0	// b1011.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_1100			0xC0	// b1100.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_1101			0xD0	// b1101.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_1110			0xE0	// b1110.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_RED_1111			0xF0	// b1111.0000
// // BFA: Gamma Micro-Adjustment Register for Red Gamma Curve
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_0000		0x00	// b0000.0000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_0001		0x01	// b0000.0001
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_0010		0x02	// b0000.0010
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_0011		0x03	// b0000.0011
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_0100		0x04	// b0000.0100
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_0101		0x05	// b0000.0101
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_0110		0x06	// b0000.0110
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_0111		0x07	// b0000.0111
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_1000		0x08	// b0000.1000
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_1001		0x09	// b0000.1001
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_1010		0x0A	// b0000.1010
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_1011		0x0B	// b0000.1011
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_1100		0x0C	// b0000.1100
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_1101		0x0D	// b0000.1101
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_1110		0x0E	// b0000.1110
// #define ILI9341_DIGITAL_GAMMA_CTRL_2_PX_BLUE_1111		0x0F	// b0000.1111
// ...
// 64th Parameter
// RFA: Gamma Micro-Adjustment Register for Red Gamma Curve
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_0000		0x00	// b0000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_0001		0x10	// b0001.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_0010		0x20	// b0010.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_0011		0x30	// b0011.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_0100		0x40	// b0100.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_0101		0x50	// b0101.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_0110		0x60	// b0110.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_0111		0x70	// b0111.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_1000		0x80	// b1000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_1001		0x90	// b1001.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_1010		0xA0	// b1010.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_1011		0xB0	// b1011.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_1100		0xC0	// b1100.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_1101		0xD0	// b1101.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_1110		0xE0	// b1110.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_RED_1111		0xF0	// b1111.0000
// BFA: Gamma Micro-Adjustment Register for Red Gamma Curve
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_0000		0x00	// b0000.0000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_0001		0x01	// b0000.0001
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_0010		0x02	// b0000.0010
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_0011		0x03	// b0000.0011
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_0100		0x04	// b0000.0100
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_0101		0x05	// b0000.0101
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_0110		0x06	// b0000.0110
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_0111		0x07	// b0000.0111
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_1000		0x08	// b0000.1000
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_1001		0x09	// b0000.1001
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_1010		0x0A	// b0000.1010
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_1011		0x0B	// b0000.1011
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_1100		0x0C	// b0000.1100
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_1101		0x0D	// b0000.1101
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_1110		0x0E	// b0000.1110
#define ILI9341_DIGITAL_GAMMA_CTRL_2_P64_BLUE_1111		0x0F	// b0000.1111

//************************************************//
//*************   Interface Control   ************//
//************************************************//

// Command: Interface Control
#define ILI9341_INTERFACE_CTRL                          0xF6

// 1st Parameter: MY_EOR / MX_EOR / MV_EOR / BGR_EOR: Exclusive OR Set Elsewhere (datasheet has typo?)
// MY_EOR
#define ILI9341_INTERFACE_CTRL_P1_MY_EOR_0				0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P1_MY_EOR_1				0x80	// b1000.0000
// MX_EOR
#define ILI9341_INTERFACE_CTRL_P1_MX_EOR_0				0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P1_MX_EOR_1				0x40	// b0100.0000
// MV_EOR
#define ILI9341_INTERFACE_CTRL_P1_MV_EOR_0				0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P1_MV_EOR_1				0x20	// b0010.0000
// BGR_EOR
#define ILI9341_INTERFACE_CTRL_P1_BGR_EOR_0 			0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P1_BGR_EOR_1 			0x08	// b0000.1000
// WEMODE: Memory write control
#define ILI9341_INTERFACE_CTRL_P1_WE_MODE_IGNORE		0x00 	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P1_WE_MODE_RESET			0x01 	// b0000.0001

// 2nd Parameter
// EPF: 65K color mode data format. See Datasheet for Graphical Explanation
#define ILI9341_INTERFACE_CTRL_P2_EPF_00				0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P2_EPF_01				0x10	// b0001.0000
#define ILI9341_INTERFACE_CTRL_P2_EPF_10				0x20	// b0010.0000
#define ILI9341_INTERFACE_CTRL_P2_EPF_11				0x30	// b0011.0000
// MDT: Select the Method of Display Data Transferring
#define ILI9341_INTERFACE_CTRL_P2_MDT_00				0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P2_MDT_01				0x01	// b0000.0001
#define ILI9341_INTERFACE_CTRL_P2_MDT_10				0x02	// b0000.0010
#define ILI9341_INTERFACE_CTRL_P2_MDT_11				0x03	// b0000.0011

// 3rd Parameter
// ENDIAN: Normal = MSB First
#define ILI9341_INTERFACE_CTRL_P3_NORMAL				0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P3_LITTLE				0x20	// b0010.0000
// DM: Select the Display Operation Mode
#define ILI9341_INTERFACE_CTRL_P3_DM_INT_CLK_MODE       0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P3_DM_RGB_INTERFACE      0x04	// b0000.0100
#define ILI9341_INTERFACE_CTRL_P3_DM_VSYNC_MODE			0x08	// b0000.1000
#define ILI9341_INTERFACE_CTRL_P3_DM_DISABLE            0x0C	// b0000.1100
// RM: Select the Interface to Access the GRAM
#define ILI9341_INTERFACE_CTRL_P3_RM_SYS_VSYNC_INTERFACE    0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P3_RM_RGB_INTERFACE      0x02	// b0000.0010
// RIM: Specify the RGB Interface Mode when the RGB Interface is Used
#define ILI9341_INTERFACE_CTRL_P3_RIM_COLMOD110_18_BIT  0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P3_RIM_COLMOD101_16_BIT  0x00	// b0000.0000
#define ILI9341_INTERFACE_CTRL_P3_RIM_COLMOD110_6_BIT   0x01	// b0000.0001
#define ILI9341_INTERFACE_CTRL_P3_RIM_COLMOD101_6_BIT   0x01	// b0000.0001

//**********   EXTENDED COMMAND SET   ************//
// EXTC Should be HIGH to enable these commands

//************************************************//
//*************   Power Control A   **************//
//************************************************//

// Command: Power Control A
#define ILI9341_PWR_CTRL_A								0xCB

// 1st Parameter
#define ILI9341_PWR_CTRL_A_P1							0x39	// b0011.1001 [Static]

// 2nd Parameter
#define ILI9341_PWR_CTRL_A_P2							0x2C	// b0010.1100 [Static]

// 3rd Parameter
#define ILI9341_PWR_CTRL_A_P3							0x00	// b0000.0000 [Static]

// 4th Parameter: REG_VD[2:0]: Vcore Control
#define ILI9341_PWR_CTRL_A_P4_REG_VD_1_55				0x30  	// b0011.0000
#define ILI9341_PWR_CTRL_A_P4_REG_VD_1_40				0x31  	// b0011.0001
#define ILI9341_PWR_CTRL_A_P4_REG_VD_1_50				0x32  	// b0011.0010
#define ILI9341_PWR_CTRL_A_P4_REG_VD_1_65				0x33  	// b0011.0011
#define ILI9341_PWR_CTRL_A_P4_REG_VD_1_60				0x34  	// b0011.0100 [Default: All]
#define ILI9341_PWR_CTRL_A_P4_REG_VD_1_70				0x35  	// b0011.0101

// 5th Parameter: VBC[2:0]: DDVDH Control
#define ILI9341_PWR_CTRL_A_P5_VBC_5_8					0x00	// b0000.0000
#define ILI9341_PWR_CTRL_A_P5_VBC_5_7					0x01	// b0000.0001
#define ILI9341_PWR_CTRL_A_P5_VBC_5_6					0x02	// b0000.0010 [Default: All]
#define ILI9341_PWR_CTRL_A_P5_VBC_5_5					0x03	// b0000.0011
#define ILI9341_PWR_CTRL_A_P5_VBC_5_4					0x04	// b0000.0100
#define ILI9341_PWR_CTRL_A_P5_VBC_5_3					0x05	// b0000.0101
#define ILI9341_PWR_CTRL_A_P5_VBC_5_2					0x06	// b0000.0110


//************************************************//
//*************   Power Control B   **************//
//************************************************//

// Command: Power Control B
#define ILI9341_PWR_CTRL_B								0xCF

// 1st Parameter
#define ILI9341_PWR_CTRL_B_P1							0x00	// b0000.0000 [Static]

// 2nd Parameter: PWR_CTRL[1:0]
#define ILI9341_PWR_CTRL_B_P2_VCI7_negVCIx4				0xC1	// b1100.0001
#define ILI9341_PWR_CTRL_B_P2_VCI7_negVCIx3				0xD1	// b1101.0001
#define ILI9341_PWR_CTRL_B_P2_VCI6_negVCIx4				0xE1	// b1110.0001
#define ILI9341_PWR_CTRL_B_P2_VCI6_negVCIx3				0xF1	// b1111.0001

// 3rd Parameter: Discharge Path Enable. (ESD protection)
#define ILI9341_PWR_CTRL_B_P3_DP_DISABLE				0x20	// b0010.0000
#define ILI9341_PWR_CTRL_B_P3_DP_ENABLE					0x30	// b0011.0000


//************************************************//
//***********  Driver Timing Control A   *********//
//************************************************//

// Command: Driver Timing Control A
#define ILI9341_DRV_TIME_CTRL_A							0xE8

// 1st Parameter: Gate Driver Non-Overlap Timing Control
#define ILI9341_DRV_TIME_CTRL_A_P1_NO_DEF				0x84	// b1000.0100 [Default]
#define ILI9341_DRV_TIME_CTRL_A_P1_NO_DEF1 				0x85	// b1000.0101

// 2nd Parameter: EQ Timing  [ EQ | CR ]
// EQ
#define ILI9341_DRV_TIME_CTRL_A_P2_EQ_1U				0x00	// b0000.0000
#define ILI9341_DRV_TIME_CTRL_A_P2_EQ_DEF1				0x01	// b0000.0001
// CR
#define ILI9341_DRV_TIME_CTRL_A_P2_CR_1U				0x00	// b0000.0000
#define ILI9341_DRV_TIME_CTRL_A_P2_CR_DEF1				0x10	// b0001.0000


// 3rd Parameter:  Pre-Charge Timing Control
#define ILI9341_DRV_TIME_CTRL_A_P3_PC_TIME_DEF			0x7A	// b0111.1010 [Default]
#define ILI9341_DRV_TIME_CTRL_A_P3_PC_TIME_1U			0x79	// b0111.1001
#define ILI9341_DRV_TIME_CTRL_A_P3_PC_TIME_2U			0x78	// b0111.1000


//************************************************//
//***********  Driver Timing Control B   *********//
//************************************************//

// Command: Driver Timing Control B
#define ILI9341_DRV_TIME_CTRL_B							0xEA

// 1st Parameter: Gate Driver Timing Control [ T1 | T2 | T3 | T4 ]
//T1
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T1_0U_EQ_2_GND		0x00	// b0000.0000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T1_1U_EQ_2_GND		0x01	// b0000.0001
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T1_2U_EQ_2_GND		0x02	// b0000.0010
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T1_3U_EQ_2_GND		0x03	// b0000.0011
//T2
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T2_0U_EQ_2_DDVDH	0x00	// b0000.0000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T2_1U_EQ_2_DDVDH	0x04	// b0000.0100
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T2_2U_EQ_2_DDVDH	0x08	// b0000.1000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T2_3U_EQ_2_DDVDH	0x0C	// b0000.1100
//T3
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T3_0U_EQ_2_DDVDH	0x00	// b0000.0000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T3_1U_EQ_2_DDVDH	0x10	// b0001.0000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T3_2U_EQ_2_DDVDH	0x20	// b0010.0000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T3_3U_EQ_2_DDVDH	0x30	// b0011.0000
//T4
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T4_0U_EQ_2_GND		0x00	// b0000.0000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T4_1U_EQ_2_GND		0x40	// b0100.0000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T4_2U_EQ_2_GND		0x80	// b1000.0000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_T4_3U_EQ_2_GND		0xC0	// b1100.0000
// Common Combinations
#define ILI9341_DRV_TIME_CTRL_BVG_SW_TALL_0U			0x00	// b0000.0000
#define ILI9341_DRV_TIME_CTRL_BVG_SW_TALL_1U			0x55	// b0101.0101
#define ILI9341_DRV_TIME_CTRL_BVG_SW_TALL_2U			0xAA	// b1010.1010
#define ILI9341_DRV_TIME_CTRL_BVG_SW_TALL_3U			0xFF	// b1111.1111
#define ILI9341_DRV_TIME_CTRL_BVG_SW_TALL_DEFAULT		0x66	// b0110.0110

// 2nd Parameter
#define ILI9341_DRV_TIME_CTRL_B_P2						0x00	// b00.00.00.00 [Default]


//************************************************//
//**********  Power On Sequence Control  *********//
//************************************************//

// Command: Power On Sequence Control
#define ILI9341_PWR_ON_SEQ_CTRL							0xED

// 1st Parameter: Soft Start Control [ CP1_SS | CP2_SS ]
// CP1_SS
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP1SS_KEEP_3F		0x40	// b0100.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP1SS_KEEP_2F		0x50	// b0101.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP1SS_KEEP_1F		0x60	// b0110.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP1SS_DISABLE		0x70	// b0111.0000
// CP2_SS
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP2SS_KEEP_3F		0x04	// b0000.0100
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP2SS_KEEP_2F		0x05	// b0000.0101
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP2SS_KEEP_1F		0x06	// b0000.0110
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP2SS_DISABLE		0x07	// b0000.0111
// Common Combinations
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP12_DEFAULT			0x55	// b0101.0101
#define ILI9341_PWR_ON_SEQ_CTRL_P1_CP1K1_CP2K3			0x64	// b0110.0100

// 2nd Parameter: Power On Sequence Control	[ EN_VCL | EN_DDVDH ]
// EN_VCL
#define ILI9341_PWR_ON_SEQ_CTRL_P2_EN_VCL_1ST_FRAME		0x00	// b0000.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P2_EN_VCL_2ND_FRAME		0x10	// b0001.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P2_EN_VCL_3RD_FRAME		0x20	// b0010.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P2_EN_VCL_4TH_FRAME		0x30	// b0011.0000
// EN_DDVDH
#define ILI9341_PWR_ON_SEQ_CTRL_P2_EN_DDVDH_1ST_FRAME	0x00	// b0000.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P2_EN_DDVDH_2ND_FRAME	0x01	// b0000.0001
#define ILI9341_PWR_ON_SEQ_CTRL_P2_EN_DDVDH_3RD_FRAME	0x02	// b0000.0010
#define ILI9341_PWR_ON_SEQ_CTRL_P2_EN_DDVDH_4TH_FRAME	0x03	// b0000.0011
// Common Combinations
#define ILI9341_PWR_ON_SEQ_CTRL_P2_EN_DEFAULT			0x01	// b0000.0001

// 3rd Parameter: Power On Sequence Control [ EN_VGH | EN_VGL ]
// EN_VGH
#define ILI9341_PWR_ON_SEQ_CTRL_P3_EN_VGH_1ST_FRAME		0x00	// b0000.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P3_EN_VGH_2ND_FRAME		0x10	// b0001.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P3_EN_VGH_3RD_FRAME		0x20	// b0010.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P3_EN_VGH_4TH_FRAME		0x30	// b0011.0000
// EN_VGL
#define ILI9341_PWR_ON_SEQ_CTRL_P3_EN_VGL_1ST_FRAME		0x00	// b0000.0000
#define ILI9341_PWR_ON_SEQ_CTRL_P3_EN_VGL_2ND_FRAME		0x01	// b0000.0001
#define ILI9341_PWR_ON_SEQ_CTRL_P3_EN_VGL_3RD_FRAME		0x02	// b0000.0010
#define ILI9341_PWR_ON_SEQ_CTRL_P3_EN_VGL_4TH_FRAME		0x03	// b0000.0011
// Common Combinations
#define ILI9341_PWR_ON_SEQ_CTRL_P3_EN_DEFAULT			0x23	// b0010.0011

// 4th Parameter: DDVDH Enhance Mode (only for 8 external capacitors)
#define ILI9341_PWR_ON_SEQ_CTRL_P4_DDVDH_ENH_DISABLE	0x01	// b0000.0001
#define ILI9341_PWR_ON_SEQ_CTRL_P4_DDVDH_ENH_ENABLE		0x81	// b1000.0001


//************************************************//
//**********  Enable 3G  				 *********//
//************************************************//

// Command: Enable 3G
#define ILI9341_ENABLE_3_GAMMA							0xF2

// 1st Parameter: Ratio Control
#define ILI9341_ENABLE_3_GAMMA_P1_3G_DISABLE			0x02	// b0000.0010
#define ILI9341_ENABLE_3_GAMMA_P1_3G_ENABLE				0x03	// b0000.0011


//************************************************//
//**********  Pump Ratio Contorl		 *********//
//************************************************//
// Command: Pump Ratio Contorl
#define ILI9341_PUMP_RATIO_CTRL              			0xF7

// 1st Parameter: Ratio Control
#define ILI9341_PUMP_RATIO_CTRL_P1_DDVDH_2xVCI			0x20	// b0010.0000
#define ILI9341_PUMP_RATIO_CTRL_P1_DDVDH_3xVCI			0x30	// b0011.0000

//***************************************************************************//
//***************************************************************************//
//***************************************************************************//



#endif