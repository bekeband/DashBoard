
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
***************************************************/
const GFX_XCHAR WelcomeScreen_MAIN_WINDOWtext[ ] = "Ablak";
const GFX_XCHAR WelcomeScreen_MTR_2text[ ] = "Meter";

const GFX_XCHAR PictureScreen_PICTUREWINDtext[ ] = "Picture";



/***************************************************
* Scheme Declarations
***************************************************/
GFX_GOL_OBJ_SCHEME* defscheme;
GFX_GOL_OBJ_SCHEME* enter_new_scheme;
GFX_GOL_OBJ_SCHEME* enter_new_s524cheme;


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
***************************************************/
void ErrorCreate(GFX_XCHAR* string)
{
    // Blue Screen Error
	GFX_ColorSet(GFX_INDEX_0, 119);
    GFX_ScreenClear(GFX_INDEX_0);
    GFX_ColorSet(GFX_INDEX_0, -1);

    // Flash Error Message
    if(string == NULL)
        {GFX_TextStringDraw(GFX_INDEX_0, 0, 0, "Runtime Error.", 0);}
    else
        {GFX_TextStringDraw(GFX_INDEX_0, 0,0, string, 0);}
}

/***************************************************
* Function 	      :    GDD_SCREEN_WelcomeScreenCreate
* Parameters      :    none
* Return          :    none
* Description     :    Creates GOL widgets used in screen - WelcomeScreen
***************************************************/
void GDD_SCREEN_WelcomeScreenCreate(void)
{
    GFX_GOL_ObjectListFree(GFX_INDEX_0);
    GFX_ColorSet(GFX_INDEX_0, GFX_RGBConvert(248, 252, 248));
    GFX_ScreenClear(GFX_INDEX_0);


     if(enter_new_s524cheme != NULL) free(enter_new_s524cheme);
        enter_new_s524cheme = GFX_GOL_SchemeCreate();

    enter_new_s524cheme->Color0 = GFX_RGBConvert(32, 168, 224);
    enter_new_s524cheme->Color1 = GFX_RGBConvert(16, 132, 168);
    enter_new_s524cheme->TextColor0 = GFX_RGBConvert(24, 24, 24);
    enter_new_s524cheme->TextColor1 = GFX_RGBConvert(248, 252, 248);
    enter_new_s524cheme->EmbossDkColor = GFX_RGBConvert(248, 204, 0);
    enter_new_s524cheme->EmbossLtColor = GFX_RGBConvert(24, 116, 184);
    enter_new_s524cheme->TextColorDisabled = GFX_RGBConvert(128, 128, 128);
    enter_new_s524cheme->ColorDisabled = GFX_RGBConvert(208, 224, 240);
    enter_new_s524cheme->CommonBkColor = GFX_RGBConvert(208, 236, 240);
    enter_new_s524cheme->pFont = (GFX_RESOURCE_HDR*)&DroidSans_Bold_12;

    if(defscheme != NULL) free(defscheme);
        defscheme = GFX_GOL_SchemeCreate();

    defscheme->Color0 = GFX_RGBConvert(32, 168, 224);
    defscheme->Color1 = GFX_RGBConvert(16, 132, 168);
    defscheme->TextColor0 = GFX_RGBConvert(24, 24, 24);
    defscheme->TextColor1 = GFX_RGBConvert(248, 252, 248);
    defscheme->EmbossDkColor = GFX_RGBConvert(248, 204, 0);
    defscheme->EmbossLtColor = GFX_RGBConvert(24, 116, 184);
    defscheme->TextColorDisabled = GFX_RGBConvert(128, 128, 128);
    defscheme->ColorDisabled = GFX_RGBConvert(208, 224, 240);
    defscheme->CommonBkColor = GFX_RGBConvert(208, 236, 240);
    defscheme->pFont = (GFX_RESOURCE_HDR*)&Gentium_16;


    GFX_GOL_WINDOW *pMAIN_WINDOW;
    pMAIN_WINDOW = GFX_GOL_WindowCreate(  GFX_INDEX_0, //gfxIndex
                       MAIN_WINDOW, //name
                       0, //left
                       0, //top
                       319, //right
                       239, //bottom
                       GFX_GOL_WINDOW_DRAW_STATE, //state
                       NULL, //bitmap
                       (GFX_XCHAR*)WelcomeScreen_MAIN_WINDOWtext, //text
                       GFX_ALIGN_CENTER, //align
                      enter_new_s524cheme //scheme
                    );

    if(pMAIN_WINDOW==NULL)
    {
      ErrorCreate(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }

    GFX_GOL_METER *pMTR_2;
    pMTR_2 = GFX_GOL_MeterCreate(  GFX_INDEX_0, //gfxIndex
                       MTR_2, //name
                       13, //left
                       45, //top
                       133, //right
                       165, //bottom
                       GFX_GOL_METER_DRAW_STATE, //state
                       GFX_GOL_METER_WHOLE_TYPE, //metertype
                       1, //pos
                       1, //minval
                       50, //maxval
                       (GFX_RESOURCE_HDR*)&Gentium_16, //titlefont
                       (GFX_RESOURCE_HDR*)&Gentium_16, //valuefont
                       (GFX_XCHAR*)WelcomeScreen_MTR_2text, //text
                      defscheme //scheme
                    );

    if(pMTR_2==NULL)
    {
      ErrorCreate(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }


}
/***************************************************
* Function 	      :    GDD_SCREEN_PictureScreenCreate
* Parameters      :    none
* Return          :    none
* Description     :    Creates GOL widgets used in screen - PictureScreen
***************************************************/
void GDD_SCREEN_PictureScreenCreate(void)
{
    GFX_GOL_ObjectListFree(GFX_INDEX_0);
    GFX_ColorSet(GFX_INDEX_0, GFX_RGBConvert(248, 252, 248));
    GFX_ScreenClear(GFX_INDEX_0);


     if(defscheme != NULL) free(defscheme);
        defscheme = GFX_GOL_SchemeCreate();

    defscheme->Color0 = GFX_RGBConvert(32, 168, 224);
    defscheme->Color1 = GFX_RGBConvert(16, 132, 168);
    defscheme->TextColor0 = GFX_RGBConvert(24, 24, 24);
    defscheme->TextColor1 = GFX_RGBConvert(248, 252, 248);
    defscheme->EmbossDkColor = GFX_RGBConvert(248, 204, 0);
    defscheme->EmbossLtColor = GFX_RGBConvert(24, 116, 184);
    defscheme->TextColorDisabled = GFX_RGBConvert(128, 128, 128);
    defscheme->ColorDisabled = GFX_RGBConvert(208, 224, 240);
    defscheme->CommonBkColor = GFX_RGBConvert(208, 236, 240);
    defscheme->pFont = (GFX_RESOURCE_HDR*)&Gentium_16;


    GFX_GOL_WINDOW *pPICTUREWIND;
    pPICTUREWIND = GFX_GOL_WindowCreate(  GFX_INDEX_0, //gfxIndex
                       PICTUREWIND, //name
                       0, //left
                       0, //top
                       319, //right
                       239, //bottom
                       GFX_GOL_WINDOW_DRAW_STATE, //state
                       (GFX_RESOURCE_HDR*)&bekeband_kicsi, //bitmap
                       (GFX_XCHAR*)PictureScreen_PICTUREWINDtext, //text
                       GFX_ALIGN_CENTER, //align
                      defscheme //scheme
                    );

    if(pPICTUREWIND==NULL)
    {
      ErrorCreate(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }


}

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


