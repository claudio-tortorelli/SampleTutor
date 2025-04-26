/*************************************************
* MOSTRADOMANDA.CPP															 *
*************************************************/

#include "MostraDomanda.h"

/* 
 * costruttore
 */

MostraDomanda::MostraDomanda(Forum* f, Disegnatore* d, int* numGruppo, int* numDomanda, bool* gruppoVuoto)
: Command(),
  _puntForum(f),
  _puntDis(d),
  _numGruppo(numGruppo),
  _numDomanda(numDomanda),
  _gruppoVuoto(gruppoVuoto)
{
}

//###############################################
/*
 * void MostraDomanda::execute()
 * Esegue il comando
 */

void MostraDomanda::execute()
{   //se precedenti command non hanno prodotto output non
    //validi, esegui
    if (*_numGruppo != -1)                        
    {
     //legge l'elenco delle domande del gruppo
     vector<string> domande;
     domande = _puntForum -> leggiElencoDomande(_numGruppo);
     *_gruppoVuoto = false; //controlla se effettivamente ci sono domande
     if (domande.size() == 0) 
      {     
       *_gruppoVuoto = true;
       _puntDis -> statusbar("Il gruppo scelto non contiene domande.");
      } 
     else //se ha trovato domande ne fa selezionare una all'utente
      {  
       *_numDomanda = _puntDis -> scegli(domande, "Seleziona una domanda da leggere");
       if (*_numDomanda != -1) 
       {     
        _puntDis -> mostraTesto(domande[*_numDomanda]);
       }  
      } 
    }
}

