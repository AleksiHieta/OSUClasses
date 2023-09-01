//square.cpp

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "square.h"

using namespace std;

Square::Square(){
	set_name("Lame Boiii");
	cout << "Square made" << endl;
}

void Square::set_length(float r){
	length = r;
}

float Square::get_length(){
	return length;
}

float Square::area(){
	float ar = pow(length, 2); 

	return ar;
}
