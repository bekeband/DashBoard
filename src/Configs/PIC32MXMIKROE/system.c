/*******************************************************************************
  System Specific Initializations

  Company:
    Microchip Technology Inc.

  File Name:
    system.c

  Summary:
    System level initializations for the specific Microchip Development Board used.

*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// Section: Includes
// *****************************************************************************
#include <xc.h>
#include <stdlib.h>
#include <system.h>
#include <sys/attribs.h>
#include <peripheral/timer.h>
//#include <usb/usb.h>
#include "driver/spi/drv_spi.h"
#include "driver/gfx/drv_gfx_display.h"
#include "driver/gfx/drv_gfx_tft003.h"
#include "driver/nvm/drv_nvm_flash_spi_m25p80.h"
#include "driver/touch_screen/drv_touch_screen.h"
//#include "memory_programmer/flash_programmer.h"

// *****************************************************************************
// Configuration bits for PIC32MX processor
// *****************************************************************************

#pragma config FPLLODIV = DIV_2
#pragma config FPLLMUL = MUL_20
#pragma config FPLLIDIV = DIV_1
#pragma config FWDTEN = OFF
#pragma config FCKSM = CSECME
#pragma config FPBDIV = DIV_2
#pragma config OSCIOFNC = ON
#pragma config POSCMOD = XT
#pragma config FSOSCEN = ON
#pragma config FNOSC = PRIPLL
#pragma config CP = OFF
#pragma config BWP = OFF
#pragma config PWP = OFF

// *****************************************************************************
// System Settings and Variables
// *****************************************************************************

int  tick = 0;        // tick counter,
int display_tick = 0; // display tick counter.
extern bool tick_tack;

// *****************************************************************************
/*  Function:
    void SYSTEM_InitializeBoard(void)

    Summary:
        This function initializes the system board modules and
        peripheral ports.

    Description:
        This function initializes the system board modules and
        peripheral ports that is specific to the PIC device
        used in this configuration.

*/
// *****************************************************************************

void SYSTEM_InitializeBoard(void)
{
    const DRV_SPI_INIT_DATA SPI_Init_Data = {2, 3, 7, 0, SPI_BUS_MODE_3, 0};

    // ---------------------------------------------------------
    // Make sure the display DO NOT flicker at start up
    // ---------------------------------------------------------
    DisplayBacklightConfig();
    DisplayPowerConfig();
    DisplayBacklightOff();

    // ---------------------------------------------------------
    // mikroe Board
    // SPI-Flash Device pins
    // ---------------------------------------------------------
    // chip select pin
    SST25_CS_TRIS   = 0;
    SST25_CS_LAT    = 1;
    // spi-clock pin
    SST25_SCK_TRIS  = 0;
    // spi-output pin
    SST25_SDO_TRIS  = 0;
    // spi-intput pin
    SST25_SDI_TRIS  = 1;

    /* Config the LED ports to output. */
    LEDPortsConfig();
    LEDPortsClear();
    // ---------------------------------------------------------
    // Initialize the Display Driver
    // ---------------------------------------------------------

    DRV_GFX_Initialize();

    DRV_NVM_M25P80_Initialize((DRV_SPI_INIT_DATA*)&SPI_Init_Data);

    // initialize system tick counter
    SYSTEM_TickInit();

    // initialize the components for Resistive Touch Screen
    TouchInit(NVMWrite, NVMRead, NVMSectorErase, NULL);
//    TouchInit(NULL, NULL, NULL, NULL);

}

// *****************************************************************************
/*  Function:
    void _USB1Interrupt(void)

    Summary:
        This function is the USB ISR for the application.

    Description:
        This function is the USB ISR for the application.

*/
// *****************************************************************************
#if defined(USB_INTERRUPT)
void __attribute__((interrupt,auto_psv)) _USB1Interrupt()
{
    USBDeviceTasks();
}
#endif

// *****************************************************************************
/*  Function:
    __T3_ISR _T3Interrupt(void)

    Summary:
        This function initializes the interrupt used for the tick timer
        of the demo.

    Description:
        This function initializes the interrupt used for the tick timer
        of the demo. This is also used to sample the resistive touch
        screen module.

*/
// *****************************************************************************

