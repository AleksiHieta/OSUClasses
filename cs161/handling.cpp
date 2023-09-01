/***************************************************************
 *Program: handling.cpp
 *Author: Aleksi Hieta
 *Date: 10/27/19
 *Input:
 *Output:
***************************************************************/

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;
/**********************************************************
 *Function: check_range()
 *Description: Checks if a number is in a given range
 *Parameters: int lower, int upper, int test
 *Pre-conditions: takes an integer
 *Post-conditions: returns boolean
*********************************************************/
bool check_range(int lower_bound, int upper_bound, int test_value){
	if ((test_value <= upper_bound) && (test_value >= lower_bound)){ // between ranges
		return true;
	}
	return false;
}

/**********************************************************
 *Function: is_capital()
 *Description: Looks for a capital letter
 *Parameters: char letter
 *Pre-conditions: takes a character input
 *Post-conditions: returns boolean
*********************************************************/
bool is_capital(char letter){
	if ((int(letter) <= 90) && (int(letter) >= 65)){ //checks if the character is between A and Z in the ASCII chart
		return true;
	}
	return false;
}

/**********************************************************
 *Function: is_even()
 *Description: finds if an integer is even
 *Parameters: int num
 *Pre-conditions: takes integer
 *Post-conditions: returns boolean
*********************************************************/
bool is_even(int num){
	if (num % 2 == 0){ // uses % to determine if even or odd
		return true;
	}
	return false;
}

/**********************************************************
 *Function: is_odd()
 *Description: checks if integer is odd
 *Parameters: int num 
 *Pre-conditions: integer value
 *Post-conditions: returns boolean
*********************************************************/
bool is_odd(int num){	
	if (num % 2 == 1){ // uses % to determine if even or odd
		return true;
	}
	return false;
}

/**********************************************************
 *Function: equality_test()
 *Description: checks if integer is less than, more than, or equal to another
 *Parameters: int num1, int num2
 *Pre-conditions: integer values
 *Post-conditions: returns -1, 0, or 1 for less, equal, or more
*********************************************************/
int equality_test(int num1, int num2){
	if (num1 < num2){
		return -1; //gives the -1,0,1 for each case
	}
	else if (num1 == num2){
		return 0;
	}
	else{
		return 1;
	}	
}

/**********************************************************
 *Function: float_is_equal()
 *Description: compares two numbers to be within a given precision
 *Parameters: float num1, float num2, float precision
 *Pre-conditions: takes two numbers
 *Post-conditions: returns boolean
*********************************************************/
bool float_is_equal(float num1, float num2, float precision){
	if (((num1 - num2) < precision) && ((num1 - num2) > -precision)){ //comparing to the negative too accounts for num2 being larger
		return true;
	}
	return false;
}

/**********************************************************
 *Function: is_int()
 *Description: checks if string is an integer
 *Parameters: string num
 *Pre-conditions: takes string and checks value
 *Post-conditions: returns boolean
*********************************************************/
bool is_int(string num){
	for(int i = 0; i < num.length(); i++){
		if ((int(num.at(i)) <= 57 && int(num.at(i)) >= 48)){ //checks each character in the string for a number outside the  ASCII chart
			return true;
		}
	}
	return false; //
}

/**********************************************************
 *Function: numbers_present()
 *Description: checks if numbers are in the string
 *Parameters: string sentence
 *Pre-conditions: takes string for comparison
 *Post-conditions: returns boolean
*********************************************************/
bool numbers_present(string sentence){
	for(int i = 0; i < sentence.length(); i++){
		if ((int(sentence.at(i)) <= 57) && (int(sentence.at(i)) >= 48)){
			return true;
		}
	}
}

/**********************************************************
 *Function: letters_present()
 *Description: checks if letters are in the string, lowercase and uppercase
 *Parameters: string sentence
 *Pre-conditions: takes string for comparison
 *Post-conditions: returns boolean
*********************************************************/
bool letters_present(string sentence){
	for(int i = 0; i < sentence.length(); i++){
		if (((int(sentence.at(i)) <= 122) && (int(sentence.at(i)) >= 97)) || ((int(sentence.at(i)) <= 90) && (int(sentence.at(i)) >= 65))){
			return true;
		}
	}
	return false;	
}

