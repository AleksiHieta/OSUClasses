// Game.h - Header File
#ifndef GAME
#define GAME

#include <iostream>
#include "player.h"
#include "deck.h"
#include "hand.h"
#include "card.h"

using namespace std;

class Game {
	Deck bigDeck;
	Player players[2];
	int input;
	
	Card* hand;
public:
	Game();
	~Game();
	Game(const Game&);
	Game& operator=(const Game& g);	

	void setup_game();
	void deal_cards();
	void print_game();

	void user_turn();
	void com_turn();

	bool winner();
};

#endif
