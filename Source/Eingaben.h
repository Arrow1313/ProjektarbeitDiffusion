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
 * 	Dies Funktion liefert ein Interface, mit dem ein Kasten nach gewünschten Werten erstellt werden kann.
 *
 */

void Eingabe_Kasten(Kasten&);


/**	\fn	Eingabe_anzahl_teilchen()
 *
 * 	Mit dieser Funktion wird ein Interface geliefert, mit dem die Anzahl der Teilchen im Kasten eingegeben werden kann.
 */

int Eingabe_anzahl_teilchen();



/**	\fn	Eingabe_anzahl_simulationen()
 *
 * 	Die Funktion liefer ein Interface, mit dem eingegeben werden kann wie oft die Simulation wieder holt werden soll.
 */

int Eingabe_anzahl_simulationen();


/**	\fn	Plotten()
 *
 * 	Die Funktion liefer ein Interface, für die Option ob der Durchlauf Graphisch dargestellt werden soll.
 *
 */

bool Plotten();

#endif /* EINGABEN_H_ */

