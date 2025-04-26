/*************************************************
* CANCELLAUTENTE.CPP														 *
*************************************************/

#include "CancellaUtente.h"

/* 
 * costruttore
 */

CancellaUtente::CancellaUtente (Disegnatore* d, ListaUtentiForum* l, int* numUtente)
: Command(),
  _puntLista(l),
  _puntDis(d),
  _numUtente(numUtente)
{ 
}

void CancellaUtente::execute()
{ 
  if (*_numUtente != -1) //controlla che precedenti command non abbiano
                         //fornito valori di numUtente non validi
  {
   //controlla che l'utente corrente non provi a cancellare se stesso
   if (*_numUtente != _puntLista -> leggiNumUtenteSistema())
    {
    //chiama il metodo di ListaUtentiForum per l'utente selezionato   
    if (_puntLista -> cancellaUtente(*_numUtente))
      {_puntDis -> statusbar("Operazione di cancellazione utente eseguita");getch();}   
    else 
      {_puntDis -> statusbar("Operazione di cancellazione utente NON eseguita: non ci sono piu' utenti");getch();}   
    }
   else
   {_puntDis -> statusbar("Operazione non eseguita: impossibile cancellare l'utente corrente");getch();}         
  }
}
