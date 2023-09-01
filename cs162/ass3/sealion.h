//sealion.h
#ifndef SEALION
#define SEALION

#include <iostream>

#include "animal.h"

using namespace std;

class Sealion : public Animal {
	int age;
	int cost;
	int baby;
	int food_cost;
	int revenue;
	string name;
public:
	Sealion();
	~Sealion();
	Sealion(const Sealion&);

	void set_age(int);

	int get_age();
	int get_cost();
	int get_baby();
	int get_food_cost();
	int get_revenue();
	string get_name();
};

#endif
