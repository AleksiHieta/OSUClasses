/**********************************************************************************
 *Author: Aleksi Hieta
 *Function: fractal.cpp
 *Input: n as base line for fractal (odd) and the columns as distance from the edge
 *Output: fractal picture based on input 
***********************************************************************************/ 
#include <iostream>
#include <cstdlib>

using namespace std;

void odd_pattern(int n, int col){
	if(n > 0){
		odd_pattern(n-2, col+1); //recursive call to print upper half that continues to split until reaching 1

	for(int i = 0; i < col; i++){   //prints base line to spread from
		cout << "  ";
	}
	for(int i = 0; i < n; i++){
		cout << "* ";  
	}
	cout << endl;

	odd_pattern(n-2, col+1);       //recursive call to print lower half until finished
	}
}
int main(){
	int n, col;

	cout << "Enter n (odd): ";
	cin >> n;
	cout << "Enter col: ";
	cin >> col;

	odd_pattern(n, col);

	return 0;
}
