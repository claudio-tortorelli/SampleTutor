/******************************************
* FORUM.H					                        *
*******************************************/

#ifndef FORUM_H
#define FORUM_H

#include <string>
#include <io.h>
#include <vector>
#include <fstream.h>
#include <conio.h>
#include "GruppoDiscussione.h"

using namespace std;

class Forum
{
public:
    //costruttore
    Forum();

    //distruttore
    ~Forum();

    //operazioni proprie di forum
	void leggiGruppiDaFile();

    //operazioni comuni a tutti gli utenti
    vector<string> leggiElencoGruppi(); 	
    vector<string> leggiElencoDomande(int* numGruppo); 	
    vector<string> leggiRisposte(int numGruppo, int numDomanda);
    void poniDomanda(int numGruppo, string domanda); 

    //operazioni riservate ai tutor
    void poniRisposta(int numGruppo, int numDomanda, string risposta);

    //operazioni riservate agli amministratori
    void creaGruppo(string nome);			
    bool cancellaGruppo(int numGruppo);
    string leggiNomeGruppo(int numGruppo);

private:	
    vector <GruppoDiscussione*> _gruppi;
    
};

#endif

