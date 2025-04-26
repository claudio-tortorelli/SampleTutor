/*************************************************
* ACCESSOGRUPPIMENUITEM.CPP  										 *
*************************************************/

#include "AccessoGruppiMenuItem.h"

/**
  * Costruttore vuoto
  */

AccessoGruppiMenuItem::AccessoGruppiMenuItem()
{
}

//#################################################

/**
  * Costruttore
  */

AccessoGruppiMenuItem::AccessoGruppiMenuItem(string testo, Forum* f, Disegnatore* d, ListaUtentiForum* l)
: MenuItem(testo, d)
{
 addCommand(new AccessoGruppi(f, d, &_numeroGruppo));
 addCommand(new MostraDomanda(f, d, &_numeroGruppo, &_numeroDomanda, &_gruppoVuoto));
 addCommand(new PoniDomanda(f, d, l, &_numeroGruppo, &_gruppoVuoto));
 addCommand(new MostraRisposte(f, d, &_numeroGruppo, &_numeroDomanda));
 addCommand(new PoniRisposta(f, d, l, &_numeroGruppo, &_numeroDomanda));
}

//############################################################

