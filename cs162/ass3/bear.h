//bear.h
#ifndef BEAR
#define BEAR

#include <iostream>

#include "animal.h"

using namespace std;

class Bear : public Animal {
	int age;
	int cost;
	int baby;
	int food_cost;
	int revenue;
	string name;
public:
	Bear();
	~Bear();
	Bear(const Bear&);

	void set_age(int);	
	
	int get_age();
	int get_cost();
	int get_baby();
	int get_food_cost();
	int get_revenue();
	string get_name();
};

#endif
