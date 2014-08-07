
#include "xc.h"
#include "system_config.h"
#include "options_screen.h"
#include "DashBoard.h"

GFX_GOL_OBJ_SCHEME  optscheme;          // Options Scheme
enum E_CONNECT_TYPE CONNECT_TYPE;
/* Automatic trying connection (infinity). */
unsigned int TRYING_CONN;
static GFX_GOL_STATICTEXT* pKLINE_INPUT_TERMINAL = NULL;

static GFX_XCHAR C1[] = "HIGH";
static GFX_XCHAR C2[] = "LOW";

void SetOptionsScheme()
{
     // initialize select screen style scheme
    memcpy( &optscheme, &APP_GENERIC_SCHEME, sizeof(GFX_GOL_OBJ_SCHEME));
    /* Setting the defscheme behaviors, ang features. */
/*    optscheme.Color0 =        DARKGRAY;   // panelFaceColor
    optscheme.Color1 =        LIGHTGRAY;  // panelFaceColor
    optscheme.TextColor0 =    GFX_RGBConvert(24, 24, 24); // first text color option
    optscheme.TextColor1 =    GFX_RGBConvert(248, 252, 248);  // second text color option
    optscheme.EmbossDkColor = GFX_RGBConvert(0, 32, 256);   // dark emboss color
    optscheme.EmbossLtColor = GFX_RGBConvert(16, 64, 224);  // light emboss color
    optscheme.TextColorDisabled = GFX_RGBConvert(128, 128, 128);
    optscheme.ColorDisabled = GFX_RGBConvert(208, 224, 240);
    optscheme.CommonBkColor = GFX_RGBConvert(208, 236, 240);*/
    optscheme.EmbossSize =    3;
    optscheme.CommonBkLeft = 0; // horizontal starting position of the background
    optscheme.CommonBkTop = 0;  // vertical starting position of the background
    optscheme.CommonBkType = GFX_BACKGROUND_COLOR;
    optscheme.pFont = (GFX_RESOURCE_HDR*)&OPTIONS_FONT;

//  memcpy(&defscheme, &GOLSchemeDefault, sizeof(GFX_GOL_OBJ_SCHEME));
}

GFX_XCHAR* GetHighLowString(bool data)
{
  if (data)
    return C1;
  else return C2;
}

