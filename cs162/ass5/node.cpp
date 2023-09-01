//node.cpp

#include "node.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Node::Node(){
	num = 0;
}

Node::~Node(){
	next = NULL;
}

/*
void Node::operator=(const Node* n){
	delete [] next;
	this->num = n->num;
	this->next = new Node;
}
*/

void Node::set_next(Node* n){
	next = n;
}

Node* Node::get_next(){
	return next;
}

void Node::set_num(int i){
	num = i;
}

int Node::get_num(){
	return num;
}
