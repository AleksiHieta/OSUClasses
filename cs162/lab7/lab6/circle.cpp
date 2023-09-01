//circle.cpp

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "circle.h"

using namespace std;

Circle::Circle(){
	//set_name("Circle")
	//set_color("Green")

	cout << "circle made" << endl;
}

void Circle::set_radius(float r){
	radius = r;
}

float Circle::get_radius(){
	return radius;
}

float Circle::get_area(){
	return pow(radius, 2) * 3.1415;
}

string Circle::get_name(){
	return "I AM CIRCLE";
}

string Circle::get_color(){
	return "Red is my color";
}

float Circle::area(){
	float ar = pow(radius, 2) * 3.14159; 

	return ar;
}
