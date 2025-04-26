/*************************************************
* MOSTRARISPOSTE.CPP														 *
*************************************************/

#include "MostraRisposte.h"

/* 
 * costruttore
 */
MostraRisposte::MostraRisposte(Forum* f, Disegnatore* d, int* numGruppo, int* numDomanda)
: Command(),
  _puntForum(f),
  _puntDis(d),
  _numGruppo(numGruppo),
  _numDomanda(numDomanda)
{
}

//#################################################
/**
 * void MostraGruppiAssociati::execute()
 * Esegue il comando 
 */
 
void MostraRisposte::execute()
{
    //se non sono stati forniti in input valori non validi da altre command
    if (*_numGruppo != -1)
    {
     vector<string> risposte;
     
     //chiama il metodo di forum che dato il numero di gruppo e domanda 
     //restituisce le risposte
     risposte = _puntForum -> leggiRisposte(*_numGruppo, *_numDomanda);
     
     //controlla che vi siano risposte ed eventualmente le mostra
     if (risposte.size() == 0)
      {
       _puntDis -> statusbar("Non ci sono risposte per questa domanda"); getch();
      } 
      else 
      {
       _puntDis -> mostraStringhe(risposte); getch();
      }
    }
}

