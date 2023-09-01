//gold.h

#ifndef GOLD 
#define GOLD

#include <iostream>

#include "event.h"

using namespace std;

class Gold : public Event{
	char symbol;
public:
	void set_symbol(char);
	char get_symbol();
	bool is_shot();
	char get_event();
	void get_percept();
};

#endif
