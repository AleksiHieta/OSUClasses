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
	string get_name();
	string get_color();

	bool operator<(Shape &s);

	float area();
	
};

#endif
