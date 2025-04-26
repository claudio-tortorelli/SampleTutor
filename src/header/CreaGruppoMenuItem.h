/******************************************
* CREAGRUPPOMENUITEM.H                    *
*******************************************/

#ifndef CREAGRUPPOMENUITEM_H
#define CREAGRUPPOMENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "Forum.h"
#include "Disegnatore.h"
#include "MenuItem.h"
#include "CreaGruppo.h"

using namespace std;

class CreaGruppoMenuItem : public MenuItem
{
public:
    //costruttori
    CreaGruppoMenuItem();
    CreaGruppoMenuItem(string testo, Disegnatore* d, Forum* f);

private:
};

#endif
