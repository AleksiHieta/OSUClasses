//rectangle.cpp

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "rectangle.h"
#include "shape.h"

using namespace std;

float Rectangle::area(){
	float ar = width * height;

	return ar;
}

Rectangle::Rectangle(){
	cout << "Rectangle created" << endl;
}

void Rectangle::set_width(float w){
	width = w;
}

void Rectangle::set_height(float h){
	height = h;
}

float Rectangle::get_width(){
	return width;
}

float Rectangle::get_height(){
	return height;
}

bool Rectangle::operator<(Rectangle &r){
	return this->area() < r.area();
}
