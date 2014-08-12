

#ifndef SERIAL_H_
#define SERIAL_H_

#include <plib.h>            /* Include to use PIC32 peripheral libraries     */
#include "system.h"

#define UART_MODULE_ID UART1 // PIM is connected to Explorer through UART1 module

/* UART signaling at 10.4K baud, 8 data bits, no parity, 1 stop */
#define DESIRED_BAUDRATE (100) //The desired BaudRate

#define TX_BUFFER_SIZE  36
#define RX_BUFFER_SIZE  36

#define waitforTXempty {while (U1STAbits.UTXBF);}

void InitUART1();
void WriteString(const char *string);
void WriteBuffer(const char *buffer, int size);
void DisableUART1();
void EnableUART1();
uint8_t RXBUFFER[RX_BUFFER_SIZE];

#endif