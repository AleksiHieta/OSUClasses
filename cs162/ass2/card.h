// Card.h - Header File
#ifndef CARD
#define CARD

#include <iostream>
#include <string>

using namespace std;

class Card {
	int size;
	int rank;
	int suit;
public:
	Card();
	~Card();
	Card(const Card&);

	int get_suit();	
	int get_rank();	
	void set_card(int, int);
	void print_card();
};

#endif
