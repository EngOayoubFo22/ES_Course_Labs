#include "Interrupt_Manager.h"
#include "../USART/USART_Interface.h"
#include "../EXT_INT/EXT_INT_Interface.h"

void INTERRUPT_EnableGlobal(void)
{
    SET_BIT(INTCON, INTERRUPT_GIE_BIT);
}

void INTERRUPT_DisableGlobal(void)
{
    CLR_BIT(INTCON, INTERRUPT_GIE_BIT);
}

void INTERRUPT_EnablePeripheral(void)
{
    SET_BIT(INTCON, INTERRUPT_PEIE_BIT);
}

void interrupt()
{
    if(UART_RX_InterruptOccurred())
    {
        UART_ISR();
    }

    if(EXT_INT_InterruptOccurred())
    {
        EXT_INT_ISR();
    }
}
