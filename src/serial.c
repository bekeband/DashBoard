
#include <stdint.h>
#include "serial.h"
#include <plib.h>

static uint8_t TXBUFFER[TX_BUFFER_SIZE];
uint8_t RXBUFFER[RX_BUFFER_SIZE];
//static UART_DATA TXBUFFERU[TX_BUFFER_SIZE];
//UART_DATA RXBUFFERU[RX_BUFFER_SIZE];
int SEND_DATA_SIZE;
int BUFFER_TEST_MODE = 1;
int IsSizeByte = 0;
int datasize;

int SEND_DATA_SIZE;
int REC_DATA_SIZE;

int ReceivedData = 0;

int TXBUFFER_PTR;
int RXBUFFER_PTR;

/* Sucessfully sended packet (packet ID.) */
long PacketSended = 0;

/* Next response data size. */
uint8_t data_size;
/* Target ECU addr. */
uint8_t ECU_ADDR;
/* Keyword variable. */
uint16_t KEYWORD;

//static s_PID_ASK

static GFX_XCHAR ERRORSTRINGS[] = {"none\0timeout\0CRC error\0invalid answer\0invalid keyword\0rxbuffer full\0wait for conn timeout\0"\
"heartbeat overtime\0connection error\0"};

static GFX_XCHAR CONNECT_STATE_STRINGS[] = {"none\0wake up\0init\0wait for connect\0datachange\0wait for heartbeat\0heartbreak OK\0heartbeat \
idle\0getpid state"};

enum e_rxstate RX_STATE_MODE;
enum e_OBD_error OBD_ERROR = none;
enum e_wakeupstate WAKE_UP_STATE = WAKE_UP_STAND_BY;
enum e_connect_state CONNECT_STATE = DSP_NONE; // CONNECT_NONE;

enum e_connect_state GetConnectState() {return CONNECT_STATE;};
enum e_OBD_error GetErrorState() {return OBD_ERROR;};

/* Wake UP ECU for slow, or fast init procedure. */

void SetConnectState(enum e_connect_state newstate) {CONNECT_STATE = newstate;};

/*void WakeUpECU()
{
  CONNECT_STATE = WAKE_UP;
}*/

void WakeUpECU()
{ 
  DisableUART1();
  TXTRIS = 0; 
  TXLAT = 0;
  __delay_ms(300);
  __delay_ms(300);
  __delay_ms(300);
  TXLAT = 1;
  __delay_ms(WKUP_INPULSE_TIME_01);
  TXLAT = 0;
  __delay_ms(WKUP_INPULSE_TIME_02);
  EnableUART1();
//  CONNECT_STATE = INIT;
}

int ConnectECU()
{
  WakeUpECU();
  WriteInit();
}

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
  return GetStringANumber(CONNECT_STATE_STRINGS, (int) CONNECT_STATE);
}

GFX_XCHAR* GetOBDErrorString()
{ 
  return GetStringANumber(ERRORSTRINGS, (int) OBD_ERROR);
}

void ClearRXBuffer()
{
  if (UARTReceivedDataIsAvailable(UART_MODULE_ID))
    UARTGetData(UART_MODULE_ID);
  U1STAbits.OERR = 0;
  RXBUFFER_PTR = 0;
/*  for (i = 0; i < RX_BUFFER_SIZE; i++)
  {
    RXBUFFER[i] = 0;
  }*/
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
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL));

  /* TODO RX interrupt not enabled !!! */
  INTEnable(INT_SOURCE_UART_RX(UART_MODULE_ID), INT_ENABLED);
  INTEnable(INT_SOURCE_UART_TX(UART_MODULE_ID), INT_ENABLED);
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

void RXSimplex()
{
  UARTEnable(UART_MODULE_ID, UART_DISABLE_FLAGS(UART_TX));
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_RX));
}

void TXSimplex()
{
  UARTEnable(UART_MODULE_ID, UART_DISABLE_FLAGS(UART_RX));
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_TX));
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
/* Asyncronious serial write */
WriteBufferAsync(const char* buffer, int size)
{
  memcpy(TXBUFFER, buffer, size);
  SEND_DATA_SIZE = size;
  TXSimplex();
}

