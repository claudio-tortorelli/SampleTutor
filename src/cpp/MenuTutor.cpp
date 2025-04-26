/*************************************************
* MENUTUTOR.CPP																	 *
*************************************************/

#include "MenuTutor.h"

/**
 * Costruttore vuoto
 */

MenuTutor::MenuTutor()
{
}
//##################################################

/**
 * Costruttore
 */

MenuTutor::MenuTutor(Forum* f, Disegnatore* d, ListaUtentiForum* l)
:Menu(f, d, l)
{ //arricchisco il vettore delle voci  
  add(new AccessoGruppiMenuItem("Accedi ai gruppi\n\0", f, d, l));
  add(new MostraGruppiAssociatiMenuItem("Mostra gruppi associati a un tutor\n\0", d, l));
}

