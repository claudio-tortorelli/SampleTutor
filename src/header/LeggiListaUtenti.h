/******************************************
* LEGGILISTAUTENTI.H                      *
*******************************************/

#ifndef LEGGILISTAUTENTI_H
#define LEGGILISTAUTENTI_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "Disegnatore.h"
#include "ListaUtentiForum.h"
#include "Command.h"

using namespace std;

class LeggiListaUtenti : public Command
{
public:
    //costruttore
    LeggiListaUtenti(ListaUtentiForum* l, Disegnatore* d, int* scelta);

    //metodi
    virtual void execute();


private:
	//puntatori ad oggetti esterni
	ListaUtentiForum* _puntLista;
    Disegnatore* _puntDis;
    int* _scelta;
};

#endif
