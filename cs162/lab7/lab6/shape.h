//shape.h
#ifndef SHAPE
#define SHAPE

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Shape {
	string name;
	string color;
public:
	Shape();
	void set_name(string); 
	void set_color(string); 
	virtual string get_name();
	virtual string get_color();
	virtual float get_area() = 0;

	bool operator<(Shape &s);
};

#endif
