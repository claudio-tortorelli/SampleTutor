/*************************************************
* CANCELLAGRUPPO.CPP														 *
*************************************************/

#include "CancellaGruppo.h"

/* 
 * costruttore
 */

CancellaGruppo::CancellaGruppo(Forum* f, Disegnatore* d, int* numGruppo)
: Command(),
  _puntForum(f),
  _puntDis(d),
  _numGruppo(numGruppo)
{ 
}

//#################################################

/**
 * void CancellaGruppo::execute()
 * Provvede per delegazione ad eseguire il comando
 */

void CancellaGruppo::execute()
{ 
  if (*_numGruppo != -1) //controlla se precedenti command hanno fornito valori
                         //di numGruppo non validi
  {
   //chiama il metodo di Forum per il gruppo selezionato
     _puntForum -> cancellaGruppo(*_numGruppo);
     {_puntDis -> statusbar("Operazione di cancellazione gruppo eseguita");}   
  } 
}
