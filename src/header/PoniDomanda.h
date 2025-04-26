/******************************************
* PONIDOMANDA.H 			                    *
*******************************************/

#ifndef PONIDOMANDA_H
#define PONIDOMANDA_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "Disegnatore.h"
#include "Forum.h"
#include "ListaUtentiForum.h"
#include "Command.h"

using namespace std;

class PoniDomanda : public Command
{
public:
    //costruttore
    PoniDomanda(Forum* f, Disegnatore* d, ListaUtentiForum* l, int* numGruppo, bool* gruppoVuoto);

    //metodi
    virtual void execute();

private:
	//puntatori ad oggetti esterni
	Forum* _puntForum;
    Disegnatore* _puntDis;
    ListaUtentiForum* _puntLista;
    int* _numGruppo;
    bool* _gruppoVuoto;
};
#endif
