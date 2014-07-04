
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
const GFX_XCHAR Screen1_CHB_1text[ ] = "CheckBox";
const GFX_XCHAR Screen1_GRB_3text[ ] = "GroupBox";



/***************************************************
* Scheme Declarations
***************************************************/
GFX_GOL_OBJ_SCHEME* defscheme;
GFX_GOL_OBJ_SCHEME* enter_new_scheme;
GFX_GOL_OBJ_SCHEME* gentium8;


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
* Function 	      :    GDD_SCREEN_Screen1Create
* Parameters      :    none
* Return          :    none
* Description     :    Creates GOL widgets used in screen - Screen1
***************************************************/
void GDD_SCREEN_Screen1Create(void)
{
    GFX_GOL_ObjectListFree(GFX_INDEX_0);
    GFX_ColorSet(GFX_INDEX_0, GFX_RGBConvert(248, 252, 248));
    GFX_ScreenClear(GFX_INDEX_0);


     if(gentium8 != NULL) free(gentium8);
        gentium8 = GFX_GOL_SchemeCreate();

    gentium8->Color0 = GFX_RGBConvert(32, 168, 224);
    gentium8->Color1 = GFX_RGBConvert(16, 132, 168);
    gentium8->TextColor0 = GFX_RGBConvert(24, 24, 24);
    gentium8->TextColor1 = GFX_RGBConvert(248, 252, 248);
    gentium8->EmbossDkColor = GFX_RGBConvert(248, 204, 0);
    gentium8->EmbossLtColor = GFX_RGBConvert(24, 116, 184);
    gentium8->TextColorDisabled = GFX_RGBConvert(128, 128, 128);
    gentium8->ColorDisabled = GFX_RGBConvert(208, 224, 240);
    gentium8->CommonBkColor = GFX_RGBConvert(208, 236, 240);
    gentium8->pFont = (GFX_RESOURCE_HDR*)&Gentium8;

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


    GFX_GOL_CHECKBOX *pCHB_1;
    pCHB_1 = GFX_GOL_CheckBoxCreate(  GFX_INDEX_0, //gfxIndex
                       CHB_1, //name
                       47, //left
                       64, //top
                       249, //right
                       154, //bottom
                       GFX_GOL_CHECKBOX_DRAW_STATE | GFX_GOL_CHECKBOX_CHECKED_STATE, //state
                       (GFX_XCHAR*)Screen1_CHB_1text, //text
                       GFX_ALIGN_LEFT, //align
                      gentium8 //scheme
                    );

    if(pCHB_1==NULL)
    {
      ErrorCreate(0);
      while(1); //Fatal Error, Check for memory leak or heap size
    }

    GFX_GOL_GROUPBOX *pGRB_3;
    pGRB_3 = GFX_GOL_GroupboxCreate(  GFX_INDEX_0, //gfxIndex
                       GRB_3, //name
                       56, //left
                       187, //top
                       268, //right
                       226, //bottom
                       GFX_GOL_GROUPBOX_DRAW_STATE, //state
                       (GFX_XCHAR*)Screen1_GRB_3text, //text
                       GFX_ALIGN_CENTER, //align
                      defscheme //scheme
                    );

    if(pGRB_3==NULL)
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
    &GDD_SCREEN_Screen1Create,
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
};


