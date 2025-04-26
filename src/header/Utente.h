/******************************************
* UTENTE.H						                    *
*******************************************/

#ifndef UTENTE_H
#define UTENTE_H

#include <vector>
#include <string>
using namespace std;

class Utente
{
public:
    //costruttori
    Utente();
    Utente(string nome, string cognome, string email, string login, string password);
    
    //metodi accessori
    string leggiNome() const;
    string leggiCognome() const;
    string leggiEmail() const;
    string leggiLogin() const;
    string leggiPassword() const;
    virtual vector <string> tuttiIDati() const;
	virtual vector <string> leggiGruppiAssociati() const;
	
    //metodi mutatori
	void cambiaPw(string nuovaPw);
    void cambiaLog(string nuovoLog);
    void cambiaNome(string nuovoNome);
    void cambiaCognome(string nuovoCognome);
    void cambiaEmail(string nuovaEmail);


private:
    //campi
    string _nome;
	string _cognome;
    string _email;
    string _login;
    string _password;
};

#endif
