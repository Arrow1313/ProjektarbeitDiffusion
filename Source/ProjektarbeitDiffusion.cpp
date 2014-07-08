//============================================================================
// Name        : ProjektarbeitV4.cpp
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "stdlib.h"
#include "stdio.h"
#include "Kasten.h"
#include "Teilchen.h"
#include "Teilchengenerator.h"
#include "Ausgleich.h"
#include "Eingaben.h"
#include "Grafikoutput.h"

using namespace std;

int main() {

	double masse_param;
	int anzahl_teilchen = Eingabe_anzahl_teilchen();
	int anzahl_simulation = Eingabe_anzahl_simulationen();
	bool erstesmal = 1;
	bool next;
	bool plotten_bahnen;
	bool plotten_verteilung;
	bool plotten_iterations_verteilung;
	unsigned long int anzahl_schritte;
	unsigned long int anzahl_schritte_max;
	unsigned long int anzahl_schritte_min;
	unsigned long int anzahl_schritte_mittel = 0;

	//Kasten instanzeren
	Kasten Kasten = Eingabe_Kasten();

	int ar_sim[anzahl_simulation];

	//Abragen was geplotte werden soll
	plotten_bahnen = Plotten();

	plotten_verteilung = Plotten_verteilung();

	plotten_iterations_verteilung = Eingabe_iterations_verteilung();


	for(int k = 0; k < anzahl_simulation; k++){
		anzahl_schritte = 0;

		Teilchen ar_t[anzahl_teilchen];
		if(erstesmal){
			masse_param = Eingabe_masse_teilchen();
			next = Abfrage(ar_t,Kasten,anzahl_teilchen,masse_param);
			erstesmal = 0;
		} else {
			if(next){
				Eingabe(anzahl_teilchen,ar_t);
			} else {
				Teilchen_Array(ar_t,Kasten,anzahl_teilchen,masse_param);
			}
		}

		//Simulation beginnen
		do{

			for(int i = 0; i < anzahl_teilchen; i++){
				ar_t[i].Kasten_Kollision_radius(Kasten);
			}

			for(int i = 0; i < anzahl_teilchen; i++){
				ar_t[i].Spalt_Kollision_exakt(Kasten);
			}

			for(int i = 0; i < anzahl_teilchen; i++){
				for(int j = i+1; j < anzahl_teilchen; j++){
					ar_t[i].Teilchen_Kollision(ar_t[j]);
				}
			}

			for(int i = 0; i < anzahl_teilchen; i++){
				ar_t[i].Bewege();
			}

			anzahl_schritte++;

			if(plotten_bahnen){
				Plotdaten(ar_t, anzahl_teilchen);
			}
			if(plotten_verteilung){
				Plot_verteilung(ar_t, anzahl_teilchen, anzahl_schritte);
			}


		}while(!Ausgeglichen(ar_t,anzahl_teilchen));
		//Ende der Bewegungsimultaion

		if(plotten_bahnen){
			Rahmendatei(Kasten);
		}
		if(plotten_verteilung){
			Rahmendatei_verteilung(anzahl_teilchen);
		}

		if(plotten_bahnen){
			system("rm rahmendatei.plot");
			system("rm Diffusion.dat");
		}
		if(plotten_verteilung){
			system("rm Verlauf.dat");
			system("rm rahmendatei_verteilung.plot");
		}

		//Auswertung der Simulation
		cout << "Es wurden: " << anzahl_schritte << " Iterationen benötigt, bei einer Spaltbreite von: " << Kasten.get_size_spalt() << endl;

		ar_sim[k] = anzahl_schritte;

		if(k == 0){
			anzahl_schritte_max = anzahl_schritte;
			anzahl_schritte_min = anzahl_schritte;
		} else {
			if(anzahl_schritte < anzahl_schritte_min){
				anzahl_schritte_min = anzahl_schritte;
			}
			if(anzahl_schritte > anzahl_schritte_max){
				anzahl_schritte_max = anzahl_schritte;
			}
		}

		if(plotten_verteilung && plotten_bahnen){
			cout << "Bitte Speichern die die Plots, wenn Sie sie behalten wollen. ENTER drücken zum fortfahren." << endl;
			getchar();
		}
	}

	//plotten der Itertaionsverteilung
	if(plotten_iterations_verteilung){
		Plot_iterations_verteilung(ar_sim,anzahl_simulation);
		Rahmendatei_iterations_verteilung(anzahl_schritte_max,anzahl_schritte_min,ar_sim,anzahl_simulation);

		system("rm iterations_verteilung.dat");
		system("rm rahmendatei_iterations_verteilung.plot");
	}


	for(int i = 0; i < anzahl_simulation; i++){
		anzahl_schritte_mittel += ar_sim[i];
	}

	anzahl_schritte_mittel /= anzahl_simulation;

	///Ergebnisse ausgeben
	cout << "Nach " << anzahl_simulation << " Durchlaeufen der Simulation für " << anzahl_teilchen << " Teilchen"
		 << " ergaben sich die folgenden Werte: Maximum der benötigten Iterationen bis ein Ausgleich erreicht wurde: " << anzahl_schritte_max << " Minimum der "
		 << " Iterationen bis ein Ausgleich erreicht wurde: " << anzahl_schritte_min << " und ein Mittelwert von " << anzahl_schritte_mittel << " benötigten Iterationen " << endl
		 << " für eine Anzahl von: " << anzahl_teilchen << " Teilchen " << endl;

	return 0;
}