int WriteBuffer(const char *buffer, int size)
{ int i;

#ifndef TEST_MODE
     /*  */
//     UARTEnable(UART_MODULE_ID, UART_DISABLE_FLAGS(UART_RX));
#endif

for (i = 0; i < size; i++)
  {
    while(!UARTTransmitterIsReady(UART_MODULE_ID));

    UARTSendDataByte(UART_MODULE_ID, *buffer);

    buffer++;

    while(!UARTTransmissionHasCompleted(UART_MODULE_ID)) ;
  }

#ifndef TEST_MODE
//     UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_RX));
#endif

return i;
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


void StartOvertimeTicker()
{
}

void ResetOvertimeTicker()
{
}


/* Serial interrupt program for RX characters. */

void __ISR(_UART_1_VECTOR, ipl2) IntUart1Handler(void)
{
  UART_DATA data;

	// Is this an RX interrupt?
	if(INTGetFlag(INT_SOURCE_UART_RX(UART_MODULE_ID)))
	{

    INTClearFlag(INT_SOURCE_UART_RX(UART_MODULE_ID));
    //    if (IsEcho) return;

    if (!IsSizeByte)
    {
      data = UARTGetData(UART_MODULE_ID);
      RXBUFFER[RXBUFFER_PTR++] = data.data8bit;
      datasize = data.data8bit & 0b00111111;
      if (!(((datasize >= MIN_ANSWER_SIZE) && (datasize <= MAX_ANSWER_SIZE))))
      {
        /* Bad data size. */
      } else
      {
        REC_DATA_SIZE = datasize + 4;
      }
      IsSizeByte = 1;
    } else
    {
      if (REC_DATA_SIZE--)
      {
        data = UARTGetData(UART_MODULE_ID);
        RXBUFFER[RXBUFFER_PTR++] = data.data8bit;
      } else
      {
        ReceivedData = 1;
      }
    }



/*if (BUFFER_TEST_MODE)
{
    if (RXBUFFER_PTR < RX_BUFFER_SIZE)
    {
      data = UARTGetData(UART_MODULE_ID);
      RXBUFFERU[RXBUFFER_PTR++] = data;
    } else
    {
      RXBUFFER_PTR = 0;
    }  
} else
{

    if (RXBUFFER_PTR < RX_BUFFER_SIZE)
    {
      if (RXBUFFER_PTR < (INIT_RESPOND_SIZE - 1))
      {
        RXBUFFER[RXBUFFER_PTR++] = U1RXREG;
      } else
      {
        if (CRCMake((INIT_RESPOND_SIZE - 1), RXBUFFER) == U1RXREG)
        {
          if (CheckConnection(RXBUFFER) > -1)
          {
            OBD_ERROR = none;
            if (CONNECT_STATE == WAIT_FOR_CONNECT)
            {
              CONNECT_STATE = DATACHANGE;
              ClearRXBuffer();
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
}*/

	}

  // Is this an TX interrupt?
	if(INTGetFlag(INT_SOURCE_UART_TX(UART_MODULE_ID)))
	{
    INTClearFlag(INT_SOURCE_UART_TX(UART_MODULE_ID));
    if (SEND_DATA_SIZE--)
    {
      data.data8bit = TXBUFFER[TXBUFFER_PTR++];
      UARTSendDataByte(UART_MODULE_ID, data.data8bit);
    }else
    {
      /* Last byte have been sending, so disable transmit, and enable receive. */
      RXSimplex();
      /* Increment succesfully sended the packet counter. */
      PacketSended += 1;
//      ReceivedData = 1;
      /* Starting overtime ticker to measuring the answer time. */
      StartOvertimeTicker();
    }

  }


}

void DisableUART1()
{
  UARTEnable(UART_MODULE_ID, UART_DISABLE_FLAGS(UART_PERIPHERAL));
}

void EnableUART1()
{
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL));
}

