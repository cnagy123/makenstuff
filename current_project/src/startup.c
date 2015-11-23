//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

// Using IAR Extended Language Conformance
#pragma language=extended

// Main Stack Segment from Linker
#pragma segment="CSTACK"

// Start of Application Code
extern void __iar_program_start(void);

// Default Exception Handler Prototypes
void NMI_Handler(void);
void HardFault_Handler(void);
void MPUFault_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMonitor_Handler(void);
void PendingSV_Handler(void);
void SysTick_Handler(void);
void DefaultInterrupt_Handler(void);

// Types of Elements within the Vector Table
typedef union{
  void(*funcPtr)(void); // Pointer to Exception Handler
  void * __ptr;         // Initial Stack Pointer
}intvec_element;

//****************************************************************************//
//                      The Vector Table                                      //
//****************************************************************************//
#pragma location = ".intvec"    // Place the Vector Table in its Own Section
const intvec_element __vector_table[] =
{
  //**************************  // [Memory Loc]  - [Vector] Name <Priority> //
  {.__ptr =__sfe("CSTACK")},    // [0x0000.0000] - [00] Initial Stack Pointer
  __iar_program_start,          // [0x0000.0004] - [01] Reset <-3>
  
  NMI_Handler,                  // [0x0000.0008] - [02] NMI <-2>
  HardFault_Handler,            // [0x0000.000C] - [03] Hard Fault <-1>
  MPUFault_Handler,             // [0x0000.0010] - [04] Memory Management <P>
  BusFault_Handler,             // [0x0000.0014] - [05] Bus Fault <P>
  UsageFault_Handler,           // [0x0000.0018] - [06] Usage Fault <P>
  0,                            // [0x0000.001C] - [07] RESERVED
  0,                            // [0x0000.0020] - [08] RESERVED
  0,                            // [0x0000.0024] - [09] RESERVED
  0,                            // [0x0000.0028] - [10] RESERVED
  SVC_Handler,                  // [0x0000.002C] - [11] SVCall <P>
  DebugMonitor_Handler,         // [0x0000.0030] - [12] Debug Monitor <P>
  0,                            // [0x0000.0034] - [13] RESERVED
  
  PendingSV_Handler,            // [0x0000.0038] - [14] PendSV <P>
  SysTick_Interrupt_Handler,    // [0x0000.003C] - [15] System Tick <P>
  
  DefaultInterrupt_Handler,     // [0x0000.0040] - [016] GPIO Port A
  DefaultInterrupt_Handler,     // [0x0000.0044] - [017] GPIO Port B
  DefaultInterrupt_Handler,     // [0x0000.0048] - [018] GPIO Port C
  DefaultInterrupt_Handler,     // [0x0000.004C] - [019] GPIO Port D
  DefaultInterrupt_Handler,     // [0x0000.0050] - [020]  GPIO Port E
  DefaultInterrupt_Handler,     // [0x0000.0054] - [021] UART0 Rx and Tx
  DefaultInterrupt_Handler,     // [0x0000.0058] - [022] UART1 Rx and Tx
  SPI_Interrupt_Handler,        // [0x0000.005C] - [023] SSI0 Rx and Tx
  I2C0_Interrupt_Handler,       // [0x0000.0060] - [024] I2C0 Master and Slave
  DefaultInterrupt_Handler,     // [0x0000.0064] - [025] PWM Fault
  DefaultInterrupt_Handler,     // [0x0000.0068] - [026] PWM Generator 0
  DefaultInterrupt_Handler,     // [0x0000.006C] - [027] PWM Generator 1
  DefaultInterrupt_Handler,     // [0x0000.0070] - [028] PWM Generator 2
  DefaultInterrupt_Handler,     // [0x0000.0074] - [029] Quadrature Encoder 0
  DefaultInterrupt_Handler,     // [0x0000.0078] - [030] ADC0 Sequence 0
  DefaultInterrupt_Handler,     // [0x0000.007C] - [031] ADC0 Sequence 1
  DefaultInterrupt_Handler,     // [0x0000.0080] - [032] ADC0 Sequence 2
  DefaultInterrupt_Handler,     // [0x0000.0084] - [033] ADC0 Sequence 3
  DefaultInterrupt_Handler,     // [0x0000.0088] - [034] Watchdog timer
  Timer0A_Interrupt_Handler,    // [0x0000.008C] - [035] Timer 0 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.0090] - [036] Timer 0 subtimer B
  Timer1A_Interrupt_Handler,    // [0x0000.0094] - [037] Timer 1 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.0098] - [038] Timer 1 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.009C] - [039] Timer 2 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.00A0] - [040] Timer 2 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.00A4] - [041] Analog Comparator 0
  DefaultInterrupt_Handler,     // [0x0000.00A8] - [042] Analog Comparator 1
  DefaultInterrupt_Handler,     // [0x0000.00AC] - [043] Analog Comparator 2
  DefaultInterrupt_Handler,     // [0x0000.00B0] - [044] System Control (PLL, OSC, BO)
  DefaultInterrupt_Handler,     // [0x0000.00B4] - [045] FLASH Control
  DefaultInterrupt_Handler,     // [0x0000.00B8] - [046] GPIO Port F
  DefaultInterrupt_Handler,     // [0x0000.00BC] - [047] GPIO Port G
  DefaultInterrupt_Handler,     // [0x0000.00C0] - [048] GPIO Port H
  DefaultInterrupt_Handler,     // [0x0000.00C4] - [049] UART2 Rx and Tx
  DefaultInterrupt_Handler,     // [0x0000.00C8] - [050] SSI1 Rx and Tx
  DefaultInterrupt_Handler,     // [0x0000.00CC] - [051] Timer 3 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.00D0] - [052] Timer 3 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.00D4] - [053] I2C1 Master and Slave
  DefaultInterrupt_Handler,     // [0x0000.00D8] - [054] Quadrature Encoder 1
  DefaultInterrupt_Handler,     // [0x0000.00DC] - [055] CAN0
  DefaultInterrupt_Handler,     // [0x0000.00E0] - [056] CAN1
  DefaultInterrupt_Handler,     // [0x0000.00E4] - [057] CAN2
  0,                            // [0x0000.00E8] - [058] Reserved
  DefaultInterrupt_Handler,     // [0x0000.00EC] - [059] Hibernate
  DefaultInterrupt_Handler,     // [0x0000.00F0] - [060] USB0
  DefaultInterrupt_Handler,     // [0x0000.00F4] - [061] PWM Generator 3
  DefaultInterrupt_Handler,     // [0x0000.00F8] - [062] uDMA Software Transfer
  DefaultInterrupt_Handler,     // [0x0000.00FC] - [063] uDMA Error
  DefaultInterrupt_Handler,     // [0x0000.0100] - [064] ADC1 Sequence 0
  DefaultInterrupt_Handler,     // [0x0000.0104] - [065] ADC1 Sequence 1
  DefaultInterrupt_Handler,     // [0x0000.0108] - [066] ADC1 Sequence 2
  DefaultInterrupt_Handler,     // [0x0000.010C] - [067] ADC1 Sequence 3
  0,                            // [0x0000.0110] - [068] Reserved
  0,                            // [0x0000.0114] - [069] Reserved
  DefaultInterrupt_Handler,     // [0x0000.0118] - [070] GPIO Port J
  DefaultInterrupt_Handler,     // [0x0000.011C] - [071] GPIO Port K
  DefaultInterrupt_Handler,     // [0x0000.0120] - [072] GPIO Port L
  DefaultInterrupt_Handler,     // [0x0000.0124] - [073] SSI2 Rx and Tx
  DefaultInterrupt_Handler,     // [0x0000.0128] - [074] SSI3 Rx and Tx
  DefaultInterrupt_Handler,     // [0x0000.012C] - [075] UART3 Rx and Tx
  DefaultInterrupt_Handler,     // [0x0000.0130] - [076] UART4 Rx and Tx
  DefaultInterrupt_Handler,     // [0x0000.0134] - [077] UART5 Rx and Tx
  DefaultInterrupt_Handler,     // [0x0000.0138] - [078] UART6 Rx and Tx
  DefaultInterrupt_Handler,     // [0x0000.013C] - [079] UART7 Rx and Tx
  0,                            // [0x0000.0140] - [080] Reserved
  0,                            // [0x0000.0144] - [081] Reserved
  0,                            // [0x0000.0148] - [082] Reserved
  0,                            // [0x0000.014C] - [083] Reserved
  DefaultInterrupt_Handler,     // [0x0000.0150] - [084] I2C2 Master and Slave
  DefaultInterrupt_Handler,     // [0x0000.0154] - [085] I2C3 Master and Slave
  DefaultInterrupt_Handler,     // [0x0000.0158] - [086] Timer 4 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.015C] - [087] Timer 4 subtimer B
  0,                            // [0x0000.0160] - [088] Reserved
  0,                            // [0x0000.0164] - [089] Reserved
  0,                            // [0x0000.0168] - [090] Reserved
  0,                            // [0x0000.016C] - [091] Reserved
  0,                            // [0x0000.0170] - [092] Reserved
  0,                            // [0x0000.0174] - [093] Reserved
  0,                            // [0x0000.0178] - [094] Reserved
  0,                            // [0x0000.017C] - [095] Reserved
  0,                            // [0x0000.0180] - [096] Reserved
  0,                            // [0x0000.0184] - [097] Reserved
  0,                            // [0x0000.0188] - [098] Reserved
  0,                            // [0x0000.018C] - [099] Reserved
  0,                            // [0x0000.0190] - [100] Reserved
  0,                            // [0x0000.0194] - [101] Reserved
  0,                            // [0x0000.0198] - [102] Reserved
  0,                            // [0x0000.019C] - [103] Reserved
  0,                            // [0x0000.01A0] - [104] Reserved
  0,                            // [0x0000.01A4] - [105] Reserved
  0,                            // [0x0000.01A8] - [106] Reserved
  0,                            // [0x0000.01AC] - [107] Reserved
  DefaultInterrupt_Handler,     // [0x0000.01B0] - [108] Timer 5 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.01B4] - [109] Timer 5 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.01B8] - [110] Wide Timer 0 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.01BC] - [111] Wide Timer 0 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.01C0] - [112] Wide Timer 1 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.01C4] - [113] Wide Timer 1 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.01C8] - [114] Wide Timer 2 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.01CC] - [115] Wide Timer 2 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.01D0] - [116] Wide Timer 3 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.01D4] - [117] Wide Timer 3 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.01D8] - [118] Wide Timer 4 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.01DC] - [119] Wide Timer 4 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.01E0] - [120] Wide Timer 5 subtimer A
  DefaultInterrupt_Handler,     // [0x0000.01E4] - [121] Wide Timer 5 subtimer B
  DefaultInterrupt_Handler,     // [0x0000.01E8] - [122] FPU
  0,                            // [0x0000.01EC] - [123] Reserved
  0,                            // [0x0000.01F0] - [124] Reserved
  DefaultInterrupt_Handler,     // [0x0000.01F4] - [125] I2C4 Master and Slave
  DefaultInterrupt_Handler,     // [0x0000.01F8] - [126] I2C5 Master and Slave
  DefaultInterrupt_Handler,     // [0x0000.01FC] - [127] GPIO Port M
  DefaultInterrupt_Handler,     // [0x0000.0200] - [128] GPIO Port N
  DefaultInterrupt_Handler,     // [0x0000.0204] - [129] Quadrature Encoder 2
  0,                            // [0x0000.0208] - [130] Reserved
  0,                            // [0x0000.020C] - [131] Reserved
  DefaultInterrupt_Handler,     // [0x0000.0210] - [132] GPIO Port P0|Summary
  DefaultInterrupt_Handler,     // [0x0000.0214] - [133] GPIO Port P1
  DefaultInterrupt_Handler,     // [0x0000.0218] - [134] GPIO Port P2
  DefaultInterrupt_Handler,     // [0x0000.021C] - [135] GPIO Port P3
  DefaultInterrupt_Handler,     // [0x0000.0220] - [136] GPIO Port P4
  DefaultInterrupt_Handler,     // [0x0000.0224] - [137] GPIO Port P5
  DefaultInterrupt_Handler,     // [0x0000.0228] - [138] GPIO Port P6
  DefaultInterrupt_Handler,     // [0x0000.022C] - [139] GPIO Port P7
  DefaultInterrupt_Handler,     // [0x0000.0230] - [140] GPIO Port Q0|Summary
  DefaultInterrupt_Handler,     // [0x0000.0234] - [141] GPIO Port Q1
  DefaultInterrupt_Handler,     // [0x0000.0238] - [142] GPIO Port Q2
  DefaultInterrupt_Handler,     // [0x0000.023C] - [143] GPIO Port Q3
  DefaultInterrupt_Handler,     // [0x0000.0240] - [144] GPIO Port Q4
  DefaultInterrupt_Handler,     // [0x0000.0244] - [145] GPIO Port Q5
  DefaultInterrupt_Handler,     // [0x0000.0248] - [146] GPIO Port Q6
  DefaultInterrupt_Handler,     // [0x0000.024C] - [147] GPIO Port Q7
  DefaultInterrupt_Handler,     // [0x0000.0250] - [148] GPIO Port R
  DefaultInterrupt_Handler,     // [0x0000.0254] - [149] GPIO Port S
  DefaultInterrupt_Handler,     // [0x0000.0258] - [150] PWM 1 Generator 0
  DefaultInterrupt_Handler,     // [0x0000.025C] - [151] PWM 1 Generator 1
  DefaultInterrupt_Handler,     // [0x0000.0260] - [152] PWM 1 Generator 2
  DefaultInterrupt_Handler,     // [0x0000.0264] - [153] PWM 1 Generator 3
  DefaultInterrupt_Handler      // [0x0000.0268] - [154] PWM 1 Fault
};

