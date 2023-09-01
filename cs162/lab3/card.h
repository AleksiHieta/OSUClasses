#ifndef CARD
#define CARD


#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 *Card characteristics: suit (diamond, heart, club, spade) and number (1-13)
 *
*/

class Card {
	string suit;
	int rank;
public:
	void set_card(int, string);
	//Card get_card();
	void print_card();	
};

#endif 

