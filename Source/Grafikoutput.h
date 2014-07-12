#include "fstream"
#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "Kasten.h"
#include "Teilchen.h"
#include "Ausgleich.h"

using namespace std;

#ifndef GRAFIKOUTPUT_H_
#define GRAFIKOUTPUT_H_


/**	\fn	Rahmendatei_bewegung(Kasten k)
 *
 * 	Diese Funktion erstellt die Rahmendatei für den Plot des Gifs und ruft das Script auf.
 *
 *	\param k	Kasten für die justierung des Plots
 */

void Rahmendatei_bewegung(Kasten);


/**	\fn	Plotdaten_bewegung(Teilchen ar_t[],int anzahl_teilchen)
 *
 * 	Diese Funktion speichert die Positionen und Radien in einer Datei, damit sie für den Plot des Gifs verwendet werden können.
 *
 *	\param ar_t[]	Der Array in dem die Teilchen gespeicher sind.
 *	\param	anzahl_teilchen	Die Anzahl der Teilchen in dem Array.
 */


void Plotdaten_bewegung(Teilchen [], int);


/**	\fn	Plot_teilchen_verteilung(Teilchen ar_t[],int anzahl_teilchen)
 *
 * 	Diese Funktion liefert die Daten für den Plot der Teilchenverteilung in Abhängigkeit von der Zeit in eine Datei.
 *
 * 	\param ar_t[]	Der Array in dem die Teilchen gespeicher sind.
 *	\param	anzahl_teilchen	Die Anzahl der Teilchen in dem Array.
 */

void Plot_teilchen_verteilung(Teilchen[],int,int);


/**	\fn	Rahmendatei_teilchen_verteilung()
 *
 * 	Die Funktion erstellt die Plotdatei, für die Verteilung der Teilchen in Abhängigkeit von der Zeit.
 *
 * 	\param anzal_teilchen	Anzahl der Teilchen.
 */

void Rahmendatei_teilchen_verteilung(int);


/**	\fn	Plot_iterations_verteilung(int ar_sim[], int anzahl_simulationen)
 *
 * 	Die Funktion speichert die Daten für den Plot der Iterationsverteilung in eine Datei
 *
 * 	\param	ar_sim[]	Array mit den benötigten Iterationsschritten.
 * 	\param	anzahl_simulationen	Die Größe des Arrays.
 */

void Plot_iterations_verteilung(int[],int);


/**	\fn	Rahmendatei_iterations_verteilung();
 *
 * 	Die Funktion liefert die Rahmendatei fürs plotten der Iterationsverteilung und ruft sie auf.
 *
 * 	\param	max	Maximum der Iterationen.
 * 	\param	min	Minimum der Iterationen.
 * 	\param	ar_sim	Array mit den Werten der einzelnen Iterationen.
 * 	\param	anzahl_sim	Anzahl der Simulationen.
 */

void Rahmendatei_iterations_verteilung(int,int,int[],int);

#endif /* GRAFIKOUTPUT_H_ */



