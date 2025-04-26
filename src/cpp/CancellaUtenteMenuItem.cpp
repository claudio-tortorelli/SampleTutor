/*************************************************
* CANCELLAUTENTEMENUITEM.CPP										 *
*************************************************/

#include "CancellaUtenteMenuItem.h"

/**
 * Costruttore vuoto
 */
 
CancellaUtenteMenuItem::CancellaUtenteMenuItem()
{
}

//############################################################

/**
 * Costruttore
 */

CancellaUtenteMenuItem::CancellaUtenteMenuItem(string testo, Disegnatore* d, ListaUtentiForum* l)
: MenuItem(testo, d)
{   
 addCommand(new LeggiListaUtenti(l, d, &_numeroUtente));  
 addCommand(new CancellaUtente(d, l, &_numeroUtente));
}

//############################################################

