//animal.h
#ifndef ANIMAL
#define ANIMAL

#include <iostream>
#include <cstdlib>

using namespace std;

class Animal{
	string name;
	int age;
	int cost;
	int baby;
	int food_cost;
	int revenue;
	
public:
	Animal();
	~Animal();
	Animal(const Animal&);
		
	void set_animal_name(string);
	void set_age(int);
	void set_cost(int);	
	void set_baby(int);	
	void set_food_cost(int);	
	void set_revenue(int);	

	string get_animal_name();
	int get_age();
	int get_cost();	
	int get_baby();	
	int get_food_cost();	
	int get_revenue();	
};

#endif
