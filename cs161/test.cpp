#include <iostream>
using namespace std;

int main()
{
	int a = 7;
	int b = 15;

	cout << "A: " << a << endl;
	cout << "B: " << b << endl;
	a = a - b;
	b = b + a;
	a = b - a;

	cout << "A: " << a << endl;
	cout << "B: " << b << endl;

	return 0;
}
