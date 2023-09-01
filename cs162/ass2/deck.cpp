// deck.cpp - Implementation File

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
