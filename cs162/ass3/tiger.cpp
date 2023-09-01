//tiger.cpp

#include "tiger.h"
#include <iostream>

using namespace std;

Tiger::Tiger(){
	age = 0;
	cost = 12000;
	baby = 3;
	food_cost = 5; 
	revenue = 1200;
	name = "Tiger";
	
}

Tiger::~Tiger(){

}

Tiger::Tiger(const Tiger&){
	cout << "Tiger copy constructor" << endl;

}

void Tiger::set_age(int n){
	age = age + n;
}

int Tiger::get_age(){
	return age;
}

int Tiger::get_cost(){
	return cost;
}

int Tiger::get_baby(){
	return baby;
}

int Tiger::get_food_cost(){
	return food_cost;
}

int Tiger::get_revenue(){
	return revenue;
}

string Tiger::get_name(){
	return name;
}

void Tiger::print_tiger(){
	cout << "____________________" << endl;
	cout << "  TAMMY THE TIGER   " << endl;
	cout << "  (^-==-/^)         " << endl;
	cout << "  >| == //<        " << endl;
	cout << " :== q''p ==:     _ " << endl;
	cout << "  .__ qp __.    .' )" << endl;
	cout << "   | ^--^     /-'   " << endl;
	cout << "  |_'    / )  '/    " << endl;
	cout << "  (  )    |-'-/     " << endl;
	cout << "  ^^,   |-|--'      " << endl;
	cout << " ( '-    |_| )      " << endl;
	cout << "  -     |-|/        " << endl;
	cout << " (( )^---( ))       " << endl;
	cout << "____________________" << endl;
}
