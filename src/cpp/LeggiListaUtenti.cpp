/*************************************************
* LEGGILISTAUTENTI.CPP													 *
*************************************************/

#include "LeggiListaUtenti.h"

/* 
 * costruttore
 */
 
LeggiListaUtenti::LeggiListaUtenti(ListaUtentiForum* l, Disegnatore* d, int* scelta)
: Command(),
  _puntLista(l),
  _puntDis(d),
  _scelta(scelta)
{
}
//#################################################
/*
 * void LeggiListaUtenti::execute()
 * Esegue il comando
 */

void LeggiListaUtenti::execute()
{
   vector<string> firme;
   int numeroUtenti = _puntLista -> numeroUtenti();
   int i; 
   for (i = 0; i < numeroUtenti; i++)
   	{
   	 firme.push_back(_puntLista -> leggiFirmaUtente(i));  
    }
   *_scelta = _puntDis -> scegli(firme,"Scegli un utente fra quelli elencati");
}

