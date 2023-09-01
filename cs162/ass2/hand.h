// hand.h - Header File
#ifndef HAND
#define HAND

#include <iostream>
#include "deck.h"

using namespace std;

class Hand {
	Card* hand;

	int n_cards;
public:
	//idfk
	
	Hand();
	~Hand();
	Hand(int );
	Hand(const Hand& h);
	Hand& operator=(const Hand& h);

	void create_hand();

	void set_hand(int, int, int);
	int get_hand_rank(int);
	int get_hand_suit(int);

	void print_hand(int);	


	void draw_card(int i, int k);
	void play_card();
	void print_hand();

	Card get_card_hand(int n);

	void add_card();
	void rem_card();
	
	void check_suit();
	void check_rank();
		
	int select_suit(); //returns best option com suit
	int select_card();
	//assignment operator overload thing?
};

#endif
