#include "../HAL/Led_interface.h"
#include "../MCAL/GPIO/gpio-interface.h"

#define LED1_PORT   GPIO_PORTC
#define LED1_PIN    GPIO_PIN0
#define LED2_PORT   GPIO_PORTC
#define LED2_PIN    GPIO_PIN1

#define SW1_PORT    GPIO_PORTB
#define SW1_PIN     GPIO_PIN0
#define SW2_PORT    GPIO_PORTB
#define SW2_PIN     GPIO_PIN1

static void LEDs_AllOn(void){
    LED_On(LED1_PORT, LED1_PIN);
    LED_On(LED2_PORT, LED2_PIN);
}

static void LEDs_AllOff(void){
    LED_Off(LED1_PORT, LED1_PIN);
    LED_Off(LED2_PORT, LED2_PIN);
}

static unsigned char SW1_IsPressed(void){
    return (GPIO_GetPinValue(SW1_PORT, SW1_PIN) == 0);
}

static unsigned char SW2_IsPressed(void){
    return (GPIO_GetPinValue(SW2_PORT, SW2_PIN) == 0);
}

static void RunShortSequence_Once(void){
    LEDs_AllOn();  Delay_ms(200);
    LEDs_AllOff(); Delay_ms(200);
}

static void RunLongSequence_Once(void){
    LEDs_AllOn();  Delay_ms(500);
    LEDs_AllOff(); Delay_ms(500);
}

void main(void){
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    GPIO_SetPinDirection(SW1_PORT, SW1_PIN, GPIO_INPUT);
    GPIO_SetPinDirection(SW2_PORT, SW2_PIN, GPIO_INPUT);

    OPTION_REG &= 0x7F;   // RBPU = 0

    LEDs_AllOff();

    while(1){
        if (SW1_IsPressed())       RunShortSequence_Once();
        else if (SW2_IsPressed())  RunLongSequence_Once();
        else                       LEDs_AllOff();
    }
}
