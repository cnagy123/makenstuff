
// Source and Destination Buffers Size
#define SSI0_BUFFER_SIZE         1024

////  SSI0 Buffers
//static uint8_t SSI0_TxBuf[SSI0_BUFFER_SIZE];
//static uint8_t SSI0_RxBuf[SSI0_BUFFER_SIZE];
//
// Error Counter.
static uint32_t errCount = 0;
//
//// The count of SSI0 buffers filled
//static uint32_t SSI0_RxCount = 0;
//static uint32_t SSI0_TxCount = 0;

// The control table used by the uDMA controller.  This table must be aligned to a 1024 byte boundary.
#pragma data_alignment=1024
uint8_t pui8ControlTable[1024];

extern void uDMA_Init(void){

}
extern void uDMA_Interrupt_Init(void){

}

extern void uDMA_Interrupt_Handler(void){

  }

// The interrupt handler for uDMA errors.  This interrupt will occur if the
// uDMA encounters a bus error while trying to perform a transfer.  This
// handler just increments a counter if an error occurs.
void uDMA_Error_Handler(void){
  
  uint32_t errStatus;
  
  // Check for Error
  errStatus = ROM_uDMAErrorStatusGet();
  
  // If Error, Clear and Increase Error Counter
  if(errStatus){
    ROM_uDMAErrorStatusClear();
    errCount++;
  }
  
}