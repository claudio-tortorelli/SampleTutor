/******************************************
* MENUUTENTE.H				                    *
*******************************************/

#ifndef MENUUTENTE_H
#define MENUUTENTE_H

#include "Menu.h"
#include "AccessoGruppiMenuItem.h"

using namespace std;

class MenuUtente : public Menu
{
public:
    //costruttori
    MenuUtente();
    MenuUtente(Forum* f, Disegnatore* d, ListaUtentiForum* l);

private:
};

#endif
