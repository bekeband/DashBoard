

#ifndef OPTIONS_SCREEN_H
#define OPTIONS_SCREEN_H

  #include <string.h>
  #include "gfx/gfx.h"
  #include "gdd_resource.h"

  #define ID_CONTYPE_BOX    0xF053
  #define ID_CHECKBOX1      0xF100

  #define ID_RADIOBUTTON1 34
  #define ID_RADIOBUTTON2 35
  #define ID_RADIOBUTTON3 36
  #define ID_BOX_TRYING   37

  extern const GFX_GOL_OBJ_SCHEME GOLSchemeDefault;
  #define APP_GENERIC_SCHEME  GOLSchemeDefault

  void SetOptionsScheme();
  uint16_t CreateOptions(void);
  bool     OptionsDrawCallback(void);
  bool     MsgOptionsCallback(uint16_t objMsg, GFX_GOL_OBJ_HEADER *pObj, GFX_GOL_MESSAGE *pMsg);


#endif