uint16_t CreateOptions(void)
{
  int width = GFX_MaxXGet();
  int height = GFX_TextStringHeightGet(optscheme.pFont);
  uint16_t newstate;


  if (GFX_GOL_GroupboxCreate(ID_CONTYPE_BOX, 0, 0, width, (height * 2) + 10,
    GFX_GOL_GROUPBOX_DRAW_STATE, "Connection type", GFX_ALIGN_VCENTER,
      &optscheme) == NULL)
  {
    return -1;    
  }

  newstate = GFX_GOL_RADIOBUTTON_DRAW_STATE | GFX_GOL_RADIOBUTTON_GROUP_STATE;
  if (CONNECT_TYPE == ISO_9141_SLOW) newstate |= GFX_GOL_RADIOBUTTON_CHECKED_STATE;

  width -= 3;
  if (GFX_GOL_RadioButtonCreate(ID_RADIOBUTTON1, 3, height + 2, (width / 3), (height * 2) + 6,
      newstate, "ISO 9141 SLOW", GFX_ALIGN_CENTER, &optscheme) == NULL)
  {
    return -1;
  };

  newstate = GFX_GOL_RADIOBUTTON_DRAW_STATE;
  if (CONNECT_TYPE == KWP_SLOW) newstate |= GFX_GOL_RADIOBUTTON_CHECKED_STATE;

  if (GFX_GOL_RadioButtonCreate(ID_RADIOBUTTON2, (width / 3), height + 2, (width / 3) * 2, (height * 2) + 6,
      newstate, "KWP SLOW", GFX_ALIGN_CENTER, &optscheme) == NULL)
  {
    return -1;
  };

  newstate = GFX_GOL_RADIOBUTTON_DRAW_STATE;
  if (CONNECT_TYPE == KWP_FAST) newstate |= GFX_GOL_RADIOBUTTON_CHECKED_STATE;

  if (GFX_GOL_RadioButtonCreate(ID_RADIOBUTTON3, (width / 3) * 2, height + 2, width, (height * 2) + 6,
      newstate, "KWP FAST", GFX_ALIGN_CENTER, &optscheme) == NULL)
  {
    return -1;
  };

  newstate = GFX_GOL_CHECKBOX_DRAW_STATE;
  if (TRYING_CONN) newstate |= GFX_GOL_CHECKBOX_CHECKED_STATE;

  if (GFX_GOL_CheckBoxCreate(ID_AUTO_CHECKBOX, 3, (height * 3) + 12, (width / 2), (height * 4) + 20,
      newstate, "AUTO CONNECT", GFX_ALIGN_CENTER, &optscheme) == NULL)
  {
    return -1;
  };

  if (GFX_GOL_CheckBoxCreate (ID_TESTKLINE_BUT, 3, (height * 5) + 12, (width / 2), (height * 6) + 20,
    GFX_GOL_CHECKBOX_DRAW_STATE, "TEST K LINE", GFX_ALIGN_HCENTER | GFX_ALIGN_VCENTER, &optscheme) == NULL)
  {
    return -1;
  }

  pKLINE_INPUT_TERMINAL = (GFX_GOL_StaticTextCreate ( ID_TESTKLINE_INPUT,
    (width / 2) + 3, (height * 5) + 12, width, (height * 6) + 20, GFX_GOL_STATICTEXT_DRAW_STATE,
    GetHighLowString(true), GFX_ALIGN_LEFT | GFX_ALIGN_TOP, &optscheme));
    if (pKLINE_INPUT_TERMINAL == NULL)
    {
      return -1;
    }else                  // use given scheme
    {
//      pKLINE_INPUT_TERMINAL->hdr.actionGet = TerminalActionGet;
    }

    if (GFX_GOL_CheckBoxCreate (ID_TESTKLINE_INPUT, 3, (height * 5) + 12, (width / 2), (height * 6) + 20,
    GFX_GOL_CHECKBOX_DRAW_STATE, "TEST K LINE", GFX_ALIGN_HCENTER | GFX_ALIGN_VCENTER, &optscheme) == NULL)
  {
    return -1;
  }

/*  newstate = GFX_GOL_CHECKBOX_DRAW_STATE;
  if (TRYING_CONN) newstate |= GFX_GOL_RADIOBUTTON_CHECKED_STATE;

  if (GFX_GOL_CheckBoxCreate(ID_MANUAL_RADIO, (width / 2), (height * 3) + 12, (width / 2) * 2, (height * 4) + 20,
      newstate, "MANU", GFX_ALIGN_CENTER, &optscheme) == NULL)
  {
    return -1;
  };*/

  return 0;
}

void SetInputString()
{
  if (pKLINE_INPUT_TERMINAL != NULL)
  {
    GFX_GOL_StaticTextSet(pKLINE_INPUT_TERMINAL, GetHighLowString(RXPORT));
    GFX_GOL_StaticTextDraw(pKLINE_INPUT_TERMINAL);
  }
}


bool MsgOptionsCallback(GFX_GOL_TRANSLATED_ACTION objMsg, GFX_GOL_OBJ_HEADER *pObject, GFX_GOL_MESSAGE *pMessage)
{
  uint16_t           objectID;
  GFX_GOL_CHECKBOX* PC;

  objectID = GFX_GOL_ObjectIDGet(pObject);

  /* KWP FAST */

  if (objectID == ID_RADIOBUTTON1)
  {
    CONNECT_TYPE = ISO_9141_SLOW;
  } else /*KWP SLOW */
  if (objectID == ID_RADIOBUTTON2)
  {
    CONNECT_TYPE = KWP_SLOW;
  } else /* ISO 9141 SLOW */
  if (objectID == ID_RADIOBUTTON3)
  {
    CONNECT_TYPE = KWP_FAST;
  } else
    if (objectID == ID_AUTO_CHECKBOX)
    { 
      if (objMsg == GFX_GOL_CHECKBOX_ACTION_CHECKED)
      {
        TRYING_CONN = 1;
      }
      else if (objMsg == GFX_GOL_CHECKBOX_ACTION_UNCHECKED)
      {
        TRYING_CONN = 0;
      }
    }else
      if (objectID == ID_TESTKLINE_BUT)
      {
        if (objMsg == GFX_GOL_CHECKBOX_ACTION_CHECKED)
        {
          TXLAT = 1;
          SetInputString();
        } 
        else if (objMsg == GFX_GOL_CHECKBOX_ACTION_UNCHECKED)
        {
          TXLAT = 0;
          SetInputString();
        }
      }

}
