/*************************************************
* FORUM.CPP																			 *
*************************************************/

#include "Forum.h"

/**
 * Forum::Forum()
 * Costruttore
 */
 
Forum::Forum()
{
}

//############################################################

/**
 * Forum::Forum()
 * Distruttore
 */

Forum::~Forum()
{
 int i;
 for(i=0; i< _gruppi.size(); i++) delete(_gruppi[i]);
}

//############################################################

/**
 * void Forum::leggiGruppiDaFile()
 * Metodo che legge i file dei gruppi (*.tut) e carica i messaggi nel vector
 * dei gruppi di discussione _gruppi
 */

void Forum::leggiGruppiDaFile()
{
struct _finddata_t _fileInfo; //struttura che contiene le info sui file
long _hand; //l'handler ai file che vengono ricercati nella dir
int _valSrc; //contiene il valore di ritorno della ricerca di file
string _nomeGruppo;

_hand = _findfirst( "*.tut", &_fileInfo ); //cerca il primo file .tut e ne restituisce l'handler
_valSrc = _hand; //assegna il valore dell'handler a _valSrc
while ( _valSrc != -1 ) //finchè _valSrc non indica che non ci sono più file nell dir...
    {      
    _nomeGruppo = _fileInfo.name;  
    _nomeGruppo = _nomeGruppo.substr(0,_nomeGruppo.length() - 4);
    GruppoDiscussione* newGruppo = new GruppoDiscussione(_nomeGruppo);
    newGruppo -> caricaFile(_fileInfo.name);
    _gruppi.push_back(newGruppo);//inserisce il nuovo gruppo nel vettore
    
    _valSrc = _findnext(_hand, &_fileInfo);//cerca il prossimo file .tut
    }
_findclose(_hand);//disalloca l'handler
}

//############################################################

/**
 * bool Forum::cancellaGruppo(int numGruppo)
 * Metodo che cancella un gruppo di discussione dal forum
 * Restituisce true in caso di successo
 */

bool Forum::cancellaGruppo(int numGruppo)
{
  if (_gruppi.size() != 0)
    {
     _gruppi[numGruppo] -> setNumeroDomande(-1);
     int i;
     vector <GruppoDiscussione*> temp;  
     delete _gruppi[numGruppo];  
     for (i = 0; i < _gruppi.size(); i++)
      {if (i != numGruppo) temp.push_back(_gruppi[i]);}
     _gruppi = temp;
     return true;
    }
  else {return false;}       
}

//############################################################

/**
 * void Forum::poniRisposta(int numGruppo, int numDomanda, string risposta)
 * Metodo per aggiungere una risposta alla domanda di indice numDomanda
 * nel gruppo di discussione di indice numGruppo
 */

void Forum::poniRisposta(int numGruppo, int numDomanda, string risposta)
{
 _gruppi[numGruppo] -> poniRisposta(numDomanda, risposta);
}

//############################################################

/**
 * void Forum::poniDomanda(int numGruppo, string domanda)
 * Metodo per aggiungere una domanda nel gruppo di discussione di indice numGruppo
 */
 
void Forum::poniDomanda(int numGruppo, string domanda)
{
 _gruppi[numGruppo] -> poniDomanda(domanda); 
} 

//############################################################
/**
 * vector<string> Forum::leggiRisposte(int numGruppo, int numDomanda)
 * Legge le risposte relative alla domanda numDomanda del gruppo di indice 
 * numGruppo, e le restituisce in un vettore di stringhe
 */
 
vector<string> Forum::leggiRisposte(int numGruppo, int numDomanda)
{
 return _gruppi[numGruppo] -> leggiRisposte(numDomanda);   
}

//############################################################

/**
 * vector<string> Forum::leggiElencoDomande(int* numGruppo)
 * Legge le domande poste in un gruppo e le restituisce in un vettore
 * di stringhe
 */
 
vector<string> Forum::leggiElencoDomande(int* numGruppo)
{
 return _gruppi[*numGruppo] -> leggiDomande();
}

//############################################################
/**
 * void Forum::creaGruppo(string nome)
 * Crea un nuovo gruppo vuoto con il nome passato come argomento
 */
 
void Forum::creaGruppo(string nome) 
{ 
 ifstream fileGrp;
 int i = 0;
 int maxI;
 bool flag;

//controlla che non si stia creando un nome di un gruppo già esistente
//se si annulla l'operazione
 vector <string> gruppi = leggiElencoGruppi();
 maxI =  gruppi.size();
 flag = 0;
 for (i = 0; i < maxI; i++)
   {
    if (nome == gruppi[i])
      {
       flag = 1;
       i =  maxI; //per uscire dal for
      }
   }
if (flag == 1)
   {
    cout << "Il nome scelto e' gia' esistente: ripetere l'operazione con altro nome" << endl;
    system("PAUSE");
   }
else
   {
    GruppoDiscussione* newGruppo = new GruppoDiscussione(nome);
    _gruppi.push_back(newGruppo); //inserisce il nuovo gruppo nel vettore 
   }
}
//############################################################

/**
 * vector<string> Forum::leggiElencoGruppi()
 * Restituisce un vettore contenente i nomi dei gruppi di discussione
 */
 
vector<string> Forum::leggiElencoGruppi()
{
  int _maxI;
  int i;
  
  vector<string> risultato;
  _maxI = _gruppi.size();  
  if (_maxI != 0)
  {
  for (i = 0; i < _maxI; i = i + 1)
   {      
   risultato.push_back(_gruppi[i] -> leggiNome());
   }
  }
  return risultato;     
}

//############################################################
/**
 * string Forum::leggiNomeGruppo(int numGruppo)
 * Restituisce il nome del gruppo di discussione di indice numGruppo
 */
string Forum::leggiNomeGruppo(int numGruppo)
{
 return _gruppi[numGruppo] -> leggiNome();
}

//############################################################


