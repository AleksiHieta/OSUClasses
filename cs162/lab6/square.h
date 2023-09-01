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

	float area();	
};

#endif
