//circle.cpp

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "circle.h"

using namespace std;

Circle::Circle(){
	cout << "circle made" << endl;
}

void Circle::set_radius(float r){
	radius = r;
}

float Circle::get_radius(){
	return radius;
}

float Circle::area(){
	float ar = pow(radius, 2) * 3.14159; 

	return ar;
}
