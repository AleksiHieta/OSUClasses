/**********************************
 *Author: Aleksi Hieta
 *Function: fraction.cpp
 *Input: numerator and denominator of a fraction as integers
 *Output: fraction in lowest terms
************************************/
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

void simplify(int &n, int &d){              //using & for reference of variables
	for(int i = 2; i < 100; i++){
		if ((n%i == 0) && (d%i == 0)){ // if n/i and d/i is an integer, divide n and d by i, then recurse
			n = n/i;
			d = d/i;
			simplify(n, d);      //recursive call of function
		}
	}
}

int get_int(char *message){ //checks that the input is integer type
	int out;
	string in;

	while(true){
		cout << message;
		getline(cin, in);
		stringstream ss(in);
		
		if(ss >> out && !(ss >> in)) return out;

		cin.clear();
		cerr << "Invalid input, try again\n";
	}
}

int main() {
	int repeat;
	do {
	int numerator = get_int("Enter an integer for the numerator: ");
	int denominator = get_int("Enter an intger for the denominator: ");
		if (denominator == 0)
			cout << "Invalid fraction" << endl;	
		else if (numerator == 0)
			cout << "Simplified Fraction: 0" << endl;      //for 0 casse
		else if (numerator == denominator)
			cout << "Simplified Fraction: 1" << endl;     //for 1 case
		else {
			simplify(numerator, denominator);
			cout << "Simplified Fraction: " << numerator << "/" << denominator << endl;
		}
		
		cout << "Would you like to simplify another fraction? (1-yes, 0-no)" << endl; //ask to do it again
		cin >> repeat;

	}while (repeat);

	return 0;
}
