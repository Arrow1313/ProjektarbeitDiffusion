#include "Kasten.h"
#include "Teilchen.h"
#include "fstream"
#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include <sstream>

using namespace std;

#ifndef GRAFIKOUTPUT_H_
#define GRAFIKOUTPUT_H_

void Rahmendatei(Kasten);
void Plotdaten(Teilchen [], int);
void Plotradien(Teilchen [],int);
void Plot_verteilung(Teilchen[],int);
void Rahmendatei_verteilung();

/**	\fn	Rahmendatei(Kasten k)
 *
 * 	Diese Funktion erstellt die Rahmendatei für die den Plot des Gifs und ruft das Script auf.
 *
 */

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

/**	\fn	Plotdaten(Teilchen ar_t[],int anzahl_teilchen)
 *
 * 	Diese Funktion speichert die Positionen und Radien in einer Datei, damit sie für den Plot der Gif verwendet werden können.
 *
 *	\param ar_t[]	Der Array in dem die Teilchen gespeicher sind.
 *	\param	anzahl_teilchen	Die Anzahl der Teilchen in dem Array.
 */

void Plotdaten(Teilchen ar_t[],int anzahl_teilchen){
	ofstream dat ("Diffusion.dat", ios::app);

	for(int i = 0; i < anzahl_teilchen; i++){
		dat << ar_t[i].get_pos_x() << "\t" << ar_t[i].get_pos_y() << "\t" << ar_t[i].get_radius() << endl;
	}

	dat << endl << endl;

	dat.close();
}

/**	\fn	Plot_verteilung(Teilchen ar_t[],int anzahl_teilchen)
 *
 * 	Diese Funktion liefer die Daten für den Plot der Teilchenverteilung in abhängigkeit der Zeit in einer Datei.
 *
 * 	\param ar_t[]	Der Array in dem die Teilchen gespeicher sind.
 *	\param	anzahl_teilchen	Die Anzahl der Teilchen in dem Array.
 */

void Plot_verteilung(Teilchen ar_t[],int anzahl_teilchen){
	ofstream dat ("Verlauf.dat", ios::app);

	int rechts;
	int links;

	Teilchen_verteilung(ar_t, anzahl_teilchen, links, rechts);

	for(int i = 0; i < anzahl_teilchen; i++){
		dat << i <<  links << rechts << endl;
	}

	dat.close();
}

/**	\fn	Rahmendatei_verteilung()
 *
 * 	Die Funktion erstellt die Plotdatei, für die Verteilung der Teilchen in abhängigkeit er Zeit.
 */

void Rahmendatei_verteilung(){
	ofstream rahmen ("rahmendatei_verteilung.plot");

		rahmen << "reset" << endl
			   << "set title \"Zeitliche Verteilung der Teilchen in den Kammern\""
			   << "set terminal png size 1280,720" << endl
			   << "set output \"Verteilung.png\"" << endl
			   << "plot 'Verlauf.dat' using 1:2 title \"Anzahl der Teilchen auf der linke Seite\", 'Verlauf.dat' using 1:3 title \"Anzahl der Teilchen auf der linke Seite\" " << endl
			   << "set output" << endl;

		system("gnuplot rahmendatei.plot");

}


#endif /* GRAFIKOUTPUT_H_ */



