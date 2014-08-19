

#ifndef SERIAL_H_
#define SERIAL_H_

#include <plib.h>            /* Include to use PIC32 peripheral libraries     */
#include "system.h"

#define UART_MODULE_ID UART1 // PIM is connected to Explorer through UART1 module

/* UART signaling at 10.4K baud, 8 data bits, no parity, 1 stop */
#define DESIRED_BAUDRATE (10400) //The desired BaudRate

#define TX_BUFFER_SIZE  36
#define RX_BUFFER_SIZE  36

#define waitforTXempty {while (U1STAbits.UTXBF);}

void InitUART1();
void WriteString(const char *string);
void WriteBuffer(const char *buffer, int size);
void DisableUART1();
void EnableUART1();
uint8_t* GetRXBuffer();
int GetRXBufferInHex(char* string, int max_size);
void ClearRXBuffer();

enum e_rxstate {
  init_start,
  init_read,
  comm_comm
};

enum e_init_state {
  format_byte,
  target_address,
  source_address,
  service_ID
};

enum e_OBD_error {
  none,
  timeout,
  CRC,
  invalid_answer,
  invalid_keyword
};

/* Protocol, overtime etc... */

#define INIT_RESPOND_SIZE 7

/* INIT_TIMEOUT: max timeout time the init packet answer.
 (7 bytes * 2 msec.*/

#define INIT_TIMEOUT  (INIT_RESPOND_SIZE * 2)

#define FORMAT_BYTE     0xC1
#define TARGET_ADDR     0x33
#define TESTER_ADDR     0xF1
#define START_COMM_REQ  0x81
#define KEY_ISO14230_4  0x8FE9

#endif