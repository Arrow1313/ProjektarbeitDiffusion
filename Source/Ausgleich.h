#ifndef AUSGLEICH_H_
#define AUSGLEICH_H_

bool Ausgeglichen(Teilchen [],int);
void Teilchen_verteilung(Teilchen[],int,int&,int&);

/**	\fn Ausgeglichen(Teilchen ar_t[], int anzahl)
 * 	Diese Funktion gibt TRUE zurück, wenn sich gleich viele Teilchen links und rechts befinden.
 * 	Bei ungerader Teilchenanzahl wird noch der Wert 1 addiert bzw. subtrahiert.
 *
 * 	\param	Teilchen ar_t[] Der Array in dem die Teilchen gespeichert sind.
 * 	\param 	int anzahl Die Anzahl der Teilchen in dem Array.
 */

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

/**	\fn Teilchen_verteilung(Teilchen ar_t[], int anzahl_teilchen, int& links, int& rechts)
 *
 * 	Diese Funktion gibt in links und rechts die jeweilige Anzahl der Teilchen auf der entsprechenden Seite
 *
 * 	\param	ar_t[]	Der Array mit den Teilchen
 * 	\param	anzahl_teilchen	Die Anzahl der Teilchen in dem Array
 * 	\param	links	Die Variable, in der die Anzahl der Teilchen in der linken Kammer zurückgegeben wird.
 * 	\param	rechts	Die Variable, in der die Anzahl der Teilchen in der rechten Kammer zurückgegeben wird.
 *
 */

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

#endif /* AUSGLEICH_H_ */
