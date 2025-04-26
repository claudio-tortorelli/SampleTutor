/*************************************************
* MESSAGGIO.CPP																	 *
*************************************************/

#include "Messaggio.h"

/**
 * Costruttore 
 */

Messaggio::Messaggio(string testo)
: _testo(testo)
{
}

//############################################################

/**
 * string Messaggio::leggiTesto()
 * Restituisce la stringa contenuta nel messaggio
 */
 
string Messaggio::leggiTesto()
{
 return _testo;
}
