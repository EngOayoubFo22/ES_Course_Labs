#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

typedef void (*EXT_INT_Callback_t)(void);

#define EXT_INT_EDGE_RISING   1
#define EXT_INT_EDGE_FALLING  0

void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 EdgeType);
void EXT_INT_SetCallback(EXT_INT_Callback_t Callback);
u8 EXT_INT_InterruptOccurred(void);
void EXT_INT_ISR(void);

#endif
