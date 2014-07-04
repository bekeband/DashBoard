
/*****************************************************************************
* Microchip Graphics Library
* Graphics Display Designer (GDD) Template
*****************************************************************************
 
* Dependencies:    See INCLUDES section below
* Processor:       PIC24F, PIC24H, dsPIC, PIC32
* Compiler:        MPLAB C30 V3.22, MPLAB C32 V1.05b
* Linker:          MPLAB LINK30, MPLAB LINK32
* Company:         Microchip Technology Incorporated
*
* Software License Agreement
*
* Copyright (c) 2010 Microchip Technology Inc.  All rights reserved.
* Microchip licenses to you the right to use, modify, copy and distribute
* Software only when embedded on a Microchip microcontroller or digital
* signal controller, which is integrated into your product or third party
* product (pursuant to the sublicense terms in the accompanying license
* agreement).  
*
* You should refer to the license agreement accompanying this Software
* for additional information regarding your rights and obligations.
*
* SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
* KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
* OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
* PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
* OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 
* BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
* DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
* INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
* COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
* CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
* OR OTHER SIMILAR COSTS.
*
* Author               Date        Comment
*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*
*****************************************************************************/


/***************************************************
*INCLUDE FILES
***************************************************/
#include "gfx/gfx.h"
#include "gfx_gdd_screens.h"

/***************************************************
* String literals used in the project
***************************************************
const GFX_XCHAR WelcomeScreen_MAIN_WINDOWtext[ ] = "Ablak";
const GFX_XCHAR WelcomeScreen_MTR_2text[ ] = "Meter";

const GFX_XCHAR PictureScreen_PICTUREWINDtext[ ] = "Picture";*/



/***************************************************
* Scheme Declarations
***************************************************/
GFX_GOL_OBJ_SCHEME defscheme;


/***************************************************
* Function and global Declarations
***************************************************/
void (*GDD_FunctionArrayCreate[GDD_SCREEN_COUNT])();
void (*GDD_PrimitivesFunctionArrayCreate[GDD_SCREEN_COUNT])();
uint16_t currentGDDScreenIndex;
uint8_t update = 0;
static uint8_t updateGPL = 0;

/***************************************************
* Function       : GDD_FirstScreenCreate
* Parameters     : none
* Return         : none
* Description    : Creates the first screen
***************************************************/
void GDD_FirstScreenCreate(void)
{
    currentGDDScreenIndex = 0;
    update = 1;
    (*GDD_FunctionArrayCreate[currentGDDScreenIndex])();
}

/***************************************************
* Function      : GDD_NextScreen
* Parameters    : none
* Return        : none
* Description   : Updates counter to show next screen
***************************************************/
void GDD_NextScreen(void)
{
    currentGDDScreenIndex++;
    if(currentGDDScreenIndex >= GDD_SCREEN_COUNT)
    {
        currentGDDScreenIndex = 0;
    }
    update = 1;
}

/***************************************************
* Function      : GDD_ScreenChangeTo
* Parameters    : uint16_t screenIndex
* Return        : none
* Description   : Show the screen referred by the index
***************************************************/
void GDD_ScreenChangeTo(uint16_t screenIndex)
{
    currentGDDScreenIndex = screenIndex;
    if(currentGDDScreenIndex >= GDD_SCREEN_COUNT)
    {
        currentGDDScreenIndex = 0;
    }
    update = 1;
}

/***************************************************
* Function       : GDD_GOL_DrawCallback
* Parameters     : none
* Return         : none
* Description    : Callback to do the actual drawing of widgets
***************************************************/
void GDD_GOL_DrawCallback(void)
{
    if(updateGPL)
    {
        (*GDD_PrimitivesFunctionArrayCreate[currentGDDScreenIndex])();
        updateGPL = 0;
    }

    if(update)
    {
        (*GDD_FunctionArrayCreate[currentGDDScreenIndex])();
        if(GDD_PrimitivesFunctionArrayCreate[currentGDDScreenIndex] != NULL)
        {
            updateGPL = 1;
        }
        update = 0;
    }
}

/***************************************************
* Function       : ErrorCreate
* Parameters     : none
* Return         : none
* Description    : Creates a Error screen 
***************************************************
void ErrorCreate(GFX_XCHAR* string)
{
    // Blue Screen Error
	GFX_ColorSet(GFX_INDEX_0);
    GFX_ScreenClear();
    GFX_ColorSet(GFX_INDEX_1);

    // Flash Error Message
    if(string == NULL)
        {GFX_TextStringDraw(0, 0, "Runtime Error.", 0);}
    else
        {GFX_TextStringDraw(0,0, string, 0);}
}*/

/***************************************************
* Function       : GDD_FunctionArrayCreate
* Parameters     : none
* Return         : none
* Description    : Creates a array of GOL function pointers
***************************************************/
void (*GDD_FunctionArrayCreate[GDD_SCREEN_COUNT])(void)=
    
{
    &GDD_SCREEN_WelcomeScreenCreate,
    &GDD_SCREEN_PictureScreenCreate,
};



/***************************************************
* Function       : GDD_PrimitivesFunctionArrayCreate
* Parameters     : none
* Return         : none
* Description    : Creates a array of GPL function pointers
***************************************************/
void (*GDD_PrimitivesFunctionArrayCreate[GDD_SCREEN_COUNT])(void)=
    
{
    NULL,
    NULL,
};


