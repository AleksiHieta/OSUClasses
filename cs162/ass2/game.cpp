// game.cpp - Implementation File

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
