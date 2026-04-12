#include "EXT_INT_Interface.h"
#include "EXT_INT_Config.h"
#include "EXT_INT_Private.h"
#include "../GPIO/GPIO_interface.h"
#include "../INTERRUPT_MANAGER/Interrupt_Manager.h"
#include "../../SERVICES/BIT_MATH.h"

static EXT_INT_Callback_t EXT_INT_Callback = NULL_PTR;

void EXT_INT_Init(void)
{
    GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);
    EXT_INT_SetEdge(EXT_INT_EDGE_FALLING);
    EXT_INT_Disable();
}

void EXT_INT_Enable(void)
{
    CLR_BIT(INTCON, EXT_INT_INTF_BIT);
    SET_BIT(INTCON, EXT_INT_INTE_BIT);
    INTERRUPT_EnableGlobal();
}

void EXT_INT_Disable(void)
{
    CLR_BIT(INTCON, EXT_INT_INTE_BIT);
    CLR_BIT(INTCON, EXT_INT_INTF_BIT);
}

void EXT_INT_SetEdge(u8 EdgeType)
{
    if(EdgeType == EXT_INT_EDGE_RISING)
    {
        SET_BIT(OPTION_REG, EXT_INT_INTEDGE_BIT);
    }
    else
    {
        CLR_BIT(OPTION_REG, EXT_INT_INTEDGE_BIT);
    }
}

void EXT_INT_SetCallback(EXT_INT_Callback_t Callback)
{
    EXT_INT_Callback = Callback;
}

u8 EXT_INT_InterruptOccurred(void)
{
    return GET_BIT(INTCON, EXT_INT_INTF_BIT);
}

void EXT_INT_ISR(void)
{
    CLR_BIT(INTCON, EXT_INT_INTF_BIT);

    if(EXT_INT_Callback != NULL_PTR)
    {
        EXT_INT_Callback();
    }
}
