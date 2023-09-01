/*
THERE ARE BUGS IN THE FOLLOWING CODE.
*/
#include <iostream>

using namespace std;

int main(){

	int x=3, y;
	char myAnswer;

	y = x;
	cout << "y is set to: " << y << endl;
	bool again = true;
	while(again){
		cout << "Please input a number: ";
		cin >> y;
	
		if(x > y){
			cout << "X is greater than Y\n";
			cout << " would you like to input another number?(0-no, 1-yes)" << endl;
			cin >> again;
		}
		else{
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number?(0-no, 1-yes)" << endl;
			cin >> again;
		}
	}
	for(x = 0; x < 10; x++){
		cout << x << endl;
	}
	cout << "What number would you like to find the factorial for? " << endl;
	int num;
	cin >> num;
	for(int x = num; x > 0; x--){
		num = num * x;	
		//cout << x << endl;
		cout << num << endl;
	}
	cout << "Are you enjoying cs161? (y or n) " << endl;
	char myanswer;
	cin >> myanswer;
	if(myanswer =='y'){
		cout << "YAY" << endl;
	}
	else{
		cout << "YOU WILL SOON!" << endl;
	}

	return 0;
}
