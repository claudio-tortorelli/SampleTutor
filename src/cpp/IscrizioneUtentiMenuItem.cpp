/*************************************************
* ISCRIZIONEUTENTIMENUITEM.CPP									 *
*************************************************/

#include "IscrizioneUtentiMenuItem.h"

/**
 * Costruttore vuoto
 */
 
IscrizioneUtentiMenuItem::IscrizioneUtentiMenuItem()
{
}

//############################################################
/**
 * Costruttore
 */

IscrizioneUtentiMenuItem::IscrizioneUtentiMenuItem(string testo, Disegnatore* d, ListaUtentiForum* l)
: MenuItem(testo, d)
{
 addCommand(new IscrizioneUtenti(l, d));
}

//############################################################

