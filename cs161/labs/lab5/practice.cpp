#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
/*
string get_sentence(string s){
	cout << "Enter a sentence: ";
	getline(cin, s);
	return s;
}

int main(){
	string sentence;

	sentence = get_sentence(sentence);
	cout << sentence << endl;

	return 0;
}
*/
void get_sentence(string &s){
	cout << "Enter a sentence: ";
	getline(cin, s);
}

int main(){
	string sentence;

	get_sentence(sentence);
	cout << sentence << endl;

	return 0;
}
