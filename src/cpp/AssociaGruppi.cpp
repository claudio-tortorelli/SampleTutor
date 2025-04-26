/*************************************************
* ASSOCIAGRUPPI.CPP															 *
*************************************************/

#include "AssociaGruppi.h"

/* 
 * costruttore
 */

AssociaGruppi::AssociaGruppi(Forum* f, Disegnatore* d, ListaUtentiForum* l, int* numeroTutor)
: Command(),
  _puntForum(f),
  _puntLista(l),
  _puntDis(d),
  _numeroTutor(numeroTutor)
{ 
}

//#########################################

/**
 * void AssociaGruppi::execute()
 * Provvede per delegazione ad eseguire il comando
 */

void AssociaGruppi::execute()
{
 if (*_numeroTutor != -1) //controlla che precedenti command abbiano fornito 
                          //valori di numeroTutor non validi
 {
   vector<string> gruppi;
   gruppi = _puntForum -> leggiElencoGruppi();  
   int scelta = _puntDis -> scegli(gruppi,"Scegli il gruppo da associare (<ESC> per annullare)");
   if (scelta != -1)
   {
    if (gruppi.size() != 0) _puntLista -> associaGruppoTutor(gruppi[scelta], _numeroTutor);
    else {_puntDis -> statusbar("Non esistono attualmente dei gruppi tra i quali scegliere!");}
   }
 }  
}
