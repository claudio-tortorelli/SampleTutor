/*************************************************
* PONIDOMANDA.CPP																 *
*************************************************/

#include "PoniDomanda.h"

/* 
 * costruttore
 */
PoniDomanda::PoniDomanda(Forum* f, Disegnatore* d, ListaUtentiForum* l, int* numGruppo, bool* gruppoVuoto)
: Command(),
  _puntForum(f),
  _puntDis(d),
  _puntLista(l),  
  _numGruppo(numGruppo),
  _gruppoVuoto(gruppoVuoto)  
{
}

//#################################################
/**
 * void MostraGruppiAssociati::execute()
 * Esegue il comando 
 */

void PoniDomanda::execute()
{
 //se non sono stati forniti in input valori non validi da altre command
 if (*_numGruppo != -1)
  {
   char ch;    
   //controlla se il gruppo è vuoto: in tal caso non mostra l'opzione delle 
   //risposte
   if (*_gruppoVuoto)
     {
      _puntDis -> mostraTesto("Premi 'D' per porre una domanda o <ESC> per tornare al menu'");
      ch = getch();      
      while ((ch != 'd') && (ch != 'D') && (ch != 27)) 
       {
        ch = getch() ;             
       }
     }
   else //se invece il gruppo e' pieno chiede se si vuol visualizzare le risp.
    {
     _puntDis -> statusbar("'D': poni nuova domanda, 'L': leggi le risposte, <ESC> per tornare al menu'");
     ch = getch();      
     while ((ch != 'd') && (ch != 'D') && (ch != 27) && (ch != 'l') && (ch != 'L')) 
       {
        ch = getch() ;             
       }
    }     
   switch (ch)
    {
     case 'L':
     case 'l': 
       break;
     case 27: 
       *_numGruppo = -1;
       break;
     case 'D':
     case 'd':
       _puntDis -> mostraTesto("Inserisci la tua domanda qui di seguito: \n");
       string domanda;
       getline(cin, domanda);
       time_t t; //variabile che contiene il tempo di sistema
       struct tm* dat; //dichiara una struttura predefinita per contenere il tempo di sistema  
       time(&t); //estrae ora e data di sistema
       dat = localtime(&t); // Converte t in una struttura tm            
       string firma = _puntLista -> leggiFirmaUtente();
       domanda = '?' + domanda + " (" + firma + ") - " + asctime(dat); //aggiunge la data e l'ora al msg   
       domanda.resize(domanda.size() - 1);//per evitare un accapo inutile si elimina l'ultima posizione 
       _puntForum -> poniDomanda(*_numGruppo, domanda);       
       *_numGruppo = -1; // inserita una domanda non si vuol proseguire nell'accesso gruppi       
       break;        
    }//switch    
  }//if     
}
