/******************************************
* MENUTUTOR.H					                    *
*******************************************/

#ifndef MENUTUTOR_H
#define MENUTUTOR_H

#include <vector>
#include <iostream.h>
#include "Menu.h"
#include "MostraGruppiAssociatiMenuItem.h"
#include "AccessoGruppiMenuItem.h"
#include "Forum.h"
#include "Disegnatore.h"
#include "ListaUtentiForum.h"

class MenuTutor : public Menu
{
public:
    //costruttori
    MenuTutor();
    MenuTutor(Forum* f, Disegnatore* d, ListaUtentiForum* l);

private:
};

#endif
