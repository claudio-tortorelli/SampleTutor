/*************************************************
* DISASSOCIAGRUPPO.CPP													 *
*************************************************/

#include "DisassociaGruppo.h"

/* 
 * costruttore
 */

DisassociaGruppo::DisassociaGruppo(Forum* f, Disegnatore* d, ListaUtentiForum* l, int* numeroTutor)
: Command(),
  _puntForum(f),
  _puntLista(l),
  _puntDis(d),
  _numeroTutor(numeroTutor)
{ 
}

//############################################

/**
 * void DisassociaGruppo::execute()
 * Esegue il comando
 */

void DisassociaGruppo::execute()
{
 if (*_numeroTutor != -1)
 {
   vector<string> gruppi;
   //legge i gruppi già associati ad un tutor
   gruppi = _puntLista -> leggiGruppiTutor(*_numeroTutor);
   int scelta = _puntDis -> scegli(gruppi,"Scegli l'associazione da eliminare (<ESC> per annullare)");
   if (scelta != -1) //se l'utente non ha chiesto di uscire
   {
    if (gruppi.size() != 0) _puntLista -> disassociaGruppoTutor(gruppi[scelta], _numeroTutor);
    else {_puntDis -> statusbar("Non esistono attualmente dei gruppi tra i quali scegliere!");}
   }
 }  
}
