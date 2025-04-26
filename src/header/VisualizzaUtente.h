/******************************************
* VISUALIZZAUTENTE.H	                    *
*******************************************/

#ifndef VISUALIZZAUTENTE_H
#define VISUALIZZAUTENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "Disegnatore.h"
#include "ListaUtentiForum.h"
#include "Command.h"

//using namespace std;

class VisualizzaUtente : public Command
{
public:
    //costruttore
    VisualizzaUtente(ListaUtentiForum* l, Disegnatore* d, int* numeroUtente);

    //metodi
    virtual void execute();

private:
	//puntatori ad oggetti esterni
	ListaUtentiForum* _puntLista;
    Disegnatore* _puntDis;
    int* _numeroUtente;
};

#endif
