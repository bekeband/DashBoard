
#include <xc.h>
#include "swreset_screen.h"
#include "exceptions.h"

/*const unsigned char DATA[8] __attribute__((space(prog), address(EXCEPTION_CAUSE_VIRTUAL), section(".text.EXCEPT_CAUSE_DATA")))
  = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};*/

const uint32_t EXCEPTION_CAUSE_DATA __attribute__((space(prog), address(EXCEPTION_CAUSE_VIRTUAL), section(".text.EXCEPT_CAUSE_DATA"))) = 0xFFFFFFFF;
const uint32_t EXCEPTION_ADDR_DATA __attribute__((space(prog), address(EXCEPTION_ADDR_VIRTUAL), section(".text.EXCEPT_ADDR_DATA"))) = 0xFFFFFFFF;

GFX_GOL_OBJ_SCHEME  swresetscheme;          // Options Scheme

void SetSwresetScheme()
{
     // initialize select screen style scheme
    memcpy( &swresetscheme, &APP_GENERIC_SCHEME, sizeof(GFX_GOL_OBJ_SCHEME));
    swresetscheme.EmbossSize =    3;
    swresetscheme.CommonBkLeft = 0; // horizontal starting position of the background
    swresetscheme.CommonBkTop = 0;  // vertical starting position of the background
    swresetscheme.CommonBkType = GFX_BACKGROUND_COLOR;
    swresetscheme.pFont = (GFX_RESOURCE_HDR*)&OPTIONS_FONT;
}

bool     SwresetDrawCallback()
{
  return true;
}

bool MsgSwresetCallback(GFX_GOL_TRANSLATED_ACTION objMsg, GFX_GOL_OBJ_HEADER *pObject, GFX_GOL_MESSAGE *pMessage)
{
  return true;
}



uint16_t CreateSwreset()
{
  static unsigned char b[80];
/*  _excep_code = EXCEPTION_CAUSE_DATA;
  _excep_addr = EXCEPTION_ADDR_DATA;*/

//  FormatExceptionString(NULL);

  // EXCEPTION_CAUSE_DATA, EXCEPTION_ADDR_DATA

  sprintf(b, "Exception code = 0X%2X, Address = 0X%4X", EXCEPTION_CAUSE_DATA, EXCEPTION_ADDR_DATA);

  if (GFX_GOL_StaticTextCreate (SWRESET_TEXT, 0, 0, 319, 200,
    GFX_GOL_STATICTEXT_DRAW_STATE, b,
      GFX_ALIGN_LEFT | GFX_ALIGN_TOP, &swresetscheme) == NULL)
  {
    
  } else
  {
    
  }
  return 0;
}
