

#ifndef OPTIONS_SCREEN_H
#define OPTIONS_SCREEN_H

#include <string.h>
#include "gfx/gfx.h"
#include "gdd_resource.h"
#include "defgraphical.h"

void SetOptionsScheme();
uint16_t CreateOptions(void);
bool     OptionsDrawCallback(void);
bool     MsgOptionsCallback(GFX_GOL_TRANSLATED_ACTION objMsg, GFX_GOL_OBJ_HEADER *pObject, GFX_GOL_MESSAGE *pMessage);

#endif