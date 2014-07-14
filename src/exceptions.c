/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#ifdef __XC32
    #include <xc.h>          /* Defines special funciton registers, CP0 regs  */
#endif

#include <plib.h>            /* Include to use PIC32 peripheral libraries     */
#include <stdint.h>          /* For uint32_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include <stdlib.h>
#include "gfx/gfx.h"
#include "exceptions.h"

/******************************************************************************/
/* Exception Macro Definitions                                                */
/******************************************************************************/

/*When WRITE_EXCEPTION_CAUSE_TO_FLASH is defined the PIC32 executes a self
write routine to save the exception cause register.*/

/* #define WRITE_EXCEPTION_CAUSE_TO_FLASH */

#ifdef WRITE_EXCEPTION_CAUSE_TO_FLASH

/* Physical Addresses which are at the end of KSEG 0 program memory. */
/* User may want to adjust these values */

#endif

/******************************************************************************/
/* Exception Variable Declaration                                             */
/******************************************************************************/

static uint32_t _excep_addr;
static enum E_EXCEPT_TYPE _excep_code;

static GFX_XCHAR message_buffer[80];

void OutExceptionDatas()
{
  GFX_ColorSet(BLACK);
  GFX_ScreenClear();
  GFX_ColorSet(WHITE);
  GFX_TextStringDraw(80, 210, (GFX_XCHAR*)&message_buffer, strlen(message_buffer));
};

GFX_XCHAR* GetExceptionString()
{
  return (GFX_XCHAR*)&message_buffer;
}

void FormatExceptionString(GFX_XCHAR* buffer)
{
  sprintf(message_buffer, "Exception code %u, address %lx", (unsigned int)_excep_code, _excep_addr);
}

/******************************************************************************/
/* Exception Handling                                                         */
/******************************************************************************/

/* This function overrides the normal _weak_ _generic_exception_handler which
is defined in the C32 User's Guide.  The _weak_ _generic_exception_handler
just does an infinite loop. */
void _general_exception_handler(void)
{ int i;
    unsigned long t0 = _CP0_GET_COUNT(); /* Used for NVMOP 6 us Delay */

    /* Mask off Mask of the ExcCode Field from the Cause Register
    Refer to the MIPs M4K Software User's manual */
    _excep_code=_CP0_GET_CAUSE() & 0x0000007C >> 2;
    _excep_addr=_CP0_GET_EPC();
    _excep_addr = 0x12345678;

    _CP0_SET_STATUS(_CP0_GET_STATUS()&0xFFFFFFE); /* Disable Interrupts */

#ifdef WRITE_EXCEPTION_CAUSE_TO_FLASH

    /* Store the exception causes in program memory in case the part exhibited
    the problem in release mode.  Gives user a place to start debugging
    the problem. */

    NVMCON = 0x4001;            /* set WREN and Word Programing mode */
    NVMADDR = EXCEPTION_CAUSE;  /* PM Address at which we'll store the */
                                /* cause register */
    NVMDATA   = _excep_code;

    /* wait at least 6 us for LVD start-up
    assume we're running at max frequency
    (80 MHz) so we're always safe */
    {
        while (_CP0_GET_COUNT() - t0 < (80/2)*6);
    }

    NVMKEY    = 0xAA996655;
    NVMKEY    = 0x556699AA;     /* unlock sequence */
    NVMCONSET = NVMCON_WR;
    while(NVMCON & NVMCON_WR);  /* wait on write to finish */

    NVMCON = 0x4001;            /* set WREN and Word Programing mode */
    NVMADDR = EXCEPTION_ADDR;   /* PM Address at which we'll store the */
                                /* exception address register */
    NVMDATA   = _excep_addr;

    /* wait at least 6 us for LVD start-up
    assume we're running at max frequency
    (80 MHz) so we're always safe */
    {
        while (_CP0_GET_COUNT() - t0 < (80/2)*6);
    }

    NVMKEY    = 0xAA996655;
    NVMKEY    = 0x556699AA;     /* unlock sequence */
    NVMCONSET = NVMCON_WR;
    while(NVMCON & NVMCON_WR);

    /* Write the exception cause and address to the part can be read and
    the cause determined. */
    FormatExceptionString(message_buffer);

    if (!NVMWriteWord((void*)EXCEPTION_CAUSE, _excep_code) && !NVMWriteWord((void*)EXCEPTION_ADDR, _excep_addr))
    {
      GFX_ColorSet(BLACK);
    } else
    {
      GFX_ColorSet(RED);
    }

    OutExceptionDatas();
    for (i = 0; i < 5; i++) __delay_ms(400);
    SoftReset();

#endif

}

