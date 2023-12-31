card.h                                                                                              0000660 0031051 0072611 00000000453 13616346523 011362  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               // Card.h - Header File
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
                                                                                                                                                                                                                     deck.cpp                                                                                            0000660 0031051 0072611 00000002623 13616362676 011722  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               // deck.cpp - Implementation File

#include "deck.h"
#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

Deck::Deck(){

}

Deck::~Deck(){
	//delete [] deck;
}

Deck::Deck(const Deck& ){
}

Card Deck::get_deck_card(int i){
//	position_in_deck = i;
//	cout << "TEST" << endl;
//	deck[i].print_card();
//	cout << "TEST" << endl;	
	return deck[i];
}

int Deck::get_card_rank(int i){
	int rk = deck[i].get_rank();

	return rk;
}

int Deck::get_card_suit(int i){
	int st = deck[i].get_suit();

	return st;
}

void Deck::create_deck(){
	for(int i = 0; i < 13; i++){
		deck[i].set_card(i+1, 1);
		deck[i+13].set_card(i+1, 2);
		deck[i+26].set_card(i+1, 3);
		deck[i+39].set_card(i+1, 4);
	}
	//cout << "deck created" << endl;
}

void Deck::shuffle_deck(){
	Card temp;
	srand(time(NULL));
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 51; j++){
			for(int k = 0; k < 51-j; k++){
				if(rand() % 2){
					temp = deck[k];
					deck[k] = deck[k+1];
					deck[k+1] = temp;
				}
			}
		}
	}
	position_in_deck = 0;
	//cout << "deck shuffled" << endl;
}


void Deck::print_deck(){
	for(int i = 0; i < 52; i++){
		deck[i].print_card();
	}
}

void Deck::set_pile(int i, int j){
	pile.set_card(i, j);
}

void Deck::print_pile(){
	cout << "PILE CARD: ";
	pile.print_card();
}

int Deck::get_pile_rank(){
	int i = pile.get_rank();

	return i;
}

int Deck::get_pile_suit(){
	int i = pile.get_suit();

	return i;
}
                                                                                                             deck.h                                                                                              0000660 0031051 0072611 00000001013 13616362363 011350  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               // deck.h - Header File
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     hand.h                                                                                              0000660 0031051 0072611 00000001263 13616360423 011356  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               // hand.h - Header File
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
                                                                                                                                                                                                                                                                                                                                             hand.cpp                                                                                            0000660 0031051 0072611 00000003161 13616360347 011715  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               // hand.cpp - Implementation File

#include "hand.h"
#include "deck.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Hand::Hand(){
	n_cards = 32;
	hand = new Card[n_cards];
	
	for(int i = 0; i < n_cards; i++){
		hand[i].set_card(0, 0);
	}

	//cout << "hand of big length auto create" << endl;
}

Hand::~Hand(){
	delete [] hand;
//	cout << "hand deleted" << endl;
}

Hand::Hand(int n){
	n_cards = n;
	hand = new Card[n_cards];
}

Hand::Hand(const Hand& h){

}

Hand& Hand::operator=(const Hand& h){
	n_cards = h.n_cards;
	hand = new Card[n_cards];
	for (int i = 0; i < n_cards; i++){
		hand[i] = h.hand[i];
	}
	return *this;
}

void Hand::create_hand(){
	hand = new Card[32];
	for(int i = 0; i < 32; i++){
		hand[i].set_card(0, 0); 
	}
	cout << "hand created" << endl;
}

void Hand::set_hand(int i, int j, int k){
	hand[i].set_card(j, k);
}

int Hand::get_hand_rank(int i){
	int rk = hand[i].get_rank();
	
	return rk;
}

int Hand::get_hand_suit(int i){
	int st = hand[i].get_suit();
	
	return st;
}


void Hand::print_hand(int i){
	hand[i].print_card();
}

void Hand::draw_card(int i, int k){

//	hand[i] = dk.get_deck_card(k);	
}

void Hand::play_card(){

}

void Hand::print_hand(){
//	n_cards = cards.length;
	cout << "Hand Printed" << endl;
	for(int i = 0; i < n_cards; i++){
		hand[i].print_card();
	}
	cout << "end hand" << endl;
}
//stuff
Card Hand::get_card_hand(int i){
	

	return hand[i];
}


void Hand::add_card(){
	//add a card to the hand

}

void Hand::rem_card(){
	//take away a card from the hand

}

void Hand::check_suit(){
}

void Hand::check_rank(){

}

int Hand::select_suit(){
	
}

int Hand::select_card(){

}

                                                                                                                                                                                                                                                                                                                                                                                                               player.cpp                                                                                          0000660 0031051 0072611 00000001502 13616360623 012271  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               //player.cpp - Implementation File

#include "player.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Player::Player(){

}

Player::~Player(){
	//delete [] Player;
}
Player::Player(const Player&){

}
/*
Hand Player::get_hand(int i){
	return players[i];
}
*/

void Player::create_player_hand(){
	hand.create_hand();
}

