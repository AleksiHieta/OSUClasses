//bear.cpp

#include "bear.h"
#include <iostream>

using namespace std;

Bear::Bear(){
	age = 0;
	cost = 5000;
	baby = 2;
	food_cost = 3; 
	revenue = 500; 
	name = "Bear";

}

Bear::~Bear(){

}

Bear::Bear(const Bear&){
	cout << "Bear copy constructor called" << endl;

}

void Bear::set_age(int n){
	age = age + n;
}

int Bear::get_age(){
	return age;
}

int Bear::get_cost(){
	return cost;
}

int Bear::get_baby(){
	return baby;
}

int Bear::get_food_cost(){
	return food_cost;
}

int Bear::get_revenue(){
	return revenue;
}

string Bear::get_name(){
	return name;
}
