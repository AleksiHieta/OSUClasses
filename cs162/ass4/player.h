//player.h

#ifndef PLAYER 
#define PLAYER

#include <iostream>

#include "event.h"

using namespace std;

class Player : public Event{
	char symbol;
public:
	Player();
	~Player();
	char get_symbol();
	bool is_shot();
	char get_event();
	void get_percept();
};

#endif
