/******************************************
* MOSTRARISPOSTE.H                        *
*******************************************/

#ifndef MOSTRARISPOSTE_H
#define MOSTRARISPOSTE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "Disegnatore.h"
#include "Forum.h"
#include "Command.h"

using namespace std;

class MostraRisposte : public Command
{
public:
    //costruttore
    MostraRisposte(Forum* f, Disegnatore* d, int* numGruppo, int* numDomanda);

    //metodi
    virtual void execute();

private:
	//puntatori ad oggetti esterni
    Forum* _puntForum;
    Disegnatore* _puntDis;
    int* _numGruppo;
    int* _numDomanda;
};

#endif
