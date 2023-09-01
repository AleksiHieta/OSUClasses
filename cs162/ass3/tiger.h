//tiger.h
#ifndef TIGER
#define TIGER

#include <iostream>

#include "animal.h"

using namespace std;

class Tiger : public Animal {
	int age;
	int cost;
	int baby;
	int food_cost;
	int revenue;
	string name;
public:
	Tiger();
	~Tiger();
	Tiger(const Tiger&);

	void set_age(int);
//	void set_cost();
//	void set_baby();
//	void set_food_cost();
//	void set_revenue();
//	void set_name();	

	int get_age();
	int get_cost();
	int get_baby();
	int get_food_cost();
	int get_revenue();
	string get_name();	

	void print_tiger();
};

#endif
