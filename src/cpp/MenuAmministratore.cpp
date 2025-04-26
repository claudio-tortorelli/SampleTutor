/*************************************************
* MENUAMMINISTRATORE.CPP												 *
*************************************************/

#include "MenuAmministratore.h"

/**
 * Costruttore vuoto
 */
MenuAmministratore::MenuAmministratore()
{
}

//############################################ 

/**
 * Costruttore
 */

MenuAmministratore::MenuAmministratore(Forum* f, Disegnatore* d, ListaUtentiForum* l)
:Menu(f, d, l)
{ //arricchisco il vettore delle voci   
  add(new AccessoGruppiMenuItem("Accedi ai gruppi\n\0", f, d, l));
  add(new MostraGruppiAssociatiMenuItem("Mostra gruppi associati a un tutor\n\0", d, l));
  add(new CreaGruppoMenuItem("Crea un nuovo gruppo\n\0", d, f));
  add(new CancellaGruppoMenuItem("Cancella un gruppo\n\0", d,f));
  add(new AssociaGruppiMenuItem("Associa un gruppo a un tutor\n\0", f, d, l));
  add(new DisassociaGruppoMenuItem("Elimina una associazione Gruppo/Tutor\n\0", f, d, l));
  add(new InfoUtenteMenuItem("Leggi informazioni sugli utenti\n\0", d, l));
  add(new IscrizioneUtentiMenuItem("Iscrizione di un utente\n\0", d, l));
  add(new CancellaUtenteMenuItem("Cancellazione di un utente\n\0", d, l));
}


