#ifndef INTERRUPT_MANAGER_H
#define INTERRUPT_MANAGER_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#define INTCON   (*(volatile u8*)0x8B)

#define INTERRUPT_GIE_BIT   7
#define INTERRUPT_PEIE_BIT  6

void INTERRUPT_EnableGlobal(void);
void INTERRUPT_DisableGlobal(void);
void INTERRUPT_EnablePeripheral(void);

#endif
