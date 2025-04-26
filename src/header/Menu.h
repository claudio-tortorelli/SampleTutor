/******************************************
* MENU.H							                    *
*******************************************/

#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <string>
#include <vector>
#include "Forum.h"
#include "Disegnatore.h"
#include "MenuItem.h"
#include "ListaUtentiForum.h"

using namespace std;

class Menu
{
public:
    //costruttori
    Menu();
    Menu(Forum* f, Disegnatore* d, ListaUtentiForum* l);

    //distruttore
    ~Menu(void);

    //metodi mutuatori
    void add(MenuItem* s);

    //metodi accessori
    void start(string firma);

private:
	//campi
    Disegnatore* _puntDis; //puntatore all'oggetto esterno Disegnatore di interfaccia
    vector<MenuItem*> _voci; //vectori di puntatori a voci del Menu
};

#endif


