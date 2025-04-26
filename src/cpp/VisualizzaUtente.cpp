/*************************************************
* VISUALIZZAUTENTE.CPP																			 *
*************************************************/

#include "VisualizzaUtente.h"

/* 
 * costruttore
 */
 
VisualizzaUtente::VisualizzaUtente(ListaUtentiForum* l, Disegnatore* d, int* numeroUtente)
: Command(),
  _puntLista(l),
  _puntDis(d),
  _numeroUtente(numeroUtente)
{ 
}

//##################################################

/**
 * void VisualizzaUtente::execute()
 * Esegue il comando 
 */

void VisualizzaUtente::execute()
{
  //se non sono stati forniti in input valori di escape da altre command  
  if (*_numeroUtente != -1) 
    {
     //invoca il metodo di ListaUtentiForum per leggere i dati di un utente
     //con un certo indice
     vector<string> DatiUtente = _puntLista -> leggiDatiUtente(*_numeroUtente);  
     
     //li visualizza
   	 _puntDis -> visualizzaDatiUtente(DatiUtente);
    } 
}

//##################################################

