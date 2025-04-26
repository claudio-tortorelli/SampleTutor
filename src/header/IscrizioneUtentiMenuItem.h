/******************************************
* ISCRIZIONEUTENTIMENUITEM.H              *
*******************************************/

#ifndef ISCRIZIONEUTENTIMENUITEM_H
#define ISCRIZIONEUTENTIMENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "IscrizioneUtenti.h"
#include "Disegnatore.h"
#include "MenuItem.h"
#include "ListaUtentiForum.h"

using namespace std;

class IscrizioneUtentiMenuItem : public MenuItem
{
public:
    //costruttori
    IscrizioneUtentiMenuItem();
    IscrizioneUtentiMenuItem(string testo, Disegnatore* d, ListaUtentiForum* l);

private:

};

#endif
