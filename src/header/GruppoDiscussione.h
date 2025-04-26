/******************************************
* GRUPPODISCUSSIONE.H                     *
*******************************************/

#ifndef GRUPPODISCUSSIONE_H
#define GRUPPODISCUSSIONE_H

#include <string>
#include <vector>
#include <io.h>
#include <conio.h>
#include <time.h>
#include <fstream.h>
#include <streambuf.h>
#include "Messaggio.h"

using namespace std;

class GruppoDiscussione
{
public:
    //costruttore
    GruppoDiscussione();
    GruppoDiscussione(string nome);
    ~GruppoDiscussione();

    //metodi
    int getNumeroDomande() const;
    int getNumeroRisposte(int i) const;
    void setNumeroDomande(int i);
    void inserisciDomanda(Messaggio _nuovoMessaggio);
    void inserisciRisposta(Messaggio _nuovoMessaggio, int _numDom);
    string leggiMessaggio(int i, int j);
    string leggiNome() const;
    vector<string> leggiRisposte(int numDom);
    vector<string> leggiDomande();
    void poniDomanda(string domanda);
    void poniRisposta(int _numDom, string risposta);
    void caricaFile(char* nomeFile);

private:
    string _nome;
    int _numDomande;
    vector< vector<Messaggio> > _messaggi; //e' la struttura contenente i messaggi in memoria    vector<Messaggio> _messaggi;

};
#endif

