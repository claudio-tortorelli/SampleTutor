/*************************************************
* ISCRIZIONEUTENTI.CPP													 *
*************************************************/

#include "IscrizioneUtenti.h"

/* 
 * costruttore
 */

IscrizioneUtenti::IscrizioneUtenti(ListaUtentiForum* l, Disegnatore* d)
: Command(),
  _puntLista(l),
  _puntDis(d)
{ 
}
//################################################
/**
 * void IscrizioneUtenti::execute()
 * Esegue il comando
 */

void IscrizioneUtenti::execute()
{
  vector<string> infoNuovoUtente;
  string bufferin; 
  vector<string> richieste;
  vector<string> scelte;
  
  richieste.push_back("Immetti il nome del nuovo utente:");
  richieste.push_back("Immetti il cognome del nuovo utente:");
  richieste.push_back("Immetti l'email del nuovo utente:");
  richieste.push_back("Immetti il login del nuovo utente:");
  richieste.push_back("Immetti la password del nuovo utente:");

  //le informazioni sul nuovo utente vengono reperite da un apposito metodo di 
  //disegnatore che le richiede ordinatamente
  infoNuovoUtente = _puntDis -> riempiForm(richieste);
  
  _puntDis -> pulisci();  
  //fa scegliere il tipo del nuovo utente
  cout << "Scegli il tipo del nuovo utente:";  
  scelte.push_back("UTENTE");
  scelte.push_back("TUTOR");
  scelte.push_back("AMMINISTRATORE");
  int n = -1;  
  while (n == -1) n = _puntDis -> scegli(scelte,"Scegli il tipo di utente");
  infoNuovoUtente.push_back(scelte[n]);

  //passa all'apposito metodo di ListaUtentiForum le info raccolte per l'iscriz.
  //e dopo l'inserimento informa l'utente
  if (_puntLista -> iscriviUtente(infoNuovoUtente))
   _puntDis -> statusbar("Operazione eseguita con successo. Premi un tasto per continuare...");
  else _puntDis -> statusbar("Operazione non eseguita. Login gia' esistente. Premi un tasto per continuare..."); 
  getch();
}
