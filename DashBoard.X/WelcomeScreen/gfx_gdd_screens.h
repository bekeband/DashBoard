
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


#ifndef    _GDD_SCREENS_H_
#define    _GDD_SCREENS_H_


/***************************************************
*FUNCTION DECLARATION
***************************************************/

void GDD_FirstScreenCreate(void);
void GDD_GOL_DrawCallback(void);
void GDD_NextScreen(void);
void GDD_ScreenChangeTo(uint16_t screenIndex);
void GDD_GOL_MessageCallback(uint16_t objMsg, GFX_GOL_OBJ_HEADER *pObj, GFX_GOL_MESSAGE *pMsg);


/***************************************************
*IMAGE DECLARATION
***************************************************/
extern const GFX_RESOURCE_HDR bekeband_kicsi;


/***************************************************
*FONT DECLARATION
***************************************************/
extern const GFX_RESOURCE_HDR Gentium8;
extern const GFX_RESOURCE_HDR DroidSans_Bold_12;
extern const GFX_RESOURCE_HDR Gentium_16;


/***************************************************
*SCREEN DECLARATION
***************************************************/
void GDD_SCREEN_WelcomeScreenCreate(void);
void GDD_SCREEN_PictureScreenCreate(void);



/***************************************************
*UNIQUE WIDGET ID'S
***************************************************/
#define MAIN_WINDOW 1
#define MTR_2 2
#define PICTUREWIND 3

#define	GDD_SCREEN_COUNT 2
#endif
