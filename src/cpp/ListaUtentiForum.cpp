/*************************************************
* LISTAUTENTIFORUM.CPP													 *
*************************************************/

#include "ListaUtentiForum.h"

/** 
 * ListaUtentiForum::ListaUtentiForum()
 * Costruttore
 */
 
ListaUtentiForum::ListaUtentiForum()
{
 _numUtenteSistema = 0;
}
//##############################################

/** 
 * ListaUtentiForum::~ListaUtentiForum()
 * Distruttore
 */

ListaUtentiForum::~ListaUtentiForum()
{
	//solo se _utenti !=0 altrimenti non deve rimuovere nulla
	if (_utenti.size() != 0)
   { 
	  vector <string> dati, gruppi;
    int numUtenti = numeroUtenti();
    int i,j, k,maxGruppi,d;
    
	  cout << endl <<"Salvataggio modifiche file utenti...\n"; 
	  ofstream fileUte("utenti.ute", ios::in | ios::out | ios::trunc);
	  ofstream fileTut("gruppitutor.ute", ios::in | ios::out | ios::trunc);
	  ofstream fileAmm("gruppiamm.ute", ios::in | ios::out | ios::trunc);

	  for (i = 0; i < numUtenti; i++)
	 	  {
	 	   dati = _utenti[i] -> tuttiIDati();
	 	   for (j = 0; j < 6; j++)
	 	 	  {
	 	 	 	  if (j == 5 && (i == numUtenti - 1))  //l'ultimo inserimento non deve andare accapo
         		{fileUte << setfill('_') << dati[j];}	 	 		         	  
      	  else 
         		{fileUte << setfill('_') << dati[j] << endl;}       		
	 	 	  }
	 	 	  
 	       fileUte << setfill(' ');
 	       
 	 	   if (dati[5] == "TUTOR")
 	 	 	  {	 	 	    
	 	 	    gruppi = _utenti[i] -> leggiGruppiAssociati();
	 	 	    maxGruppi = gruppi.size();	 	 	   
	 	 	    if (maxGruppi != 0)//ha gruppi associati?
	 	 	  	  {
	 	 	  	   fileTut << dati[3] << endl; //inserisce log	
	 	 	  	   for (k = 0; k < maxGruppi; k++) //inserisce i gruppi
	 	 	  	    {   	 	  	     
	 	 	  		   fileTut << gruppi[k] << endl;
 	 	  		    }
             if (i == numUtenti - 1)  //l'ultimo inserimento non deve andare accapo
       		    {fileTut << "*";}	 	 		         	  
     		     else 
   		        {fileTut << "*" << endl;} 		        		        
  		      } 		         		      
        }
		   if (dati[5] == "AMMINISTRATORE")
 	 	 	  {	 	 	    
	 	 	    gruppi = _utenti[i] -> leggiGruppiAssociati();
	 	 	    maxGruppi = gruppi.size();	 	 	    	 	 	    
	 	 	    if (maxGruppi != 0)//ha gruppi associati?
	 	 	  	  { 	 	  	  
	 	 	  	   fileAmm << dati[3] << endl; //inserisce log	
	 	 	  	   for (k = 0; k < maxGruppi; k++) //inserisce i gruppi
 	 	  	      {  	       
	 	 	  		   fileAmm << gruppi[k] << endl;
	 	 	  	    } 	 	  	    
 	 	  	     if (i == numUtenti - 1)  //l'ultimo inserimento non deve andare accapo
 	  	        {fileAmm << "*";}	 	 		         	  
  	         else 
         		  {fileAmm << "*" << endl;}             
       		  }       		  
 	 		  }
 	 		 delete _utenti[i]; //elimina il puntatore a utente salvato 
		  }	 
	  fileUte.close();
	  fileTut.close();
	  fileAmm.close();	  
	 }
}
//#######################################

/** 
 * vector < string > ListaUtentiForum::leggiFileUtenti(string login, string password) 
 * Metodo che legge il file degli utenti, e restituisce le informazioni relative
 * all'utente di cui si passano login e password.
 */

