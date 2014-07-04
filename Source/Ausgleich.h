/*
 * Ausgleich.h
 *
 *  Created on: 30.06.2014
 *      Author: frederik
 */

#ifndef AUSGLEICH_H_
#define AUSGLEICH_H_

bool Ausgeglichen(Teilchen [],int);

bool Ausgeglichen(Teilchen ar_t [], int anzahl){
	int ungerade;
	int count = 0;

	if(anzahl % 2){
		ungerade = 1;
	} else {
		ungerade = 0;
	}

	for(int i = 0; i < anzahl; i++){
		if(ar_t[i].get_pos_x() < 0){
			count++;
		}
	}

	if((count - ungerade == anzahl/2)
		|| (count + ungerade == anzahl/2)){
		return 1;
	}

	return 0;
}


#endif /* AUSGLEICH_H_ */
