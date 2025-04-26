/******************************************
* CANCELLAGRUPPO.H                        *
*******************************************/

#ifndef CANCELLAGRUPPO_H
#define CANCELLAGRUPPO_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string>
#include "Forum.h"
#include "Disegnatore.h"
#include "Command.h"

using namespace std;

class CancellaGruppo : public Command
{
public:
    //costruttore
    CancellaGruppo(Forum* f, Disegnatore* d, int* numGruppo);

    //metodi
    virtual void execute();

private:
	//puntatori ad oggetti esterni
    Forum* _puntForum;
    Disegnatore* _puntDis;
    int* _numGruppo;
};

#endif
