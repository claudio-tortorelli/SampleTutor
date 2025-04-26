/******************************************
* MOSTRAGRUPPIASSOCIATIMENUITEM.H         *
*******************************************/

#ifndef MOSTRAGRUPPIASSOCIATIMENUITEM_H
#define MOSTRAGRUPPIASSOCIATIMENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "LeggiListaTutor.h"
#include "MostraGruppiAssociati.h"
#include "MenuItem.h"
#include "ListaUtentiForum.h"
#include "Disegnatore.h"

using namespace std;

class MostraGruppiAssociatiMenuItem : public MenuItem
{
public:
    //costruttori
    MostraGruppiAssociatiMenuItem();
    MostraGruppiAssociatiMenuItem(string testo, Disegnatore* d, ListaUtentiForum* l);

private:
	//dati condivisi tra le command
    int _numeroTutor;
};

#endif
