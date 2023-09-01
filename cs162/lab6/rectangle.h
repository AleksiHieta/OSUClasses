//rectangle.h
#ifndef RECT
#define RECT

#include <iostream>
#include <cstdlib>

#include "shape.h"

class Rectangle : public Shape {
	float width;
	float height;
public:
	Rectangle();	
	
	void set_width(float);
	void set_height(float);
	
	float get_height();
	float get_width();

	float area();

	bool operator<(Rectangle &r);
};

#endif
