/*************************************************
 *Program: Linked List
 *Author: Aleksi Hieta
 *Date: 3/15/2020
 *Input: User inputs data (int), choice of position
 *of entry into the list, choice to add another  
 *element, and whether the list is printed 
 *ascending or descending
 *Output: List of data as inputted, list of  
 *organized data, and the number of prime numbers
 *in the list.
*************************************************/
#include "linked_list.h"
#include "node.h"

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <sstream>


using namespace std;

int main(){
	char input;	
	int number;	

	List L;

	bool again;
	do{
		cout << "===============" << endl;
		cout << " Current List: " << endl;
		L.print();

		cout << "Length: " << L.get_length() << endl;
	
		//takes and checks data input
		int num;
		string num1;
		bool num_valid;
		do{
		cout << "\nEnter an integer: ";
		cin >> num1;
		
		if(!(istringstream(num1) >> num)){
			cout << "Invalid input" << endl;
			num_valid = false;
		}
		else{
			num_valid = true;
		}
		}while(!num_valid);
	

		//choose where to put element and check
		bool choice_valid;
		do{
		string choice1;
		int choice;
		cout << "Want to enter at front, back, or insert at a given index? (1, 2, 3): ";
		cin >> choice1;

		if(!(istringstream(choice1) >> choice)){
			cout << "Invalid Input" << endl;
			choice_valid = false;	
		}
		else{
			choice_valid = true;
		}

		if(choice == 1){
			L.push_front(num);
		}
		else if(choice == 2){
			L.push_back(num);
		}
		else if(choice == 3){
			int idx;
			if(L.get_length() != 0){
			do{
			cout << "Enter index from 0 to " << L.get_length()-1 << ": ";
			cin >> idx;
			}while(!(idx >= 0 && idx < L.get_length()));

			L.insert(num, idx);
			}
			else{
				L.push_back(num);
			}
		}
		else{
			cout << "Invalid Input" << endl;
			choice_valid = false;
		}

		}while(!choice_valid);	


		
		//ask for another number
		string again1;
		bool again_valid;
		do{
		
		cout << "Add another number? (yes-1, no-0): ";
		cin >> again1;

		if(!(istringstream(again1) >> again)){
			cout << "Invalid input" << endl;
			again_valid = false;
		}
		else{
			again_valid = true;
		}
		}while(!again_valid);
	}while(again == 1);

	cout << "============" << endl;
	cout << " Final List " << endl;
	L.print();

	bool order;
	string order1;
	bool order_valid;
	do{

	cout << "List in ascending or descending order? (1 or 0): ";
	cin >> order1;

	if(!(istringstream(order1) >> order)){
		cout << "Invalid input" << endl;
		order_valid = false;
	}
	else{
		order_valid = true;
	}

	}while(!order_valid);

	cout << "Length: " << L.get_length() << endl;
	
	if(order == 1){
		cout << "Ascending Order" << endl;
		L.sort_ascend(L,0,L.get_length()-1);
	}
	else{
		cout << "Descending Order" << endl;
		L.sort_descend(L,0,L.get_length()-1);
	}


	L.print();

	cout << L.prime_nums() << " Prime Number(s)" << endl;

	return 0;
}
