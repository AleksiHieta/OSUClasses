//bats.h

#ifndef BATS 
#define BATS

#include <iostream>

#include "event.h"

using namespace std;

class Bats : public Event{
	char symbol;
public:
	Bats();
	~Bats();
	char get_symbol();
	bool is_shot();
	char get_event();
	void get_percept();
};

#endif
