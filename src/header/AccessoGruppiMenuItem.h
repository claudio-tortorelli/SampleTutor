/******************************************
* ACCESSOGRUPPIMENUITEM.H                 *
*******************************************/

#ifndef ACCESSOGRUPPIMENUITEM_H
#define ACCESSOGRUPPIMENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "AccessoGruppi.h"
#include "MostraDomanda.h"
#include "MostraRisposte.h"
#include "MenuItem.h"
#include "PoniDomanda.h"
#include "PoniRisposta.h"
#include "Forum.h"
#include "Disegnatore.h"
#include "ListaUtentiForum.h"

using namespace std;

class AccessoGruppiMenuItem : public MenuItem
{
public:
    //costruttori
    AccessoGruppiMenuItem();
    AccessoGruppiMenuItem(string testo, Forum* f, Disegnatore* d, ListaUtentiForum* l);

private:
	//valori condivisi tra le command
    int _numeroGruppo;
    int _numeroDomanda;
    bool _gruppoVuoto;
};

#endif
