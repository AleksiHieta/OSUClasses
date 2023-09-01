/*********************************************************************************************************************
 * Program: Assignment 1
 * Author: Aleksi Hieta
 * Description: Takes various inputs to calculate the income, taxes, and remaining money for a car company
 * Input: Monthly Salary, Months Worked, Cost of a Car, Number of Cars Sold, Number of Misconducts, Tax Year, State
 * Output: Gross Income, Taxes, Remaining

**********************************************************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	float monthsal = 0;
	int monthwork = 0;
	float costcar = 0;
	int numcars = 0;
	int misconducts = 0;
	int year = 0;
	char state = 'x';
	float annualincome = 0;
	float profit = 0;
	float deduction = 0;
	float grossincome = 0;
	float taxes = 0;
	float remaining = 0;


	cout << "Enter monthly salary: " << endl;
	cin >> monthsal;

	cout << "Enter months worked out of the year: " << endl;
	cin >> monthwork;

	cout << "Enter the cost of a car: " << endl;
	cin >> costcar;

	cout << "Enter the number of cars cold: " << endl;
	cin >> numcars;

	cout << "Enter the number of misconducts" << endl;
	cin >> misconducts;

	cout << "Enter which tax year. 1 for 2017, 2 for 2018: " << endl;
	cin >> year;

	cout << "Enter which state. A, B, or C: " << endl;
	cin >> state;

		srand(time(NULL));	

	annualincome = monthsal * monthwork;

	profit = numcars * (costcar*(1 + 0.01 * (rand() % 6 + 4)));
	
		if (misconducts = 0){
			deduction = 0;
		}	
		else {
			deduction = 100 * 2^(misconducts - 1);
		}
	
	grossincome = annualincome + 0.02 * profit - deduction;

		
if (year = 1){
	if (state = 'A'){
		taxes = grossincome * 0.06;
	}
	else if (state = 'B'){
		if (grossincome <= 2000){
			taxes = 0;
		}
		else if (grossincome > 2000 && grossincome <= 10000){
			taxes = 100;
		}
		else {
			taxes = 100 + (grossincome-2000) * 0.1;
		}
	}
	else {
		if (grossincome <= 3500){
			taxes = grossincome * 0.05;
		}
		else if (grossincome > 3500 && grossincome <= 9000){
			taxes = 175 + (grossincome-3500) * 0.07;
		}
		else if (grossincome > 9000 && grossincome <= 12500){
			taxes = 560 + (grossincome-9000) * 0.09;
		}
		else if (grossincome > 12500) {
			taxes = 1100 + (grossincome-12500) * 0.099;
		}
	}
}
else if (year = 1){
	if (state = 'A'){
		taxes = grossincome * 0.08;
	}
	else if (state = 'B'){
		if (grossincome <= 2500){
			taxes = 0;
		}
		else if (grossincome > 2500 && grossincome <= 10000){
			taxes = 115;
		}
		else {
			taxes = 115 + (grossincome-2500) * 0.105;
		}
	}
	else {
		if (grossincome <= 3450){
			taxes = grossincome * 0.05;
		}
		else if (grossincome > 3450 && grossincome <= 8700){
			taxes = 172.5 + (grossincome-3450) * 0.07;
		}
		else if (grossincome > 8700 && grossincome <= 12500){
			taxes = 540 + (grossincome-8700) * 0.09;
		}
		else if (grossincome > 12500){
			taxes = 1107 + (grossincome-12500) * 0.099;
		}
	}
}

	remaining = grossincome - taxes;	
	
	grossincome =float(int(grossincome*100)/100);
	taxes = int(taxes*100)/100;
	remaining = int(remaining*100)/100;

	cout << "Gross Income is: " << grossincome << endl;
	cout << "Taxes is: " << taxes << endl;
	cout << "The remaining is: " << remaining << endl;
	
	return 0;

}
