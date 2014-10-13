

#ifndef SERIAL_H_
#define SERIAL_H_

#include <plib.h>            /* Include to use PIC32 peripheral libraries     */
#include "system.h"
#include "defgraphical.h"

#define UART_MODULE_ID UART1 // PIM is connected to Explorer through UART1 module

/* UART signaling at 10.4K baud, 8 data bits, no parity, 1 stop */
#define DESIRED_BAUDRATE (10400) //The desired BaudRate

#define TX_BUFFER_SIZE  36
#define RX_BUFFER_SIZE  36

#define waitforTXempty {while (U1STAbits.UTXBF);}

enum e_wakeupstate {
  WAKE_UP_STAND_BY,
  WAKE_UP_INIT,
  PRE_DELAY,    // 1 sec
  WK_ON_DELAY,  // 25msec
  WK_OFF_DELAY,  // 25 msec
  WAKE_UP_END
};
enum e_rxstate {
  RXSTATE_NONE,
  INIT_LOOPBACK,
  init_read,
  comm_comm
};

enum e_connect_state {
  CONNECT_NONE    = 0,
  WAKE_UP = 1,
  INIT    = 2,
  WAIT_FOR_CONNECT = 3,
  DATACHANGE  = 4,
  WAIT_FOR_HEARTBEAT = 5,
  GET_HEARTBEAT = 6,
  HEARTBEAT_IDLE = 7,
  DSP_NONE = -1
};

enum e_OBD_error {
  none = 0,
  timeout = 1,
  CRC = 2,
  invalid_answer = 3,
  invalid_keyword = 4,
  rxbuffer_full = 5,
  wait_for_con_timeout = 6,
  heartbeat_overtime = 7,
  connection_error = 8
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
#define CONNECT_OVERTIME  4000
/* HEARTBEAT_OVERTIME */
#define HEARTBEAT_OVERTIME  1400
/* Waiting between for two heartbeat. */
#define HEARTBEAT_IDLE  400

#define PRE_DELAY_TIME  1000
#define WKUP_INPULSE_TIME_01  25
#define WKUP_INPULSE_TIME_02  25

/* INIT_TIMEOUT: max timeout time the init packet answer.
 (7 bytes * 2 msec.*/

#define INIT_TIMEOUT  (INIT_RESPOND_SIZE * 2)

#define INIT_FORMAT_BYTE      0xC1
#define PID_FORMAT_BYTE       0xC2
#define TARGET_ADDR     0x33
#define TESTER_ADDR     0xF1
#define START_COMM_REQ  0x81
#define KEY_ISO14230_4  0x8FE9
#define SERVICE_01      0x01



#define PID_PIDS_SUPPORTED_LOW      0x00
#define PID_MONITOR_STAT            0x01
#define PID_FREEZE_DTC              0x02
#define PID_FUEL_SYSTEM_STATUS      0x03
#define PID_CALC_ENGINE_LOAD        0x04
#define PID_COOLANT_TEMP            0x05
#define PID_SHORT_FUEL_BANK_1       0x06
#define PID_LONG_FUEL_BANK_1        0x07
#define PID_SHORT_FUEL_BANK_2       0x08
#define PID_LONG_FUEL_BANK_2        0x09
#define PID_FUEL_PRESSURE           0x0A

#define PID_PIDS_SUPPORTED_HIGH     0x20

void InitUART1();
void WriteString(const char *string);
int WriteBuffer(const char *buffer, int size);
void DisableUART1();
void EnableUART1();
void WriteGetPIDs();

#ifdef DEBUG_TERMINAL
int GetRXBufferInHex(char* string, int max_size);
#endif

void ClearRXBuffer();
uint8_t CRCMake(int size, uint8_t* buffer);

void WakeUpECU();
int ConnectECU();

void WriteInit();
void WriteGetPIDs();
void WriteGetPID2s();
void WriteGetPID(uint8_t PIDADDR);

enum e_connect_state GetConnectState();
enum e_OBD_error GetErrorState();

void SetConnectState(enum e_connect_state newstate);

GFX_XCHAR* GetConnectStateString();
GFX_XCHAR* GetOBDErrorString();


/* PID ask structure for pid request. */
struct s_PID_ASK
{
  /* Own the PID code, whitch must be send to ECU. */
  uint8_t PID_CODE;
  /* Size of the expected return value(s).*/
  uint8_t return_size;
};

#define READ_OVERTIME   -1
#define READ_OK         0

#define ANSWER_OVERTIME -1
#define ANSWER_OK       0

#endif