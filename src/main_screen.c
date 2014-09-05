
#include <stdio.h>
#include <stdlib.h>
#include "gfx/gfx.h"
#include "system.h"
#include "main_screen.h"

/* Trying connection options for START button show. */
extern unsigned int TRYING_CONN;

GFX_GOL_OBJ_SCHEME  mainscheme;          // main scheme
enum e_connect_state old_connect_state = NONE;
enum e_OBD_error OLD_OBD_ERROR = none;

int number = 0;

/* DEBUG terminal for chacking the communication traffic. */
//GFX_GOL_STATICTEXT* pDEBUG_TERMINAL;

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
{ int height;
  GFX_GOL_STATICTEXT* pSt;

  height = GFX_TextStringHeightGet(MAIN_SCHEME.pFont);

  if (!TRYING_CONN)
  {
    if (!CreateStartButton()) ErrorCreate(0);
  }

  pSt = GFX_GOL_StaticTextCreate (
        CONNECT_TERMINAL,                  // ID
        0, 4, 150, (height + 4 + 2),               // dimension
        GFX_GOL_STATICTEXT_DRAW_STATE,  // draw the object
        "",
        GFX_ALIGN_LEFT | GFX_ALIGN_TOP, // align text on the center
        &MAIN_SCHEME);
  if (pSt == NULL)
    {
      ErrorCreate(0);
    } else
    {
      pSt->hdr.actionGet = ConnectTerminalActionGet;
    }

  pSt = GFX_GOL_StaticTextCreate (
        ERROR_TERMINAL,                  // ID
        160, 4, 319, (height + 4 + 2),               // dimension
        GFX_GOL_STATICTEXT_DRAW_STATE,  // draw the object
        "",
        GFX_ALIGN_LEFT | GFX_ALIGN_TOP, // align text on the center
        &MAIN_SCHEME);
  if (pSt == NULL)
    {
      ErrorCreate(0);
    } else
    {
      pSt->hdr.actionGet = ErrorTerminalActionGet;
    }

}

GFX_GOL_TRANSLATED_ACTION ConnectTerminalActionGet(void* pObject, GFX_GOL_MESSAGE* pMessage)
{ GFX_GOL_STATICTEXT *pSt; GFX_XCHAR* str;
  if ((pMessage->type == TYPE_TIMER) && (pMessage->uiEvent == EVENT_SET))
  {
    if (GetConnectState() != old_connect_state)
    {
      pSt = (GFX_GOL_STATICTEXT *)pObject;
      old_connect_state = GetConnectState();
      str = GetConnectStateString();
      GFX_GOL_StaticTextSet(pSt, str);
      GFX_GOL_ObjectStateSet(pSt, GFX_GOL_STATICTEXT_DRAW_STATE);
    }
  } else
    return GFX_GOL_StaticTextActionGet(pObject, pMessage);
}

GFX_GOL_TRANSLATED_ACTION ErrorTerminalActionGet(void* pObject, GFX_GOL_MESSAGE* pMessage)
{ GFX_GOL_STATICTEXT *pSt; GFX_XCHAR* str;
  if ((pMessage->type == TYPE_TIMER) && (pMessage->uiEvent == EVENT_SET))
  {
    if (GetErrorState() != OLD_OBD_ERROR)
    {
      pSt = (GFX_GOL_STATICTEXT *)pObject;
      OLD_OBD_ERROR = GetErrorState();
      str = GetOBDErrorString();
      GFX_GOL_StaticTextSet(pSt, str);
      GFX_GOL_ObjectStateSet(pSt, GFX_GOL_STATICTEXT_DRAW_STATE);
    }
  } else
    return GFX_GOL_StaticTextActionGet(pObject, pMessage);
}
