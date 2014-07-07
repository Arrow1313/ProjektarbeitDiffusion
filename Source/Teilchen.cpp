#include "Teilchen.h"
#include "iostream"
#include "math.h"

double Teilchen::dt = 0.1;
int Teilchen::teilchen_kollisionen = 0;
int Teilchen::wand_kollisionen = 0;
int Teilchen::spalt_kollisionen = 0;

Teilchen::Teilchen()
:pos_x(0), pos_y(0), v_x(1), v_y(1), radius(1), masse(1), used(0)
{

}

Teilchen::Teilchen(double x, double y, double x_v, double y_v, double r, double m)
:used(0)
{
	this->pos_x = x;
	this->pos_y = y;
	this->v_x = x_v;
	this->v_y = y_v;
	this->radius = r;
	this->masse = m;
}


void Teilchen::output_pos(){
	std::cout << "pos_x: " << this->get_pos_x() << " pos_y: " << this->get_pos_y() << std::endl;
}

void Teilchen::output_v(){
	std::cout << "v_x: " << this->get_v_x() << " pos_y: " << this->get_v_y() << std::endl;
}

double Teilchen::next_x_pos(){
	return (this->pos_x + this->v_x * this->dt);
}

double Teilchen::next_y_pos(){
	return (this->pos_y + this->v_y * this->dt);
}

void Teilchen::Kasten_Kollision(Kasten k){

	if(this->pos_x > k.x_rechts && this->next_x_pos() <= k.x_rechts){
		this->v_x *= -1;
		this->used = 1;
		std::cout << "Kollison mit der Wand rechts" << std::endl;
		this->wand_kollisionen++;
	}

	if(this->pos_x < k.x_links && this->next_x_pos() > k.x_links){
		this->v_x *= -1;
		this->used = 1;
		std::cout << "Kollison mit der Wand links" << std::endl;
		this->wand_kollisionen++;
	}

	if(this->pos_y < k.y_oben && this->next_y_pos() > k.y_oben){
		this->v_y *= -1;
		this->used = 1;
		std::cout << "Kollison mit der Wand oben" << std::endl;
		this->wand_kollisionen++;
	}

	if(this->pos_y > k.y_unten && this->next_y_pos() < k.y_unten){
		this->v_y *= -1;
		this->used = 1;
		std::cout << "Kollison mit der Wand unten" << std::endl;
		this->wand_kollisionen++;
	}
}


void Teilchen::Kasten_Kollison_radius(Kasten Kasten){
	double abstand_rechts = fabs(this->pos_x) - fabs(Kasten.x_rechts);
	double abstand_links = fabs(this->pos_x) - fabs(Kasten.x_links);
	double abstand_oben = fabs(this->pos_y) - fabs(Kasten.y_oben);
	double abstand_unten = fabs(this->pos_y) - fabs(Kasten.y_unten);

	if(abstand_rechts < this->radius){
		this->v_x *= -1;
		this->used = 1;
		std::cout << "Kollison mit der Wand rechts" << std::endl;
		this->wand_kollisionen++;
	}

	if(abstand_links < this->radius){
		this->v_x *= -1;
		this->used = 1;
		std::cout << "Kollison mit der Wand links" << std::endl;
		this->wand_kollisionen++;
	}

	if(abstand_oben < this->radius){
		this->v_y *= -1;
		this->used = 1;
		std::cout << "Kollison mit der Wand oben" << std::endl;
		this->wand_kollisionen++;
	}

	if(abstand_unten < this->radius){
		this->v_y *= -1;
		this->used = 1;
		std::cout << "Kollison mit der Wand unten" << std::endl;
		this->wand_kollisionen++;
	}
}

void Teilchen::Teilchen_Kollision(Teilchen& t){
	double x_abstand;
	double y_abstand;
	double abstand;
	double minimal_abstand;
	double temp_v_x_1;
	double temp_v_y_1;
	double temp_v_x_2;
	double temp_v_y_2;

	x_abstand = fabs(t.get_pos_x()- this->pos_x);
	y_abstand = fabs(t.get_pos_y() - this->pos_y);
	abstand = sqrt((pow(x_abstand,2.)+pow(y_abstand,2.)));
	minimal_abstand = this->radius + t.get_radius();

	if(abstand < minimal_abstand){
		temp_v_x_1 = (this->masse*this->v_x + t.get_masse()*(2*t.get_v_x()-this->v_x))/(this->masse+t.get_masse());
		temp_v_y_1 = (this->masse * this->v_y + t.get_masse()*(2*t.get_v_y()-this->v_y))/(this->masse+t.get_masse());

		temp_v_x_2 = (t.get_masse()*t.get_v_x()+this->masse*(2*this->v_x-t.get_v_x()))/(this->masse+t.get_masse());
		temp_v_y_2 = (t.get_masse()*t.get_v_y()+this->masse*(2*this->v_y-t.get_v_y()))/(this->masse+t.get_masse());

		this->v_x = temp_v_x_1;
		this->v_y = temp_v_y_1;

		t.set_v_x(temp_v_x_2);
		t.set_v_y(temp_v_y_2);

		this->used = 1;
		t.set_used(1);

		std::cout << "Teilchen Kollison" << std::endl;

		this->teilchen_kollisionen++;
	}

}

bool Teilchen::Teilchen_Kollision_b(Teilchen& t){
	double x_abstand;
		double y_abstand;
		double abstand;
		double minimal_abstand;

		x_abstand = fabs(t.get_pos_x()- this->pos_x);
		y_abstand = fabs(t.get_pos_y() - this->pos_y);
		abstand = sqrt((pow(x_abstand,2.)+pow(y_abstand,2.)));
		minimal_abstand = this->radius + t.get_radius();

		if(abstand < minimal_abstand){
			return 1;
		}

		return 0;
}

void Teilchen::Spalt_Kollision(Kasten k){
	if((this->pos_x < 0 && this->next_x_pos() > 0)
		|| (this->pos_x > 0 && this->next_x_pos() < 0)){
		if(fabs(this->pos_y) > (k.get_size_spalt()/2)){
			std::cout << "Kollsion Spalt" << std::endl;
			this->v_x *= -1;
			this->used = 1;

			this->spalt_kollisionen++;
		}
	}
}

void Teilchen::Bewege(){
	this->pos_x += this->dt * this->v_x;
	this->pos_y += this->dt * this->v_y;

	this->used = 0;
}
