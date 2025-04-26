/******************************************
* COMMAND.H                               *
*******************************************/

#ifndef COMMAND_H
#define COMMAND_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <vector>
#include <string>

class Command
{
public:
    //costruttori
    Command();

    //distruttore
    virtual ~Command();

    //metodi virtuali puri
    virtual void execute() = 0;


private:


};

#endif
