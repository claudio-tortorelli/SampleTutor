/******************************************
* INFOUTENTEMENUITEM.H                    *
*******************************************/

#ifndef INFOUTENTEMENUITEM_H
#define INFOUTENTEMENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "MenuItem.h"
#include "VisualizzaUtente.h"
#include "LeggiListaUtenti.h"
#include "Disegnatore.h"
#include "ListaUtentiForum.h"

using namespace std;

class InfoUtenteMenuItem : public MenuItem
{
public:
    //costruttori
    InfoUtenteMenuItem();
    InfoUtenteMenuItem(string testo, Disegnatore* d, ListaUtentiForum* l);

private:
	//dati condivisi tra le command
    int _numeroUtente;
};

#endif
