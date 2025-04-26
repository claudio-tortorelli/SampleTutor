/*************************************************
* CANCELLAGRUPPOMENUITEM.CPP										 *
*************************************************/

#include "CancellaGruppoMenuItem.h"

/**
 * Costruttore vuoto
 */
 
CancellaGruppoMenuItem::CancellaGruppoMenuItem()
{
}

//############################################################

/**
 * Costruttore
 */
 
CancellaGruppoMenuItem::CancellaGruppoMenuItem(string testo, Disegnatore* d, Forum* f)
: MenuItem(testo, d)
{   
    addCommand(new AccessoGruppi(f, d, &_numGruppo));
    addCommand(new CancellaGruppo(f, d, &_numGruppo));
}

//############################################################

