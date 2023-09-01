//Driver.cpp - Driver File

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
