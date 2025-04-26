/******************************************
* LEGGILISTATUTOR.H                       *
*******************************************/

#ifndef LEGGILISTATUTOR_H
#define LEGGILISTATUTOR_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "Disegnatore.h"
#include "ListaUtentiForum.h"
#include "Command.h"

using namespace std;

class LeggiListaTutor : public Command
{
public:
    //costruttore
    LeggiListaTutor(ListaUtentiForum* l, Disegnatore* d, int* scelta);

    //metodi
    virtual void execute();


private:
	//puntatori ad oggetti esterni
	ListaUtentiForum* _puntLista;
    Disegnatore* _puntDis;
    int* _scelta;
};

#endif
