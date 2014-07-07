/*
 * Eingaben.cpp
 *
 *  Created on: 06.07.2014
 */

#include "Eingaben.h"

Kasten Eingabe_Kasten(){
	bool wahl;
	cout << "Soll der Standartkasten(x=100,y=100,s=20) erstellt werden(0), oder wollen Sie selbst Hand anlegen(1)?" << endl;
	cin >> wahl;

	if(!wahl){
		Kasten* temp_Kasten = new Kasten;

		return *temp_Kasten;

	} else {
		double x_laenge;
		double y_laenge;
		double spalt;

		cout << "Welche Länge soll der Kasten in x-Richtung haben?" << endl;
		cin >> x_laenge;

		cout << "Welche Länge soll der Kasten in y-Richtung haben?" << endl;
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
	cout << "Soll die nachfolgende Simulation Geplottet werden (1 = Ja, 0 = Nein)? Bitte beachten Sie, dass Gnuplot 4.6 vorrausgesetzt wird." << endl;
	cin >> plotten;
	if(plotten){
		cout << "Achtung, der vorherige Plot wird überschrieben, falls er nicht aus dem Zielverzeichnis entfernt wurde." << endl;
	}
	return plotten;
}

