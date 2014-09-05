
#include <stdint.h>
#include "serial.h"
#include <plib.h>

static uint8_t TXBUFFER[TX_BUFFER_SIZE];
uint8_t RXBUFFER[RX_BUFFER_SIZE];

int TXBUFFER_PTR;
int RXBUFFER_PTR;

/* Next response data size. */
uint8_t data_size;
/* Target ECU addr. */
uint8_t ECU_ADDR;
/* Keyword variable. */
uint16_t KEYWORD;

static GFX_XCHAR ERRORSTRINGS[] = {"none\0timeout\0CRC error\0invalid answer\0invalid keyword\0"};
static GFX_XCHAR ERRORSTRING[] = {"none\0wake up\0init\0wait for connect\0datachange\0"};

enum e_rxstate rxstate = init_start;
enum e_OBD_error OBD_ERROR = none;
enum e_wakeupstate WAKE_UP_STATE = WAKE_UP_STAND_BY;
enum e_connect_state CONNECT_STATE = NONE;

enum e_connect_state GetConnectState() {return CONNECT_STATE;};
enum e_OBD_error GetErrorState() {return OBD_ERROR;};

GFX_XCHAR* GetStringANumber(const GFX_XCHAR* buffer, int hownum)
{ int i = 0, num = 0;
  for (i = 0; num < hownum; i++)
  {
    if (buffer[i] == '\0') num++;
  }
  return (GFX_XCHAR*)&buffer[i];
}

GFX_XCHAR* GetConnectStateString()
{
  return GetStringANumber(ERRORSTRING, (int) CONNECT_STATE);
}

GFX_XCHAR* GetOBDErrorString()
{ 
  return GetStringANumber(ERRORSTRINGS, (int) OBD_ERROR);
}

/* Format a byte array to hex string. */
int Format8bytesforhex(char* bstring, uint8_t* bstart)
{
  sprintf(bstring, "%2X %2X %2X %2X %2X %2X %2X %2X", bstart[0],bstart[1], bstart[2], bstart[3], bstart[4], bstart[5], bstart[6], bstart[7]);
}

void ClearRXBuffer()
{ int i;
  RXBUFFER_PTR = 0;
  TXBUFFER_PTR = 0;
  for (i = 0; i < RX_BUFFER_SIZE; i++)
  {
    RXBUFFER[i] = 0;
  }
}

