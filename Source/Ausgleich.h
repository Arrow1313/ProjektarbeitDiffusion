#ifndef AUSGLEICH_H_
#define AUSGLEICH_H_

#include "Teilchen.h"

/**
 * \file Ausgleich.h
 *
 * 	In dieser Datei werden Funktionen deklariert um zu prüfen, ob sich ein Ausgelichszustand eingestellt hat
 */

/**	\fn Ausgeglichen(Teilchen ar_t[], int anzahl)
 *
 * 	Diese Funktion gibt TRUE zurück, wenn sich gleich viele Teilchen links und rechts befinden.
 * 	Bei ungerader Teilchenanzahl wird noch der Wert 1 addiert bzw. subtrahiert.
 *
 * 	\param	ar_t[] Der Array in dem die Teilchen gespeichert sind.
 * 	\param 	anzahl Die Anzahl der Teilchen in dem Array.
 */
bool Ausgeglichen(Teilchen [],int);

/**	\fn Teilchen_verteilung(Teilchen ar_t[], int anzahl_teilchen, int& links, int& rechts)
 *
 * 	Diese Funktion gibt in links und rechts die jeweilige Anzahl der Teilchen auf der entsprechenden Seite
 *
 * 	\param	ar_t[]	Der Array mit den Teilchen
 * 	\param	anzahl_teilchen	Die Anzahl der Teilchen in dem Array
 * 	\param	links	Die Variable, in der die Anzahl der Teilchen in der linken Kammer zurückgegeben wird.
 * 	\param	rechts	Die Variable, in der die Anzahl der Teilchen in der rechten Kammer zurückgegeben wird.
 *
 */

void Teilchen_verteilung(Teilchen[],int,int&,int&);

#endif /* AUSGLEICH_H_ */
