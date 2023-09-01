// hand.cpp - Implementation File

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

