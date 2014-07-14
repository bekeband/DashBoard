

#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

/* Define the exception address, and cause store address in program memory. */
#define EXCEPTION_CAUSE 0x1D030000
#define EXCEPTION_CAUSE_VIRTUAL 0x9D030000
#define EXCEPTION_ADDR  0x1D030004
#define EXCEPTION_ADDR_VIRTUAL  0x9D030004

/* static in case exception condition would stop auto variable being created  */
static enum E_EXCEPT_TYPE {
    EXCEP_IRQ = 0,           /* interrupt */
    EXCEP_AdEL = 4,          /* address error exception (load or ifetch) */
    EXCEP_AdES,              /* address error exception (store) */
    EXCEP_IBE,               /* bus error (ifetch) */
    EXCEP_DBE,               /* bus error (load/store) */
    EXCEP_Sys,               /* syscall */
    EXCEP_Bp,                /* breakpoint */
    EXCEP_RI,                /* reserved instruction */
    EXCEP_CpU,               /* coprocessor unusable */
    EXCEP_Overflow,          /* arithmetic overflow */
    EXCEP_Trap,              /* trap (possible divide by zero) */
    EXCEP_IS1 = 16,          /* implementation specfic 1 */
    EXCEP_CEU,               /* CorExtend Unuseable */
    EXCEP_C2E                /* coprocessor 2 */
} S_EXCEPT_TYPE;

/* static in case exception condition would stop auto variable being created */
static enum E_EXCEPT_TYPE _excep_code;
static uint32_t _excep_addr;

//static GFX_XCHAR message_buffer[80];

void FormatExceptionString(GFX_XCHAR* buffer);
GFX_XCHAR* GetExceptionString();

#endif