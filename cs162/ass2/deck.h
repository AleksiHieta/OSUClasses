// deck.h - Header File
#ifndef DECK
#define	DECK

#include <iostream>
#include <cstdlib>
#include "card.h"
#include <string>

using namespace std;

class Deck {
	Card deck[52];
	Card pile;
	int n_cards;
	
	int position_in_deck;
public:

	Deck();
	~Deck();
	Deck(const Deck&);

	Card get_deck_card(int);

	int get_card_suit(int);
	int get_card_rank(int);

	void create_deck();
	void shuffle_deck();
	void print_deck();
	
	void set_pile(int, int);
	void print_pile();

	int get_pile_rank();
	int get_pile_suit();
};

#endif
