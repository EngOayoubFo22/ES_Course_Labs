#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/USART/USART_Interface.h"

#define MOTOR_PORT GPIO_PORTC
#define MOTOR_PIN1  GPIO_PIN0
#define MOTOR_PIN2  GPIO_PIN2

#define LED_PORT   GPIO_PORTC
#define LED_PIN    GPIO_PIN1

static void Motor_Stop(void)
{
    GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_LOW);
    GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
    LED_Off(LED_PORT, LED_PIN);
}

static void Motor_MoveForward(void)
{
    GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_HIGH);
    GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
    LED_On(LED_PORT, LED_PIN);
}

static void App_HandleBluetoothCommand(u8 UART_Data)
{
    switch(UART_Data)
    {
        case 'f':
            Motor_MoveForward();
        break;

        case 's':
            Motor_Stop();
        break;

        default:
        break;
    }
}

static void App_Init(void)
{
    GPIO_Init();
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN2, GPIO_OUTPUT);
    LED_Init(LED_PORT, LED_PIN);

    Motor_Stop();

    UART_Init();
    UART_SetCallback(App_HandleBluetoothCommand);
}

int main(void)
{
    App_Init();

    while(1)
    {
    }

    return 0;
}
