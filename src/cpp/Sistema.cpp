/*************************************************
* SISTEMA.CPP																		 *
*************************************************/

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <typeinfo>
#include "Sistema.h"

/**
 * Sistema::Sistema()
 * Costruttore
 */
 
Sistema::Sistema()
{
 _disegnatore = new Disegnatore;
 _listaUtenti = new ListaUtentiForum;
 _forumSistema = new Forum;
 _menuSistema = new Menu;
}

//##################################################

/**
 * Sistema::~Sistema()
 * Distruttore
 */

Sistema::~Sistema()
{
 delete(_disegnatore);
 delete(_listaUtenti);
 delete(_forumSistema);
 delete(_menuSistema);
}

//##################################################
/**
 * int main()
 * Metodo dal quale parte e termina la computazione. Crea un oggetto di tipo
 * Sistema, chiamato tutoraggio, che si occuperà di riconoscere un utente. 
 * Se viene riconosciuto un utente valido, il sistema si preoccupa di caricare
 * i gruppi da file ed avviare il menù
 */

int main()
{
  clrscr();
  //nel seguente modo, alla fine devo distruggere l'oggetto con delete(Sistema)
  //che chiama il distruttore ~Sistema
  Sistema* tutoraggio = new Sistema;
  
  //nel seguente modo, il compilatore provvede alla distruzione dell'oggetto 
  //quando va fuori dall'area di visibiltà
  //Sistema tutoraggio1;
  if (tutoraggio -> accediSistema())
    {
     tutoraggio -> caricaGruppi();
     tutoraggio -> avviaMenu();
    }
  tutoraggio -> uscita();
  delete(tutoraggio);
  return 0;
}

//############################################################

/**
 * void Sistema::accediSistema()
 * Metodo che si preoccupa del riconoscimento di un utente. Se il sistema
 * non possiede alcun utente, ne viene creato uno con dati di default.
 * Se viene riconosciuto un utente valido, crea anche un menu' idoneo.
 */

bool Sistema::accediSistema()
{
  bool riconosciuto = false;
  string  _nomeUtente;

  int  _numeroUtente;
  vector<string> _utenteTrovato;

  string login, password;
 
  clrscr();

   //se non eistono utenti nel file, viene creato un amministratore
   //con dati di default
   if (_listaUtenti -> fileUtentiVuoto()) 
   {
    _utenteTrovato = creaPrimoUtente();
   }
   else
   {
	gotoxy(3,3);
	textcolor(14);
	textbackground(9);
	printf ("PROCEDURA DI ACCESSO AL SISTEMA: RICONOSCIMENTO UTENTE");
	gotoxy(3,4);
	cout << "------------------------------------------------------\n" ;
	while (login == "")
		{
		gotoxy(3,6);
  	cout << "Immettere il proprio login: \n";
  	gotoxy(3,7);
    getline(cin, login);
    }
  while (password == "")
  	{
    gotoxy(3,9);
    cout << "Immettere la propria password: \n";
    gotoxy(3,10);
    getline(cin, password);    
    }
  
    _utenteTrovato = _listaUtenti -> leggiFileUtenti(login, password);    
   }

   // se utenteTrovato.size != 0 allora l'utente non è stato trovato 
  if (_utenteTrovato.size() != 0)
     {
       if (_utenteTrovato[5] == "UTENTE")
         {
          _menuSistema = new MenuUtente(_forumSistema, _disegnatore , _listaUtenti);
         _utenteSistema = _listaUtenti -> getUtenteCorrente();             
         }
       if (_utenteTrovato[5] == "TUTOR")
         {
          _menuSistema = new MenuTutor(_forumSistema, _disegnatore , _listaUtenti);
          _utenteSistema = _listaUtenti -> getUtenteCorrente();
         }
       if (_utenteTrovato[5] == "AMMINISTRATORE")
         {
         _menuSistema = new MenuAmministratore(_forumSistema, _disegnatore , _listaUtenti);
         _utenteSistema = _listaUtenti -> getUtenteCorrente();
         }
       textcolor(10);
	   textbackground(0);
	   gotoxy(3,12);
	   cout << "Utente riconosciuto.";
	   gotoxy(3,14);	  	  
	   cout << "Benvenuto " << _utenteTrovato[0] << "!";
	   gotoxy(3,16);
	   system("PAUSE");	
	   riconosciuto = true;
     }  
  //controllo tra gli utenti registrati:
  //è in fase di registrazione che va garantita l'unicità
  //della password e login
  else
  	{	//utente non trovato  
      textcolor(12);
	  textbackground(0);
	  gotoxy(3,12);
	  cout << "Utente sconosciuto.";
	  gotoxy(3,14);
	  printf("Registrarsi o verificare la correttezza dei dati immessi\n");
	  gotoxy(3,16);
	  system("PAUSE");	
  	}
  return riconosciuto;
 }

//############################################## 

/**
 * void Sistema::avviaMenu()
 * Metodo che fa avviare il menu, personalizzato con la firma dell'utente corrente
 */

void Sistema::avviaMenu()
{
 _menuSistema -> start(_listaUtenti -> leggiFirmaUtente());    	 	
}

//############################################## 

/**
 * void Sistema::caricaGruppi()
 * Metodo che fa caricare i gruppi di discussione al forum
 */

void Sistema::caricaGruppi()
{
	_forumSistema -> leggiGruppiDaFile(); 
}

//############################################## 

/**
 * void Sistema::uscita()
 * Terminazione del programma
 */

void Sistema::uscita()
{
  textbackground(0); textcolor(7);
  system("CLS");
  cout << "Grazie per averci scelto :)\n";
  getch();
}
//############################################## 

/**
 * vector<string> Sistema::creaPrimoUtente()
 * Metodo che crea un utente di default come primo utente del sistema.
 */

vector<string> Sistema::creaPrimoUtente()
{
 cout << "Non ci sono attualmente utenti del sistema\n";
 cout << "Provvedo a creare il primo utente con login \"root\" e password \"root\"\n";
 vector<string> infoDefault;
 infoDefault.push_back("root");
 infoDefault.push_back("root");
 infoDefault.push_back("email"); 
 infoDefault.push_back("root");
 infoDefault.push_back("root"); 
 infoDefault.push_back("AMMINISTRATORE"); 
 _listaUtenti -> iscriviUtente(infoDefault);
 return infoDefault;
}

