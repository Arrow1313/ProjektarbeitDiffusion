#ifndef TEILCHEN_H_
#define TEILCHEN_H_

#include "Kasten.h"

/** \class
 *
 * 	\brief Die Klasse stellt Teilchen für den Diffusionsprozess zur verfügung.
 *
 * 	In dieser Klasse sind alle Teilchen Eingenschaften enthalten, so wie Methoden und Variablen zu Verwaltung
 * 	der Bewegung.
 * 	Es wurden auch Klassenatribute definiert, zur analyse des Stoßhäufgikeiten.
 */

class Teilchen {
private:
	double pos_x; 	/** \var pos_x
					 *	Diese Varibale gibt die x-Position des Teilchens an.
					 */

	double pos_y; 	/**	\var pos_y
					 *	Diese Variable gibt die y-Position des Teilchens an.
					 */

	double v_x; 	/**	\var v_x
					 *	Diese Variable gibt die Geschwindigkeit in x-Richtung an.
					 */

	double v_y; 	/**	\var v_y
					 *	Diese Variable gibt die Geschwindigkeit in y-Richtung an.
					 */

	double radius;	/**	\var radius
					 *	Diese Variable gibt den Radius des Teilchens an.
					 */

	double masse;	/** \var masse
					 *	Diese Variable gibt die Masse des Teilchens an.
					 */

	bool used;		/** \var used
					 *	Diese Variable gibt an, ob das Teilchen in einem Rechenzyklus schon benutzt wurde.
					 */
public:

	static double dt;					/** \var dt
										 *	Gibt den Zeitschritt für die iterationen an.
										 *	Für exakte Simulationen sollte dt sehr klein gewählt werden.
										 */

	static int teilchen_kollisionen;	/** \var teilchen_kollisionen
										 *	Gibt die Anzahl der Teilchen-Teilchen kollisionen an.
										 */

	static int wand_kollisionen;		/**	\var wand_kollisionen
										 *	Gibt die Anzahl der Wand-Teilchen kollisionen an.
										 */

	static int spalt_kollisionen;		/**	\var spalt_kollisionen
										 *	Gibt die Anzahl der Spalt-Teilchen kollisionen an.
										 */
	//getter-Funktion
	bool get_used(){return used;};		/** \fn get_used()
										 *	Gibt zurück, ob used gesetz ist.
										 */


	double get_pos_x(){return pos_x;};	/** \fn get_pos_x()
	 	 	 	 	 	 	 	 	 	 *	Gibt die x-Position des Teilchens zurück.
	 	 	 	 	 	 	 	 	 	 */

	double get_pos_y(){return pos_y;};	/** \fn get_pos_y()
	 	 	 	 	 	 	 	 	 	 *	Gibt die y-Position des Teilchens zurück.
	 	 	 	 	 	 	 	 	 	 */

	double get_v_x(){return v_x;};		/** \fn get_v_x()
	 	 	 	 	 	 	 	 	 	 *	Gibt die x-Geschwindigkeit des Teilchens zurück.
	 	 	 	 	 	 	 	 	 	 */

	double get_v_y(){return v_y;};		/** \fn get_v_y()
	 	 	 	 	 	 	 	 	 	 *	Gibt die y-Geschwindigkeit des Teilchens zurück.
	 	 	 	 	 	 	 	 	 	 */

	double get_radius(){return radius;};	/** \fn get_used()
	 	 	 	 	 	 	 	 	 	 	 *	Gibt den Radius des Teilchens zurück.
	 	 	 	 	 	 	 	 	 	 	 */

	double get_masse(){return masse;};		/** \fn get_used()
	 	 	 	 	 	 	 	 	 	 	 *	Gibt die Masse des Teilchens zurück.
	 	 	 	 	 	 	 	 	 	 	 */


	//setter-Funktionen
	void set_used(bool u){used = u;};		/** \fn set_used(bool u)
	 	 	 	 	 	 	 	 	 	 	 *	Mit der Methode kann die Variable used gesetzt werden.
	 	 	 	 	 	 	 	 	 	 	 *	\param u Wert von used.
	 	 	 	 	 	 	 	 	 	 	 */

	void set_pos_x(double x){pos_x = x;}	/**	\fn set_pos_x(double x)
											 *	Mit der Methode kann die x-Position gesetzt werden.
											 *	\param x Neue x-Position.
											 */

	void set_pos_y(double y){pos_y = y;}	/**	\fn set_pos_y(double y)
	 	 	 	 	 	 	 	 	 	 	 *	Mit der Methode kann die y-Position gesetzt werden.
	 	 	 	 	 	 	 	 	 	 	 *	\param y Neue y-Position.
	 	 	 	 	 	 	 	 	 	 	 */

	void set_v_x(double x){v_x = x;}		/**	\fn set_v_x(double x)
	 	 	 	 	 	 	 	 	 	 	 *	Mit der Methode kann die x-Geschwindigkeit gesetzt werden.
	 	 	 	 	 	 	 	 	 	 	 *	\param x Die neue x-Geschwindigkeit.
	 	 	 	 	 	 	 	 	 	 	 */

	void set_v_y(double y){v_y = y;}		/**	\fn set_v_y(double y)
	 	 	 	 	 	 	 	 	 	 	 *	Mit der Methode kann die y-Geschwindigkeit gesetzt werden.
	 	 	 	 	 	 	 	 	 	 	 *	\param y Die neue y-Geschwindigkeit.
	 	 	 	 	 	 	 	 	 	 	 */

	void set_radius(double r){radius = r;};	/**	\fn set_radius(double r)
	 	 	 	 	 	 	 	 	 	 	 *	Mit der Methode kann der Radius des Teilchens gesetzt werden.
	 	 	 	 	 	 	 	 	 	 	 *	\param r Neuer Radius.
	 	 	 	 	 	 	 	 	 	 	 */

	void set_masse(double m){masse = m;};	/**	\fn set_masse(double m)
	 	 	 	 	 	 	 	 	 	 	 *	Mit der Methode kann die Masse des Teilchens gesetzt werden.
	 	 	 	 	 	 	 	 	 	 	 *	\param m Die neue Masse.
	 	 	 	 	 	 	 	 	 	 	 */


	void output_pos();	/**	\fn output_pos()
						 *	Mit der Methode werden die x- und y-Positionen ausgegeben.
						 */

	void output_v();	/**	\fn output_v()
						 *	Mit dieser Methode werden die x- und y-Geschwindigkeiten ausgegeben.
						 */

	Teilchen();												/** \fn Teilchen()
															 *	Default Konstruktor mit pos_x=0, pos_y=0, v_x=1, v_y=1, radius=1, masse=1 und used=0
															 */

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
