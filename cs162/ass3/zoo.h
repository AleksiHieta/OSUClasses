//zoo.h
#ifndef ZOO
#define ZOO

#include <iostream>
#include <cstdlib>

#include "animal.h"
#include "tiger.h"
#include "bear.h"
#include "sealion.h"

using namespace std;

class Zoo {
	Animal** dudes_in_zoo;
	Tiger* tigers_in_zoo;
	Bear* bears_in_zoo;
	Sealion* sealions_in_zoo;

	int BANK;
	int size;
	int size_tiger;
	int size_bear;
	int size_sealion;
	bool buy;
	int boost;
public:
	Zoo();
	~Zoo();
	Zoo(const Zoo&);
	int get_BANK();

	void add_tiger(bool);
	void add_bear(bool);
	void add_sealion(bool);

	void rem_tiger();
	void rem_bear();
	void rem_sealion();

	int random_event();
	void revenue(int);
	void buy_animals(int, int);	
	void food();

	void setup_game();
	bool out_o_money();
	void user_turn();
};

#endif
