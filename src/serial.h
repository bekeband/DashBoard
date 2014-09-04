

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

void WakeUpECU();
void MakeUpEQU();

bool WriteInit();

enum e_wakeupstate {
  WAKE_UP_STAND_BY,
  WAKE_UP_INIT,
  PRE_DELAY,    // 1 sec
  WK_ON_DELAY,  // 25msec
  WK_OFF_DELAY,  // 25 msec
  WAKE_UP_END
};
enum e_rxstate {
  init_start,
  init_read,
  comm_comm
};

enum e_connect_state {
  NONE    = 0,
  WAKE_UP = 1,
  INIT    = 2,
  WAIT_FOR_CONNECT = 3,
  DATACHANGE  = 4,
  DSP_NONE = -1
};

enum e_connect_state GetConnectState();
char* GetConnectStateString();

enum e_OBD_error {
  none = 0,
  timeout,
  CRC,
  invalid_answer,
  invalid_keyword,
  rxbuffer_full,
  wait_for_con_timeout,
  connection_error
};

struct s_ask_packet{
    uint8_t DEV_ADDR;
    uint8_t ASK_CODE;
    uint16_t DATA_ADDRESS;
    uint8_t CHECKSUM;
};


#define MY_ADDRESS 32
#define EOP 0x06
//#define BIN_DATA_SIZE 7

/* Protocol, overtime etc... */

#define INIT_RESPOND_SIZE 7
/* Wait for connect. This is the overtime to wait is msec. */
#define CONNECT_OVERTIME  400

/* INIT_TIMEOUT: max timeout time the init packet answer.
 (7 bytes * 2 msec.*/

#define INIT_TIMEOUT  (INIT_RESPOND_SIZE * 2)

#define FORMAT_BYTE     0xC1
#define TARGET_ADDR     0x33
#define TESTER_ADDR     0xF1
#define START_COMM_REQ  0x81
#define KEY_ISO14230_4  0x8FE9

/* predefined procedures here. */
int IsReadPacket();
void SetSerialOut(const uint8_t newbuffer[],int size);
void ClearPacket();
struct s_ask_packet* GetPacket();
int GetTick();

int ASCII_Serial_Input(uint8_t inchar);
int BINARY_Serial_Input(uint8_t inchar);
int Serial_Input(uint8_t inchar);

void ResetInbufPTR();
void Serial_Output();
void StartT4Timer();

void DisableUART1TX();
void EnableUART1RX();
void EnableUART1TX();
void DisableUART1();

#endif