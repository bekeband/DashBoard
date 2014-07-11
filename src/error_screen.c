

#include "error_screen.h"

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


