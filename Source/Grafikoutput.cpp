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



void Rahmendatei_verteilung(){
	ofstream rahmen ("rahmendatei_verteilung.plot");

		rahmen << "reset" << endl
			   << "set title \"Zeitliche Verteilung der Teilchen in den Kammern\""
			   << "set terminal png size 1280,720" << endl
			   << "set output \"Verteilung.png\"" << endl
			   << "plot 'Verlauf.dat' using 1:2 title \"Anzahl der Teilchen auf der linken Seite\", 'Verlauf.dat' using 1:3 title \"Anzahl der Teilchen auf der linke Seite\" " << endl
			   << "set output" << endl;

		system("gnuplot rahmendatei.plot");

}


