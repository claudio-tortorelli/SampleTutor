/******************************************
* ACCESSOGRUPPI.H                         *
*******************************************/

#ifndef ACCESSOGRUPPI_H
#define ACCESSOGRUPPI_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include "Forum.h"
#include "Disegnatore.h"
#include "Command.h"


class AccessoGruppi : public Command
{
public:
    //costruttore
    AccessoGruppi(Forum* f, Disegnatore* d, int* sceltaGruppo);

    //metodi
    virtual void execute();

private://puntatori ad oggetti esterni
	Forum* _puntForum;
    Disegnatore* _puntDis;
    int* _sceltaGruppo; //gruppo scelto al quale accedere
};

#endif
