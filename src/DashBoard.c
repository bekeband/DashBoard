/* 
 * File:   DashBoard.c
 * Author: user
 *
 * Created on 2014. június 22., 11:17
 */

#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "gfx/gfx.h"
#include "gfx/gfx_gol_list_box.h"
#include "options_screen.h"
#include "DashBoard.h"

#define ID_BACK     0xF050
#define ID_MAIN     0xF051
#define ID_OPTIONS  0xF052

#define MAIN_WINDOW     1
#define MAIN_TERMINAL   40
#define MAIN_LISTBOX    60

/* Size of terminal buffer in characters. */
#define TERMINAL_BUFFER_SIZE  200

#define DEF_SCHEME mainscheme

/* tick_tack variable for ticken. */
bool tick_tack;

/* End of program area physical address. */
#define ISO_PROTOCOL_OPTION_EEPROM_ADDR 0x1D07FFFF

/***************************************************
* String literals used in the project
***************************************************/
const GFX_XCHAR WelcomeScreen_MAIN_WINDOWtext[ ] = "Ablak";
const GFX_XCHAR WelcomeScreen_MTR_2text[ ] = "Meter";
const GFX_XCHAR ConnectString[] = "Connect ISO 9141 protocol:";
GFX_XCHAR PictureScreen_PICTUREWINDtext[] = "Picture";

GFX_XCHAR TerminalBuffer[TERMINAL_BUFFER_SIZE] = "Terminal buffer   ";

GFX_XCHAR ListBoxDatas[] = "FirstItem\nSecond Item\nThird Item";
GFX_XCHAR AddedItem[] = "Added Item\nMore add Item";

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
} APP_SCREEN_STATES;

typedef enum
{
  ISO9141_5BAUD,
  KWP_5BAUD,
  KWP_FAST,
} CONNECT_STATES;

// *****************************************************************************
// Application Variables
// *****************************************************************************
GFX_GOL_OBJ_SCHEME  mainscheme;          // Application main scheme


APP_SCREEN_STATES   screenState;
CONNECT_STATES      connectState;
/***************************************************
* Function       : ErrorCreate
* Parameters     : none
* Return         : none
* Description    : Creates a Error screen
***************************************************/
void ErrorCreate(GFX_XCHAR* string)
{
    // Blue Screen Error
	GFX_ColorSet(LIGHTRED);
  GFX_ScreenClear();
  GFX_ColorSet(BLACK);

  // Flash Error Message
  if(string == NULL)
    {
      GFX_TextStringDraw(0, 0, "Runtime Error.", 16);
    }
  else
    {
      GFX_TextStringDraw(0,0, string, 0);
    }
    while (1);  // infinity loop
}


/* APP_createMainButton(void)
 * Create main button for main screen reach at all program state.
*/

// *****************************************************************************
uint16_t APP_CreateMainButton(void)
{
  GFX_GOL_BUTTON *pObj;
  pObj = GFX_GOL_ButtonCreate ( ID_MAIN, 20, 210, 100, 236, 0,
    GFX_GOL_BUTTON_DRAW_STATE, NULL, NULL, "MAIN",
    GFX_ALIGN_HCENTER | GFX_ALIGN_VCENTER, &DEF_SCHEME );

    if(pObj == NULL)
        return (0);
    return 1;
}

uint16_t CreateOptionsButton(void)
{
  GFX_GOL_BUTTON *pObj;
  pObj = GFX_GOL_ButtonCreate ( ID_OPTIONS, 120, 210, 200, 236, 0,
    GFX_GOL_BUTTON_DRAW_STATE, NULL, NULL, "OPTIONS",
    GFX_ALIGN_HCENTER | GFX_ALIGN_VCENTER, &DEF_SCHEME );

    if(pObj == NULL)
        return (0);
    return 1;
}

int number = 0;

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

