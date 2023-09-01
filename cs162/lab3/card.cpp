#include <iostream>
#include <cstdlib>
#include "card.h"

using namespace std;

//mutators
void Card::set_card(int r, string s){
	rank = r;
	suit = s;
}

//accessors
//Card Card::get_card(){
//	return card;
//}

void Card::print_card(){
	cout << rank << " " << suit;
}
