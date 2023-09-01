//list.cpp

#include "linked_list.h"

#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

List::List(){
	head = NULL;
	curr = NULL;
	temp_head = NULL;
	temp_curr = NULL;
	length = 0;
}

List::~List(){
	head = NULL;

	//delete
}


int List::get_length(){
	return length;
}

Node* List::get_head(){
	return head;
}

Node* List::get_curr(){
	return curr;
}

void List::set_curr(Node* n){
	curr = n;
}

void List::print(){
	//prints list
	curr = head;

	while(curr != NULL){
		cout << curr->get_num() << " ";

		curr = curr->get_next();
	}
	cout << endl;
}

void List::clear(){
	//delete list
}

void List::push_front(int data){
	//insert at front
	Node* new_node = new Node;  //make new node
	new_node->set_num(data);

	if(head != NULL){
		new_node->set_next(head); //points the new node to the head
		head = new_node;
	}
	else{
		head = new_node;
	}
	length++;
}

void List::push_back(int data){
	//insert at back                                                      :)
	//  :o
	Node* new_node = new Node;  //make new node
	new_node->set_num(data);

	if(head != NULL){  //case where there are elements
		curr = head;
		while(curr->get_next() != NULL){ //find end
			curr = curr->get_next();
		}
		curr->set_next(new_node);	//set end
	}
	else{ //no elements yet
		head = new_node;
	}
	length++;
}

void List::insert(int data, int index){
	//insert at front
	Node* new_node = new Node;  //make new node
	new_node->set_num(data);

	if(index == 0){
		push_front(data);
	}
	else{
		curr = head;
		for(int i = 0; i < index-1; i++){ //find node before given spot
			curr = curr->get_next();
		}
	
		new_node->set_next(curr->get_next()); //both same next
		curr->set_next(new_node); //curr points to new
	length++;
	}
}

Node* List::index_node(int index){
	curr = head;

	for(int i = 0; i < index; i++){
		curr = curr->get_next();
	}
	return curr;
}

void List::set_index_data(int index, int data){
	curr = head;
	
	for(int i = 0; i < index; i++){
		curr = curr->get_next();
	}

	curr->set_num(data);
}

int List::get_index_data(int index){
	curr = head;

	for(int i = 0; i < index; i++){
		curr = curr->get_next();
	}
	return curr->get_num();
}

void List::replace_node(List L1, int idx1, List L2, int idx2){
	L1.set_curr(L1.get_head());

	L2.set_curr(L2.get_head());

	cout << "currs set" << endl;

	for(int i = 0; i < idx1-1; i++){
		L1.set_curr(L1.get_curr()->get_next());
	}
	for(int i = 0; i < idx2; i++){
		L2.set_curr(L2.get_curr()->get_next());
	}	

	cout << "Went deep into lists" << endl;

	if(L1.get_curr()->get_next()->get_next() == NULL){
		L2.get_curr()->set_next(NULL);
	}
	else{
		L2.get_curr()->set_next((L1.get_curr()->get_next())->get_next());
	}
	cout << "set next of list 2" << endl;	

	L1.get_curr()->set_next(L2.get_curr());

	cout << "inserted into list 1" << endl;
}

void List::list_merge_a(List list, int start, int mid, int end){
        int i = start;
        int k = 0;
        int j = mid+1;
	
	List temp;	
	int temp_length = 0;

        for(int i = 0; i < end-start+1; i++){
		temp.push_back(0);
		temp_length++;
	}

        while(i <= mid && j <= end){
                if(list.get_index_data(i) < list.get_index_data(j)){    //LESS THAN
                        //replace_node(temp, k, list, i);
			
			temp.set_index_data(k, list.get_index_data(i));
 			//temp @ k       list @ i                      
			 k++;
                        i++;
                }
                else{
                        temp.set_index_data(k, list.get_index_data(j));
                        k++;
                        j++;
                }
        }
        while(i <= mid){
                temp.set_index_data(k, list.get_index_data(i));
                k++;
                i++;
        }
        while(j <= end){
                temp.set_index_data(k, list.get_index_data(j));
                k++;
                j++;
        }
        for(i = start; i <= end; i++){
                list.set_index_data(i, temp.get_index_data(i-start));
	}
}

void List::sort_ascend(List list, int start, int end){
        if(start < end){
                int mid = (start+end)/2;
                sort_ascend(list, start, mid);
                sort_ascend(list, mid+1, end);

                list_merge_a(list, start, mid, end);
        }
}

void List::list_merge_d(List list, int start, int mid, int end){
        int i = start;
        int k = 0;
        int j = mid+1;
	
	List temp;	
	int temp_length = 0;

        for(int i = 0; i < end-start+1; i++){
		temp.push_back(0);
		temp_length++;
	}

        while(i <= mid && j <= end){
                if(list.get_index_data(i) > list.get_index_data(j)){    //GREATER THAN
                        temp.set_index_data(k, list.get_index_data(i));
                        k++;
                        i++;
                }
                else{
                        temp.set_index_data(k, list.get_index_data(j));
                        k++;
                        j++;
                }
        }
        while(i <= mid){
                temp.set_index_data(k, list.get_index_data(i));
                k++;
                i++;
        }
        while(j <= end){
                temp.set_index_data(k, list.get_index_data(j));
                temp.set_index_data(k, list.get_index_data(j));
                k++;
                j++;
        }
        for(i = start; i <= end; i++){
                list.set_index_data(i, temp.get_index_data(i-start));
	}
}

void List::sort_descend(List list, int start, int end){
        if(start < end){
                int mid = (start+end)/2;
                sort_descend(list, start, mid);
                sort_descend(list, mid+1, end);

                list_merge_d(list, start, mid, end);
        }
}

int List::prime_nums(){
	int count = 0;

	curr = head;

//	for(int i = 0; i < length-1; i++){
//		for(int j = 0; j < i; j++){
//			curr = curr->get_next();
//		}
	for(int i = 0; i < length; i++){
		bool is_prime = true;
		int k = 2;
		float k2 = 2.0;
		
		do{


		if(curr->get_num() < 0){
			is_prime = false;
		}

		if(curr->get_num()/k == curr->get_num()/k2){
			is_prime = false;
		}
		k++;
		k2 = k2 + 1.0;
		}while(k < curr->get_num());

		if(is_prime){
			count++;
		}
		
		curr = curr->get_next();
	}		
//	}while(curr->get_next() != NULL);
	return count;
}
