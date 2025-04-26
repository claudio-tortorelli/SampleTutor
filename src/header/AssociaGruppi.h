/******************************************
* ASSOCIAGRUPPI.H                         *
*******************************************/

#ifndef ASSOCIAGRUPPI_H
#define ASSOCIAGRUPPI_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string>
#include "ListaUtentiForum.h"
#include "Disegnatore.h"
#include "Forum.h"
#include "Command.h"

class AssociaGruppi : public Command
{
public:
    //costruttore
    AssociaGruppi(Forum* f, Disegnatore* d, ListaUtentiForum* l, int* numeroTutor);

    //metodi
    virtual void execute();

private: //puntatori ad oggetti esterni
    Forum* _puntForum;
    ListaUtentiForum* _puntLista;
    Disegnatore* _puntDis;
    int* _numeroTutor;
};

#endif
