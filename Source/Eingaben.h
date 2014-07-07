#include "Kasten.h"
#include "Teilchen.h"
#include "fstream"
#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <sstream>

using namespace std;

#ifndef EINGABEN_H_
#define EINGABEN_H_


/**	\fn	Eingabe_Kasten()
 *
 * 	Die Funktion "Eingabe_Kasten()" liefert ein Interface, mit dem ein Kasten nach gewünschten Werten erstellt werden kann.
 *
 */

Kasten Eingabe_Kasten();


/**	\fn	Eingabe_anzahl_teilchen()
 *
 * 	Die Funktion "Eingabe_anzahl_teilchen()" liefert ein Interface , mit dem die Anzahl der Teilchen im Kasten eingegeben werden kann.
 */

int Eingabe_anzahl_teilchen();



/**	\fn	Eingabe_anzahl_simulationen()
 *
 * 	Die Funktion "Eingabe_anzahl_simulationen()" liefert ein Interface, mit dem eingegeben werden kann wie oft die Simulation wiederholt werden soll.
 */

int Eingabe_anzahl_simulationen();


/**	\fn	Plotten()
 *
 * 	Die Funktion "Plotten()" liefert ein Interface für die Option, den Durchlauf Graphisch darzustellen.
 *
 */


bool Plotten();

/** \fn	Plotten_vereilung()
 *
 * 	Die Funktion liefert ein Interface, für die Option, ob der Zeitliche verlauf, für die Verteilung der Teilchen geplottet werden soll.
 */

bool Plotten_verteilung();


/**	\fn	Eingabe_radius_teilchen()
*
*	Die Funktion "Eingabe_radius_teilchen()" liefert ein Interface für die Option, den Radius der Teilchen zufällig generieren zu lassen oder auf einen Konstanten Wert zu setzen.
*
*/

double Eingabe_radius_teilchen();

#endif /* EINGABEN_H_ */

