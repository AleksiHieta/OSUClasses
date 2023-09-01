//pit.h

#ifndef PIT 
#define PIT

#include <iostream>

#include "event.h"

using namespace std;

class Pit : public Event{
	char symbol;
public:
	Pit();
	char get_symbol();
	bool is_shot();
	char get_event();
	void get_percept();
};

#endif
