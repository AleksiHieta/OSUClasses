#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	int length;
	int upper;
	int lower;
	int num;
	int numupper;
	int numlower;
	int numnumber;

	cout << "Length of password: " << endl;
	cin >> length;
	cout << "Include uppercase letters? (1-yes,0-no): " << endl;
	cin >> upper;
		if (upper == 1){
			cout << "How many uppercase letters?:" << endl;
			cin>> numupper;
		}
	cout << "Include lowercase letters? (1-yes,0-no): " << endl;
	cin >> lower;
		if (lower == 1){
			cout << "How many lowercase letters?:" << endl;
			cin >> numlower;
		}
	cout << "Include numbers? (1-yes,no-0)" << endl;
	cin >> num;
		if (num == 1){
			cout << "How many numbers?:" << endl;
			cin >> numnumber;
		}

	srand(time(NULL));
	string password = "";
	
		for (int i = 0; i < numupper; i++){
			password += char(rand() % 26 + 65);
		}
		for (int i = 0; i < numlower; i++){
			password += char(rand() % 26 + 97);
		}	
		for (int i = 0; i < numnumber; i++){
			password += char(rand() % 10 + 48);
		}
	
	
	cout << password << endl;

}
