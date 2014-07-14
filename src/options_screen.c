

#include "options_screen.h"
#include "DashBoard.h"

GFX_GOL_OBJ_SCHEME  optscheme;          // Options Scheme

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

uint16_t CreateOptions(void)
{
  int width = GFX_MaxXGet();
  int height = GFX_TextStringHeightGet(optscheme.pFont);

  if (GFX_GOL_GroupboxCreate(ID_CONTYPE_BOX, 0, 0, width, (height * 2) + 10,
    GFX_GOL_GROUPBOX_DRAW_STATE, "Connection type", GFX_ALIGN_VCENTER,
      &optscheme) == NULL)
  {
    return -1;    
  }

  width -= 3;
  if (GFX_GOL_RadioButtonCreate(ID_RADIOBUTTON1, 3, height + 2, (width / 3), (height * 2) + 6,
      GFX_GOL_RADIOBUTTON_DRAW_STATE | GFX_GOL_RADIOBUTTON_GROUP_STATE,
      "ISO 9141 SLOW", GFX_ALIGN_CENTER, &optscheme) == NULL)
  {
    return -1;
  };

  if (GFX_GOL_RadioButtonCreate(ID_RADIOBUTTON2, (width / 3), height + 2, (width / 3) * 2, (height * 2) + 6,
      GFX_GOL_RADIOBUTTON_DRAW_STATE,
      "KWP SLOW", GFX_ALIGN_CENTER, &optscheme) == NULL)
  {
    return -1;
  };

    if (GFX_GOL_RadioButtonCreate(ID_RADIOBUTTON3, (width / 3) * 2, height + 2, width, (height * 2) + 6,
      GFX_GOL_RADIOBUTTON_DRAW_STATE,
      "KWP FAST", GFX_ALIGN_CENTER, &optscheme) == NULL)
  {
    return -1;
  };

  if (GFX_GOL_GroupboxCreate(ID_BOX_TRYING, 0, (height * 2) + 12, width, (height * 2) + 80,
    GFX_GOL_GROUPBOX_DRAW_STATE, "Trying connection", GFX_ALIGN_VCENTER,
      &optscheme) == NULL)
  {
    return -1;
  }

  return 0;
}

bool     OptionsDrawCallback(void)
{

}

bool MsgOptionsCallback(GFX_GOL_TRANSLATED_ACTION objMsg, GFX_GOL_OBJ_HEADER *pObject, GFX_GOL_MESSAGE *pMessage)
{
  uint16_t           objectID;

  objectID = GFX_GOL_ObjectIDGet(pObject);

  if (objectID == ID_RADIOBUTTON2)
  {
    if (objMsg == GFX_GOL_RADIOBUTTON_ACTION_CHECKED )
    {
      if ((67 / 0) > 1) return 0;
    }
  } else
  if (objectID == ID_RADIOBUTTON1)
  {
    SoftReset();
  }

}
