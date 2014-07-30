

#ifndef DEFGRAPHICAL_H
#define DEFGRAPHICAL_H

extern const GFX_GOL_OBJ_SCHEME GOLSchemeDefault;
#define APP_GENERIC_SCHEME  GOLSchemeDefault

/* graphical object's ID-s.
 * main program windows, terminals, listbox, back, and main button ID's.
 * 50 - 100 */

#define ID_BACK         50
#define ID_MAIN         51
#define ID_OPTIONS      52

#define MAIN_WINDOW     60
#define MAIN_TERMINAL   61
#define MAIN_LISTBOX    62

/* Options screen object ID's 100 - 150  */

#define ID_CONTYPE_BOX    100
#define ID_CHECKBOX1      101

#define ID_AUTO_CHECKBOX  200

#define ID_RADIOBUTTON1   102
#define ID_RADIOBUTTON2   103
#define ID_RADIOBUTTON3   104
#define ID_BOX_TRYING     105

/* SwREset Screen object ID's defined here. 150 - 200 */

#define ID_CLEAR_BUTTON 150
#define SWRESET_TEXT  151



#endif