
#include <stdio.h>
#include <stdlib.h>
#include "gfx/gfx.h"
#include "system.h"
#include "main_screen.h"

/* Trying connection options for START button show. */
extern unsigned int TRYING_CONN;

GFX_GOL_OBJ_SCHEME  mainscheme;          // main scheme
enum e_connect_state old_connect_state = DSP_NONE;

int number = 0;

/* DEBUG terminal for chacking the communication traffic. */
GFX_GOL_STATICTEXT* pDEBUG_TERMINAL;
GFX_XCHAR TerminalBuffer[TERMINAL_BUFFER_SIZE] = "Terminal buffer   ";
//GFX_XCHAR CONNECT_STRINGS[][] = {{"NONE"},{"WAKE-UP"},{"INIT"},{"WAIT-FOR-CONNECT"},{"DATACHANGE"}};
GFX_XCHAR ListBoxDatas[] = "FirstItem\nSecond Item\nThird Item";
//GFX_XCHAR AddedItem[] = "Added Item\nMore add Item";

void SetMainScheme()
{
    // initialize select screen style scheme
    memcpy( &MAIN_SCHEME, &APP_GENERIC_SCHEME, sizeof(GFX_GOL_OBJ_SCHEME));
    MAIN_SCHEME.EmbossSize =    3;
    MAIN_SCHEME.CommonBkLeft = 0; // horizontal starting position of the background
    MAIN_SCHEME.CommonBkTop = 0;  // vertical starting position of the background
    MAIN_SCHEME.CommonBkType = GFX_BACKGROUND_COLOR;
    MAIN_SCHEME.pFont = (GFX_RESOURCE_HDR*)&APP_DEMO_FONT;

}


uint16_t CreateStartButton(void)
{
  GFX_GOL_BUTTON *pObj;
  pObj = GFX_GOL_ButtonCreate ( ID_START_CONNECTION, 220, 210, 300, 236, 0,
    GFX_GOL_BUTTON_DRAW_STATE, NULL, NULL, "START",
    GFX_ALIGN_HCENTER | GFX_ALIGN_VCENTER, &MAIN_SCHEME );

    if(pObj == NULL)
        return (0);
    return 1;
}

/***************************************************
 * MainScreenCreate(void) Create the application main screen in default scheme.
 * in default scheme.
 * 
 **************************************************/
void MainScreenCreate(void)
{

    if (!TRYING_CONN)
    {
      if (!CreateStartButton()) ErrorCreate(0); 
    }

    pDEBUG_TERMINAL = (GFX_GOL_StaticTextCreate (
        MAIN_TERMINAL,                  // ID
        0, 100, 319, 160,               // dimension
        GFX_GOL_STATICTEXT_DRAW_STATE,  // draw the object
        (GFX_XCHAR*)TerminalBuffer,     // 2 lines of text
        GFX_ALIGN_LEFT | GFX_ALIGN_TOP, // align text on the center
        &MAIN_SCHEME));
    if (pDEBUG_TERMINAL == NULL)
    {
      ErrorCreate(0);
    }else                  // use given scheme
    {
      pDEBUG_TERMINAL->hdr.actionGet = TerminalActionGet;
    }

/*    GFX_GOL_CheckBoxCreate(ID_CONTYPE_BOX, 0, 180, 319, 220, GFX_GOL_CHECKBOX_DRAW_STATE,
        "Scale", GFX_ALIGN_CENTER, &MAIN_SCHEME);*/

    if (GFX_GOL_ListBoxCreate (
        MAIN_LISTBOX,                   // ID
        10, 10, 300, 96,                // dimension
        GFX_GOL_LISTBOX_DRAW_STATE,     // draw the object
        (GFX_XCHAR*)ListBoxDatas,
        GFX_ALIGN_LEFT | GFX_ALIGN_TOP, // align text on the center
        &MAIN_SCHEME) == NULL)
    {
      ErrorCreate(0);
    }

// create the list of items to be placed in the listbox
// Add items (each line will become one item,
// lines must be separated by 'n' character)

//  GFX_GOL_ListBoxItemAdd(pMAIN_LISTBOX, NULL, (GFX_XCHAR*)AddedItem, NULL, 0, 1);
  /* Create MAIN button on bottom of screen. */


}

GFX_GOL_TRANSLATED_ACTION TerminalActionGet(void* pObject, GFX_GOL_MESSAGE* pMessage)
{ char ubuf[16]; GFX_GOL_STATICTEXT *pSt;
  if ((pMessage->type == TYPE_TIMER) && (pMessage->uiEvent == EVENT_SET))
  {

    if (GetConnectState() != old_connect_state)
    {
/*      pSt = (GFX_GOL_STATICTEXT *)pObject;
      old_connect_state = GetConnectState();
      GFX_GOL_StaticTextSet(pSt, "Nonemone");*/
    }
    utoa(ubuf, number, 10);
    number++;
    GFX_GOL_STATICTEXT *pSt;
    pSt = (GFX_GOL_STATICTEXT *)pObject;
    pMessage->uiEvent = EVENT_INVALID;
    return (GFX_GOL_OBJECT_ACTION_INVALID);
  } else
    return GFX_GOL_StaticTextActionGet(pObject, pMessage);
}
