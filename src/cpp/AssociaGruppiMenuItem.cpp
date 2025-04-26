/*************************************************
* ASSOCIAGRUPPIMENUITEM.CPP 										 *
*************************************************/

#include "AssociaGruppiMenuItem.h"

/** 
 * Costruttore vuoto
 */
 
AssociaGruppiMenuItem::AssociaGruppiMenuItem()
{
}

//###################################################
/**
 * Costruttore
 */ 
 
AssociaGruppiMenuItem::AssociaGruppiMenuItem(string testo, Forum* f, Disegnatore* d, ListaUtentiForum* l)
: MenuItem(testo, d)
{
 addCommand(new LeggiListaTutor(l, d, &_numeroUtente));
 addCommand(new AssociaGruppi(f, d, l, &_numeroUtente));
}

//############################################################

