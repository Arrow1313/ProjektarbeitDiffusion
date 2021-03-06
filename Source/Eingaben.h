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

/**
 * 	\file Eingaben.h
 *
 * 	In dieser Datei werden Funktionen deklariert welche ein Interaface für Abfragen liefert
 */

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


/**	\fn	Plotten_bewegung()
 *
 * 	Die Funktion "Plotten()" liefert ein Interface für die Option, den Durchlauf Graphisch darzustellen.
 *
 */


bool Plotten_bewegung();

/** \fn	Plotten_verteilung_teilchen()
 *
 * 	Die Funktion liefert ein Interface, für die Option, ob der Zeitliche verlauf, für die Verteilung der Teilchen geplottet werden soll.
 */

bool Plotten_verteilung_teilchen();


/**	\fn	Eingabe_radius_teilchen()
*
*	Die Funktion "Eingabe_radius_teilchen()" liefert ein Interface für die Option, den Radius der Teilchen zufällig generieren zu lassen oder auf einen Konstanten Wert zu setzen.
*
*/

double Eingabe_radius_teilchen();


/**	\fn	Plotten_iterations_verteilung()
 *
 * 	Diese Funktion liefert ein Interface, für die Option, dass die Verteilung der Iterationsdauern geplottet wird.
 */

bool Plotten_iterations_verteilung();


/**	\fn	Eingabe_masse_teilchen()
 *
 * 	Die Funktion liefert ein Interface, mit welchem abgefragt werden kann ob man die Masse konstant halten will.
 *
 */

double Eingabe_masse_teilchen();


/** \fn Eingabe_dt_teilchen
 *
 * 	Diese Funktion liefert ein Interface, für die Option, die Schrittweite dt zu ändern.
 */

double Eingabe_dt_teilchen();


#endif /* EINGABEN_H_ */