void InitUART1()
{
#ifdef TEST_MODE
  UARTConfigure(UART_MODULE_ID, UART_ENABLE_PINS_TX_RX_ONLY | UART_INVERT_TRANSMIT_POLARITY | 
      UART_INVERT_RECEIVE_POLARITY | UART_ENABLE_LOOPBACK);
#else
  UARTConfigure(UART_MODULE_ID, UART_ENABLE_PINS_TX_RX_ONLY | UART_INVERT_TRANSMIT_POLARITY |
      UART_INVERT_RECEIVE_POLARITY);
#endif
  UARTSetFifoMode(UART_MODULE_ID, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
  UARTSetLineControl(UART_MODULE_ID, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
  UARTSetDataRate(UART_MODULE_ID, GetPeripheralClock(), DESIRED_BAUDRATE);
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

  INTEnable(INT_SOURCE_UART_RX(UART_MODULE_ID), INT_ENABLED);
//  INTEnable(INT_SOURCE_UART_TX(UART_MODULE_ID), INT_ENABLED);
  INTSetVectorPriority(INT_VECTOR_UART(UART_MODULE_ID), INT_PRIORITY_LEVEL_2);
  INTSetVectorSubPriority(INT_VECTOR_UART(UART_MODULE_ID), INT_SUB_PRIORITY_LEVEL_2);
  ClearRXBuffer();
}

void PutCharacter(const char character)
{
        while(!UARTTransmitterIsReady(UART_MODULE_ID))
            ;

        UARTSendDataByte(UART_MODULE_ID, character);


        while(!UARTTransmissionHasCompleted(UART_MODULE_ID))
            ;
}

// Helper functions
void WriteString(const char *string)
{

//  PORTDbits.RD0 = 0;
    while(*string != '\0')
    {
        while(!UARTTransmitterIsReady(UART_MODULE_ID))
            ;

        UARTSendDataByte(UART_MODULE_ID, *string);

        string++;

        while(!UARTTransmissionHasCompleted(UART_MODULE_ID)) ;
    }
//  PORTDbits.RD0 = 1;
}

void WriteBuffer(const char *buffer, int size)
{ int i;

for (i = 0; i < size; i++)
    {
        while(!UARTTransmitterIsReady(UART_MODULE_ID))
            ;

        UARTSendDataByte(UART_MODULE_ID, *buffer);

        buffer++;

//        while(!UARTTransmissionHasCompleted(UART_MODULE_ID)) ;
    }

}

uint8_t CRCMake(int size, uint8_t* buffer)
{ int i; uint8_t sum = 0;
  for (i = 0; i < size; i++)
  {
    sum += buffer[i];
  }
return sum;
}

int CheckConnection(uint8_t* buffer)
{
  if ((buffer[0] > 0x80) && (buffer[0] < 0x88))
  {
    data_size = buffer[0] - 0x80;
    if ((buffer[1] == TESTER_ADDR) && (buffer[3] == INIT_FORMAT_BYTE))
    {
      ECU_ADDR = RXBUFFER[2];
      KEYWORD = RXBUFFER[4] + (RXBUFFER[5] * 256);
      if (KEYWORD == KEY_ISO14230_4)
      { /* Initialization OK...*/
        return 0;
      } else
      {
        return -3;
      }
    } else return -2;
  } else return -1;
}

/* Serial interrupt program for RX characters. */

void __ISR(_UART_1_VECTOR, ipl2) IntUart1Handler(void)
{
	// Is this an RX interrupt?
	if(INTGetFlag(INT_SOURCE_UART_RX(UART_MODULE_ID)))
	{
    if (RXBUFFER_PTR < RX_BUFFER_SIZE)
    {
      if (RXBUFFER_PTR < (INIT_RESPOND_SIZE - 1))
      {
        RXBUFFER[RXBUFFER_PTR++] = U1RXREG;
      } else
      {
        if (CRCMake((INIT_RESPOND_SIZE - 1), RXBUFFER) == U1RXREG)
        {/* CRC OK*/
          if (CheckConnection(RXBUFFER) > -1)
          {
            OBD_ERROR = none;
            if (CONNECT_STATE == WAIT_FOR_CONNECT)
            {
              /* Have been running the data change with ECU. */
              CONNECT_STATE = DATACHANGE;
              LED_RED_02_LAT() = 1;
            }
          } else
          {
            OBD_ERROR = connection_error;
          }
        }else
        {
          OBD_ERROR = CRC;
        }
      }
    } else
    {
      OBD_ERROR = rxbuffer_full;
      RXBUFFER_PTR = 0;
    }
    // Clear the RX interrupt Flag
	  INTClearFlag(INT_SOURCE_UART_RX(UART_MODULE_ID));

	}
}

void DisableUART1()
{
  UARTEnable(UART_MODULE_ID, UART_DISABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
}

void EnableUART1()
{
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
}

bool WriteInit()
{
#ifndef TEST_MODE
  TXBUFFER[0] = INIT_FORMAT_BYTE;
  TXBUFFER[1] = TARGET_ADDR;
  TXBUFFER[2] = TESTER_ADDR;
  TXBUFFER[3] = START_COMM_REQ;
  TXBUFFER[4] = CRCMake(3, TXBUFFER);

#define INIT_SIZE 5
#else
  TXBUFFER[0] = 0x83;
  TXBUFFER[1] = TESTER_ADDR;
  TXBUFFER[2] = 0x11;
  TXBUFFER[3] = INIT_FORMAT_BYTE;
  TXBUFFER[4] = 0xE9;
  TXBUFFER[5] = 0x8F;
  TXBUFFER[6] = CRCMake(6, TXBUFFER);

#define INIT_SIZE 7
#endif

  WriteBuffer(TXBUFFER, INIT_SIZE);
  return true;
}

/* Wake UP ECU for slow, or fast init procedure. */

void WakeUpEQU()
{
  CONNECT_STATE = WAKE_UP;
}

/* We'll use the T4 timer for overtime measuring the incoming packets. */

int T4_TICK_TACK = 0;

void __ISR(_TIMER_4_VECTOR, ipl2) Timer4Handler(void)
{
  switch (CONNECT_STATE)
  { /* switch connect_state */
    case NONE:
    {
      
    } break;
    case WAKE_UP:
    {
      switch (WAKE_UP_STATE)
      {
        case WAKE_UP_STAND_BY:
        {
          LED_YELLOW_02_LAT() = 0;
          WAKE_UP_STATE = WAKE_UP_INIT;
        } break;
        case  WAKE_UP_INIT:
        {
          T4_TICK_TACK = 0;
          DisableUART1();
          TXTRIS = 0; /* TX port set output, */
          TXLAT = 0;
          WAKE_UP_STATE = PRE_DELAY;
        } break;
        case  PRE_DELAY:
        {
          if (T4_TICK_TACK++ == 1000)
          {
            T4_TICK_TACK = 0;
            TXLAT = 1;
            WAKE_UP_STATE = WK_ON_DELAY;
          }
        } break;
        case  WK_ON_DELAY:
        {
          if (T4_TICK_TACK++ == 25)
          {
            T4_TICK_TACK = 0;
            TXLAT = 0;
            WAKE_UP_STATE = WK_OFF_DELAY;
          }
        } break;
        case  WK_OFF_DELAY:
        {
          if (T4_TICK_TACK++ == 25)
          {
            EnableUART1();
            WAKE_UP_STATE = WAKE_UP_END;
          }
        } break;
        case  WAKE_UP_END:
        {

          T4_TICK_TACK = 0;
          WAKE_UP_STATE = WAKE_UP_STAND_BY;
          CONNECT_STATE = INIT;
        } break;
    } break;
    case INIT:
    {
#ifndef TEST_MODE
     /*  */
     UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_TX));
#endif
      WriteInit();
#ifndef TEST_MODE
     UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX));
#endif
      LED_YELLOW_01_LAT() = 1;
      CONNECT_STATE = WAIT_FOR_CONNECT;
    } break;
    case WAIT_FOR_CONNECT:
    {
      if (T4_TICK_TACK++ > CONNECT_OVERTIME)
      {
        CONNECT_STATE = NONE;
        OBD_ERROR = wait_for_con_timeout;
      }
    }break;
    /* This state give in the timer4 UART1RX interrupt, when read the connection string. */
    case DATACHANGE:
    {
      
      LED_RED_01_LAT() = 1;
    }

    }
  }

  IFS0bits.T4IF = 0;
}

