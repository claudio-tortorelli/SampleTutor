/******************************************
* ASSOCIAGRUPPIMENUITEM.H                 *
*******************************************/

#ifndef ASSOCIAGRUPPIMENUITEM_H
#define ASSOCIAGRUPPIMENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "LeggiListaTutor.h"
#include "AssociaGruppi.h"
#include "MenuItem.h"
#include "Forum.h"
#include "Disegnatore.h"
#include "ListaUtentiForum.h"

using namespace std;

class AssociaGruppiMenuItem : public MenuItem
{
public:
    //costruttori
    AssociaGruppiMenuItem();
    AssociaGruppiMenuItem(string testo, Forum* f, Disegnatore* d, ListaUtentiForum* l);

private:
	//valori condivisi tra le command
    int _numeroUtente;
    int _numeroGruppo;
};

#endif
