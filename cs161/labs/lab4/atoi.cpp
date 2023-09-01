/******************************************************
* Function: atoi
* Description: character into decimal value
* Parameters: char character
* Pre-conditions: input is a character
* Post-conditions: returns decimal value of character
*****************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char character;
	cout << "Enter a character " << endl;
	cin >> character;

	cout << "The equivalent decimal is: " << int(character) << endl;

	return 0;
} 	
