//shape.cpp

#include <iostream>
#include <cstdlib>
#include <string>

#include "shape.h"

using namespace std;

Shape::Shape(){
	cout << "SHAPE CREATED" << endl;	
}

float Shape::area(){
	float f;


	return f;
}

void Shape::set_name(string n){
	name = n;
}

void Shape::set_color(string c){
	color = c;
}

string Shape::get_name(){
	return name;
}

string Shape::get_color(){
	return color;
}

bool Shape::operator<(Shape &s){
	return this->color < s.color;
}
