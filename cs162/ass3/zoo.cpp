//zoo.cpp

#include "zoo.h"
#include <iostream>

using namespace std;

Zoo::Zoo(){
	dudes_in_zoo = new Animal*[3];
	tigers_in_zoo = new Tiger[0];
	size_tiger = 0;
	bears_in_zoo = new Bear[0];
	size_bear = 0;
	sealions_in_zoo = new Sealion[0];
	size_sealion = 0;


	cout << "Zoo created" << endl;
}

Zoo::~Zoo(){
	for(int i = 0; i < 3; i++){
		delete [] dudes_in_zoo[i];
		dudes_in_zoo[i] = NULL;
	}
	delete [] dudes_in_zoo;
	dudes_in_zoo = NULL;
	cout << "zoo destroyed" << endl;
}

Zoo::Zoo(const Zoo& z){
	cout << "Zoo copy constructor" << endl;
}

int Zoo::get_BANK(){
	return BANK;
}

void Zoo::add_tiger(bool buy){
	Tiger* temp = new Tiger[size_tiger+1];	
	for(int i = 0; i < size_tiger; i++){
		temp[i] = tigers_in_zoo[i];
	}
	Tiger t;
	temp[size_tiger] = t;
	if(buy){
		temp[size_tiger].set_age(48);
	}
	

	delete [] tigers_in_zoo;

	tigers_in_zoo = temp;
	size_tiger++;
}

void Zoo::add_bear(bool buy){
	Bear* temp = new Bear[size_bear+1];	
	for(int i = 0; i < size_bear; i++){
		temp[i] = bears_in_zoo[i];
	}
	Bear b;
	temp[size_bear] = b;
	if(buy){
		temp[size_bear].set_age(48);
	}
	delete [] bears_in_zoo;
	
	bears_in_zoo = temp;	
	size_bear++;
}

void Zoo::add_sealion(bool buy){
	Sealion* temp = new Sealion[size_sealion+1];	
	for(int i = 0; i < size_sealion; i++){
		temp[i] = sealions_in_zoo[i];
	}
	Sealion s;
	temp[size_sealion] = s;
	if(buy){
		temp[size_sealion].set_age(48);
	}
	delete [] sealions_in_zoo;

	sealions_in_zoo = temp;
	size_sealion++;
}

void Zoo::rem_tiger(){
	Tiger* temp = new Tiger[size_tiger-1];	
	for(int i = 0; i < size_tiger-1; i++){
		temp[i] = tigers_in_zoo[i];
	}
	delete [] tigers_in_zoo;

	tigers_in_zoo = temp;
	size_tiger--;
}

void Zoo::rem_bear(){
	Bear* temp = new Bear[size_bear-1];	
	for(int i = 0; i < size_bear-1; i++){
		temp[i] = bears_in_zoo[i];
	}
	delete [] bears_in_zoo;

	bears_in_zoo = temp;
	size_bear--;
}

void Zoo::rem_sealion(){
	Sealion* temp = new Sealion[size_sealion-1];	
	for(int i = 0; i < size_sealion-1; i++){
		temp[i] = sealions_in_zoo[i];
	}
	delete [] sealions_in_zoo;

	sealions_in_zoo = temp;
	size_sealion--;
}

int Zoo::random_event(){
	srand(time(NULL));
	int choice = rand() % 4;

	if(choice == 0){
		//nothing
		cout << "NOTHING HAPPENED" << endl;
	}
	else if(choice == 1){
		cout << "REVENUE BOOST" << endl;
		boost = rand() % 251 + 150;
	}
	else if(choice == 2){
		int animal;
		if(size_tiger > 0 && size_bear > 0 && size_sealion > 0){
			animal = rand() % 3;
		}
		else{
			if(size_tiger > 0){
				animal = 0;
			}
			else if(size_bear > 0){
				animal = 1;
			}
			else if(size_sealion > 0){
				animal = 2;
			}
		}
		if(animal == 0){
		cout << "TIGER GOT SICK" << endl;
			if(BANK < tigers_in_zoo[0].get_cost()/2){
				rem_tiger();
			}						
			else{
				if(tigers_in_zoo[0].get_age() < 6){
					BANK = BANK - tigers_in_zoo[0].get_cost();
				}
				else{
					BANK = BANK - tigers_in_zoo[0].get_cost()/2;
				}
			}
		}	
		else if(animal == 1){
		cout << "BLACK BEAR GOT SICK" << endl;
			if(BANK < bears_in_zoo[0].get_cost()/2){
				rem_bear();
			}						
			else{
				if(bears_in_zoo[0].get_age() < 6){
					BANK = BANK - bears_in_zoo[0].get_cost();
				}
				else{
					BANK = BANK - bears_in_zoo[0].get_cost()/2;
				}
			}
		}
		else if(animal == 2){
		cout << "SEALION GOT SICK" << endl;
			if(BANK < sealions_in_zoo[0].get_cost()/2){
				rem_sealion();
			}
			else{
				if(sealions_in_zoo[0].get_age() < 6){
					BANK = BANK - sealions_in_zoo[0].get_cost();
				}
				else{
					BANK = BANK - sealions_in_zoo[0].get_cost()/2;
				}				
			}		
		}
	}
	else if(choice == 3){
		int animal = rand() % 3;

		if(animal == 0){
			cout << "BABY TIGERS!!" << endl;
			for(int i = 0; i < tigers_in_zoo[0].get_baby(); i++){
				add_tiger(false);
			}
		}	
		if(animal == 1){
			cout << "BABY BLACK BEARS!!" << endl;
			for(int i = 0; i < bears_in_zoo[0].get_baby(); i++){
				add_bear(false);
			}
		}	
		if(animal == 2){
			cout << "BABY SEALIONS!!" << endl;
			for(int i = 0; i < sealions_in_zoo[0].get_baby(); i++){
				add_sealion(false);
			}
		}	
		
	}
	return 0;
}

