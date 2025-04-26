/*************************************************
* ACCESSOGRUPPI.CPP															 *
*************************************************/

#include "AccessoGruppi.h"

/* 
 * costruttore
 */

AccessoGruppi::AccessoGruppi(Forum* f, Disegnatore* d, int* sceltaGruppo)
: Command(),
  _puntForum(f),
  _puntDis(d),
  _sceltaGruppo(sceltaGruppo)
{ 
}

//##################################################

/**
 * void AssociaGruppi::execute()
 * Provvede per delegazione ad eseguire il comando
 */

void AccessoGruppi::execute() 
{
   vector<string> gruppi;
   gruppi = _puntForum -> leggiElencoGruppi();  
   if (gruppi.size() != 0) //ci sono gruppi ai quali accedere?
     {*_sceltaGruppo = _puntDis -> scegli(gruppi,"Scegli il gruppo al quale vuoi accedere. <ESC> per tornare al menu' principale");}
   else 
      {
       *_sceltaGruppo = -1; //ritorna il valore che segnala assenza di gruppi
       _puntDis -> statusbar("Non esistono attualmente dei gruppi tra i quali scegliere!");
       getch();
      }
}


