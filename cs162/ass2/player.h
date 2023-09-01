// player.h - Header File
#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>
#include "hand.h"
#include "deck.h"

using namespace std;

class Player {
	//Hand hand;
	Hand hand;
	string name; //name of player
public:
	Player();
	~Player();
	Player(const Player&);

	//Hand get_hand(int);
	void print_player_hand();
	void create_player_hand();

	void set_hand_thang(int, int, int);
	int get_hand_card_rank(int);
	int get_hand_card_suit(int);

	void print_hand_thang(int);
	int ask_user_card();
};

#endif
