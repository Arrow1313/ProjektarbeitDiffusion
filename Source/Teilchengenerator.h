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

/**
 * 	\file Teilchengenerator.h
 *
 * 	In dieser Datei werden Funktionen deklariert mit welchen das genrieren der Teilchen abgehandelt wird
 */

using namespace std;



/**	\fn	Abfrage(Teilchen ar_t[],Kasten Kasten ,int anzahl,double param_masse, double param_radius)
 *
 *	Die Funkton fragt ab, auf welche Weise die Teilchen erstellt werden sollen und liefert in dem Array die Teilchen zurück.
 *
 *	\param	ar_t[]	Array mit den Teilchen.
 *	\param	Kasten		Kasten, in dem die Teilchen erstell werden sollen.
 *	\param	anzahl	Anzahl der Teilchen, die sich im Array befinden.
 *	\param	param_masse	Übergabewert für die Auswahl der Masse aller Teilchen.
 *	\param	param_radius	Übergabewert für die Auswahl des Radiuses aller Teilchen.
 */
bool Abfrage(Teilchen [],Kasten,int,double,double);


/**	\fn	Random_Teilchen(Kasten Kasten,double param_masse, double param_radius)
 *
 * 	Liefert ein zufällig erzeugtes Teilchen, welches in dem übergebenen Kasten liegt.
 *
 * 	\param Kasten	Der Kasten, in dem das Teilchen liegen soll.
 *	\param	param_masse	Übergabewert für die Auswahl der Masse aller Teilchen.
 *	\param	param_radius	Übergabewert für die Auswahl des Radiuses aller Teilchen.
 */
Teilchen Random_Teilchen(Kasten,double,double);


/**	\fn	Teilchen_Array(Teilchen ar_t[],Kasten Kasten ,int anzahl,double param_radius, double param_mass)
 *
 * 	Die Funktion Speichert die Teilchen in dem übergeben Array
 *
 *	\param	ar_t[]	Array mit den Teilchen.
 *	\param	Kasten		Kasten, in dem die Teilchen erstell werden sollen.
 *	\param	anzahl	Anzahl der Teilchen, die sich im Array befinden.
 *	\param	param_masse	Übergabewert für die Auswahl der Masse aller Teilchen.
 *	\param	param_radius	Übergabewert für die Auswahl des Radiuses aller Teilchen.
 */
void Teilchen_Array(Teilchen[],Kasten,int,double,double);


/**	\fn	Eingabe_teilchen_werte(int anzahl, Teilchen ar_t[])
 *
 * 	Liefert ein Interface, für die Eingabe der Werte des Teilchens.
 *
 *	\param	ar_t[]	Array mit den Teilchen.
 *	\param	anzahl	Anzahl der Teilchen, die sich im Array befinden.
 */
void Eingabe_teilchen_werte(int,Teilchen []);


#endif /* TEILCHENGENERATOR_H_ */
