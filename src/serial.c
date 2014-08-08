
#include <stdint.h>
#include "serial.h"
#include <plib.h>

static uint8_t TXBUFFER[TX_BUFFER_SIZE];
static uint8_t RXBUFFER[RX_BUFFER_SIZE];

static int TXBUFFER_PTR;
static int RXBUFFER_PTR;