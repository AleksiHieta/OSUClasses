//node.h

#ifndef NODE
#define NODE

#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
	int num;
	Node* next;	
public:
	Node();
	~Node();
	//void operator=(const Node*);
	
	
	void set_next(Node*);
	Node* get_next();	
	void set_num(int);
	int get_num();


};

#endif
