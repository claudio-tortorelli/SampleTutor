/******************************************
* MOSTRAGRUPPIASSOCIATI.H                 *
*******************************************/

#ifndef MOSTRAGRUPPIASSOCIATI_H
#define MOSTRAGRUPPIASSOCIATI_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string>
#include "ListaUtentiForum.h"
#include "Disegnatore.h"
#include "Command.h"

using namespace std;

class MostraGruppiAssociati : public Command
{
public:
    //costruttore
    MostraGruppiAssociati(Disegnatore* d, ListaUtentiForum* l, int* numeroTutor);

    //metodi
    virtual void execute();

private:
	//puntatori ad oggetti esterni
    ListaUtentiForum* _puntLista;
    Disegnatore* _puntDis;
    int* _numeroTutor;
};

#endif
