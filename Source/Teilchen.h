/*
 * Teilchen.h
 *
 *  Created on: 19.06.2014
 *      Author: frederik
 */

#ifndef TEILCHEN_H_
#define TEILCHEN_H_

#include "Kasten.h"

class Teilchen {
private:
	double pos_x; 	/** <Position des Teilchens in der X-Ebene.> */
	double pos_y; 	/** <Position des Teilchens in der Y-Ebene.> */
	double v_x; 	/** <Geschwindigkeit des Teilchens in X-Richtung.> */
	double v_y; 	/** <Geschwindigkeit des Teilchens in Y-Richtung.> */
	double radius;	/** <Radius des Teilches.> */
	double masse;	/** <Masse des Teilchens.> */
	bool used;
public:

	static double dt;
	//getter-Funktion
	/** \brief Gibt an, ob das Teilchen schon eine Kollison hatte oder nicht
	*
	*	Dieser Wert stellt sicher, dass Teilchen nicht durch eine Wand gedrückt werden.
	*	Er wird in der Implementierung nur von derm
	*/
	bool get_used(){return used;};
	double get_pos_x(){return pos_x;};
	double get_pos_y(){return pos_y;};
	double get_v_x(){return v_x;};
	double get_v_y(){return v_y;};
	double get_radius(){return radius;};
	double get_masse(){return masse;};
	//setter-Funktionen
	void set_used(bool u){used = u;};
	void set_pos_x(double x){pos_x = x;}
	void set_pos_y(double y){pos_y = y;}
	void set_v_x(double x){v_x = x;}
	void set_v_y(double y){v_y = y;}
	void set_radius(double r){radius = r;};
	void set_masse(double m){masse = m;};

	void output_pos();
	void output_v();

	Teilchen();
	Teilchen(double,double,double,double,double,double);

	void Kasten_Kollision(Kasten);
	void Teilchen_Kollision(Teilchen&);
	bool Teilchen_Kollision_b(Teilchen&);
	void Spalt_Kollision(Kasten);
	double next_x_pos();
	double next_y_pos();
	void Bewege();
};

#endif /* TEILCHEN_H_ */
