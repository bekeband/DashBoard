/* 
 * File:   DashBoard.c
 * Author: user
 *
 * Created on 2014. j�nius 22., 11:17
 */

#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "gfx/gfx.h"
#include "gfx/gfx_gol_list_box.h"
#include "options_screen.h"
#include "swreset_screen.h"
#include "main_screen.h"
#include "DashBoard.h"
#include "exceptions.h"
#include "peripheral/reset.h"
#include "defgraphical.h"
#include "error_screen.h"

/* tick_tack variable for ticken. */
bool tick_tack;

// *****************************************************************************
// Demo States
// *****************************************************************************
typedef enum
{
  INIT_PROGRAM,
  CREATE_BACKGROUND,
  CREATE_MAIN_MENU,
  DISPLAY_MAIN_MENU,
  CREATE_OPTIONS,
  DISPLAY_OPTIONS,
  CREATE_SWRESET,
  DISPLAY_SWRESET,
} APP_SCREEN_STATES;

typedef enum
{
  ISO9141_5BAUD,
  KWP_5BAUD,
  KWP_FAST,
} CONNECT_STATES;

APP_SCREEN_STATES   screenState;
CONNECT_STATES      connectState;

/* APP_createMainButton(void)
 * Create main button for main screen reach at all program state.
*/

// *****************************************************************************
uint16_t APP_CreateMainButton(void)
{
  GFX_GOL_BUTTON *pObj;
  pObj = GFX_GOL_ButtonCreate ( ID_MAIN, 20, 210, 100, 236, 0,
    GFX_GOL_BUTTON_DRAW_STATE, NULL, NULL, "MAIN",
    GFX_ALIGN_HCENTER | GFX_ALIGN_VCENTER, &MAIN_SCHEME );

  if(pObj == NULL)
    return (0);
  return 1;
}

uint16_t CreateOptionsButton(void)
{
  GFX_GOL_BUTTON *pObj;
  pObj = GFX_GOL_ButtonCreate ( ID_OPTIONS, 120, 210, 200, 236, 0,
    GFX_GOL_BUTTON_DRAW_STATE, NULL, NULL, "OPTIONS",
    GFX_ALIGN_HCENTER | GFX_ALIGN_VCENTER, &MAIN_SCHEME );

    if(pObj == NULL)
        return (0);
    return 1;
}

bool APP_ObjectDrawCallback(void)
{
  switch (screenState)
  {
    case INIT_PROGRAM:
//      SetMainScheme();
      if (mGetSWRFlag())
      {
        mClearSWRFlag();
        screenState = CREATE_SWRESET;
      } else
      {
        screenState = CREATE_BACKGROUND;
      };
      break;
    case CREATE_BACKGROUND:
      GFX_ColorSet(GREEN);
      GFX_ScreenClear();
      screenState = CREATE_MAIN_MENU;
      break;
    case CREATE_MAIN_MENU:
      GFX_GOL_ObjectListFree();
//      SetMainScheme();
      CreateOptionsButton();
      MainScreenCreate();
      screenState = DISPLAY_MAIN_MENU;       // switch to next state
      break;
    case DISPLAY_MAIN_MENU:
      break;
    case CREATE_OPTIONS:
//      SetOptionsScheme();
      GFX_ColorSet(BLUE);
      GFX_ScreenClear();
      APP_CreateMainButton();
      CreateOptions();
      screenState = DISPLAY_OPTIONS;
      break;
    case DISPLAY_OPTIONS:
//      OptionsDrawCallback();
      break;
    case CREATE_SWRESET:
      GFX_ColorSet(BLUE);
      GFX_ScreenClear();
      APP_CreateMainButton();

      CreateSwreset();
      screenState = DISPLAY_SWRESET;
      break;
    case DISPLAY_SWRESET:

      break;
    default:
      break;
  }
   return true;
};

bool APP_ObjectMessageCallback( GFX_GOL_TRANSLATED_ACTION objectMessage,
  GFX_GOL_OBJ_HEADER* pObject, GFX_GOL_MESSAGE* pMessage)
{
  uint16_t objID;

  objID = GFX_GOL_ObjectIDGet(pObject);

  switch (screenState)
  {
    case INIT_PROGRAM:
      break;
    case CREATE_BACKGROUND:
      break;
    case DISPLAY_MAIN_MENU:
      
      if ((objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED) && (objID == ID_OPTIONS))
      {
        if (GFX_GOL_ObjectStateGet(pObject, GFX_GOL_BUTTON_PRESSED_STATE))
        {
          GFX_GOL_ObjectListFree();
          screenState = CREATE_OPTIONS;
          LED_RED_02_LAT() = !(LED_RED_02_PORT());
        };
      }
    break;
    case DISPLAY_SWRESET:
 
    case DISPLAY_OPTIONS:
      if ((objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED) && (objID == ID_MAIN))
      {

        if (GFX_GOL_ObjectStateGet(pObject, GFX_GOL_BUTTON_PRESSED_STATE))
        {
            /* Test for exception. */

          GFX_GOL_ObjectListFree();
          screenState = CREATE_BACKGROUND;
        };
      } else
      {
        return MsgOptionsCallback(objectMessage, pObject, pMessage);
      }
      break;
    default: break;
  };
}

int TickGetMessage(GFX_GOL_MESSAGE* msg)
{
  if (tick_tack)
  {
    msg->type = TYPE_TIMER;
    msg->uiEvent = EVENT_SET;
    tick_tack = false;
  } else
  {
    msg->uiEvent = EVENT_INVALID;
  }
}

int main(int argc, char** argv) {

      // GOL message structure to interact with GOL
  GFX_GOL_MESSAGE msg;

  INTEnableSystemMultiVectoredInt();
  INTEnableInterrupts();
    // step 1: Initialize board, drivers and graphics library
  SYSTEM_InitializeBoard();
  GFX_Initialize();


    /* Software reset occurs ?*/
    // set the message callback function pointer
  GFX_GOL_MessageCallbackSet(APP_ObjectMessageCallback);
    // set the draw callback function pointer
  GFX_GOL_DrawCallbackSet(APP_ObjectDrawCallback);

    // clear the screen with the given color
  GFX_ColorSet(BLACK);
  GFX_ScreenClear();

  screenState = INIT_PROGRAM;

  SetSwresetScheme();
  SetOptionsScheme();
  SetMainScheme();

  DisplayBacklightOn();
    while(1)
    {
        // Draw GOL objects
        if(GFX_GOL_ObjectListDraw() == GFX_STATUS_SUCCESS)
        {
          TouchGetMsg(&msg);                // Get message from touch screen
          /* If is not touch message, then get tick message. */
          if (msg.uiEvent == EVENT_INVALID)
          {
            TickGetMessage(&msg);
          }
          GFX_GOL_ObjectMessage(&msg);      // Process message
        }
    }

  return (EXIT_SUCCESS);
}