void WriteGetPIDs()
{
  TXBUFFER[0] = PID_FORMAT_BYTE;
  TXBUFFER[1] = TARGET_ADDR;
  TXBUFFER[2] = TESTER_ADDR;
  TXBUFFER[3] = SERVICE_01;
  TXBUFFER[4] = PID_PIDS_SUPPORTED_LOW;
  TXBUFFER[5] = CRCMake(5, TXBUFFER);
  SEND_DATA_SIZE = 6;
  ClearRXBuffer();
  WriteBuffer(TXBUFFER, SEND_DATA_SIZE);
}

void WriteGetPID2s()
{
  TXBUFFER[0] = PID_FORMAT_BYTE;
  TXBUFFER[1] = TARGET_ADDR;
  TXBUFFER[2] = TESTER_ADDR;
  TXBUFFER[3] = SERVICE_01;
  TXBUFFER[4] = PID_PIDS_SUPPORTED_HIGH;
  TXBUFFER[5] = CRCMake(5, TXBUFFER);
  SEND_DATA_SIZE = 6;
  ClearRXBuffer();
  WriteBuffer(TXBUFFER, SEND_DATA_SIZE);
}

int MakeGetPIDBuffer(uint8_t PIDADDR)
{
  TXBUFFER[0] = PID_FORMAT_BYTE;
  TXBUFFER[1] = TARGET_ADDR;
  TXBUFFER[2] = TESTER_ADDR;
  TXBUFFER[3] = SERVICE_01;
  TXBUFFER[4] = PIDADDR;
  TXBUFFER[5] = CRCMake(5, TXBUFFER);
  /* return with buffer size. */
  return 6;
//  ClearRXBuffer();
//  WriteBuffer(TXBUFFER, SEND_DATA_SIZE);
//  ClearRXBuffer();
}

void WriteInit()
{ int isize;
#ifndef TEST_MODE
  TXBUFFER[0] = INIT_FORMAT_BYTE;
  TXBUFFER[1] = TARGET_ADDR;
  TXBUFFER[2] = TESTER_ADDR;
  TXBUFFER[3] = START_COMM_REQ;
  TXBUFFER[4] = CRCMake(4, TXBUFFER);
  SEND_DATA_SIZE = 5;
#else
  TXBUFFER[0] = 0x83;
  TXBUFFER[1] = TESTER_ADDR;
  TXBUFFER[2] = 0x11;
  TXBUFFER[3] = INIT_FORMAT_BYTE;
  TXBUFFER[4] = 0xE9;
  TXBUFFER[5] = 0x8F;
  TXBUFFER[6] = CRCMake(6, TXBUFFER);
  SEND_DATA_SIZE = 7;
#endif
//  isize = WriteBuffer(TXBUFFER, SEND_DATA_SIZE);
  WriteBufferAsync(TXBUFFER, SEND_DATA_SIZE);
}

int GetConnect()
{
  UARTEnable(UART_MODULE_ID, UART_DISABLE_FLAGS(UART_RX));
  WriteInit();
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_RX));
//  delay(200);
  return GetAnswer(INIT_RESPOND_SIZE, 100);
}

int GetECUData(int txsize, int overtime)
{
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_TX));
  WriteBuffer(TXBUFFER, txsize);
//  ClearRXBuffer();
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_TX));
  return GetAnswer(overtime);
}

int GetAnswer(int overtime)
{ //int i = 0;
  UART_DATA data; int datasize;
  RXBUFFER_PTR = 0;
  /* Get first byte to size. */
  if (GetSerialByte(overtime) == READ_OK)
  {
    data = UARTGetData(UART_MODULE_ID);
    RXBUFFER[RXBUFFER_PTR] = data.data8bit;
    datasize = data.data8bit & 0b00111111;
    if (!(((datasize >= MIN_ANSWER_SIZE) && (datasize <= MAX_ANSWER_SIZE))))
      return BAD_ANSWER_SIZE;
  } else return ANSWER_OVERTIME;

  /* more (datasize + 3) byte reading from serial line... */
  for (RXBUFFER_PTR = 1; RXBUFFER_PTR < (datasize + 4) ; RXBUFFER_PTR++)
  {
    if (GetSerialByte(overtime) == READ_OK)
    {
      data = UARTGetData(UART_MODULE_ID);
      RXBUFFER[RXBUFFER_PTR] = data.data8bit;
    }
    else return ANSWER_OVERTIME;
  }

  return ANSWER_OK;

/*  while ((i < answer_size) && ((UARTReceivedDataIsAvailable (UART_MODULE_ID) || ((GetTickValue() < overtime)))))
  {
    RXBUFFER[i++] == UARTGetData(UART1);
  }*/
}

