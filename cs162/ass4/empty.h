//empty.h

#ifndef EMPTY 
#define EMPTY

#include <iostream>

#include "event.h"

using namespace std;

class Empty : public Event{
	char symbol;
public:
	Empty();
	~Empty();
	char get_symbol();
	bool is_shot();
	char get_event();
	void get_percept();
};

#endif
