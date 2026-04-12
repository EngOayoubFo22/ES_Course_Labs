#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* CPU Frequency */
#define FOSC 4000000

/* Baud Rate */
#define UART_BAUDRATE 9600

/* Speed Mode */
#define UART_HIGH_SPEED 1

#if UART_HIGH_SPEED
#define UART_SPBRG_VALUE ((FOSC / (16UL * UART_BAUDRATE)) - 1UL)
#else
#define UART_SPBRG_VALUE ((FOSC / (64UL * UART_BAUDRATE)) - 1UL)
#endif

#endif
