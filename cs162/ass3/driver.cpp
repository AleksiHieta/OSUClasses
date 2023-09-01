//driver.cpp

#include <iostream>

#include "animal.h"
#include "zoo.h"
#include "tiger.h"
#include "sealion.h"
#include "bear.h"

using namespace std;

int main() {
	Zoo zoo;
	
	int user;
	zoo.setup_game();
	while(!zoo.out_o_money() || user == 0){
		zoo.user_turn();
		cout << "Keep going? 1 yes, 0 no: ";
		cin >> user;
		//achievements
		if(zoo.get_BANK() > 1000000){
			cout << "MILIONAIRE ACHIEVEMENT" << endl;
		}	
	}
	cout << "_________" << endl;
	cout << "GAME OVER" << endl;
	cout << "_________" << endl;

	return 0;
}