//****************************************************************************//
//                       Default Exception Handler Definitions [Weak]         //
//****************************************************************************//
#pragma call_graph_root = "interrupt"
__weak void NMI_Handler(void){
  for(;;){
  }
}
#pragma call_graph_root = "interrupt"
__weak void HardFault_Handler(void){
  for(;;){
  }
}
#pragma call_graph_root = "interrupt"
__weak void MPUFault_Handler(void){
  for(;;){
  }
}
#pragma call_graph_root = "interrupt"
__weak void BusFault_Handler(void){
  for(;;){
  }
}
#pragma call_graph_root = "interrupt"
__weak void UsageFault_Handler(void){
  for(;;){
  }
}
#pragma call_graph_root = "interrupt"
__weak void SVC_Handler(void){
  for(;;){
  }
}
#pragma call_graph_root = "interrupt"
__weak void DebugMonitor_Handler(void){
  for(;;){
  }
}
#pragma call_graph_root = "interrupt"
__weak void PendingSV_Handler(void){
  for(;;){
  }
}
#pragma call_graph_root = "interrupt"
__weak void SysTick_Handler(void){
  for(;;){
  }
}
// Default Interrupt Handler
#pragma call_graph_root = "interrupt"
__weak void DefaultInterrupt_Handler(void){
  for(;;){
  }
}

//****************************************************************************//
//      Default, Low-Level Application Initialization and Start-Up            //
//****************************************************************************//
void __cmain( void );
__weak void __iar_init_core( void );
__weak void __iar_init_vfp( void );

#pragma required=__vector_table
void __iar_program_start( void )
{
  __iar_init_core();
  __iar_init_vfp();
  __cmain();
}
