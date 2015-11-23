//****************************************************************************//
//      Nagy, D. Chris                                                        //
//****************************************************************************//

#ifndef __ONBOARD_H__
#define __ONBOARD_H__

extern void LED_Init(void);
extern void Switch_Init(void);

extern uint32_t poll_switch(uint32_t *pDiff, uint32_t *pRawRead );

#endif