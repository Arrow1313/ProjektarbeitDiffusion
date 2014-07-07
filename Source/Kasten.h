#ifndef KASTEN_H_
#define KASTEN_H_

#include <vector>

/**  \class Kasten
 *
 * \brief Diese Klasse liefert den Kasten in dem die Teilchen sich bewegen.
 *
 *  Der Kasten setzt sich aus sechs Wänden zusammen, vier Außenwände und zwei Innenwände für den Spalt.
 *  Der Aufbau des Kastens basiert auf auf der Annahme, dass er zum Ursprung symmetrisch ist, dadurch ergben
 *  sich zwei gleich große  Teilkästen.
 */

class Kasten {
private:
	double size_x; 		/** \var size_x
						 *	Die Variable gibt die Länge des Kastens in X-Richtung an
						 */

	double size_y;		/** \var size_y
						 *	Die Variable gibt die Länge des Kastens in Y-Richtung an
						 */

	double size_spalt;	/** \var size_spalt
						 *	Die Variable gibt die Breite des Spaltes an
						 */
public:
	double x_rechts;	/** \var  x_rechts
						 * 	Die Variable gibt die Position der rechten Wand auf der X-Achse an
						 */

	double x_links;		/** \var x_links
						 *	Die Variable gibt die Position der linken Wand auf der X-Achse an
						 */

	double y_oben;		/** \var y_oben
						 *	Die Variable gibt die Position der oberen Wand auf der Y-Achse an
						 */

	double y_unten;		/** \var y_unten
						 *	Die Variable gibt die Position der unteren Wand auf der Y-Achse an
						 */

	//getter-Funktionen
	double get_size_x(){return size_x;}; 			/** \fn double get_size_x()
	 	 	 	 	 	 	 	 	 	 	 	 	 *	 Die Methode gibt die Länge des Kastens in X-Richtung zurück.
													 */

	double get_size_y(){return size_y;};			/** \fn double get_size_y()
													 *	 Die Funktion gibt die Länge des Kastens in Y-Richtung zurück
													 */

	double get_size_spalt(){return size_spalt;};	/** \fn  double get_size_spalt()
													 *	 Die Funktion gibt die Breite des Spaltes zurück
													 */

	//setter-Funktion
	void set_size_x(double x){size_x = x;};			/** \fn void set_size_x(double x)
	 	 	 	 	 	 	 	 	 	 	 	 	 *	 Mit diser Funktion kann die Länge des Kastens in X-Richung verändert werden
													 *	 \param x Die neue Länge.
													 */

	void set_size_y(double y){size_y = y;};			/** \fn void set_size_y(double y)
													 *	 Mit diser Funktion kann die Länge des Kastens in Y-Richung verändert werden
													 *	 \param y Die neue Länge.
													 */

	void set_size_spalt(double s){size_spalt = s;};	/** \fn void set_size_spalt(double s)
													 *	 Mit diser Funktion kann die Breite des Spaltes verändert werden
													 *	 \param s Die neue Spaltbreichte
													 */


	Kasten();										/** \fn Kasten()
													 *	Initialisiert den Kasten mit den default Werten X-Länge = 100, Y-Länge = 100, Spaltbreite = 20.
													 */

	Kasten(double,double,double);					/** \fn Kasten(double x,double y,double s)
													 *	Mit diesem Konstruktor können die Werte des Kastens direkt übergben werden.
													 *	\param x Länge des Kastens in X-Richtung
													 *	\param y Länge des Kastens in Y-Richtung
													 *	\param s Breite des Spaltes
													 */

};

#endif /* KASTEN_H_ */