vector < string > ListaUtentiForum::leggiFileUtenti(string login, string password) 
{
 vector<string> _utenteTrovato;
 vector <string> _vettTutor, _vettAmm;
 string _bufferIn, _nome, _cognome, _email, _log, _pw, _tipo; 
 int _i = 0;
 int j;
 int maxVet;
 
 //cerca il file contenente le info sugli utenti registrati
 //lo apre e inizializza il vector in base a ciò che legge
 
 ifstream _fileTut ("gruppitutor.ute", ios::in | ios::out);      	
 if (!_fileTut.is_open()) //nel caso qualche cosa non vada...      	
  {cout << "Error opening file gruppitut.ute"; system("PAUSE");}        
 else if (_fileTut.peek() != EOF)  	
	{
   while (!_fileTut.eof())
   	{
     _fileTut >> _bufferIn;
     _vettTutor.push_back(_bufferIn);
    }    			    				
  }
 _fileTut.close();

 ifstream _fileAmm ("gruppiamm.ute", ios::in | ios::out);
 if (! _fileAmm.is_open()) //nel caso qualche cosa non vada...
 	{ cout << "Error opening file gruppiamm.ute";}
 else if (_fileAmm.peek() != EOF)  	
 	{
 	 while (!_fileAmm.eof())
   	{
     _fileAmm >> _bufferIn;
     _vettAmm.push_back(_bufferIn);
    }    			    				
  }  
 _fileAmm.close();
       	
 ifstream _fileIn ("utenti.ute", ios::in | ios::out);  //apre il file utenti        
 if (! _fileIn.is_open()) //nel caso qualche cosa non vada...
   { cout << "Error opening file utenti.ute";}  
 else if (_fileIn.peek() != EOF) 
   {               
    while (!_fileIn.eof())//lo legge fino alla fine    
     { 
      _fileIn >> _nome;      
      _fileIn >> _cognome;
      _fileIn >> _email;      
      _fileIn >> _log;
      _fileIn >> _pw;
      _fileIn >> _tipo;
      if (login == _log && password == _pw) 
        {
         _utenteTrovato.push_back(_nome);
         _utenteTrovato.push_back(_cognome);
         _utenteTrovato.push_back(_email);
         _utenteTrovato.push_back(_log);
         _utenteTrovato.push_back(_pw);
         _utenteTrovato.push_back(_tipo);            
         _numUtenteSistema = _i;               
        }                                   
      _i++; 
      
      if (_tipo == "UTENTE")
   	   {           	  
   	    add(new Utente(_nome, _cognome, _email, _log, _pw));
   	   }
   	   
      if (_tipo == "TUTOR") //legge i gruppi associati prima di crearlo
       {
       	j = 0;
       	vector <string> _gruppiAssociati;    
       	if (_vettTutor.size() != 0) //se ci sono gruppi associati
       	{
       	 maxVet = _vettTutor.size() - 1;
         while (_log != _vettTutor[j] && j < maxVet)//scandisce il vettore
          {j++;}
         if (j < maxVet)              
          {
           j++;
           while (_vettTutor[j] != "*")         		  
         	  {
             _gruppiAssociati.push_back(_vettTutor[j]);
             j++;
            }
          }
        }  
        Tutor* newTutor = new Tutor(_nome, _cognome, _email, _log, _pw, _gruppiAssociati);
        add(newTutor);
        addTutor(newTutor);    	         		        
   	   }

     	if (_tipo == "AMMINISTRATORE") //legge i gruppi associati prima di crearlo
       {
       	j = 0;
       	vector <string> _gruppiAssociati;           	
       	if (_vettAmm.size() != 0)
       	{
         maxVet = _vettAmm.size() - 1;
         while (_log != _vettAmm[j] && j < maxVet)//scandisce il vettore
          {j++;}        
         if (j < maxVet)               
          {
           j++;
           while (_vettAmm[j] != "*")         		  
          	 {
             _gruppiAssociati.push_back(_vettAmm[j]);
             j++;
            }
          }
        }    
        Amministratore* newAmm = new Amministratore(_nome, _cognome, _email, _log, _pw, _gruppiAssociati);
        add(newAmm);
        addTutor(newAmm);
   	   }
     }//WHILE          
   } //elseif        
 _fileIn.close();	
      
 return _utenteTrovato;
}
//################################################

/** 
 * vector < string > ListaUtentiForum::leggiDatiUtente(int num) 
 * Restituisce i dati dell'utente cosi' come sono stati letti dal file "utenti.ute"
 */

vector < string > ListaUtentiForum::leggiDatiUtente(int num) 
{
	vector < string > _datiUtente ;
	_datiUtente.push_back(_utenti[num] -> leggiNome());
	_datiUtente.push_back(_utenti[num] -> leggiCognome());
	_datiUtente.push_back(_utenti[num] -> leggiEmail());
	_datiUtente.push_back(_utenti[num] -> leggiLogin());
	_datiUtente.push_back(_utenti[num] -> leggiPassword());
	return (_datiUtente);
}
//################################################

