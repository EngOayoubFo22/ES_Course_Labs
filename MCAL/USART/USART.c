#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"
#include "../INTERRUPT_MANAGER/Interrupt_Manager.h"
#include "../../SERVICES/BIT_MATH.h"

static UART_Callback_t UART_Callback = NULL_PTR;

static void UART_ConfigureCore(void)
{
    CLR_BIT(TXSTA, SYNC);
    SET_BIT(RCSTA, SPEN);

#if UART_HIGH_SPEED
    SET_BIT(TXSTA, BRGH);
#else
    CLR_BIT(TXSTA, BRGH);
#endif

    SPBRG = UART_SPBRG_VALUE;
}

void UART_Init(void)
{
    UART_ConfigureCore();

    SET_BIT(RCSTA, CREN);
    SET_BIT(TXSTA, TXEN);
    SET_BIT(PIE1, RCIE);

    INTERRUPT_EnablePeripheral();
    INTERRUPT_EnableGlobal();
}

void UART_Write(u8 Data)
{
    while(!UART_TX_Empty())
    {
    }

    TXREG = Data;
}

u8 UART_Read(void)
{
    while(!UART_RX_InterruptOccurred())
    {
    }

    return RCREG;
}

u8 UART_TX_Empty(void)
{
    return GET_BIT(TXSTA, TRMT);
}

void UART_SetCallback(UART_Callback_t Callback)
{
    UART_Callback = Callback;
}

u8 UART_RX_InterruptOccurred(void)
{
    return GET_BIT(PIR1, RCIF);
}

void UART_ISR(void)
{
    u8 UART_Data = RCREG;

    if(UART_Callback != NULL_PTR)
    {
        UART_Callback(UART_Data);
    }
}
