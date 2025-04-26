/*************************************************
* AMMINISTRATORE.CPP														 *
*************************************************/

#include "Amministratore.h"

/** 
 * Amministratore::Amministratore(string nome, string cognome, string email, string login, string password, vector <string> gruppiAssociati)
 * Costruttore
 */

Amministratore::Amministratore(string nome, string cognome, string email, string login, string password, vector <string> gruppiAssociati)
:Tutor(nome, cognome, email, login, password, gruppiAssociati)
{
}

//##################################################

/** 
 * Amministratore::Amministratore(string nome, string cognome, string email, string login, string password)
 * Costruttore
 */

Amministratore::Amministratore(string nome, string cognome, string email, string login, string password)
:Tutor(nome, cognome, email, login, password)
{
}

//##################################################

/** 
 * vector<string> Amministratore::tuttiIDati() const
 * Restituisce i dati dell'utente nel modo in cui vengono memorizzati su file
 */

vector <string> Amministratore::tuttiIDati() const
{
	vector <string> dati;
	dati.push_back(leggiNome());
	dati.push_back(leggiCognome());
	dati.push_back(leggiEmail());
	dati.push_back(leggiLogin());
	dati.push_back(leggiPassword());
	dati.push_back("AMMINISTRATORE"); //serve per salvare questi dati su file in modo corretto
	return (dati);
}
//#############################################

