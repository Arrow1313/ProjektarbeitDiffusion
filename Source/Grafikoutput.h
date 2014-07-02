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
set terminal gif
set output "Diffusion.gif"
stats "Diffusion.txt" nooutput
unset xtic
unset ytic
set samples 1000
set xrange [-Kasten.get_size_x()/2:Kasten.get_size_x()/2]
set yrange [-Kasten.get_size_y()/2:Kasten.get_size_y()/2]
do for [i=1:int(STATS_blocks)] {
set arrow from 0,Spaltgröße/2 to 0,Kasten.get_size_y()/2 nohead
set arrow from 0,-Spaltgröße/2 to 0,-Kasten.get_size_y()/2 nohead
    plot 'Diffusion.txt' using 1:2 index i-1 with points pointsize "Teilchen.radius oder Default" pointtype 19
}
set output
*/