void __ISR(_TIMER_3_VECTOR, ipl2) _T3Interrupt(void)
{
    TouchDetectPosition();
    /* Display tick-tack flag to display refresh rate. */
    if (display_tick++ == DISPLAY_REFRESH)
    {
      tick_tack = true;
      display_tick = 0;
    }
    /* Must be increment to delay procedure !!!!. */
    tick++;
    IFS0bits.T3IF = 0;
}

/*********************************************************************
 * Section: Tick Delay
 *********************************************************************/
/* T3 ticker 0.5 msec timer */
#define TICK_PERIOD     (((SYS_CLK_FrequencyPeripheralGet() / 256)) / 2000)
/* T4 ticker must be 1 msec timer. */
#define TICK4_PERIOD    (((SYS_CLK_FrequencyPeripheralGet() / 256)) / 1000)

// *****************************************************************************
/*  Function:
    void SYSTEM_TickInit(void)
    Initialize Timer3 timer for 500usec system timer
    *****************************************************************************/
void SYSTEM_TickInit(void)
{
  OpenTimer3(T3_ON | T3_PS_1_256, TICK_PERIOD);
  ConfigIntTimer3(T3_INT_ON | T3_INT_PRIOR_1);

  OpenTimer4(T4_ON | T4_PS_1_256, TICK4_PERIOD);
  ConfigIntTimer4(T4_INT_ON | T4_INT_PRIOR_1);

}

void ResetTick()
{
  tick = 0;
}

int GetTickValue()
{
  return tick;
}

// *****************************************************************************
/*  Function:
    void SYSTEM_ProgramExternalMemory(void)

    Summary:
        Routine that programs the external memory used by the
        application.

    Description:
        This function programs the external memory on the system.
        Use the UART as the module to receive data to program the
        external memory.

*/
// *****************************************************************************
void SYSTEM_ProgramExternalMemory()
{
    // start the external memory programming
//    ProgramExternalMemory(DataRead, DataWrite, DataChipErase);

    // delay the reset to have time for the acknowledge data to
    // be sent to the host side
//    __delay_ms(100);

}

// *****************************************************************************
/*  Function:
    GFX_STATUS GFX_ExternalResourceCallback(
                                GFX_RESOURCE_HDR *pResource,
                                uint32_t offset,
                                uint16_t nCount,
                                void     *pBuffer)

    Summary:
        This function performs data fetch from external memory.

    Description:
        This function must be implemented in the application.
        The library will call this function each time when
        the external memory data will be required. The application
        must copy requested byte quantity into the buffer provided.
        Data start address in external memory is a sum of the address
        in GFX_RESOURCE_HDR structure and offset.

    Precondition:
        None.

    Parameters:
        pResource - Pointer to the external memory resource information.
        offset - offset of the data from the location of the resource
                 in external memory.
        nCount - Number of bytes to be transferred into the buffer.
        buffer - Pointer to the buffer that will hold the retrieved data.

    Returns:
        GFX_STATUS_SUCCESS when all the data was succesfully retrieved.
        GFX_STATUS_FAILURE when partial or no data was retrieved.

    Example:
        None.

*/
// *****************************************************************************
// If there are several memories in the system they can be selected by IDs.
// In this demo ID for memory chip installed on Graphics PICTail board is assumed to be 0.
#define M25P80_MEMORY    0
 

GFX_STATUS GFX_ExternalResourceCallback(
                                GFX_RESOURCE_HDR *pResource,
                                uint32_t offset,
                                uint16_t nCount,
                                void     *pBuffer)
{
    uint32_t addr;

    // get the proper address
    switch (pResource->type)
    {
        case GFX_RESOURCE_FONT_EXTERNAL_NONE:
            addr = pResource->resource.font.location.extAddress;
            break;
        case GFX_RESOURCE_MCHP_MBITMAP_EXTERNAL_RLE:
        case GFX_RESOURCE_MCHP_MBITMAP_EXTERNAL_NONE:
            addr = pResource->resource.image.location.extAddress;
            break;
        default:
            // type is incorrect
            return (GFX_STATUS_FAILURE);
    }
    addr += offset;

    if(pResource->ID == M25P80_MEMORY)
    {
        // Read data requested into buffer provided
        DRV_NVM_M25P80_Read(addr, (uint8_t*)pBuffer, nCount);
    }

    return (GFX_STATUS_SUCCESS);
}


