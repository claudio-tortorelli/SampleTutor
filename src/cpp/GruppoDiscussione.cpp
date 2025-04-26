/*************************************************
* GRUPPODISCUSSIONE.CPP 												 *
*************************************************/

#include "GruppoDiscussione.h"

/**
 * GruppoDiscussione::GruppoDiscussione()
 * Costruttore
 */
 
GruppoDiscussione::GruppoDiscussione()
{
}

//############################################################
/**
 * GruppoDiscussione::GruppoDiscussione(string nome)
 * Costruttore
 */

GruppoDiscussione::GruppoDiscussione(string nome)
: _nome(nome)
{   
   _numDomande = 0; //numero domande nel gruppo   
}

//############################################

/**
 * GruppoDiscussione::~GruppoDiscussione()
 * Distruttore
 */

GruppoDiscussione::~GruppoDiscussione()
{
 
 int maxDom = getNumeroDomande();
 int maxRis;
 int i,j,dim;
 
 string nomeFile = leggiNome() + ".tut";
 const char* nomeInChar = nomeFile.c_str();
 
 if (maxDom != -1)
  {   
   ofstream fileGrp(nomeInChar,ios::in | ios::out | ios:: trunc);
   for (i = 0; i < maxDom; i++)
 	{
     maxRis = getNumeroRisposte(i);     			     			          
     if (maxRis != -1)
      {
   	   for (j = 0; j < maxRis; j++)   
       	{
       	 if ((j == maxRis-1) && (i == maxDom-1))//serve a non andare a capo in fondo
       	  {fileGrp << leggiMessaggio(i,j);}
         else
     	  {fileGrp << leggiMessaggio(i,j) << endl;}
  	 	}
      }                    	 		       	
 	}
   fileGrp.close();	
  }
 else
  {
   remove (nomeInChar); 
  }  
}


//############################################################
/**
 * void GruppoDiscussione::poniRisposta(int numDom, string risposta)
 * Metodo per aggiungere una risposta alla domanda di indice numDom
 */

void GruppoDiscussione::poniRisposta(int numDom, string risposta)
{
 inserisciRisposta(risposta, numDom);
}

//############################################################
/**
 * vector<string> GruppoDiscussione::leggiDomande()
 * Metodo che restituisce un vettore di stringhe contenenti le domande poste
 * nel gruppo di discussione
 */

vector<string> GruppoDiscussione::leggiDomande()
{
 vector<string> domande;
 
 int i; //variabili ausiliarie
 string msg;
 
 for (i = 0; i < _numDomande; i++)
   {            
    msg = this -> leggiMessaggio(i,0);         
    domande.push_back(msg.substr(1, msg.length()));
   }  
 return domande;
}

//############################################################
/**
 * void GruppoDiscussione::poniDomanda(string domanda)
 * Metodo per aggiungere una domanda al gruppo di discussione
 */

void GruppoDiscussione::poniDomanda(string domanda)
{
 inserisciDomanda(Messaggio (domanda));
}

//############################################################
/**
 * vector<string> GruppoDiscussione::leggiRisposte(int numDom)
 * Metodo che restituisce un vettore di stringhe contenenti le risposte date
 * alla domanda di indice numDom
 */

vector<string> GruppoDiscussione::leggiRisposte(int numDom)
{
 vector<string> risposte;
 int maxJ, j; //variabili ausiliarie
 string msg;
 
 maxJ = (this -> getNumeroRisposte(numDom)); //massimo indice di una domanda nella struttura
 for (j = 1; j < maxJ; j++) //ordine cronologico
   {            
    risposte.push_back(leggiMessaggio(numDom, j));
   }  
 return risposte;
}


//############################################################
/**
 * int GruppoDiscussione::getNumeroDomande() const
 * Restituisce il valore del campo _numDomande
 */

int GruppoDiscussione::getNumeroDomande() const
{
   return _numDomande;
}

//############################################################
/**
 * int GruppoDiscussione::getNumeroRisposte(int i) const
 * Restituisce il numero di risposte per la domanda di indice i
 */

int GruppoDiscussione::getNumeroRisposte(int i) const
{  
 return _messaggi[i].size();
}

//############################################################
/**
 * void GruppoDiscussione::inserisciDomanda(Messaggio _nuovoMessaggio) 
 * Inserisce una nuova domanda nel gruppo di discussione
 */

void GruppoDiscussione::inserisciDomanda(Messaggio _nuovoMessaggio) 
{
   _messaggi.resize(_messaggi.size() + 1); //aggiunge 1 vector a _messaggi
   _messaggi[_numDomande].push_back(_nuovoMessaggio); //inserisce la domanda
   _numDomande = _numDomande + 1; //aggiorna le variabili indice   
}   
//############################################################
/**
 * void GruppoDiscussione::inserisciRisposta(Messaggio _nuovoMessaggio, int _numDom) 
 * Inserisce una nuova risposta per la domanda di indice _numDom
 */

void GruppoDiscussione::inserisciRisposta(Messaggio _nuovoMessaggio, int _numDom) 
{
   _messaggi[_numDom].push_back(_nuovoMessaggio);                         
}

//############################################################
/**
 * string GruppoDiscussione::leggiMessaggio(int i, int j)
 * Legge il messaggio di indice (i,j)
 */

string GruppoDiscussione::leggiMessaggio(int i, int j)
{ 
 return _messaggi[i][j].leggiTesto();
}

//############################################################
/**
 * string GruppoDiscussione::leggiNome() const 
 * Restituisce il valore del campo _nome
 */

string GruppoDiscussione::leggiNome() const 
{
 return _nome;
}
//############################################################
/**
 * void GruppoDiscussione::caricaFile(char* nomeFile)
 * Legge i messaggi di un gruppo di discussione dal file corrispondente
 */

void GruppoDiscussione::caricaFile(char* nomeFile)
{
  ifstream _fileIn;
  int _numDom; //conta il numero di domande inserite in ogni gruppo
  string _bufferIn;
  
    _fileIn.open(nomeFile); //apre lo stream al file
    if (!_fileIn) //non è riuscito ad aprire
        {
        cout << "Ho incontrato problemi nell'apertura del file";        
        system("PAUSE");
        }
    else //apertura regolare
       { 
       if (_fileIn.peek() != EOF)//controlla se il file è non inizializzato
          {
          _numDom = -1;                   
          while (!_fileIn.eof())//lo legge fino alla fine
              {                                  
              getline(_fileIn,_bufferIn); //legge una riga=nome di un file gruppo                                                         
              Messaggio _nuovoMessaggio (_bufferIn);
              if (_bufferIn[0] == '?')
                {_numDom = _numDom + 1;
                 inserisciDomanda(_nuovoMessaggio);
                }
              else
                {inserisciRisposta(_nuovoMessaggio, _numDom);}               
              }       
          }
       }
    _fileIn.close(); //chiude lo stream   
}

//############################################################
/**
 * void GruppoDiscussione::setNumeroDomande(int i)
 * Cambia il valore del campo _numDomande
 */

void GruppoDiscussione::setNumeroDomande(int i)
{
 _numDomande = i;
}
