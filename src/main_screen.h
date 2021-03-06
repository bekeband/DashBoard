

#if !defined MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include "defgraphical.h"
#include "serial.h"

extern GFX_GOL_OBJ_SCHEME  mainscheme;
#define MAIN_SCHEME mainscheme

/* Size of terminal buffer in characters. */
#define TERMINAL_BUFFER_SIZE  200

void SetMainScheme();
GFX_GOL_TRANSLATED_ACTION ConnectTerminalActionGet(void* pObject, GFX_GOL_MESSAGE* pMessage);
GFX_GOL_TRANSLATED_ACTION ErrorTerminalActionGet(void* pObject, GFX_GOL_MESSAGE* pMessage);
GFX_GOL_TRANSLATED_ACTION DebugTerminalActionGet(void* pObject, GFX_GOL_MESSAGE* pMessage);
GFX_GOL_STATICTEXT* pDEBUG_TERMINAL;

#endif
