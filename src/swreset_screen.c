
#include <xc.h>
#include "swreset_screen.h"
#include "exceptions.h"

/*const unsigned int EXCEPTION_CAUSE_DATA __attribute__((space(prog), address(EXCEPTION_CAUSE_VIRTUAL), section(".text.EXCEPT_CAUSE_DATA")));
const unsigned int EXCEPTION_ADDR_DATA __attribute__((space(prog), address(EXCEPTION_ADDR_VIRTUAL), section(".text.EXCEPT_ADDR_DATA")));*/

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

static GFX_XCHAR b[80];

uint16_t CreateSwreset()
{
  _excep_code = 0x0675;
  _excep_addr = 0x033;

  FormatExceptionString(b);

  if (GFX_GOL_StaticTextCreate (SWRESET_TEXT, 0, 0, 319, 200,
    GFX_GOL_STATICTEXT_DRAW_STATE, (GFX_XCHAR*)b,
      GFX_ALIGN_LEFT | GFX_ALIGN_TOP, &swresetscheme) == NULL)
  {
    
  } else
  {
    
  }
  return 0;
}
