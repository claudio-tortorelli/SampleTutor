/******************************************
* AMMINISTRATORE.H                        *
*******************************************/

#ifndef AMMINISTRATORE_H
#define AMMINISTRATORE_H

#include "Tutor.h"

class Amministratore : public Tutor
{
public:
    //costruttori
    Amministratore(string nome, string cognome, string email, string login, string password, vector <string> gruppiAssociati);
    Amministratore(string nome, string cognome, string email, string login, string password);

    //metodi accessori
    virtual vector <string> tuttiIDati() const;

private:
};

#endif
