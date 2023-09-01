#include <iostream>
#include <cstdlib>
#include "deck.h"

using namespace std;

int main(){
	Card cd;
	Deck dk;
	dk.create_deck();
//	dk.print_deck();

	dk.shuffle_deck();
	dk.print_deck();


	return 0;
}