int GetSerialByte(int overtime)
{
  /* reset the TIMER_3 ticker to overtime measuring. */
  ResetTick();
  while (!UARTReceivedDataIsAvailable(UART_MODULE_ID))
  {
    if (GetTickValue() > overtime)
    {
      return  READ_OVERTIME;
    }
  };
  return READ_OK;
}

/* We'll use the T4 timer for overtime measuring the incoming packets. */

int T4_TICK_TACK = 0;

void __ISR(_TIMER_4_VECTOR, ipl2) Timer4Handler(void)
{
  switch (CONNECT_STATE)
  { /* switch connect_state */
    case CONNECT_NONE:
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
          if (T4_TICK_TACK++ == PRE_DELAY_TIME)
          {
            T4_TICK_TACK = 0;
            TXLAT = 1;
            WAKE_UP_STATE = WK_ON_DELAY;
          }
        } break;
        case  WK_ON_DELAY:
        {
          if (T4_TICK_TACK++ == WKUP_INPULSE_TIME_01)
          {
            T4_TICK_TACK = 0;
            TXLAT = 0;
            WAKE_UP_STATE = WK_OFF_DELAY;
          }
        } break;
        case  WK_OFF_DELAY:
        {
          if (T4_TICK_TACK++ == WKUP_INPULSE_TIME_02)
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
      WriteInit();
      CONNECT_STATE = WAIT_FOR_CONNECT;
    } break;

    case WAIT_FOR_CONNECT:
    {
      if (T4_TICK_TACK++ > CONNECT_OVERTIME)
      {
        CONNECT_STATE = CONNECT_NONE;
        OBD_ERROR = wait_for_con_timeout;
      }
    }break;

/*    case LOOPBACK_OK:
    {

    }break;*/

    /* This state give in the timer4 UART1RX interrupt, when read the connection string. */
    case DATACHANGE:
    {
      LED_RED_01_LAT() = 1;
      T4_TICK_TACK = 0;
//      WriteGetPIDs();
      CONNECT_STATE = WAIT_FOR_HEARTBEAT;
      BUFFER_TEST_MODE = 1;
    } break;

    case WAIT_FOR_HEARTBEAT:
    {
/*      if (T4_TICK_TACK++ > HEARTBEAT_OVERTIME)
      {
        CONNECT_STATE = CONNECT_NONE;
        OBD_ERROR = heartbeat_overtime;
      };*/

    } break;
    /* We get PID datas from ECU... */
    case GET_HEARTBEAT:
    {
      T4_TICK_TACK = 0;
      CONNECT_STATE = HEARTBEAT_IDLE;
    }break;
    
    case HEARTBEAT_IDLE:
    {
      if (T4_TICK_TACK++ > HEARTBEAT_IDLE)
      {
        CONNECT_STATE = DATACHANGE;
      }
    }break;
    }
  }

  IFS0bits.T4IF = 0;
}

#ifdef DEBUG_TERMINAL
int GetRXBufferInHex(char* string, int size)
  {
  sprintf(string, "%2x %2x %2x %2x %2x %2x %2x %2x %2x %2x %2x %2x %2x %2x %2x %2x",
      RXBUFFER[0], RXBUFFER[1], RXBUFFER[2] ,RXBUFFER[3], RXBUFFER[4], RXBUFFER[5], RXBUFFER[6], RXBUFFER[7],
      RXBUFFER[8], RXBUFFER[9], RXBUFFER[10] ,RXBUFFER[11], RXBUFFER[12], RXBUFFER[13], RXBUFFER[14], RXBUFFER[15]
      );
  }
#endif