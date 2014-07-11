

#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

/* Define the exception address, and cause store address in program memory. */
  #define EXCEPTION_CAUSE 0x1D07FF00
  #define EXCEPTION_CAUSE_VIRTUAL 0x9D07FF00
  #define EXCEPTION_ADDR  0x1D07FF04
  #define EXCEPTION_ADDR_VIRTUAL  0x9D07FF04

/* static in case exception condition would stop auto variable being created */
static unsigned int _excep_code;
static unsigned int _excep_addr;

static GFX_XCHAR message_buffer[80];

void FormatExceptionString(GFX_XCHAR* buffer);

#endif