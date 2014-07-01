#ifndef KASTEN_H_
#define KASTEN_H_

#include <vector>

class Kasten {
private:
	double size_x;
	double size_y;
	double size_spalt;
public:
	double x_rechts;
	double x_links;
	double y_oben;
	double y_unten;

	//getter-Funktionen
	double get_size_x(){return size_x;};
	double get_size_y(){return size_y;};
	double get_size_spalt(){return size_spalt;};
	//setter-Funktion
	void set_size_x(double x){size_x = x;};
	void set_size_y(double y){size_y = y;};
	void set_size_spalt(double s){size_spalt = s;};

	void init();

	Kasten();
	Kasten(double,double,double);

};

#endif /* KASTEN_H_ */
