/******************************************
* PONIRISPOSTA.H			                    *
*******************************************/

#ifndef PONIRISPOSTA_H
#define PONIRISPOSTA_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "Disegnatore.h"
#include "Forum.h"
#include "ListaUtentiForum.h"
#include "Command.h"

using namespace std;

class PoniRisposta : public Command
{
public:
    //costruttore
    PoniRisposta(Forum* f, Disegnatore* d, ListaUtentiForum* l, int* numGruppo, int* numDomanda);

    //metodi
    virtual void execute();


private:
	//puntatori ad oggetti esterni
    Forum* _puntForum;
    Disegnatore* _puntDis;
    ListaUtentiForum* _puntLista;
    int* _numGruppo;
    int* _numDomanda;
};

#endif
