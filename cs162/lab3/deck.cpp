#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.h"

using namespace std;

/*
Deck::Deck(){
	numCards = 0;
	cards = NULL;
}

Deck::~Deck(){
	delete [] cards;
}
*/
void Deck::create_deck(){

	for(int i = 0; i < 13; i++){

		BigDeck[i].set_card(i+1,"<3");
		BigDeck[i+13].set_card(i+1,"<>");
		BigDeck[i+26].set_card(i+1,"-8o");
		BigDeck[i+39].set_card(i+1,"-8>");
	}
}

void Deck::shuffle_deck(){
	srand(time(NULL));
for(int k = 0; k < 1000; k++){
	for(int i = 0; i < 51; i++){
		for(int j = 0; j < 51-i; j++){
			if(rand() % 2){
				temp = BigDeck[j];
				BigDeck[j] = BigDeck[j+1];
				BigDeck[j+1] = temp;
			}
		}
	}
}
}
void Deck::print_deck(){
	for(int i = 0; i < 52; i++){
		BigDeck[i].print_card();
		cout << endl;
	}

}
