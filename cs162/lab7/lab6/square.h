//square.h
#ifndef SQUARE
#define SQUARE

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "rectangle.h"

class Square : public Rectangle {
	float length;
public:
	Square();
	void set_length(float r);
	float get_length();	

	float get_area();
	string get_name();
	string get_color();

	float area();	
};

#endif