void Player::set_hand_thang(int i, int j, int k){
	hand.set_hand(i, j, k);
}

int Player::get_hand_card_rank(int i){
	int rk = hand.get_hand_rank(i);

	return rk;
}

int Player::get_hand_card_suit(int i){
	int st = hand.get_hand_suit(i);

	return st;
}

void Player::print_player_hand(){
//	player[i].print_hand();
}

void Player::print_hand_thang(int i){
	hand.print_hand(i);

}

int Player::ask_user_card(){
	int input;
	cout << "Enter Number for playing card: ";
	cin >> input;


	return input;
}
                                                                                                                                                                                              player.h                                                                                            0000660 0031051 0072611 00000001011 13616360456 011735  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               // player.h - Header File
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
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       game.h                                                                                              0000660 0031051 0072611 00000000703 13616462024 011353  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               // Game.h - Header File
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
                                                             game.cpp                                                                                            0000660 0031051 0072611 00000004765 13616466433 011732  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               // game.cpp - Implementation File

#include "game.h"
#include "hand.h"
#include "deck.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Game::Game(){

}

Game::~Game(){
	//delete [] cards;
}

Game::Game(const Game&){

}

Game& Game::operator=(const Game& g){
	
	return *this;
}

void Game::setup_game(){
	bigDeck.create_deck();
	bigDeck.shuffle_deck();
//	bigDeck.print_deck();
}

void Game::deal_cards(){
	for(int i = 0; i < 7; i++){
		players[0].set_hand_thang(i, bigDeck.get_card_rank(i), bigDeck.get_card_suit(i));
		players[1].set_hand_thang(i, bigDeck.get_card_rank(i+7), bigDeck.get_card_suit(i+7));
	}
	//cout << "cards dealt" << endl;
	bigDeck.set_pile(bigDeck.get_card_rank(14), bigDeck.get_card_suit(14));
}

void Game::print_game(){
//	cout << "COM HAND" << endl;
//	for(int i = 0; i < 32; i++){
//		players[0].print_hand_thang(i);
//	}
	cout << "PLAYER HAND" << endl;
	for(int i = 0; i < 32; i++){
		players[1].print_hand_thang(i);
	}
	bigDeck.print_pile();
}

void Game::user_turn(){
	int input = players[1].ask_user_card();
	
	int test;
	do{
	if((players[0].get_hand_card_rank(input-1) == bigDeck.get_pile_rank()) || (players[0].get_hand_card_suit(input-1) == bigDeck.get_pile_suit())){
		bigDeck.set_pile(players[1].get_hand_card_rank(input-1), players[1].get_hand_card_suit(input-1));
		test = 0;
	}
	else{
		input = players[1].ask_user_card();
		test = 1;
	}
	}while(test == 1);

	cout << "user player: ";
	players[1].print_hand_thang(input-1);

	players[1].set_hand_thang(input-1, 0, 0);

}

void Game::com_turn(){
	int input = 100;
	for(int i = 0; i < 32; i++){
		if((players[0].get_hand_card_rank(i) == bigDeck.get_pile_rank()) || (players[0].get_hand_card_suit(i) == bigDeck.get_pile_suit())){
			input = i;
		}
	}
	if(input == 100){
		//players[0].draw_card();
	}
	cout <<"computer played: ";
	players[0].print_hand_thang(input);
	
	bigDeck.set_pile(players[0].get_hand_card_rank(input), players[0].get_hand_card_suit(input));

	players[0].set_hand_thang(input, 0, 0);
}

bool Game::winner(){
	for(int i = 0; i < 32; i++){
		if(players[0].get_hand_card_suit(i) == 0 && players[0].get_hand_card_rank(i) == 0){
			cout << "*************" << endl;
			cout << "COMPUTER WINS" << endl;
			cout << "*************" << endl;
	
			return false;
		}
	}

	for(int i = 0; i < 32; i++){
		if(players[0].get_hand_card_suit(i) == 0 && players[0].get_hand_card_rank(i) == 0){
			cout << "*************" << endl;
			cout << "PLAYER WINS" << endl;
			cout << "*************" << endl;
			
			return false;
		}
	}
	return true;
}
           driver.cpp                                                                                          0000660 0031051 0072611 00000001153 13616466403 012275  0                                                                                                    ustar   hietaa                          upg12841                                                                                                                                                                                                               //Driver.cpp - Driver File

/***********************************
 *Program: Crazy Eights
 *Author: Aleksi Hieta
 *Description: plays crazy eights between a player and the computer
 *Input: integers for the card selection
 *Output: game board
************************************/



#include <iostream>
#include <cstdlib>

#include "card.h"
#include "deck.h"
#include "game.h"
#include "hand.h"
#include "player.h"

using namespace std;

int main(){
	Game gm;


	gm.setup_game();
	gm.deal_cards();
	gm.print_game();

	do{
	gm.user_turn();
	gm.com_turn();	
	gm.print_game();
	}while(gm.winner() == false);

	return 0;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
