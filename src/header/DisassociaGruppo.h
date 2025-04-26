/******************************************
* DISASSOCIAGRUPPO.H                      *
*******************************************/

#ifndef DISASSOCIAGRUPPO_H
#define DISASSOCIAGRUPPO_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string>
#include "ListaUtentiForum.h"
#include "Disegnatore.h"
#include "Forum.h"
#include "Command.h"

using namespace std;

class DisassociaGruppo : public Command
{
public:
    //costruttore
    DisassociaGruppo(Forum* f, Disegnatore* d, ListaUtentiForum* l, int* numeroTutor);

    //metodi
    virtual void execute();

private:
	//puntatori ad oggetti esterni
    Forum* _puntForum;
    ListaUtentiForum* _puntLista;
    Disegnatore* _puntDis;
    int* _numeroTutor;
};

#endif
