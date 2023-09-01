#include <iostream>

#include <ctime>

#include <cstdlib>

using namespace std;

int main()
{
	int x;
	srand(time(NULL));
	/*x = rand();
	cout << "x = " << x << endl;

	srand(time(NULL));
	x = rand();	
	cout << "x = " << x << endl;
	*/

	x = rand() % 6;

	cout << "Random number is: " << x << endl;

	if (x==0){
		cout << "Bummer, I'm zero!" << endl;
	}
	else if (x%2==1){
		cout << "I'm odd!" << endl;
		
		if (x==1){
			cout << "I'm number 1" << endl;
		}
		else if (x==3){
			cout << "I'm number 3" << endl;
		}
		else {
			cout << "I'm number 5" << endl;
		}

	}
	else if (x%2==0) {
		cout << "I'm even!" << endl;
		
		if (x==2){
			cout << "2!" << endl;
		}
		else {
			cout << "4!" << endl;
		}
		
	}

	return 0;
}