/**********************************************************
 *Function: sub_string()
 *Description: checks if a substring is within a larger string
 *Parameters: string sentence, string sub_string
 *Pre-conditions: takes two for comparison by looping through
 *Post-conditions: returns boolean
*********************************************************/
bool contains_sub_string(string sentence, string sub_string){
	for(int i = 0; i < (sentence.length()-sub_string.length()); i++){
		if (sentence.substr(i, sub_string.length()) == sub_string){
			return true;
		}
	}	
	return false;
}

/**********************************************************
 *Function: word_count()
 *Description: counts number of words in a sentence
 *Parameters: string sentence
 *Pre-conditions: sentence must have spaces between words
 *Post-conditions: returns number of words
*********************************************************/
int word_count(string sentence){
	int words = 1;
	for(int i = 0; i < sentence.length(); i++){
		if (int(sentence.at(i)) == 32){
			words += 1;
		}
	}
	return words;
}

/**********************************************************
 *Function: to_upper()
 *Description: takes lowercase lettters to uppercase
 *Parameters: string sentence
 *Pre-conditions: string contains lowercase letters
 *Post-conditions: returns capitalized sentence
*********************************************************/
string to_upper(string sentence){
	for(int i = 0; i < sentence.length(); i++){
		if ((int(sentence.at(i)) <= 122) && (int(sentence.at(i)) >= 97)){
			sentence.at(i) = sentence.at(i)-32;		
		}
	}
	return sentence;
}

/**********************************************************
 *Function: to_lower()
 *Description: takes string and makes all letters lowercase
 *Parameters: string sentence
 *Pre-conditions: sentence contains all letters
 *Post-conditions: sentence all lowercase
*********************************************************/
string to_lower(string sentence){
	for(int i = 0; i < sentence.length(); i++){
		if ((int(sentence.at(i)) <= 90) && (int(sentence.at(i)) >= 65)){
			sentence.at(i) = sentence.at(i)+32;		
		}
	}
	return sentence;
}

