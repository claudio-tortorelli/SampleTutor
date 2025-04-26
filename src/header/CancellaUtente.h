/******************************************
* CANCELLAUTENTE.H                        *
*******************************************/

#ifndef CANCELLAUTENTE_H
#define CANCELLAUTENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string>
#include "ListaUtentiForum.h"
#include "Disegnatore.h"
#include "Command.h"

using namespace std;

class CancellaUtente : public Command
{
public:
    //costruttore
    CancellaUtente(Disegnatore* d, ListaUtentiForum* l, int* numUtente);

    //metodi
    virtual void execute();

private:
	//puntatori ad oggetti esterni
    ListaUtentiForum* _puntLista;
    Disegnatore* _puntDis;
    int* _numUtente;
};

#endif
