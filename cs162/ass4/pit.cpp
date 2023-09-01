//pit.cpp

#include "pit.h"

using namespace std;

Pit::Pit(){
	symbol = 'P';
}

char Pit::get_symbol(){
	return 'P';
}

bool Pit::is_shot(){
	return false;
}

char Pit::get_event(){
	return 'P';
}

void Pit::get_percept(){
	cout << "You feel a breeze!" << endl;
}	
