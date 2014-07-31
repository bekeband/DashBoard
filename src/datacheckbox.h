
#ifndef DATACHECKBOX_H
#define DATACHECKBOX_H

#include "gfx/gfx.h"

struct S_DATACHECKBOX {
  GFX_GOL_CHECKBOX* CHECKBOXPTR;
  uint32_t*         DATAADDRESS;
  uint16_t          BITNUMBER;
};

GFX_GOL_CHECKBOX* DataCheckBoxCreate(
                                uint16_t            ID,
                                uint16_t            left,
                                uint16_t            top,
                                uint16_t            right,
                                uint16_t            bottom,
                                uint16_t            state,
                                GFX_XCHAR           *pText,
                                GFX_ALIGNMENT       alignment,
                                GFX_GOL_OBJ_SCHEME  *pScheme);


#endif
