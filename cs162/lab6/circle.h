//circle.h
#ifndef CIRCLE
#define CIRCLE

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "shape.h"

class Circle : public Shape {
	float radius;
public:
	Circle();
	void set_radius(float r);
	float get_radius();	

	float area();	
};

#endif
