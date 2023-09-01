//rectangle.cpp

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <exception>
#include <stdexcept>
#include <fstream>

#include "rectangle.h"
#include "shape.h"

using namespace std;

float Rectangle::area(){
	float ar = width * height;

	return ar;
}

Rectangle::Rectangle(float w, float h){
	if(w == 0 || h == 0){
		throw invalid_argument("RECTANGLE BAD");
	}
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

float Rectangle::get_area(){
	return (width * height);
}

string Rectangle::get_name(){
	return "I am a Rect";
}

string Rectangle::get_color(){
	return "Rectangles are orange";
}

bool Rectangle::operator<(Rectangle &r){
	return this->area() < r.area();
}
