/*************************************************
* DISASSOCIAGRUPPOMENUITEM.CPP									 *
*************************************************/

#include "DisassociaGruppoMenuItem.h"

/**
 * Costruttore vuoto
 */
 
DisassociaGruppoMenuItem::DisassociaGruppoMenuItem()
{
}
//##################################################

/**
 * Costruttore
 */
 
DisassociaGruppoMenuItem::DisassociaGruppoMenuItem(string testo, Forum* f, Disegnatore* d, ListaUtentiForum* l)
: MenuItem(testo, d)
{
 addCommand(new LeggiListaTutor(l, d, &_numeroUtente));
 addCommand(new DisassociaGruppo(f, d, l, &_numeroUtente));
}

//############################################################

