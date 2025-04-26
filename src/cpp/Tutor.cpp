/*************************************************
* TUTOR.CPP																			 *
*************************************************/

#include "Tutor.h"

/** 
 * Tutor::Tutor(string nome, string cognome, string email, string login, string password)
 * Costruttore
 */

Tutor::Tutor(string nome, string cognome, string email, string login, string password)
:Utente(nome, cognome, email, login, password)
{
}

//##################################################

/** 
 * Tutor::Tutor(string nome, string cognome, string email, string login, string password, vector <string> gruppiAssociati)
 * Costruttore
 */

Tutor::Tutor(string nome, string cognome, string email, string login, string password, vector <string> gruppiAssociati)
:Utente(nome, cognome, email, login, password)
{ 
 _gruppiAssociati = gruppiAssociati;
}
//##################################################

/** 
 * vector<string> Tutor::tuttiIDati() const
 * Restituisce i dati dell'utente nel modo in cui vengono memorizzati su file
 */

vector <string> Tutor::tuttiIDati() const
{
	vector <string> dati;
	dati.push_back(leggiNome());
	dati.push_back(leggiCognome());
	dati.push_back(leggiEmail());
	dati.push_back(leggiLogin());
	dati.push_back(leggiPassword());
	dati.push_back("TUTOR"); //serve per salvare questi dati su file in modo corretto
	return (dati);
}
//#############################################

/** 
 * vector<string> Tutor::tuttiIDati() const
 * Restituisce i gruppi associati al tutor
 */

vector <string> Tutor::leggiGruppiAssociati() const
{
 return _gruppiAssociati;
}
//#############################################

/** 
 * vector<string> Tutor::tuttiIDati() const
 * Aggiunge un'associazione tutor/gruppo
 */

void Tutor::aggiungiGruppo(string gruppo)
{
 //prima controlla se il gruppo era stato gia' aggiunto
 int i; bool trovato;
 for(i=0; i<_gruppiAssociati.size(); i++) 
  if (_gruppiAssociati[i] == gruppo) trovato = true;
 //quindi inserisce il gruppo
 if (!trovato) _gruppiAssociati.push_back(gruppo);
}
//#############################################

/** 
 * vector<string> Tutor::tuttiIDati() const
 * Elimina un'associazione tutor/gruppo
 */

void Tutor::eliminaGruppo(string gruppo)
{
 //temp e' una copia di _gruppiAssociati senza il gruppo che si vuole eliminare
 vector<string> temp;
 for(int i=0; i<_gruppiAssociati.size(); i++) 
  if (_gruppiAssociati[i] != gruppo) temp.push_back(_gruppiAssociati[i]);
 //si aggiorna _gruppiAssociati a temp
 _gruppiAssociati = temp; 
}

