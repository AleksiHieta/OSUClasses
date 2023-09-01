//animal.cpp

#include "animal.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


Animal::~Animal(){
//	cout << "Animal Destructor Called" << endl;
}
	
Animal::Animal(){
	//cout << "Animal Created" << endl;
}

Animal::Animal(const Animal& a){
//	cout << "animal copy constructor" << endl;
}

void Animal::set_animal_name(string s){
	name = s;
}

void Animal::set_age(int s){
	age = s;
}
void Animal::set_cost(int s){
	cost = s;
}
void Animal::set_baby(int s){
	baby = s;
}
void Animal::set_food_cost(int s){
	food_cost = s;
}

void Animal::set_revenue(int s){
	revenue = s;
}

string Animal::get_animal_name(){
	return "stuff";
}

int Animal::get_age(){
	return age;
}

int Animal::get_cost(){
	return cost;
}

int Animal::get_baby(){
	return baby;
}

int Animal::get_food_cost(){
	return food_cost;
}

int Animal::get_revenue(){
	return revenue;
}
