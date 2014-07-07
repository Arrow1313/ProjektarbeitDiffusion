#include <iostream>
#include "Teilchengenerator.h"

using namespace std;

bool Abfrage(Teilchen ar_t[],Kasten Kasten,int anzahl){
	bool wahl;

	//Methode der Generierung erfragen und einleiten
	cout << endl << "Sollen die Teilchen automatisch(0) erstllt werden oder von Hand(1) eingeben werden?" << endl;
	cin >> wahl;

	if(wahl){
		Eingabe(anzahl,ar_t);
	} else if(!wahl){
		Teilchen_Array(ar_t,Kasten,anzahl);
	}

	return wahl;
}

void Eingabe(int anzahl,Teilchen ar_t[]){
	double pos_x;
	double pos_y;
	double v_x;
	double v_y;
	double masse;
	double radius;
	for(int i = 0; i < anzahl; i++){

		//Werte des Teilchens abfragen
		cout << "Bitte geben Sie die x-pos ein: ";
		cin >> pos_x;
		cout << endl << "Bitte geben Sie die y-pos ein: ";
		cin >> pos_y;
		cout << endl << "Bitte geben Sie die x-Geschwindigkeit ein: ";
		cin >> v_x;
		cout << endl << "Bitte geben Sie die y-Geschwindigkeit ein: ";
		cin >> v_y;
		cout << endl << "Bitte geben Sie den Rasius ein (Vorsicht bei großen Radien): ";
		cin >> radius;
		cout << endl << "Bitte geben Sie die Masse ein: ";
		cin >> masse;

		//Teilchen erstellen und eintragen
		Teilchen* temp_t = new Teilchen(pos_x,pos_y,v_x,v_y,radius,masse);
		ar_t[i] = *temp_t;
	}
}

void Teilchen_Array(Teilchen ar_t[], Kasten Kasten, int anzahl){

	bool flag;

	for(int i = 0; i < anzahl; i++){
		if(i == 0){
			ar_t[i] = Random_Teilchen(Kasten);
		}else {
			flag = 0;
			do{
				Teilchen temp_t = Random_Teilchen(Kasten);
				for(int j = 0; j < i; j++){
					if(temp_t.Teilchen_Kollision_b(ar_t[j])){
						break;
					} else if((j == i-1) && !temp_t.Teilchen_Kollision_b(ar_t[j])){
						ar_t[i] = temp_t;
						flag = 1;
					}
				}
			}while(!flag);
		}
	}
}//Ende Teilchen_Array


Teilchen Random_Teilchen(Kasten Kasten){
	srand(time(NULL));

	double pos_x = ((double)rand() / RAND_MAX)*((Kasten.get_size_x()-(Kasten.get_size_spalt()/10))/2);
	double pos_y = ((double)rand() / RAND_MAX)*((Kasten.get_size_y()-(Kasten.get_size_spalt()/10))/2)-((Kasten.get_size_y()/2)-(Kasten.get_size_spalt()/10)/2);
	double v_x = ((double)rand() / RAND_MAX)*(Kasten.get_size_x()/20)-(Kasten.get_size_x()/40);
	double v_y = ((double)rand() / RAND_MAX)*(Kasten.get_size_y()/20)-(Kasten.get_size_y()/40);
	double radius = ((double)rand() / RAND_MAX)*(Kasten.get_size_spalt()/10)+0.01;
	double masse = ((double)rand() / RAND_MAX)*(Kasten.get_size_spalt()/10)+0.01;

	//Teilchen mit den Randomwerten erstllen
	Teilchen* neues_teilchen = new Teilchen(pos_x,pos_y,v_x,v_y,radius,masse);

	return *neues_teilchen;

}
