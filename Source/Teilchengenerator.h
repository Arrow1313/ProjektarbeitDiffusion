/*
 * Teilchengenerator.h
 *
 *  Created on: 30.06.2014
 */

#include "iostream"
#include "stdlib.h"
#include "Teilchen.h"
#include "Kasten.h"

#ifndef TEILCHENGENERATOR_H_
#define TEILCHENGENERATOR_H_

using namespace std;

bool Abfrage(Teilchen [],Kasten,int);
Teilchen Random_Teilchen(Kasten);
void Teilchen_Array(Teilchen[],Kasten,int);
void Eingabe(int,Teilchen []);


#endif /* TEILCHENGENERATOR_H_ */
