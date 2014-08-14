
#include <stdint.h>
#include "serial.h"
#include <plib.h>

uint8_t TXBUFFER[TX_BUFFER_SIZE];
uint8_t RXBUFFER[RX_BUFFER_SIZE];

int TXBUFFER_PTR;
int RXBUFFER_PTR;

uint8_t data_size;

enum e_rxstate rxstate = init_comm;

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

/* Serial interrupt program for RX characters. */

void __ISR(_UART_1_VECTOR, ipl2) IntUart1Handler(void)
{
	// Is this an RX interrupt?
	if(INTGetFlag(INT_SOURCE_UART_RX(UART_MODULE_ID)))
	{
    switch (rxstate)
    {
      case init_comm:
      {
        /* It seems format byte ? */
        if ((U1RXREG > 0x80) && (U1RXREG < 0x88))
        { /* save datasize for future. */
          data_size = U1RXREG - 0x80;
        }
      }
    };

    if (RXBUFFER_PTR < RX_BUFFER_SIZE)
    {
      RXBUFFER[RXBUFFER_PTR++] = U1RXREG;
    }

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
