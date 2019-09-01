
#ifndef INC_CMDLINE_H_
#define INC_CMDLINE_H_

#include "includes.h"

#define RX_BUFFER_SIZE   32

void CmdlineTask(void const * argument);
void USART_CharReception_Callback(void);

#endif
