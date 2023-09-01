/************************************************************
 *Program: Hunt the Wumpus
 *Author: Aleksi Hieta
 *Date: 03/01/2020
 *Description: plays the game "Hunt the Wumpus" based off 
 *of an early text adventure game. This version now includes 
 *a grid, bats, pit, gold, and wumpus.
************************************************************/

#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <sstream>
#include <vector>

#include "player.h"
#include "bats.h"
#include "gold.h"
#include "empty.h"
#include "pit.h"
#include "wumpus.h"
#include "room.h"
#include "event.h"

using namespace std;

int main(int argc, char* argv[]){
	int size;
	bool mode;
	string type;

	if(argc != 3){
		cout << "Invalid number of arguments" << endl;
		return 0;
	}
	else{
		string size1 = argv[1];
		type = argv[2];	

		if(!(istringstream(size1) >> size)){
			cout << "Invalid Input for Size" << endl;
			return 0;
		};
		if(size > 10 || size < 4){
			cout << "Invalid Input for Size" << endl;
			cout << "(Enter between 4 and 10)" << endl;
			return 0;
		}
		if(!(istringstream(type) >> mode)){
			cout << "Invalid Input for Mode" << endl;
			return 0;
		}
	}
	cout << endl;
	cout << "           Welcome to   " << endl;
	cout << "       =================" << endl;
	cout << "        HUNT THE WUMPUS " << endl;
	cout << "       =================" << endl;
	if(mode == 1){
	cout << "          (Debug Mode)  " << endl;
	}
	cout << endl;
	cout << endl;
	if(mode == 1){
	cout << "Player = * | Bats = B | Wumpus = W | Pit = P | Gold = G" << endl;
	}

	Room room;
	room.extend_room_cave(size, mode);
	room.set_room_cave();



	return 0;
}
