/*************************************************
* MENUUTENTE.CPP																 *
*************************************************/

#include "MenuUtente.h"

/**
 * Costruttore vuoto
 */

MenuUtente::MenuUtente()
{
}

//#######################################################

/**
  * Costruttore
 */

MenuUtente::MenuUtente(Forum* f, Disegnatore* d, ListaUtentiForum* l)
:Menu(f, d, l)
{
 add(new AccessoGruppiMenuItem("Leggi elenco dei gruppi\n\0", f, d, l));
}