/**********************************************************
 *Function: get_int()
 *Description: takes a string and turns into an integer
 *Parameters: string prompt
 *Pre-conditions: processes string
 *Post-conditions: returns equivalent integer
*********************************************************/
int get_int(string prompt){
	cout << "\nEnter a number: " << endl;
	cin >> prompt;
	
	cout << "Actual: ";                       //Printing "Actual: " here is easier to manage while getting the same prompt displayed
	for(int i = 0; i < prompt.length(); i++){
		cout << prompt.at(i)-48;
	}
	cout << endl;
	return 0;
}
/**********************************************
 *Description: Calls all functions with test cases
***********************************************/
int main(){

	cout << "\nTesting check_range(2,5,3) \n"; //Good check_range()
	cout << "Expected: 1";
	cout << "\nActual: " << check_range(2,5,3);
	(check_range(2,5,3)==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing check_range(2,5,7) \n"; //Bad
	cout << "Expected: 0";
	cout << "\nActual: " << check_range(2,5,7);
	(check_range(2,5,7)==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting is_capital(\'D\') \n"; //Good is_capital()
	cout << "Expected: 1";
	cout << "\nActual: " << is_capital('D');
	(is_capital('D')==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing is_capital(\'d\') \n"; //Bad
	cout << "Expected: 0";
	cout << "\nActual: " << is_capital('d');
	(is_capital('d')==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting is_even(2)\n"; //Good is_even()
	cout << "Expected: 1";
	cout << "\nActual: " << is_even(2);
	(is_even(2)==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing is_even(5)\n"; //Bad
	cout << "Expected: 0";
	cout << "\nActual: " << is_even(5);
	(is_even(5)==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting is_odd(3)\n"; //Good is_odd()
	cout << "Expected: 1";
	cout << "\nActual: " << is_odd(3);
	(is_odd(3)==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing is_odd(4)\n"; //Bad
	cout << "Expected: 0";
	cout << "\nActual: " << is_odd(4);
	(is_odd(4)==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting equality_test(1,3) \n"; //less than equality_test()
	cout << "Expected: -1";
	cout << "\nActual: " << equality_test(1,3);
	(equality_test(1,3)==-1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing equality_test(4,4) \n"; //equal
	cout << "Expected: 0";
	cout << "\nActual: " << equality_test(4,4);
	(equality_test(4,4)==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing equality_test(5,3)\n"; //more than
	cout << "Expected: 1";
	cout << "\nActual: " << equality_test(5,3);
	(equality_test(5,3)==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting float_is_equal(3.001,2.999,0.005)\n"; //Good float_is_equal()
	cout << "Expected: 1";
	cout << "\nActual: " << float_is_equal(3.001,2.999,0.005);
	(float_is_equal(3.001,2.999,0.005)==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing float_is_equal(3.001,2.991,0.005)\n"; //Bad
	cout << "Expected: 0";
	cout << "\nActual: " << float_is_equal(3.001,2.991,0.005);
	(float_is_equal(3.001,2.991,0.005)==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting is_int(\"32\")\n"; //Good is_int()
	cout << "Expected: 1";
	cout << "\nActual: " << is_int("32");
	(is_int("32")==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing is_int(\"abc\")\n"; //Bad
	cout << "Expected: 0";
	cout << "\nActual: " << is_int("abc");
	(is_int("abc")==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting numbers_present(\"12c4\")\n"; //Good numbers_present()
	cout << "Expected: 1";
	cout << "\nActual: " << numbers_present("12c4");
	(numbers_present("12c4")==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing numbers_present(\"abtd\")\n"; //Bad
	cout << "Expected: 0";
	cout << "\nActual: " << numbers_present("abtd");
	(numbers_present("abtd")==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting letters_present(\"12c4\")\n"; //Good letters_present()
	cout << "Expected: 1";
	cout << "\nActual: " << letters_present("12c4");
	(letters_present("12c4")==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing letters_present(\"12?4\")\n"; //Bad
	cout << "Expected: 0";
	cout << "\nActual: " << letters_present("12?4");
	(letters_present("12?4")==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting contains_sub_string(\"testing this string\", \"ting\")\n"; //Good sub_string()
	cout << "Expected: 1";
	cout << "\nActual: " << contains_sub_string("testing this string", "ting");
	(contains_sub_string("testing this string", "ting")==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing contains_sub_string(\"testing this string\", \"stuff\")\n"; //Bad
	cout << "Expected: 0";
	cout << "\nActual: " << contains_sub_string("testing this string", "stuff");
	(contains_sub_string("testing this string", "stuff")==0)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting word_count(\"one two three\")\n"; //Good word_count()
	cout << "Expected: 3";
	cout << "\nActual: " << word_count("one two three");
	(word_count("one two three")==3)? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing word_count(\"one_two_three\")\n"; //Bad
	cout << "Expected: 1";
	cout << "\nActual: " << word_count("one_two_three");
	(word_count("one_two_three")==1)? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting to_upper(\"hello\")\n"; //All lower to_upper()
	cout << "Expected: HELLO";
	cout << "\nActual: " << to_upper("hello");
	(to_upper("hello")=="HELLO")? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing to_upper(\"TeStiNG\")\n"; //Mixed
	cout << "Expected: TESTING";
	cout << "\nActual: " << to_upper("TeStiNG");
	(to_upper("TeStiNG")=="TESTING")? cout << "\tPASS\n" : cout << "\tFAIL\n";



	cout << "\n\nTesting to_lower(\"HELLO\")\n"; //All upper to_lower()
	cout << "Expected: hello";
	cout << "\nActual: " << to_lower("HELLO");
	(to_lower("HELLO")=="hello")? cout << "\tPASS\n" : cout << "\tFAIL\n";

	cout << "Testing to_lower(\"TeStiNG\")\n"; //Mixed to_lower()
	cout << "Expected: testing";
	cout << "\nActual: " << to_lower("TeStiNG");
	(to_lower("TeStiNG")=="testing")? cout << "\tPASS\n" : cout << "\tFAIL\n";


	cout << "\n\nTesting get_int(\"Prompt\")\n"; //get_int
	cout << "Expected: prompt as an int";
	get_int("");



	return 0;
}

