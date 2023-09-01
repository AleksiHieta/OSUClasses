//sealion.cpp

#include "sealion.h"
#include <iostream>

using namespace std;

Sealion::Sealion(){
	age = 0;
	cost = 700;
	baby = 1;
	food_cost = 1;
	revenue = 140;	
	name = "Sealion";
}

Sealion::~Sealion(){
}

Sealion::Sealion(const Sealion&){
	cout << "Sealion copy constructor" << endl;
}

void Sealion::set_age(int n){
	age = age + n;
}

int Sealion::get_age(){
	return age;
}

int Sealion::get_cost(){
	return cost;
}

int Sealion::get_baby(){
	return baby;
}

int Sealion::get_food_cost(){
	return food_cost;
}

int Sealion::get_revenue(){
	return revenue;
}

string Sealion::get_name(){
	return name;
}