/** 
 * string ListaUtentiForum::leggiFirmaUtente() 
 * Restituisce una stringa formata da nome e cognome dell'utente corrente
 */

string ListaUtentiForum::leggiFirmaUtente() 
{
  string firmaUtente; cout << "prima";
  firmaUtente = _utenti[_numUtenteSistema] -> leggiNome() + " " + _utenti[_numUtenteSistema] -> leggiCognome();
  return (firmaUtente); cout << "dopo"; getch();
}

//################################################

/** 
 * string ListaUtentiForum::leggiFirmaUtente(int num) 
 * Restituisce una stringa formata da nome e cognome dell'utente di indice num
 */

string ListaUtentiForum::leggiFirmaUtente(int num) 
{
  string firmaUtente;
  firmaUtente = _utenti[num] -> leggiNome() + " " + _utenti[num] -> leggiCognome();
  return (firmaUtente);
}

//################################################

/** 
 * int ListaUtentiForum::numeroUtenti()
 * Restituisce il numero degli utenti del sistema
 */

int ListaUtentiForum::numeroUtenti()
{
	return (_utenti.size());
}

//################################################

/** 
 * Utente* ListaUtentiForum::getUtenteCorrente()
 * Restituisce un puntatore all'utente corrente
 */

Utente* ListaUtentiForum::getUtenteCorrente()
{
 if (_utenti.size() != 0)
 	{return _utenti[_numUtenteSistema];}
	else return NULL;
}

//################################################

/** 
 * int ListaUtentiForum::leggiNumUtenteSistema()
 * Restituisce il numero dell'utente che sta utilizzando il sistema
 */

int ListaUtentiForum::leggiNumUtenteSistema()
{
 return _numUtenteSistema;
}

//################################################

/** 
 * void ListaUtentiForum::cambiaPwUtente(int numUtente, string newPw)
 * Cambia la password dell' utente con indice num
 */

void ListaUtentiForum::cambiaPwUtente(int numUtente, string newPw)
{
	_utenti[numUtente] -> cambiaPw(newPw);
}

//################################################

/** 
 * void ListaUtentiForum::cambiaLogUtente(int numUtente, string newLog)
 * Cambia il login dell' utente con indice num
 */

void ListaUtentiForum::cambiaLogUtente(int numUtente, string newLog)
{
	_utenti[numUtente] -> cambiaLog(newLog);
}

//################################################

/** 
 * void ListaUtentiForum::cambiaNomeUtente(int numUtente, string newNome)
 * Cambia il nome dell' utente con indice num
 */

void ListaUtentiForum::cambiaNomeUtente(int numUtente, string newNome)
{
	_utenti[numUtente] -> cambiaNome(newNome);
}

//################################################

/** 
 * void ListaUtentiForum::cambiaCognomeUtente(int numUtente, string newCognome)
 * Cambia il cognome dell' utente con indice num
 */

void ListaUtentiForum::cambiaCognomeUtente(int numUtente, string newCognome)
{
	_utenti[numUtente] -> cambiaCognome(newCognome);
}

//################################################

/** 
 * void ListaUtentiForum::cambiaEmailUtente(int numUtente, string newEmail)
 * Cambia l'email dell' utente con indice num
 */

void ListaUtentiForum::cambiaEmailUtente(int numUtente, string newEmail)
{
	_utenti[numUtente] -> cambiaEmail(newEmail);
}

//################################################

/** 
 * vector <string> ListaUtentiForum::elencoGruppiAssociati(int numUtente)
 * Restituisce l'elenco dei gruppi associati all'utente di indice num
 */

vector <string> ListaUtentiForum::elencoGruppiAssociati(int numUtente)
{
	return _utenti[numUtente]->leggiGruppiAssociati();         	  
}

//################################################

/** 
 * void ListaUtentiForum::add(Utente* u)
 * Aggiunge un puntatore a un nuovo utente alla lista degli utenti
 */

void ListaUtentiForum::add(Utente* u)
{
 _utenti.push_back(u);
}

//################################################

/** 
 * void ListaUtentiForum::addTutor(Tutor* t)
 * Aggiunge un puntatore a un nuovo tutor alla lista dei tutor
 */

void ListaUtentiForum::addTutor(Tutor* t)
{
 _listaTutor.push_back(t);
}

//################################################

