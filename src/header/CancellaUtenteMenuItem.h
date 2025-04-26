/******************************************
* CANCELLAUTENTEMENUITEM.H                *
*******************************************/

#ifndef CANCELLAUTENTEMENUITEM_H
#define CANCELLAUTENTEMENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "ListaUtentiForum.h"
#include "Disegnatore.h"
#include "MenuItem.h"
#include "CancellaUtente.h"
#include "LeggiListaUtenti.h"

using namespace std;

class CancellaUtenteMenuItem : public MenuItem
{
public:
    //costruttori
    CancellaUtenteMenuItem();
    CancellaUtenteMenuItem(string testo, Disegnatore* d, ListaUtentiForum* l);

private:
	//valori condivisi tra le command
    int _numeroUtente;
};
#endif
