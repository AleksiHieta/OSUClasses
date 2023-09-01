//player.cpp - Implementation File

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