void Zoo::revenue(int b){
	int Revenue;
	for(int i = 0; i < size_tiger; i++){
		if(tigers_in_zoo[i].get_age() < 6){
			Revenue += 2*tigers_in_zoo[i].get_revenue();
		}
		else{
		Revenue += tigers_in_zoo[i].get_revenue();
		}
	}
	for(int i = 0; i < size_bear; i++){
		if(bears_in_zoo[i].get_age() < 6){
			Revenue += 2*bears_in_zoo[i].get_revenue();
		}
		else{
		Revenue += bears_in_zoo[i].get_revenue();
		}
	}
	for(int i = 0; i < size_sealion; i++){
		if(sealions_in_zoo[i].get_age() < 6){
			Revenue += 2*sealions_in_zoo[i].get_revenue() + b;
		}
		else{
		Revenue += sealions_in_zoo[i].get_revenue() + b;
		}
	}
	BANK += Revenue;
}

void Zoo::buy_animals(int s, int n){
	for(int i = 0; i < n; i++){
		if(s == 1){
			BANK = BANK - tigers_in_zoo[i].get_cost();
		}
		if(s == 2){
			BANK = BANK - bears_in_zoo[i].get_cost();
		}
		if(s == 3){
			BANK = BANK - sealions_in_zoo[i].get_cost();
		}
	}
}

void Zoo::food(){
	srand(time(NULL));

	int base = (rand() % 33) + 64;	

	for(int i = 0; i < size_tiger; i++){
		BANK = BANK - base*tigers_in_zoo[i].get_food_cost();
	}
	for(int i = 0; i < size_bear; i++){
		BANK = BANK - base*bears_in_zoo[i].get_food_cost();
	}
	for(int i = 0; i < size_sealion; i++){
		BANK = BANK - base*sealions_in_zoo[i].get_food_cost();
	}
}

bool Zoo::out_o_money(){
	if(BANK < 0){
		return true;
	}
	return false;
}

void Zoo::setup_game(){
	BANK = 100000;
}

void Zoo::user_turn(){
	cout << "Bank Money: $" << BANK << endl;	
	cout << "___________________" << endl;
	cout << "ANIMALS IN YOUR ZOO" << endl;
	for(int i = 0; i < size_tiger; i++){
		tigers_in_zoo[i].set_age(1);
		cout << tigers_in_zoo[i].get_name();
		if(tigers_in_zoo[i].get_age() < 6){
			cout << " Baby" << endl;
		}
		else if(tigers_in_zoo[i].get_age() > 48){
			cout << " Adult" << endl;
		}
		else{
			cout << endl;
		}
	}
	for(int i = 0; i < size_bear; i++){
		bears_in_zoo[i].set_age(1);
		cout << bears_in_zoo[i].get_name();
		if(bears_in_zoo[i].get_age() < 6){
			cout << " Baby" << endl;
		}
		else if(bears_in_zoo[i].get_age() > 48){
			cout << " Adult" << endl;
		}
		else{
			cout << endl;
		}
	}
	for(int i = 0; i < size_sealion; i++){
		sealions_in_zoo[i].set_age(1);
		cout << sealions_in_zoo[i].get_name();
		if(sealions_in_zoo[i].get_age() < 6){
			cout << " Baby" << endl;
		}
		else if(sealions_in_zoo[i].get_age() > 48){
			cout << " Adult" << endl;
		}
		else{
			cout << endl;
		}
	}
	cout << "___________________" << endl;
	
	int species = 0;
	int num_animals = 0;
	do{
	cout << "Choose a species to add to the zoo! 4 - none, 1 - Tiger, 2 - Bear, 3 - Sealion: ";
	cin >> species;
	}while(species < 1 || species > 4);
	
	if(species != 4){
	do{
	cout << "You can add either 1 or 2 of the chosen animal to the zoo. Enter 1 or 2: ";
	cin >> num_animals;
	}while(num_animals < 1 || num_animals > 2);
	cout << "You bought " << num_animals;
	}
	if(species == 1){
		cout << " Tiger(s)" << endl;
	}
	if(species == 2){
		cout << " Bear(s)" << endl;;
	}
	if(species == 3){
		cout << " Sealion(s)" << endl;;
	}
	
	for(int i = 0; i < num_animals; i++){
		if(species == 1){
			add_tiger(true);
		}
		if(species == 2){
			add_bear(true);
		}
		if(species == 3){
			add_sealion(true);
		}
	}

	boost = 0;	
	buy_animals(species, num_animals);
	random_event();
	revenue(boost);
	food();
}
