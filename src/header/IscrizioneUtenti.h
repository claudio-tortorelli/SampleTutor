/******************************************
* ISCRIZIONEUTENTI.H                      *
*******************************************/

#ifndef ISCRIZIONEUTENTI_H
#define ISCRIZIONEUTENTI_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string>
#include "ListaUtentiForum.h"
#include "Disegnatore.h"
#include "Command.h"

using namespace std;

class IscrizioneUtenti : public Command

{
public:
    //costruttore
    IscrizioneUtenti(ListaUtentiForum* l, Disegnatore* d);

    //metodi
    virtual void execute();

private:
	//puntatori ad oggetti esterni
    ListaUtentiForum* _puntLista;
    Disegnatore* _puntDis;
};

#endif
