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
set pointsize 3
unset xtic
unset ytic
set xrange [-Kasten.get_size_x()/2:Kasten.get_size_x()/2]
do for [i=1:int(STATS_blocks)] {
    plot 'Diffusion.txt'
}
set output
*/



