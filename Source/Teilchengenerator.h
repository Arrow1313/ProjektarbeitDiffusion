/*
 * Teilchengenerator.h
 *
 *  Created on: 30.06.2014
 */

#include "iostream"
#include "stdlib.h"
#include "Teilchen.h"
#include "Kasten.h"

#ifndef TEILCHENGENERATOR_H_
#define TEILCHENGENERATOR_H_

using namespace std;

bool Abfrage(Teilchen [],Kasten,int);

/**	\fn	Abfrage(Teilchen ar_t[],Kasten k ,int anzahl_teilchen)
 *	Die Funkton fragt ab, auf welche Weise die Teilchen erstellt werden sollen und liefert in dem Array die Teilchen zurück.
 *
 *	\param	ar_t[]	Array mit den Teilchen.
 *	\param	k		Kasten, in dem die Teilchen erstellt werden sollen.
 *	\param	anzahl_teilchen	Anzahl der Teilchen, die sich im Array befinden.
 */

Teilchen Random_Teilchen(Kasten);

/**	\fn	Random_Teilchen(Kasten k)
 * 	Liefert ein zufällig erzeugtes Teilchen, welches in dem übergebenen Kasten liegt.
 *
 * 	\param k	Der Kasten, in dem das Teilchen liegen soll.
 */

void Teilchen_Array(Teilchen[],Kasten,int);

/**	\fn	Teilchen_Array(Teilchen ar_t[],Kasten k ,int anzahl_teilchen)
 * 	Die Funktion Speichert die Teilchen in dem übergebenen Array
 *
 *	\param	ar_t[]	Array mit den Teilchen.
 *	\param	k		Kasten, in dem die Teilchen erstellt werden sollen.
 *	\param	anzahl_teilchen	Anzahl der Teilchen, die sich im Array befinden.
 */

void Eingabe(int,Teilchen []);

/**	\fn	Eingabe(int anzahl_teilchen, Teilchen ar_t[])
 * 	Liefert ein Interface, für die Eingabe der Werte des Teilchens.
 *
 *	\param	ar_t[]	Array mit den Teilchen.
 *	\param	anzahl_teilchen	Anzahl der Teilchen, die sich im Array befinden.
 */



#endif /* TEILCHENGENERATOR_H_ */
