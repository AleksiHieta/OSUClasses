
//hand.cpp - Implementation File


#include "hand.h"
//constructor
Hand::Hand(){
	cout << "construct" << endl;
	//ptr = NULL;
	size = 52;
	cards = new Card[size];
}
//destructor
Hand::~Hand(){
	cout << "destruct" << endl;
	delete [] cards;
}
//copy constructor
Hand::Hand(const Hand& h){
	cout << "copy construct" << endl;
	this->size = h.size;
	this->cards = new Card[size];
	for(int i = 0; i < size; i++){
		this->cards[i] = h.cards[i];
	}
}

//assignment operator overload
Hand& Hand::operator=(const Hand& h){
	cout << "assignment operator" << endl;
	delete [] ptr;
	this->size = h.size;
	this->cards = new Card[size];
	for(int i = 0; i < size; i++){
		cards[i] = h.cards[i];
	}
	return *this;
}

void g(Hand &h){
	cout << "cool" << endl;
}

