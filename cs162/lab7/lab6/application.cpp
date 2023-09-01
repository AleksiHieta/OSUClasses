//application.cpp

#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <stdexcept>

#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

using namespace std;

void print_shape_info(Shape &s){
	cout << s.get_name() << endl;
	cout << s.get_color() << endl;
	cout << s.get_area() << endl;
}

int main(){
	Shape* array[3]; //rectangle, circle, square
	Rectangle R1;
	Circle C1;
	Square S1;

	R1.set_height(1);
	R1.set_width(69);
	C1.set_radius(1);
	S1.set_length(20.5);

	Shape* rptr;
	rptr = &R1;


	array[0] = &R1;
	array[1] = &C1;
	array[2] = &S1;
	
	for(int i = 0; i < 3; i++){
		cout << array[i]->get_name() << endl;
		cout << array[i]->get_color() << endl;
		cout << array[i]->get_area() << endl;
	}

	cout << "ALTERNATE EXAMPLE" << endl;
	print_shape_info(R1);	


	try{
		Rectangle R2(0, 1);

	}catch(invalid_argument e){
		cout << "INVALID RECTANGLE AREA" << endl;
		cout << "Area of 0 found" << endl;
		cout << e.what();
	}	




































/*	Shape shape;

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

	
*/
	return 0;
}
