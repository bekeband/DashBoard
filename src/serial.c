
#include <stdint.h>
#include "serial.h"
#include <plib.h>

uint8_t TXBUFFER[TX_BUFFER_SIZE];
uint8_t RXBUFFER[RX_BUFFER_SIZE];

int TXBUFFER_PTR;
int RXBUFFER_PTR;

uint8_t data_size;

uint8_t ECU_ADDR;

uint16_t KEYWORD;

enum e_rxstate rxstate = init_start;
enum e_OBD_error OBD_ERROR = none;

uint8_t* GetRXBuffer()
{
  return (uint8_t*)&RXBUFFER;
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
  UARTConfigure(UART_MODULE_ID, UART_ENABLE_PINS_TX_RX_ONLY | UART_INVERT_TRANSMIT_POLARITY | UART_INVERT_RECEIVE_POLARITY);
  UARTSetFifoMode(UART_MODULE_ID, UART_INTERRUPT_ON_TX_NOT_FULL | UART_INTERRUPT_ON_RX_NOT_EMPTY);
  UARTSetLineControl(UART_MODULE_ID, UART_DATA_SIZE_8_BITS | UART_PARITY_NONE | UART_STOP_BITS_1);
  UARTSetDataRate(UART_MODULE_ID, GetPeripheralClock(), DESIRED_BAUDRATE);
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

  INTEnable(INT_SOURCE_UART_RX(UART_MODULE_ID), INT_ENABLED);
  INTSetVectorPriority(INT_VECTOR_UART(UART_MODULE_ID), INT_PRIORITY_LEVEL_2);
  INTSetVectorSubPriority(INT_VECTOR_UART(UART_MODULE_ID), INT_SUB_PRIORITY_LEVEL_0);
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

//  PORTDbits.RD0 = 0;
for (i = 0; i < size; i++)
    {
        while(!UARTTransmitterIsReady(UART_MODULE_ID))
            ;

        UARTSendDataByte(UART_MODULE_ID, *buffer);

        buffer++;

        while(!UARTTransmissionHasCompleted(UART_MODULE_ID)) ;
    }
//  PORTDbits.RD0 = 1;
}

void ClearUART1Errors()
{
  
}

bool CRCTest(int size, uint8_t* buffer, uint8_t TestCRC)
{ int i; uint8_t sum = 0;
  for (i = 0; i < size; i++)
  {
    sum += buffer[i];
  }
  return (TestCRC == sum);
}

/* Serial interrupt program for RX characters. */

void __ISR(_UART_1_VECTOR, ipl2) IntUart1Handler(void)
{
	// Is this an RX interrupt?
	if(INTGetFlag(INT_SOURCE_UART_RX(UART_MODULE_ID)))
	{
    unsigned char nextchar;
    nextchar = U1RXREG;
    switch (rxstate)
    {
      case init_start:
      {

        /* It seems format byte ? */
        if ((nextchar > 0x80) && (nextchar < 0x88))
        { /* save datasize for future. */
          SetTimeout(INIT_TIMEOUT);
          data_size = nextchar - 0x80;
          RXBUFFER_PTR = 0;
          StartTimeout();
          rxstate = init_read;
        };

      }break;
      /* read init command from ECU. */
      case init_read:
      {
        if (!GetTimeout())
        {
          if (RXBUFFER_PTR < (INIT_RESPOND_SIZE - 1))
          {
            RXBUFFER[RXBUFFER_PTR++] = U1RXREG;
          }else
            /* Get data_size + 3 bytes, perhaps init communication end. */
          {
            if (CRCTest(RXBUFFER_PTR - 1, RXBUFFER, RXBUFFER[RXBUFFER_PTR]))
            {/* CRC OK*/
              if ((RXBUFFER[0] == TESTER_ADDR) && (RXBUFFER[2] == FORMAT_BYTE))
              { /* Store ECU address. */
                ECU_ADDR = RXBUFFER[1];
                KEYWORD = RXBUFFER[3] + (RXBUFFER[4] * 256);
                if (KEYWORD == KEY_ISO14230_4)
                { /* Initialization OK...*/

                } else
                {
                  OBD_ERROR = invalid_keyword;
                  rxstate = init_start;
                }
              }
            } else
            {
              OBD_ERROR = CRC;
              rxstate = init_start;
            }
          }
        } else
          /* Timeout error. */
        {
          OBD_ERROR = timeout;
          rxstate = init_start;
        }

      }break;

    };

/*    if (RXBUFFER_PTR < RX_BUFFER_SIZE)
    {
      RXBUFFER[RXBUFFER_PTR++] = U1RXREG;
    }*/

    /* Received character */
    mPORTDToggleBits(BIT_2);
    // Clear the RX interrupt Flag
	  INTClearFlag(INT_SOURCE_UART_RX(UART_MODULE_ID));

      // Echo what we just received.
//      PutCharacter(UARTGetDataByte(UART_MODULE_ID));

      // Toggle LED to indicate UART activity

	}

	// We don't care about TX interrupt
	if (INTGetFlag(INT_SOURCE_UART_TX(UART_MODULE_ID)))
	{
    INTClearFlag(INT_SOURCE_UART_TX(UART_MODULE_ID));
	}
//  if (INTgetFlag())
}

void DisableUART1()
{
  UARTEnable(UART_MODULE_ID, UART_DISABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
}

void EnableUART1()
{
  UARTEnable(UART_MODULE_ID, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));
}
