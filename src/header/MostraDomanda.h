/******************************************
* MOSTRADOMANDA.H			                    *
*******************************************/

#ifndef MOSTRADOMANDA_H
#define MOSTRADOMANDA_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "Disegnatore.h"
#include "Forum.h"
#include "Command.h"

using namespace std;

class MostraDomanda : public Command
{
public:
    //costruttore
    MostraDomanda(Forum* f, Disegnatore* d, int* numGruppo, int* numDomanda, bool* gruppoVuoto);

    //metodi
    virtual void execute();

private:
	//puntatori ad oggetti esterni
    Forum* _puntForum;
    Disegnatore* _puntDis;
    int* _numGruppo;
    int* _numDomanda;
    bool* _gruppoVuoto;
};

#endif
