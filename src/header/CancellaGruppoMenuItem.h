/******************************************
* CANCELLAGRUPPOMENUITEM.H                *
*******************************************/

#ifndef CANCELLAGRUPPOMENUITEM_H
#define CANCELLAGRUPPOMENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "Forum.h"
#include "Disegnatore.h"
#include "MenuItem.h"
#include "AccessoGruppi.h"
#include "CancellaGruppo.h"

using namespace std;

class CancellaGruppoMenuItem : public MenuItem
{
public:
    //costruttori
    CancellaGruppoMenuItem();
    CancellaGruppoMenuItem(string testo, Disegnatore* d, Forum* f);

private:
	//valori condivisi tra le command
    int _numGruppo;
};

#endif
