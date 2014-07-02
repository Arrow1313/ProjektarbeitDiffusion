/*
 * Kasten.cpp
 *
 *  Created on: 19.06.2014
 */

#include "Kasten.h"

Kasten::Kasten()
:size_x(100),size_y(100),size_spalt(20)
{
	this->x_links = (size_x/2);
	this->x_rechts = -(size_x/2);
	this->y_oben = (size_y/2);
	this->y_unten = -(size_y/2);
}

Kasten::Kasten(double x,double y,double s){
	this->size_x = x;
	this->size_y = y;
	this->size_spalt = s;

	this->x_links = (size_x/2);
	this->x_rechts = -(size_x/2);
	this->y_oben = (size_y/2);
	this->y_unten = -(size_y/2);
}
