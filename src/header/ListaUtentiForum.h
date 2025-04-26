/******************************************
* LISTAUTENTIFORUM.H                      *
*******************************************/

#ifndef LISTAUTENTIFORUM_H
#define LISTAUTENTIFORUM_H

#include <string>
#include <vector>
#include "Amministratore.h"

using namespace std;

class ListaUtentiForum
{
public:
    //costruttore
    ListaUtentiForum();
    ~ListaUtentiForum();

    //metodi
    vector <string> leggiDatiUtente(int num);
    int numeroUtenti();
    Utente* getUtenteCorrente();
    int leggiNumUtenteSistema();
    void cambiaPwUtente(int numUtente, string newPw);
	void cambiaLogUtente(int numUtente, string newLog);
	void cambiaNomeUtente(int numUtente, string newNome);
	void cambiaCognomeUtente(int numUtente, string newCognome);
	void cambiaEmailUtente(int numUtente, string newEmail);
	vector <string> elencoGruppiAssociati(int numUtente);
	vector <string> leggiFileUtenti(string login, string password);
	void add(Utente* u);
	void addTutor(Tutor* t);
    bool iscriviUtente(vector<string> nuovoUtente);
    bool cancellaUtente(int numUtente);
    string leggiFirmaUtente();
    string leggiFirmaUtente(int num);
    vector<string> leggiFirmeTutor();
    void associaGruppoTutor(string gruppo, int* numeroTutor);
    void disassociaGruppoTutor(string gruppo, int* numeroTutor);
    vector<string> leggiGruppiTutor(int numeroTutor);
	void rinfrescaListaTutor();
	bool fileUtentiVuoto();

private:
    vector< Utente* > _utenti;
    vector< Tutor* > _listaTutor;
    int _numUtenteSistema;
};
#endif

