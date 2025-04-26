/******************************************
* SISTEMA.H						                    *
*******************************************/

#ifndef SISTEMA_H
#define SISTEMA_H

#include "MenuUtente.h"
#include "MenuTutor.h"
#include "MenuAmministratore.h"
#include "Forum.h"
#include <vector.h>
#include "Amministratore.h"
#include "Disegnatore.h"
#include "ListaUtentiForum.h"

class Sistema
{
public:
    //costruttore
    Sistema();
    ~Sistema();

    //metodi
    bool accediSistema();
    void avviaMenu();
    void caricaGruppi();
	void uscita();
	vector<string> creaPrimoUtente();

private:
    //campi
    Utente* _utenteSistema;
    Menu* _menuSistema;
    Forum* _forumSistema;
	ListaUtentiForum* _listaUtenti;
	Disegnatore* _disegnatore;
};

#endif
