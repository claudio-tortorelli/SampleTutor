/*************************************************
* CREAGRUPPO.CPP																 *
*************************************************/

#include "CreaGruppo.h"

CreaGruppo::CreaGruppo(Forum* f, Disegnatore* d)
: Command(),
  _puntForum(f),
  _puntDis(d)
{ 
}

//##############################################
/**
 * void CreaGruppo::execute()
 * Provvede per delegazione ad eseguire il comando
 */

void CreaGruppo::execute()
{ 
 string nome; //nome file
 bool flag = 1; 
 int i; int j;
 // chiede il nome del gruppo e lo rifiuta se vuoto o maggiore di 30 car.
 while (flag == 1) 
   {    
    flag = 0;
    _puntDis -> mostraTesto("Immetti il nome del nuovo gruppo (max. 30 caratteri)");     
    getline(cin, nome);
    for (j = 0; j<nome.length(); j++)
     if(nome[j] == ' ') nome[j] = '_';
    if (nome[0] == '\0' || nome.size() > 30) {flag = 1;}
   }  
 nome = nome.c_str();//converte la stringa in const char*
 //cerca dove finisce nell'array di char il nome e vi aggiunge '.tut'
 i = 0;
 while (nome[i] != '\0') i++; 
 //chiama il metodo di Forum per il gruppo selezionato   
 _puntForum -> creaGruppo(nome);
 _puntDis -> statusbar("Operazione di Creazione gruppo eseguita");
}
