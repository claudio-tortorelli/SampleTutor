/*************************************************
* MOSTRAGRUPPIASSOCIATIMENUITEM.CPP							 *
*************************************************/

#include "MostraGruppiAssociatiMenuItem.h"

/**
 * Costruttore vuoto
 */
 
MostraGruppiAssociatiMenuItem::MostraGruppiAssociatiMenuItem()
{
}

//##################################################

/**
 * Costruttore 
 */
 
MostraGruppiAssociatiMenuItem::MostraGruppiAssociatiMenuItem(string testo, Disegnatore* d, ListaUtentiForum* l)
: MenuItem(testo, d)
{
 addCommand(new LeggiListaTutor(l, d, &_numeroTutor));
 addCommand(new MostraGruppiAssociati(d, l, &_numeroTutor));
}

//############################################################

