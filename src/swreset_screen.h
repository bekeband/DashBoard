

#ifndef SWRESET_SCREEN_H
#define SWRESET_SCREEN_H

#include <string.h>
#include "gfx/gfx.h"
#include "gdd_resource.h"
#include "defgraphical.h"

void      SetSwresetScheme();
uint16_t  CreateSwreset(void);
bool      SwresetDrawCallback(void);
bool      MsgSwresetCallback(GFX_GOL_TRANSLATED_ACTION objMsg, GFX_GOL_OBJ_HEADER *pObject, GFX_GOL_MESSAGE *pMessage);

#endif