//bats.cpp

#include "bats.h"

using namespace std;

Bats::Bats(){
	symbol = 'B';
}

Bats::~Bats(){
}

char Bats::get_symbol(){
	return 'B';
}
bool Bats::is_shot(){
	return false;
}

char Bats::get_event(){
	return 'B';
}

void Bats::get_percept(){
	cout << "You hear wings flapping!" << endl;
}	
