//wumpus.cpp

#include "wumpus.h"

using namespace std;

void Wumpus::set_symbol(char c){
	symbol = 'W';
}

char Wumpus::get_symbol(){
	return 'W';
}

bool Wumpus::is_shot(){
	return true;
}

char Wumpus::get_event(){
	return 'W';
}

void Wumpus::get_percept(){
	cout << "You smell a terrible stench!" << endl;
}	
