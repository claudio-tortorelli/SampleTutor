/******************************************
* CREAGRUPPO.H                            *
*******************************************/

#ifndef CREAGRUPPO_H
#define CREAGRUPPO_H


#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <string>
#include "Forum.h"
#include "Disegnatore.h"
#include "Command.h"

using namespace std;

class CreaGruppo : public Command
{
public:
    //costruttore
    CreaGruppo(Forum* f, Disegnatore* d);

    //metodi
    virtual void execute();

private:
	//puntatori a oggetti esterni
    Forum* _puntForum;
    Disegnatore* _puntDis;
};

#endif
