

#include <stdio.h>
#include <stdlib.h>
#include "gfx/gfx.h"
#include "system.h"
#include "main_screen.h"

GFX_GOL_OBJ_SCHEME  mainscheme;          // main scheme

int number = 0;

GFX_XCHAR TerminalBuffer[TERMINAL_BUFFER_SIZE] = "Terminal buffer   ";
GFX_XCHAR ListBoxDatas[] = "FirstItem\nSecond Item\nThird Item";
GFX_XCHAR AddedItem[] = "Added Item\nMore add Item";

void SetMainScheme()
{
    // initialize select screen style scheme
    memcpy( &MAIN_SCHEME, &APP_GENERIC_SCHEME, sizeof(GFX_GOL_OBJ_SCHEME));
    /* Setting the defscheme behaviors, ang features. */
/*    MAIN_SCHEME.Color0 =        DARKGRAY;   // panelFaceColor
    MAIN_SCHEME.Color1 =        LIGHTGRAY;  // panelFaceColor
    MAIN_SCHEME.TextColor0 =    GFX_RGBConvert(24, 24, 24); // first text color option
    MAIN_SCHEME.TextColor1 =    GFX_RGBConvert(248, 252, 248);  // second text color option
    MAIN_SCHEME.EmbossDkColor = GFX_RGBConvert(0, 32, 256);   // dark emboss color
    MAIN_SCHEME.EmbossLtColor = GFX_RGBConvert(16, 64, 224);  // light emboss color
    MAIN_SCHEME.TextColorDisabled = GFX_RGBConvert(128, 128, 128);
    MAIN_SCHEME.ColorDisabled = GFX_RGBConvert(208, 224, 240);
    MAIN_SCHEME.CommonBkColor = GFX_RGBConvert(208, 236, 240);*/
    MAIN_SCHEME.EmbossSize =    3;
    MAIN_SCHEME.CommonBkLeft = 0; // horizontal starting position of the background
    MAIN_SCHEME.CommonBkTop = 0;  // vertical starting position of the background
    MAIN_SCHEME.CommonBkType = GFX_BACKGROUND_COLOR;
    MAIN_SCHEME.pFont = (GFX_RESOURCE_HDR*)&APP_DEMO_FONT;

//  memcpy(&defscheme, &GOLSchemeDefault, sizeof(GFX_GOL_OBJ_SCHEME));
}

/***************************************************
 * MainScreenCreate(void) Create the application main screen in default scheme.
 * in default scheme.
 * 
 **************************************************/
void MainScreenCreate(void)
{
    GFX_GOL_STATICTEXT* pMAIN_TERMINAL;
    GFX_GOL_LISTBOX*    pMAIN_LISTBOX;

    pMAIN_TERMINAL = GFX_GOL_StaticTextCreate (
        MAIN_TERMINAL,                  // ID
        0, 100, 319, 160,               // dimension
        GFX_GOL_STATICTEXT_DRAW_STATE,  // draw the object
        (GFX_XCHAR*)TerminalBuffer,     // 2 lines of text
        GFX_ALIGN_LEFT | GFX_ALIGN_TOP, // align text on the center
        &MAIN_SCHEME);                  // use given scheme

    if(pMAIN_TERMINAL == NULL)
      {
        ErrorCreate(0);
      } else
      {
        pMAIN_TERMINAL->hdr.actionGet = TerminalActionGet;
      }

/*    GFX_GOL_CheckBoxCreate(ID_CONTYPE_BOX, 0, 180, 319, 220, GFX_GOL_CHECKBOX_DRAW_STATE,
        "Scale", GFX_ALIGN_CENTER, &MAIN_SCHEME);*/

    pMAIN_LISTBOX = GFX_GOL_ListBoxCreate (
        MAIN_LISTBOX,                   // ID
        10, 10, 300, 96,                // dimension
        GFX_GOL_LISTBOX_DRAW_STATE,     // draw the object
        (GFX_XCHAR*)ListBoxDatas,
        GFX_ALIGN_LEFT | GFX_ALIGN_TOP, // align text on the center
        &MAIN_SCHEME);                  // use given scheme


    if(pMAIN_LISTBOX == NULL)
      {
        ErrorCreate(0);
      }

// create the list of items to be placed in the listbox
// Add items (each line will become one item,
// lines must be separated by 'n' character)

  GFX_GOL_ListBoxItemAdd(pMAIN_LISTBOX, NULL, (GFX_XCHAR*)AddedItem, NULL, 0, 1);
  /* Create MAIN button on bottom of screen. */
}

GFX_GOL_TRANSLATED_ACTION TerminalActionGet(void* pObject, GFX_GOL_MESSAGE* pMessage)
{ char ubuf[16];
  if ((pMessage->type == TYPE_TIMER) && (pMessage->uiEvent == EVENT_SET))
  {
//    LED_YELLOW_02_LAT() = !(LED_YELLOW_02_PORT());
    utoa(ubuf, number, 10);
    memcpy(((char*)&TerminalBuffer) + 16, (char*)ubuf, 2);
    number++;
    GFX_GOL_STATICTEXT *pSt;
    pSt = (GFX_GOL_STATICTEXT *)pObject;
    pSt->hdr.state = GFX_GOL_STATICTEXT_DRAW_STATE;
    pMessage->uiEvent = EVENT_INVALID;
    return (GFX_GOL_OBJECT_ACTION_INVALID);
  } else
    return GFX_GOL_StaticTextActionGet(pObject, pMessage);
}
