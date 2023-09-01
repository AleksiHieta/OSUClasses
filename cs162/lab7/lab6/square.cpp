//square.cpp

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "square.h"

using namespace std;

Square::Square(){
	set_name("Lame Boiii");
	set_color("Grey");
	cout << "Square made" << endl;
}

void Square::set_length(float r){
	length = r;
}

float Square::get_length(){
	return length;
}

float Square::get_area(){
	return pow(length, 2);
}

string Square::get_name(){
	return "LAME BOIIII";
}

string Square::get_color(){
	return "GREY";
}

float Square::area(){
	float ar = pow(length, 2); 

	return ar;
}
