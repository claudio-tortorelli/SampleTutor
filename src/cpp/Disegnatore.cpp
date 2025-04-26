/*************************************************
* DISEGNATORE.CPP	      												 *
*************************************************/

#include "Disegnatore.h"

/**
 * Disegnatore::Disegnatore()
 * Costruttore
 */
 
Disegnatore::Disegnatore()
{
}

//#######################################################
/**
 * void Disegnatore::statusbar(string s)
 * Disegna la statusbar in fondo allo schermo e avvisa l'utente con la stringa s
 */

void Disegnatore::statusbar(string s)
{
 textcolor(15); textbackground(3);
 gotoxy(1,25);
 cout << "                                                                               ";
 gotoxy(1,25);
 cout << s;
}

//#######################################################
/**
 * void Disegnatore::opzione(string s, int n, int id, int lb)
 * metodo privato, usato per evidenziare una opzione
 */

void Disegnatore::opzione(string s, int n, int id, int lb)
{
 //pulisce la riga
 textbackground(9); //textcolor(15);
 gotoxy(10,7+((id-lb)*2));
 cout << "                                                                       ";
 //scrive l'opzione, evidenziata se n==id
 if (n == id) {textcolor(9); textbackground(15);}
  else {textcolor(15); textbackground(9);}
 gotoxy(10,7+((id-lb)*2));
 
 if (s.size() > 60)
 { s = s.substr(0,60) + "...\n\0"; }
 
 cout << s;
}

//#######################################################
/**
 * void Disegnatore::pulisci()
 * Metodo per cancellare la parte dello schermo dove avviene l'interazione
 * fra utente e applicazione
 */

void Disegnatore::pulisci()
{
 textcolor(15); textbackground(9); 
 int i;
 gotoxy(1,5);
 for (i=0; i<20; i++) 
  cout << "                                                                                \0";
 gotoxy(1,6);
}

//#######################################################
/**
 * int Disegnatore::scegli(vector<string> opzioni, string messaggio)
 * Metodo che permette all'utente di scegliere con i tasti cursore fra un
 * insieme di stringhe; viene restituito l'indice dell'opzione scelta
 */

int Disegnatore::scegli(vector<string> opzioni, string messaggio)
{
  pulisci();
  int i;
  char ch1 = '\0'; //carattere da leggere da tastiera
  int n = 0; //indice della opzione evidenziata
  int maxop = (opzioni.size() - 1); //massimmo indice di un'opzione
  int lb = 0; int ub = 8; //limiti inferiore e superiore
  if (maxop < ub) ub = maxop;
  while ((ch1 != 13) && (ch1 != 27)) //si sceglie con <INVIO>
    {
     if (messaggio != "") statusbar(messaggio);
     else statusbar("Scegli un'opzione con i tasti cursore e premi <INVIO>. <ESC> per uscire");
     //aggiorna n a seconda del tasto premuto in precedenza
     if ((ch1 == 72) && (n > 0)) n--;
     if ((ch1 == 80) && (n < maxop)) n++;

     //mostra le voci del menu
     for (i = lb; i<=ub; i++)
     opzione(opzioni[i],n,i,lb);

     //aspetta la pressione di un tasto, e aggiorna le variabili per la gestione del menu
     ch1 = getch();
     if ((ch1 == -32) || (ch1 == 0)) ch1 = getch();
     if (maxop > 8)
     {
      if ((ch1 == 80) && (n == ub) && (n < maxop)) {lb++; ub++;}
      if ((ch1 == 72) && (n == lb) && (n > 0)) {lb--;  ub--;}
     }
     //premendo il tasto <ESC>, si annulla la scelta
     if (ch1 == 27) n = -1;

    }
    //clrscr();
  return n;
}

//#######################################################
/**
 * void Disegnatore::visualizzaDatiUtente(vector<string> info)
 * Metodo per visualizzare a schermo i dati di un utente, passati in un vettore
 * di stringhe
 */

void Disegnatore::visualizzaDatiUtente(vector<string> info)
{
 int max = info.size() - 1;
 int i;
 pulisci();  
 gotoxy(4,6);	
 cout << "Nome: " << info[0] << endl;
 gotoxy(4,7);
 cout << "Cognome: " << info[1] << endl;
 gotoxy(4,8);
 cout << "Email: " << info[2] << endl;
 gotoxy(4,9);
 cout << "Login: " << info[3] << endl;
 gotoxy(4,10);
 cout << "Password: " << info[4] << endl;
 gotoxy(4,13);	
 statusbar("Premere un tasto per tornare al menu'");
 getch();	
}
//#######################################################
/**
 * void Disegnatore::disegnaInterfaccia(string firma)
 * Metodo che disegna l'interfaccia principale dell'applicazione
 */

void Disegnatore::disegnaInterfaccia(string firma)
{
  textcolor(14); textbackground(9);
  clrscr();

  int i;
  cout << " * * Sistema di Tutoraggio Studenti di Claudio Tortorelli e Dario Di Minno * *";
  cout << "\n\n";
  int l = (61 - firma.length())/2;
  gotoxy(l, 3); cout << "[Utente Corrente: " + firma + "]\n";
  for (i=0; i<80; i++) cout << "_";
}

//#######################################################
/**
 * void Disegnatore::mostraTesto(string testo)
 * Metodo che pulisce lo schermo e mostra una stringa
 */

void Disegnatore::mostraTesto(string testo)
{
 pulisci();
 cout << testo;
 cout << "\n";
}

//#######################################################
/**
 * void Disegnatore::mostraStringhe(vector<string> stringhe)
 * Metodo che pulisce lo schermo e mostra un insieme di stringhe
 */

void Disegnatore::mostraStringhe(vector<string> stringhe)
{
 statusbar("Premere un tasto per continuare...");
 pulisci();
 for (int i=0; i<stringhe.size(); i++)
 {
  if ((wherey() + (stringhe[i].length()/80)) > 23)
   {    
    getch();
    pulisci();
   } 
  cout << i << ". " << stringhe[i];
  cout << "\n\n";
 } 
}

//#######################################################
/**
 * vector<string> Disegnatore::riempiForm(vector<string> richieste)
 * Metodo per il riempimento di un form. Vengono poste delle richieste (passate
 * come parametro di ingresso) e viene restituito un vettore di stringhe 
 * contenente le risposte
 */

vector<string> Disegnatore::riempiForm(vector<string> richieste)
{
 int i = 0; int j = 0;
 vector<string> info;
 string bufferIn;
 

 statusbar("La stringa vuota non e' ammessa e gli spazi vengono cambiati in '_'");
 pulisci();
 for (i=0; i<richieste.size(); i++)
 {bufferIn = "\0";
   while (bufferIn == "\0")
   {
    gotoxy(4,6+(i*2));
    cout << richieste[i];
    getline(cin, bufferIn);
    for (j=0; j<bufferIn.length(); j++)
     if (bufferIn[j] == ' ') bufferIn[j] = '_';
    info.push_back(bufferIn);
   }
 }  
 return info; 
}

