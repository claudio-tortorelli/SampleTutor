/******************************************
* MESSAGGIO.H					                    *
*******************************************/

#ifndef MESSAGGIO_H
#define MESSAGGIO_H

#include <string>
#include <vector>

using namespace std;

class Messaggio
{
public:
    //costruttore
    Messaggio(string testo);

    //metodi accessori
    string leggiTesto();

private:
    string _testo; //è il contenuto del messaggio
};

#endif

