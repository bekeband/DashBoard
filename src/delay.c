
#include <plib.h>
#include "delay.h"
#include "system.h"

/* delay used with system timer */

void delay(uint32_t period)
{
  while (GetTickValue() < period);
}

void __delay_ms(uint16_t msec)
{
  ResetTick();
  delay(msec * 2);
}

void __delay_us(uint16_t usec)
{
  delay(usec);
}
