#include <iostream>
#include <string>

using namespace std;

bool checkForA(string str)
{
	cin >> str;

	for(int i=0; i<str.length(); i++){
		if(str.at(i)=='a')
			return true;
	}

	return false;

}

