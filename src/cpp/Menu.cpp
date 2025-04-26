/*************************************************
* MENU.CPP																			 *
*************************************************/

#include "Menu.h"

/**
 * Costruttore vuoto
 */

Menu::Menu()
{
}

//#######################################################

/**
 * Costruttore
 */

Menu::Menu(Forum* f, Disegnatore* d, ListaUtentiForum* l)
{
  _puntDis = d;
}

//#######################################################

/**
  * Distruttore
 */

Menu::~Menu(void)
{
 int i;
 for(i=0; i< _voci.size(); i++) delete(_voci[i]);
}

//#######################################################

/**
 * Menu::start()
 * Metodo che fa partire e mantiene attivo il menu
 * fino alla fine dell'interazione dell'utente
 * con l'applicazione
 */

void Menu::start(string firma)
{
  int i; int s = 0;
  //_firma = firma; //togli
  _puntDis -> disegnaInterfaccia(firma);

  //mostra le voci del menu tra le quali scegliere
  vector<string> scelte;
  for (i=0; i<_voci.size(); i++) scelte.push_back(_voci[i] -> leggiTesto());

  //se la scelta non e' <esc> richiama la clicked della voce selezionata
  while(s != -1)
  {
   s = _puntDis -> scegli(scelte,"");
   if (s != -1) _voci[s] -> clicked();
  }
}

//#######################################################

/**
 * Menu::add()
 * Metodo che permette di aggiungere una voce (MenuItem) al menu
 */

void Menu::add(MenuItem* s)
{
 _voci.push_back(s);
}

//#######################################################
