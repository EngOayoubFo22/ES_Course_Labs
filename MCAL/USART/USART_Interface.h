#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

typedef void (*UART_Callback_t)(u8 Data);

void UART_Init(void);

void UART_Write(u8 Data);
u8 UART_Read(void);
u8 UART_TX_Empty(void);

void UART_SetCallback(UART_Callback_t Callback);
u8 UART_RX_InterruptOccurred(void);
void UART_ISR(void);

#endif
