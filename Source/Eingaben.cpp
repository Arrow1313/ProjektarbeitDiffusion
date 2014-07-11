/*
 * Eingaben.cpp
 *
 *  Created on: 06.07.2014
 */

#include "Eingaben.h"

Kasten Eingabe_Kasten(){
	bool wahl;
	cout << "Soll der standart Kasten(x=100,y=100,s=20) erstellt werden(0), oder wollen Sie selbst hand anlegen(1)?" << endl;
	cin >> wahl;

	if(!wahl){
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


int Eingabe_anzahl_teilchen(){
	int anzahl_teilchen;
	cout << "Wie viele Teilchen sollen erstellt werden?" << endl;
	cin >> anzahl_teilchen;

	return anzahl_teilchen;
}

int Eingabe_anzahl_simulationen(){
	int anzahl_simulationen;
	cout << "Wie oft soll die Simulation durchgeführt werden?" << endl;
	cin >> anzahl_simulationen;

	return anzahl_simulationen;
}


bool Plotten(){
	bool plotten;
	cout << "Soll für die nachfolgende Simulation, die Bewegungen der Teilchen geplottet werden (1 = Ja, 0 = Nein)? Bitte beachten, dass Gnuplot 4.6 vorrausgesetzt wird.Bitte passen Sie auf, dass der vorherige Plot überschrieben wird." << endl;
	cin >> plotten;

	return plotten;
}

bool Plotten_verteilung(){
	bool plotten_verteilung;
	cout << "Soll für die nachfolgende Simulation die zeitliche Verteilung der Teilchen geplottet werden (1 = Ja, 0 = Nein)?Bitte passen Sie auf, dass der vorherige Plot überschrieben wird. " << endl;
	cin >> plotten_verteilung;

	return plotten_verteilung;
}

double Eingabe_radius_teilchen(){
	double radius;
	cout << "Bitte geben sie den Radius an, der für alle Teilchen angenommen werden soll, falls sie einen Wert kleiner gleich 0 eingeben, werden die Radien zufällig erstellt. " << endl;
	cin >> radius;

	return radius;
}

double Eingabe_dt_teilchen(){
	double dt;
	cout << "Bitte geben sie die Schrittweite dt an, die verwendet werden soll, falls sie einen Wert kleiner gleich 0 eingeben, wird dt auf 0.1 gesetzt. Es ist zu beachten, dass zum plotten nicht zu kleines dt gewählt wird, da die Rechenleistung dann sehr groß wird, und zu großes dt führt zu Rechenfehlern. " << endl;
	cin >> dt;
	return dt;
}

bool Eingabe_iterations_verteilung(){
	bool plot_iterations_verteilung;
	cout << "Soll die Verteilung der Iterationen geplottet werden (1 = Ja, 0 = Nein)?" << endl;
	cin >> plot_iterations_verteilung;

	return plot_iterations_verteilung;
}


double Eingabe_masse_teilchen(){
	double masse;
	cout << "Bitte geben sie die Masse an, die für alle Teilchen angenommen werden soll, falls sie eine Wert kleiner gleich 0 eingeben, werden die Massen zufällig erstellt. " << endl;
	cin >> masse;

	return masse;
}
