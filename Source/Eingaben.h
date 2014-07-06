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

void Eingabe_Kasten(Kasten&);
int Eingabe_anzahl_teilchen();
int Eingabe_anzahl_simulationen();
bool Plotten();

/**	\fn	Eingabe_Kasten()
 *
 * 	Dies Funktion liefert ein Interface, mit dem ein Kasten nach gewünschten Werten erstellt werden kann.
 *
 */

Kasten Eingabe_Kasten(){
	bool wahl;
	cout << "Soll der standart Kasten(x=100,y=100,s=20) erstellt werden(0), oder wollen Sie selbst hand anlegen(1)?" << endl;
	cin >> wahl;

	if(wahl){
		Kasten* temp_Kasten = new Kasten;

		return *temp_Kasten;

	} else {
		double x_laenge;
		double y_laenge;
		double spalt;

		cout << "Welche Länge in x-Richtung soll der Kasten haben?" << endl;
		cin >> x_laenge;

		cout << "Welche Länge in y-Richtung soll der Kastern haben?" << endl;
		cin >> y_laenge;

		cout << "Welche Breite soll der Spalt haben?" << endl;
		cin >> spalt;

		Kasten* temp_Kasten = new Kasten(x_laenge,y_laenge,spalt);

		return *temp_Kasten;
	}
}

/**	\fn	Eingabe_anzahl_teilchen()
 *
 * 	Mit dieser Funktion wird ein Interface geliefert, mit dem die Anzahl der Teilchen im Kasten eingegeben werden kann.
 */

int Eingabe_anzahl_teilchen(){
	int anzahl_teilchen;
	cout << "Wie viele Teilchen sollen erstellt werden?" << endl;
	cin >> anzahl_teilchen;

	return anzahl_teilchen;
}

/**	\fn	Eingabe_anzahl_simulationen()
 *
 * 	Die Funktion liefer ein Interface, mit dem eingegeben werden kann wie oft die Simulation wieder holt werden soll.
 */

int Eingabe_anzahl_simulationen(){
	int anzahl_simulationen;
	cout << "Wie oft soll die Simulation durchgeführt werden?" << endl;
	cin >> anzahl_simulationen;

	return anzahl_simulationen;
}

/**	\fn	Plotten()
 *
 * 	Die Funktion liefer ein Interface, für die Option ob der Durchlauf Graphisch dargestellt werden soll.
 *
 */

bool Plotten(){
	bool plotten;
	cout << "Soll die nachfolgende Simulation Geplottet werden (1 = Ja, 0 = Nein)? Bitte beachten, dass Gnuplot 4.6 vorrausgesetzt wird." << endl;
	cin >> plotten;
	if(plotten){
		cout << "Bitte passen Sie auf, dass der vorherige Plot überschrieben wird." << endl;
	}
	return plotten;
}

#endif /* EINGABEN_H_ */

