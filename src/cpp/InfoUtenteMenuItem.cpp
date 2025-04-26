/*************************************************
* INFOUTENTEMENUITEM.CPP												 *
*************************************************/

#include "InfoUtenteMenuItem.h"

/**
 * Costruttore vuoto
 */
 
InfoUtenteMenuItem::InfoUtenteMenuItem()
{
}

//############################################################

/**
  * Costruttore
 */

InfoUtenteMenuItem::InfoUtenteMenuItem(string testo, Disegnatore* d, ListaUtentiForum* l)
: MenuItem(testo, d)
{
 addCommand(new LeggiListaUtenti(l, d, &_numeroUtente));
 addCommand(new VisualizzaUtente(l, d, &_numeroUtente));
}

//############################################################

