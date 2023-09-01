//gold.cpp

#include "gold.h"

using namespace std;

void Gold::set_symbol(char c){
	symbol = 'G';
}

char Gold::get_symbol(){
	return 'G';
}

bool Gold::is_shot(){
	return false;
}

char Gold::get_event(){
	return 'G';
}

void Gold::get_percept(){
	cout << "You see a glimmer nearby!" << endl;
}
