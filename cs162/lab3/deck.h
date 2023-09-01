#ifndef DECK
#define DECK

#include <iostream>
#include <cstdlib>
#include "card.h"
#include <string>

using namespace std;

/*
 *Deck of cards: contains all 52 cards
 *
*/

class Deck {
	Card BigDeck[52];
	Card temp;
public:
//	void get_deck();
//	void set_deck();
	void create_deck();
	void shuffle_deck();
	void print_deck();
};

#endif
