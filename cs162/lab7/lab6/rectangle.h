//rectangle.h
#ifndef RECT
#define RECT

#include <iostream>
#include <cstdlib>
#include <exception>

#include "shape.h"

class Rectangle : public Shape {
	float width;
	float height;
public:
	Rectangle();	
	Rectangle(float w, float l);
	
	void set_width(float);
	void set_height(float);
	
	float get_height();
	float get_width();

	float get_area();
	virtual string get_name();
	virtual string get_color();

	float area();

	bool operator<(Rectangle &r);
};

#endif
