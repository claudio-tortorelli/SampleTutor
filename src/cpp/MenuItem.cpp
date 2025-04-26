/*************************************************
* MENUITEM.CPP																	 *
*************************************************/

#include "MenuItem.h"

/**
 * Costruttore vuoto
 */

MenuItem::MenuItem()
{
}

//############################################################

/**
  * Costruttore
 */

MenuItem::MenuItem(string testo, Disegnatore* d)
: _testo(testo),
  _disegnatore(d)
{
}

//############################################################

/**
 * Distruttore
 */

MenuItem::~MenuItem()
{
 int i;
 for(i=0; i< _comandi.size(); i++) delete(_comandi[i]);
}

//############################################################

/**
 * MenuItem::clicked()
 * Metodo che fa scattare l'esecuzione di un comando o di una 
 * sequenza di comandi in seguito alla scelta di una voce del menu
 */

void MenuItem::clicked()
{
 int _dim = _comandi.size();
 int _i;
 for (_i = 0; _i < _dim; _i = _i + 1)
   {
    _comandi[_i] -> execute();
   }
}

//############################################################

/**
 * MenuItem::leggiTesto()
 * Metodo accessore che restituisce il valore del campo _testo
 */

string MenuItem::leggiTesto() const 
{
 return _testo;
}

//############################################################

/**
 * MenuItem::addCommand()
 * Metodo che permette di aggiungere un comando al 
 * vettore di comandi di MenuItem
 */

void MenuItem::addCommand(Command* c)
{
 _comandi.push_back(c);
}

