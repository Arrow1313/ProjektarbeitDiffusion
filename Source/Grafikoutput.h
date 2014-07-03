/*
 * Grafikoutput.h
 *
 *  Created on: 01.07.2014
 */

#include "iostream"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#include "Teilchen.h"
#include "Kasten.h"

using namespace std;

/*
gnuplot 
reset
set terminal gif animate delay "dt" size 1280,720
set output "Diffusion.gif"
stats "Diffusion.txt" nooutput
unset xtic
unset ytic
unset key
set samples 100
set xrange [-Kasten.get_size_x()/2:Kasten.get_size_x()/2]
set yrange [-Kasten.get_size_y()/2:Kasten.get_size_y()/2]
do for [i=1:int(STATS_blocks)] {
set arrow from 0,Spaltgröße/2 to 0,Kasten.get_size_y()/2 nohead
set arrow from 0,-Spaltgröße/2 to 0,-Kasten.get_size_y()/2 nohead
#mit den arrows können wir die Spalte einstellen
    plot 'Diffusion.txt' using 1:2:3 index i-1 with circles fs solid
# Die dritte Spalte ist nun der Radius*Faktor, der von Gnuplot
# abhängt, also können wir auch den Radius plotten
}
set output
*/



