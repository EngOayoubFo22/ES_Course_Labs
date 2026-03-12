#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

void T0_Init(void);
void T0_Enable(void);
void T0_Disable(void);
void T0_SetCallback(void (*handler)(void));
void T0_Reset(void);
void T0_SetValue(u8 preload);
u8 T0_GetFlag(void);
void T0_SetFlag(void);
void T0_ClearFlag(void);

#endif