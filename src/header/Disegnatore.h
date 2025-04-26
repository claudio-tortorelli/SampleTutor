/******************************************
* DISEGNATORE.H                           *
*******************************************/

#ifndef DISEGNATORE_H
#define DISEGNATORE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream.h>
#include <string>
#include <vector>

using namespace std;

class Disegnatore
{
public:
    //costruttore
    Disegnatore();

    //metodi
    int scegli(vector<string> opzioni, string messaggio);
    void pulisci();
    void disegnaInterfaccia(string firma);
    void visualizzaDatiUtente(vector<string> info);
    void mostraTesto(string testo);
    void statusbar(string s);
    void mostraStringhe(vector<string>);
    vector<string> riempiForm(vector<string>);

private:
    void opzione(string s, int n, int id, int lb);
};

#endif