void SetMainScheme()
{
     // initialize select screen style scheme
    memcpy( &DEF_SCHEME, &APP_GENERIC_SCHEME, sizeof(GFX_GOL_OBJ_SCHEME));
    /* Setting the defscheme behaviors, ang features. */
/*    DEF_SCHEME.Color0 =        DARKGRAY;   // panelFaceColor
    DEF_SCHEME.Color1 =        LIGHTGRAY;  // panelFaceColor
    DEF_SCHEME.TextColor0 =    GFX_RGBConvert(24, 24, 24); // first text color option
    DEF_SCHEME.TextColor1 =    GFX_RGBConvert(248, 252, 248);  // second text color option
    DEF_SCHEME.EmbossDkColor = GFX_RGBConvert(0, 32, 256);   // dark emboss color
    DEF_SCHEME.EmbossLtColor = GFX_RGBConvert(16, 64, 224);  // light emboss color
    DEF_SCHEME.TextColorDisabled = GFX_RGBConvert(128, 128, 128);
    DEF_SCHEME.ColorDisabled = GFX_RGBConvert(208, 224, 240);
    DEF_SCHEME.CommonBkColor = GFX_RGBConvert(208, 236, 240);*/
    DEF_SCHEME.EmbossSize =    3;
    DEF_SCHEME.CommonBkLeft = 0; // horizontal starting position of the background
    DEF_SCHEME.CommonBkTop = 0;  // vertical starting position of the background
    DEF_SCHEME.CommonBkType = GFX_BACKGROUND_COLOR;
    DEF_SCHEME.pFont = (GFX_RESOURCE_HDR*)&APP_DEMO_FONT;

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
        0, 100, 319, 200,               // dimension
        GFX_GOL_STATICTEXT_DRAW_STATE,  // draw the object
        (GFX_XCHAR*)TerminalBuffer,         // 2 lines of text
        GFX_ALIGN_LEFT | GFX_ALIGN_TOP, // align text on the center
        &DEF_SCHEME); // use given scheme

    if(pMAIN_TERMINAL == NULL)
      {
        ErrorCreate(0);
      } else
      {
        pMAIN_TERMINAL->hdr.actionGet = TerminalActionGet;
      }

    pMAIN_LISTBOX = GFX_GOL_ListBoxCreate (
        MAIN_LISTBOX,                 // ID
        10, 10, 300, 96,               // dimension
        GFX_GOL_LISTBOX_DRAW_STATE,  // draw the object
        (GFX_XCHAR*)ListBoxDatas,
        GFX_ALIGN_LEFT | GFX_ALIGN_TOP, // align text on the center
        &DEF_SCHEME);  // use given scheme


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

bool APP_ObjectDrawCallback(void)
{
  switch (screenState)
  {
    case INIT_PROGRAM:
      screenState = CREATE_BACKGROUND;
      break;
    case CREATE_BACKGROUND:
      GFX_ColorSet(GREEN);
      GFX_ScreenClear();
      screenState = CREATE_MAIN_MENU;
      break;
    case CREATE_MAIN_MENU:
      GFX_GOL_ObjectListFree();
      SetMainScheme();
      CreateOptionsButton();
      MainScreenCreate();
      screenState = DISPLAY_MAIN_MENU;       // switch to next state
      break;
    case DISPLAY_MAIN_MENU:
      break;
    case CREATE_OPTIONS:
      SetOptionsScheme();
      GFX_ColorSet(BLUE);
      GFX_ScreenClear();
      APP_CreateMainButton();
      CreateOptions();
      screenState = DISPLAY_OPTIONS;
      break;
    case DISPLAY_OPTIONS:
//      OptionsDrawCallback();
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
    case DISPLAY_OPTIONS:
      if ((objectMessage == GFX_GOL_BUTTON_ACTION_RELEASED) && (objID == ID_MAIN))
      {

        if (GFX_GOL_ObjectStateGet(pObject, GFX_GOL_BUTTON_PRESSED_STATE))
        {
          GFX_GOL_ObjectListFree();
          screenState = CREATE_BACKGROUND;
        };
      } break;

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
  DisplayBacklightOn();
    // set the message callback function pointer
  GFX_GOL_MessageCallbackSet(APP_ObjectMessageCallback);
    // set the draw callback function pointer
  GFX_GOL_DrawCallbackSet(APP_ObjectDrawCallback);

    // clear the screen with the given color
  GFX_ColorSet(BLACK);
  GFX_ScreenClear();

  screenState = INIT_PROGRAM;

//  SetMainScheme();

    // call the function that creates the selection screen menu
//  MainScreenCreate();

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

