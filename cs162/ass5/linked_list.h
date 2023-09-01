//list.h

#ifndef LIST
#define LIST

#include "node.h"

#include <iostream>
#include <cstdlib>

using namespace std;

class List {
	unsigned int length;
	Node* head;
	Node* temp_head;
	Node* curr;
	Node* temp_curr;
public:
	List();
	~List();

	int get_length();
	Node* get_head();
	Node* get_curr();
	void set_curr(Node*);
	void print();
	void clear();
	void push_front(int);
	void push_back(int);
	void insert(int, int);

	void replace_node(List, int, List, int);

	Node* index_node(int); //returns indexed node

	void set_index_data(int, int); //sets data of indexed node
	int get_index_data(int); //returns data of indexed node

	void list_merge_a(List, int, int, int);
	void sort_ascend(List, int, int); //IMPORTANT ONE

	void list_merge_d(List, int, int, int);
	void sort_descend(List, int, int); //IMPORTANT ONE

	int prime_nums();
};

#endif
