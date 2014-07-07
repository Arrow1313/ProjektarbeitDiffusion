/*
 * Ausgleich.cpp
 *
 *  Created on: 06.07.2014
 */

#include "Ausgleich.h"

bool Ausgeglichen(Teilchen ar_t [], int anzahl){
	int count = 0;

	for(int i = 0; i < anzahl; i++){
		if(ar_t[i].get_pos_x() < 0){
			count++;
		}
	}

	if((count == anzahl/2)){
		return 1;
	}

	return 0;
}


void Teilchen_verteilung(Teilchen ar_t[], int anzahl_teilchen, int& links, int& rechts){
	int count_links = 0;

	for(int i = 0; i < anzahl_teilchen; i++){
			if(ar_t[i].get_pos_x() < 0){
				count_links++;
			}
		}

	links = count_links;
	rechts = (anzahl_teilchen - count_links);
}



