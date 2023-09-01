//room.h

#ifndef ROOM
#define ROOM

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "player.h"
#include "event.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"
#include "wumpus.h"
#include "empty.h"

using namespace std;

class Room {
	vector< vector<Event*> > room_cave;
	int size;
	bool mode;
	int player_row;
	int player_col;
	int escape_row;
	int escape_col;
	int wumpus_row;
	int wumpus_col;
	int row;
	int col;
	char choice;
	char direction;
	int arrow_count;
	bool gold_collected;
	bool alive;
	char event;
public:
	Room();
	void extend_room_cave(int s, bool m);
	void set_room_cave();
	void print_room_cave();

	void check_nearby();
};

#endif
