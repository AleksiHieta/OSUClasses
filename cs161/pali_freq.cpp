/*******************************************************************************************************************
 *Function: pali_freq.cpp
 *Desription: takes a sentence and either runs a palindrone, frequency, or given frequency test.
 *Input: character array
 *Palindrone: detects if the sentence is a palindrone or not
 *	Output: yes or no for palindrone
 *Frequency: determines the frequency of all words in the sentence
 *	Output: all words with number beside it of times it occurs
 *Given Frequency: Takes another input of N words and finds the frequency of given words in the sentence
 *	Output: returnsa words given with number beside it of times it occurs in the sentence
 *
********************************************************************************************************************/
#include <iostream>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <string>
#include <bits/stdc++.h>

using namespace std;

char * purge_sent(char * str){
	char * temp = new char [1025];
	strcpy(temp,str);

	for(int i = 0; i < strlen(temp); i++){
		if (int(temp[i]) < 48 || (int(temp[i]) > 57 && int(temp[i]) < 65) || (int(temp[i]) > 90 && int(temp[i]) < 97) || int(temp[i]) > 122 || temp[i] == '\0'){
			//removes everything but letters and numbers
			strcpy(&temp[i],&temp[i+1]);
			i--;
		}
	}
	
	for(int i = 0; i < strlen(temp); i++){
		if (int(temp[i]) <= 90 && int(temp[i]) >= 65){
			temp[i] = int(temp[i]) + 32;
			//makes all letters lowercase
		}
	}
	return temp;
}

char * purge_all(char * str){
	char * temp = new char [1025];
	strcpy(temp,str);

	
	for(int i = 0; i < strlen(temp); i++){
		if ((int(temp[i]) < 32) || (int(temp[i]) > 32 && int(temp[i]) < 65) || (int(temp[i]) > 90 && int(temp[i]) < 97) || (int(temp[i]) > 122)){
			//removes everything but letters and spaces
			strcpy(&temp[i],&temp[i+1]);
			i--;
		}
	}
	for(int i = 0; i < strlen(temp); i++){
		if (int(temp[i]) <= 90 && int(temp[i]) >= 65){
			temp[i] = int(temp[i]) + 32;
			//makes all letters lowercase
		}
	}
	return temp;
}

bool is_palindrone(char * str, char * str2){
	char * temp = new char [1025];
	strcpy(temp, str);

	char * temp2 = new char [1025];
	strcpy(temp2, str2);


	if(strcmp(temp, temp2)){
		return false;
	}

	return true;
}


char * back(char * str){
	char * temp_back = new char [1025];
	strcpy(temp_back, str);
	
	for(int i = strlen(temp_back); i > 0; i--){
		temp_back[i-1] = str[strlen(str)-i];
	}
	return temp_back;
}

int num_words(char * arr){
	int num = 1;
	for(int i = 0; i < strlen(arr); i++){
		if(arr[i] == ' '){
			num = num + 1;
		}
	}
	return num;
}

int word_length(char * arr){
	int len = 0;
	for(int i = 0; i < strlen(arr); i++){
		if(arr[i] == ' '){
			return i;
		}
	}
	return strlen(arr);
}

void delete_2Darr(char** a, int row){
	for(int i = 0; i < row; i++)
		delete [] a[i];
	delete [] a;
}


int main(){
	int again;
//do{
//	int again = 1;
	char sent[1025];
	char temp[1025];

	cout << "Input a sentence: ";
	cin.getline(sent, 1024);

	if(cin.fail()){
		cin.ignore(256,'\n');
		cin.clear();
	}

	int choice;
	cout << "Palindrome (1), Frequency (2), Given Frequency (3): ";
	cin >> choice;	

	if (choice == 1){           //Palindrome
		char backwards[1025];
		strcpy(temp, purge_sent(sent));
		strcpy(backwards, back(temp));
		

		if(is_palindrone(temp, backwards)){
			cout << "You're good, it's a palindrone!" << endl;
		}
		else{
			cout << "Nope, not the ticket" << endl;
		}

	}
	else if (choice == 2){      //Frequency
		char temp[1025];

		strcpy(temp, purge_all(sent));
		
		int words = num_words(sent);
	//	cout << words << endl;

		char sub_array[1025];
		
		char str[1025];
		char* token = strtok(temp, " ");
		while(token != NULL){
			int k = 1;
			if(strcmp(purge_sent(str),purge_sent(token)) == 0)
				cout << token << ": " << ++k << endl;
			else
				cout << token << ": 1" << endl; 
			strcpy(str, token);
			token = strtok(NULL, " ");
		}

		
		


	}
	else if (choice == 3){                      //Given Frequency

		strcpy(temp, purge_all(sent));
		char test[1025];

		int N = 0;
		cout << "How many words would you like to search for?: ";
		cin >> N;
		
		int k = 0;
		for(int i = 0; i < N+1; i++){
			cin.getline(test, 1024);
			char* token = strtok(temp, " ");
			while(token != NULL){
					
				if(strcmp(purge_sent(test), purge_sent(token)) == 0)
					cout << test << ": " << ++k << endl;
				token = strtok(NULL, " ");
			}
			cout << test << ": " << k << endl;
		}
		/*int col = 256;
		char** a;
		a = new char* [N];
		for(int i = 0; i < N; i++)
			a[i] = new char [col];

		for(int i = 0; i < N; i++){
			for(int j = 0; j < col; j++){
				a[i][j] = ' ';
			}
		}

		for(int i = 0; i < N+1; i++){
			cin.getline(a[i], col);
		}
	

	
		for(int i = 0; i < N; i++){
			for(int j = 0; j < strlen(a[i]); j++){
				cout << a[i][j];
			}
		}
*/		



	

//	delete_2Darr(a, N);
	}

	else{
		cout << "Invalid input" << endl;
	}

	

return 0;

}



