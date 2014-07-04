/*
 * Grafikoutput.h
 *
 *  Created on: 02.07.2014
 *      Author: frederik
 */

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

void Plotdaten(Teilchen ar_t[],int anzahl){
	ofstream dat ("Diffusion.dat", ios::app);

	for(int i = 0; i < anzahl; i++){
		dat << ar_t[i].get_pos_x() << "\t" << ar_t[i].get_pos_y() << "\t" << ar_t[i].get_radius() << endl;
	}

	dat << endl << endl;

	dat.close();
}



#endif /* GRAFIKOUTPUT_H_ */



