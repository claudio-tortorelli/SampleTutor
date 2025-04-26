/*************************************************
* LEGGILISTATUTOR.CPP 													 *
*************************************************/

#include "LeggiListaTutor.h"

/* 
 * costruttore
 */


LeggiListaTutor::LeggiListaTutor(ListaUtentiForum* l, Disegnatore* d, int* scelta)
: Command(),
  _puntLista(l),
  _puntDis(d),
  _scelta(scelta)
{
}
//####################################################
/**
 * void LeggiListaTutor::execute()
 * Esegue il comando
 */

void LeggiListaTutor::execute()
{
 vector<string> firme;
 //richiede a ListaUtentiForum l'elenco delle "firme" dei tutor  
 firme = _puntLista -> leggiFirmeTutor(); 
 //se questo elenco non è vuoto fa scegliere l'utente tra questi
 if (firme.size() != 0)
 *_scelta = _puntDis -> scegli(firme,"Scegli un tutor o premi <ESC> per tornare al menu'");
 else *_scelta = -1; //esce dall'operazione senza effettuare scelte
}

