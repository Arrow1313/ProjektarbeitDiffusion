/*
 * Grafikoutput.cpp
 *
 *  Created on: 06.07.2014
 */

#include "Grafikoutput.h"

void Rahmendatei(Kasten Kasten){

	ofstream rahmen ("rahmendatei.plot");

	rahmen << "reset" << endl
		   << "set notitle" << endl
		   << "set terminal gif animate delay 2 size 1280,720" << endl
		   << "set output \"Diffusion.gif\"" << endl
		   << "stats \"Diffusion.dat\" nooutput" << endl
		   << "unset xtic" << endl
		   << "unset ytic" << endl
		   << "set samples 1000" << endl
		   << "set xrange [" << -Kasten.get_size_x()/2 << ":" << Kasten.get_size_x()/2 << "]" << endl
		   << "set yrange [" << -Kasten.get_size_y()/2 << ":" << Kasten.get_size_y()/2 << "]" << endl
		   << "do for [i=1:int(STATS_blocks)] {" << endl
		   << "set arrow from 0," << Kasten.get_size_spalt()/2 << " to 0," << Kasten.get_size_y()/2 << " nohead" << endl
		   << "set arrow from 0," << -Kasten.get_size_spalt()/2 << " to 0,"<< -Kasten.get_size_y()/2 << " nohead" << endl
		   << "plot 'Diffusion.dat' using 1:2:3 index ((i-1)) with circles fs solid notitle"  << endl
		   << "}" << endl
		   << "set output" << endl;

	system("gnuplot rahmendatei.plot");

}


void Plotdaten(Teilchen ar_t[],int anzahl_teilchen){
	ofstream dat ("Diffusion.dat", ios::app);

	for(int i = 0; i < anzahl_teilchen; i++){
		dat << ar_t[i].get_pos_x() << "\t" << ar_t[i].get_pos_y() << "\t" << ar_t[i].get_radius() << endl;
	}

	dat << endl << endl;

	dat.close();
}


void Plot_verteilung(Teilchen ar_t[],int anzahl_teilchen, int iteration){
	ofstream dat ("Verlauf.dat", ios::app);

	int rechts;
	int links;

	Teilchen_verteilung(ar_t, anzahl_teilchen, links, rechts);

	dat << iteration << "\t" << links << "\t" << rechts << endl;

	dat.close();
}



void Rahmendatei_verteilung(int anzahl_teilchen){
	ofstream rahmen ("rahmendatei_verteilung.plot");

		rahmen << "reset" << endl
			   << "set title \"Zeitliche Verteilung der Teilchen in den Kammern\"" << endl
			   << "set yrange [" << -1 << ":" << anzahl_teilchen+1 << "]" << endl
			   << "set terminal png size 1280,720" << endl
			   << "set output \"Verteilung.png\"" << endl
			   << "plot 'Verlauf.dat' using 1:2 w l title \"Anzahl der Teilchen auf der linke Seite\", 'Verlauf.dat' using 1:3 w l title \"Anzahl der Teilchen auf der linke Seite\" " << endl
			   << "set output" << endl;

		system("gnuplot rahmendatei_verteilung.plot");

}


void Plot_iterations_verteilung(int ar_sim[],int anzahl_sim){
	ofstream dat ("iterations_verteilung.dat", ios::app);

		//Array für die Daten initialiseren
		int ar_daten[anzahl_sim][2];
		for(int i = 0; i < anzahl_sim; i++){
			ar_daten[i][0] = 0;
			ar_daten[i][1] = 0;
		}

		for(int i = 0; i < anzahl_sim; i++){
			for(int j = 0; j < anzahl_sim; j++){
				if(ar_daten[j][1] == 0){
					ar_daten[j][0] = ar_sim[i];
					ar_daten[j][1]++;
					break;
				}
				else if(ar_daten[j][0] == ar_sim[i]){
					ar_daten[j][1]++;
					break;
				}
			}
		}

		for(int i = 0; i < anzahl_sim; i++){
			if(ar_daten[i] != 0){
				dat <<  ar_daten[i][0] << "\t" << ar_daten[i][1] << endl;
			}
		}

		dat.close();
}




void Rahmendatei_iterations_verteilung(int max, int min){
	ofstream rahmen ("rahmendatei_iterations_verteilung.plot");

		rahmen << "reset" << endl
			   << "set title \"Verteilung der Ierationsdauern\"" << endl
			   << "set xrange [" << min-50 << ":" << max+50 << "]" << endl
			   << "set yrange [-1" << ":" << "5" << "]" << endl
			   << "set terminal png size 1280,720" << endl
			   << "set output \"Iterations_verteilung.png\"" << endl
			   << "plot 'iterations_verteilung.dat' using 1:2 title \"Iterationsverteilung\"" << endl
			   << "set output" << endl;

		system("gnuplot rahmendatei_iterations_verteilung.plot");
}
