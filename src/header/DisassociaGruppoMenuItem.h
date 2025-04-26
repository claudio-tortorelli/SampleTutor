/******************************************
* DISASSOCIAGRUPPOMENUITEM.H              *
*******************************************/

#ifndef DISASSOCIAGRUPPOMENUITEM_H
#define DISASSOCIAGRUPPOMENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "LeggiListaTutor.h"
#include "DisassociaGruppo.h"
#include "MenuItem.h"
#include "Forum.h"
#include "Disegnatore.h"
#include "ListaUtentiForum.h"

using namespace std;

class DisassociaGruppoMenuItem : public MenuItem
{
public:
    //costruttori
    DisassociaGruppoMenuItem();
    DisassociaGruppoMenuItem(string testo, Forum* f, Disegnatore* d, ListaUtentiForum* l);

private:
	//dati condivisi tra le command
    int _numeroUtente;
    int _numeroGruppo;
};

#endif
