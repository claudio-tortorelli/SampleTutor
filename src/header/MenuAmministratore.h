/******************************************
* MENUAMMINISTRATORE.H                    *
*******************************************/

#ifndef MENUAMM_H
#define MENUAMM_H

#include "Menu.h"
#include "IscrizioneUtentiMenuItem.h"
#include "InfoUtenteMenuItem.h"
#include "CreaGruppoMenuItem.h"
#include "CancellaGruppoMenuItem.h"
#include "AssociaGruppiMenuItem.h"
#include "DisassociaGruppoMenuItem.h"
#include "AccessoGruppiMenuItem.h"
#include "MostraGruppiAssociatiMenuItem.h"
#include "CancellaUtenteMenuItem.h"


class MenuAmministratore : public Menu
{
public:
    //costruttori
    MenuAmministratore();
    MenuAmministratore(Forum* f, Disegnatore* d, ListaUtentiForum* l);

private:
};

#endif
