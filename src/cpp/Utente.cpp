/*************************************************
* UTENTE.CPP																		 *
*************************************************/

#include "Utente.h"

/** 
 * Utente::Utente()
 * Costruttore
 */

Utente::Utente()
{
}
//#############################################
/** 
 * Utente::Utente(string nome, string cognome, string email, string login, string password)
 * Costruttore
 */

Utente::Utente(string nome, string cognome, string email, string login, string password)
: _nome(nome),
	_cognome(cognome),
  _email(email),
  _login(login),
  _password(password)   
{
}
//#############################################

/** 
 * string Utente::leggiNome() const
 * Metodo accessore
 */

string Utente::leggiNome() const {return _nome;}
//#############################################

/** 
 * string Utente::leggiNome() const
 * Metodo accessore
 */

string Utente::leggiCognome() const {return _cognome;}

//#############################################

/** 
 * string Utente::leggiNome() const
 * Metodo accessore
 */

string Utente::leggiEmail() const {return _email;}

//#############################################

/** 
 * string Utente::leggiNome() const
 * Metodo accessore
 */

string Utente::leggiLogin() const {return _login;}

//#############################################

/** 
 * string Utente::leggiNome() const
 * Metodo accessore
 */

string Utente::leggiPassword() const {return _password;}

//#############################################

/** 
 * vector<string> Utente::tuttiIDati() const
 * Restituisce i dati dell'utente nel modo in cui vengono memorizzati su file
 */

vector <string> Utente::tuttiIDati() const
{
	vector <string> dati;
	dati.push_back(leggiNome());
	dati.push_back(leggiCognome());
	dati.push_back(leggiEmail());
	dati.push_back(leggiLogin());
	dati.push_back(leggiPassword());
	dati.push_back("UTENTE");
	return (dati);
}

//#############################################

/** 
 * vector<string> Utente::leggiGruppiAssociati() const
 * Restituisce i gruppi associati, che per un utente e' un insieme vuoto
 */

vector <string> Utente::leggiGruppiAssociati() const
{ 
 vector <string> vuoto;
 return vuoto;
}
//#############################################

/** 
 * void Utente::cambiaNome(string nuovoNome)
 * Metodo mutatore
 */

void Utente::cambiaNome(string nuovoNome)
{
	_nome = nuovoNome;
}
//#############################################

/** 
 * void Utente::cambiaCognome(string nuovoCognome)
 * Metodo mutatore
 */

void Utente::cambiaCognome(string nuovoCognome)
{
	_cognome = nuovoCognome;
}
//#############################################

/** 
 * void Utente::cambiaEmail(string nuovaEmail)
 * Metodo mutatore
 */

void Utente::cambiaEmail(string nuovaEmail)
{
	_email = nuovaEmail;
}
//#############################################

/** 
 * void Utente::cambiaLog(string nuovoLog)
 * Metodo mutatore
 */

void Utente::cambiaLog(string nuovoLog)
{
	_login = nuovoLog;
}

//#############################################

/** 
 * void Utente::cambiaPw()
 * Metodo mutatore
 */

void Utente::cambiaPw(string nuovaPw)
{
	_password = nuovaPw;
}
