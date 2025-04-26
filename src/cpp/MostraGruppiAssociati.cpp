/*************************************************
* MOSTRAGRUPPIASSOCIATI.CPP											 *
*************************************************/

#include "MostraGruppiAssociati.h"

/* 
 * costruttore
 */

MostraGruppiAssociati::MostraGruppiAssociati(Disegnatore* d, ListaUtentiForum* l, int* numeroTutor)
: Command(),
  _puntLista(l),
  _puntDis(d),
  _numeroTutor(numeroTutor)
{ 
}

//####################################################
/**
 * void MostraGruppiAssociati::execute()
 * Esegue il comando 
 */

void MostraGruppiAssociati::execute()
{
 vector<string> gruppi;
 
 //se qualche command precedente ha prodotto output non
 //validi, esegue
 if (*_numeroTutor != -1)                          
 {
  //chiama il metodo di ListaUtentiForum che fornisce i gruppi associati ad un
  //certo Tutor
  gruppi = _puntLista -> leggiGruppiTutor(*_numeroTutor);
  
  //se esistono gruppi associati li mostra
  if (gruppi.size() != 0)
  _puntDis -> mostraStringhe(gruppi);
  else _puntDis -> statusbar("Il tutor selezionato non ha gruppi associati");
  getch();
 }
}

