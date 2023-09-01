//empty.cpp

#include "empty.h"

using namespace std;

Empty::Empty(){
	//cout << "Empty created" << endl;
}

Empty::~Empty(){
	//cout << "Empty destoyed" << endl;
}

char Empty::get_symbol(){
	return ' ';
}

bool Empty::is_shot(){
	return false;
}

char Empty::get_event(){
	return 'E';
}

void Empty::get_percept(){
	//nothing happens
}
