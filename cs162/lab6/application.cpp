//application.cpp

#include <iostream>
#include <cstdlib>
#include <string>

#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std;

int main(){
	Shape shape;

	shape.set_name("Rectangle");
	shape.set_color("Burple");

	cout << "Name: " << shape.get_name() << endl; 
	cout << "Color: " << shape.get_color() << endl; 
	cout << endl;

	Rectangle r;

	r.set_width(4.20);
	r.set_height(6.66);
	
	cout << "RECTANGLE 1" << endl;
	cout << "Rectangle Width: " << r.get_width() << endl;
	cout << "Rectangle Height: " << r.get_height() << endl;
	cout << "Rectangle Area: " << r.area() << endl;
	cout << endl;

	Circle c;

	c.set_radius(4.68652);
	cout << "Circle Radius: " << c.get_radius() << endl;
	cout << "Circle Area: " << c.area() << endl;
	cout << endl;

	Square s;

	s.set_length(1.2);
	cout << "Square Length: " << s.get_length() << endl;
	cout << "Square Area: " << s.area() << endl;

	cout << "Square Name: " << s.get_name() << endl;

	cout << endl;

	Rectangle r2;

	r2.set_width(0.001);
	r2.set_height(69);
	
	cout << "RECTANGLE 2" << endl;
	cout << "Rectangle Width: " << r2.get_width() << endl;
	cout << "Rectangle Height: " << r2.get_height() << endl;
	cout << "Rectangle Area: " << r2.area() << endl;
	cout << endl;

	if(r < r2){
		cout << "First Rect is SMALLER than Second Rect" << endl;
	}
	else {
		cout << "First Rect is BIGGER than Second Rect" << endl;
	}

	

	return 0;
}
