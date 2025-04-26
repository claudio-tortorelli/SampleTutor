/*************************************************
* CREAGRUPPOMENUITEM.CPP												 *
*************************************************/

#include "CreaGruppoMenuItem.h"

/**
  * Costruttore vuoto
  */
 
CreaGruppoMenuItem::CreaGruppoMenuItem()
{
}

//############################################################

/**
 * Costruttore
 */

CreaGruppoMenuItem::CreaGruppoMenuItem(string testo, Disegnatore* d, Forum* f)
: MenuItem(testo, d)
{   
 addCommand(new CreaGruppo(f, d));
}

//############################################################

