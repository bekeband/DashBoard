
#include <plib.h>
#include "delay.h"

void delay(uint32_t period)
{
/*  IFS0bits.T3IF = 0;
  OpenTimer23(T23_ON | T23_IDLE_CON | T23_PS_1_256 | T23_SOURCE_INT, period);
#if defined (SIMULATE)
#else
  while (!IFS0bits.T3IF) ;
#endif
  CloseTimer23();*/

  IFS0bits.T1IF = 0;
  OpenTimer1(T1_ON | T1_IDLE_CON | T1_TMWDIS_OFF | T1_SOURCE_INT | T1_PS_1_256, period);
#if defined (SIMULATE)
#else
  while (!IFS0bits.T1IF) ;
#endif
  CloseTimer1();
}

void __delay_ms(uint16_t msec)
{
  delay(msec * 156);
}

void __delay_us(uint16_t usec)
{
  delay(usec);
}
