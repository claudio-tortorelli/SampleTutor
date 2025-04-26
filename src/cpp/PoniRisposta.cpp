/*************************************************
* PONIRISPOSTA.CPP															 *
*************************************************/

#include "PoniRisposta.h"

/* 
 * costruttore
 */

PoniRisposta::PoniRisposta(Forum* f, Disegnatore* d, ListaUtentiForum* l, int* numGruppo, int* numDomanda)
: Command(),
  _puntForum(f),
  _puntDis(d),
  _puntLista(l),
  _numGruppo(numGruppo),
  _numDomanda(numDomanda)
{
}

//############################################
/**
 * void PoniRisposta::execute()
 * Esegue il comando 
 */

void PoniRisposta::execute()
{
  //se non sono stati forniti in input valori di escape da altre command
  if (*_numGruppo != -1)
    {
    //ricerca l'indice dell'utente corrente nella lista utenti
    int numUtente = _puntLista -> leggiNumUtenteSistema();
    
    //controlla se l'utente corrente, tra i tutor, ha tra i gruppi associati
    //quello a cui potrebbe rispondere
    vector<string> gruppi = _puntLista -> elencoGruppiAssociati(numUtente);
    if (gruppi.size() != 0) //è un tutor con qualche gruppo già associato
      {
       string gruppoCorrente = _puntForum -> leggiNomeGruppo(*_numGruppo);
       bool trovato = false;
       for (int i=0; i<gruppi.size(); i++) 
         {
          if (gruppi[i] == gruppoCorrente) trovato = true;
         } 
       if (trovato == true) //il tutor è abilitato alla risposta
         {
          _puntDis -> mostraTesto("Premi 'R' per rispondere alla domanda o <ESC> per tornare al menu'");
          char ch = getch();      
          while ((ch != 'r' && ch != 'R') && (ch != 27)) 
            {
             ch = getch() ;             
            }
          if (ch != 27) //rispondi alla data domanda
            {
             _puntDis -> statusbar("Attenzione! Le risposte non possono cominciare col carattere '?'");
             string risposta = "?";
             //controllo che la risposta non cominci con '?'
             while (risposta[0] == '?')              
              {
               _puntDis -> mostraTesto("Inserisci la tua risposta qui di seguito: \n");
               getline(cin, risposta);       
              }             
             time_t t; //variabile che contiene il tempo di sistema
             struct tm* dat; //dichiara una struttura predefinita per contenere il tempo di sistema
             time(&t); //estrae ora e data di sistema
             dat = localtime(&t); // Converte t in una struttura tm            
             string firma = _puntLista -> leggiFirmaUtente();
             risposta = risposta + " (" + firma + ") - " + asctime(dat); //aggiunge la data e l'ora al msg 
             risposta.resize(risposta.size() - 1);//per evitare un accapo inutile si elimina l'ultima posizione 
             
             //inserisce la risposta formattata nel gruppo a seguito della
             //relativa domanda
             _puntForum -> poniRisposta(*_numGruppo, *_numDomanda, risposta);
            }
         }
      } 
    }
}
