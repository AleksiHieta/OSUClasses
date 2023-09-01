//event.cpp

#include "event.h"

using namespace std;

Event::Event(){
	thang = ' ';
	there = false;
}

char Event::get_symbol(){
	cout << "Default event symbol called" << endl;
	return 'F';
}

void Event::set_there(bool b){
	there = b;
}

bool Event::is_there(){
	return there;
}
