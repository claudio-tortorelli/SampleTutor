/******************************************
* MENUITEM.H                    					*
*******************************************/

#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
#include <vector>
#include "Command.h"
#include "Disegnatore.h"

using namespace std;

class MenuItem
{
public:
    //costruttori
    MenuItem();
    MenuItem(string testo, Disegnatore* d);

    //distruttore
    ~MenuItem();

    //metodi mutuatori
    void addCommand(Command* c);

	//metodi accessori
    string leggiTesto() const;
    void clicked();

private:
    //campi
    string _testo;   //voce del menu visualizzata sullo schermo
    vector <Command*> _comandi; //vector di comandi da eseguire
    Disegnatore* _disegnatore; //puntatore al disegnatore esterno
};

#endif
