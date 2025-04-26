/******************************************
* TUTOR.H							                    *
*******************************************/

#ifndef TUTOR_H
#define TUTOR_H

#include "Utente.h"
#include "GruppoDiscussione.h"


class Tutor : public Utente
{
public:
    //costruttori
    Tutor(string nome, string cognome, string email, string login, string password, vector <string> gruppiAssociati);
	Tutor(string nome, string cognome, string email, string login, string password);

    //metodi
    vector <string> leggiGruppiAssociati() const;
    vector <string> tuttiIDati() const;
    void aggiungiGruppo(string gruppo);
    void eliminaGruppo(string gruppo);

private:
    //campi
    vector <string> _gruppiAssociati;
};

#endif
