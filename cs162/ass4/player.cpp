//player.cpp

#include "player.h"

using namespace std;

Player::Player(){
	symbol = '*';
}

Player::~Player(){
}

char Player::get_symbol(){
	return '*';
}

bool Player::is_shot(){
	return false;
}

char Player::get_event(){
	return '*';
}

void Player::get_percept(){
	//nothing happens
}	