/** 
 * bool ListaUtentiForum::iscriviUtente(vector<string> nuovoUtente)
 * Metodo che permette l'iscrizione di un utente
 */

bool ListaUtentiForum::iscriviUtente(vector<string> nuovoUtente)
{
 //controlla se esiste gia' un utente con la login specificata
 bool trovato = false;
 for(int i=0; i<_utenti.size(); i++)
  if (_utenti[i] -> leggiLogin() == nuovoUtente[3]) trovato = true;
 if (!trovato)
 {
     switch(nuovoUtente[5][0]) {
        case 'U': add(new Utente(nuovoUtente[0], nuovoUtente[1], nuovoUtente[2], nuovoUtente[3], nuovoUtente[4]));
        break;
        case 'T': add(new Tutor(nuovoUtente[0], nuovoUtente[1], nuovoUtente[2], nuovoUtente[3], nuovoUtente[4]));
        rinfrescaListaTutor();
        break;
        case 'A': add(new Amministratore(nuovoUtente[0], nuovoUtente[1], nuovoUtente[2], nuovoUtente[3], nuovoUtente[4]));
        rinfrescaListaTutor();
        break;   
     }
 }
 return (!trovato);
}
//################################################

/** 
 * vector<string> ListaUtentiForum::leggiFirmeTutor()
 * Restituisce nome e cognome di tutti i tutor
 */

vector<string> ListaUtentiForum::leggiFirmeTutor()
{
 vector<string> firme;
 int i;
 for(i=0; i<_listaTutor.size(); i++)
 {
  vector<string> temp = _listaTutor[i] -> tuttiIDati();
  firme.push_back(temp[0] + " " + temp[1]);
 }
 return firme;
}

//################################################

/** 
 * void ListaUtentiForum::associaGruppoTutor(string gruppo, int* numeroTutor)
 * Aggiunge a un tutor l'associazione a un gruppo
 */

void ListaUtentiForum::associaGruppoTutor(string gruppo, int* numeroTutor)
{
 _listaTutor[*numeroTutor] -> aggiungiGruppo(gruppo);
}

//################################################

/** 
 * void ListaUtentiForum::disassociaGruppoTutor(string gruppo, int* numeroTutor)
 * Toglie a un tutor l'associazione a un gruppo
 */

void ListaUtentiForum::disassociaGruppoTutor(string gruppo, int* numeroTutor)
{
 _listaTutor[*numeroTutor] -> eliminaGruppo(gruppo);
}

//################################################

/** 
 * vector<string> ListaUtentiForum::leggiGruppiTutor(int numeroTutor)
 * Restituisce i gruppi associati a un tutor
 */

vector<string> ListaUtentiForum::leggiGruppiTutor(int numeroTutor)
{
 return _listaTutor[numeroTutor] -> leggiGruppiAssociati();
}

//################################################

/** 
 * bool ListaUtentiForum::cancellaUtente(int numUtente)
 * Cancella l'utente di indice num
 */

bool ListaUtentiForum::cancellaUtente(int numUtente)
{ 
  string login = _utenti[numUtente] -> leggiLogin();
  
  //trova l'utente da cancellare e fa un delete e una pop  
  if (_utenti.size() != 0) //tutti cancellati?
    {
     int i;
     vector< Utente* > temp;  
     delete _utenti[numUtente];  
     for (i = 0; i < _utenti.size(); i++)
      {if (i != numUtente) temp.push_back(_utenti[i]);}
     _utenti = temp;
     rinfrescaListaTutor();
     return true;
    }
  else {return false;}       
}
//################################################

/** 
 * void ListaUtentiForum::rinfrescaListaTutor()
 * Aggiorna la lista dei tutor in base alla lista attuale degli utenti
 */

void ListaUtentiForum::rinfrescaListaTutor()
{
 vector< Tutor* > temp;
 for(int i=0; i<_utenti.size(); i++)
 {
  Tutor* tutorTemp = dynamic_cast<Tutor*> (_utenti[i]);
  if (tutorTemp != NULL) temp.push_back(tutorTemp);
 }
 _listaTutor = temp;
}

//################################################

/** 
 * bool ListaUtentiForum::fileUtentiVuoto()
 * Controlla se il file degli utenti e' vuoto
 */

bool ListaUtentiForum::fileUtentiVuoto()
{
 ifstream fileUt("utenti.ute");
 bool vuoto = (fileUt.peek() == EOF);
 fileUt.close();
 return vuoto;
}
 
