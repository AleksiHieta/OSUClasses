#include <iostream>
#include <cstdlib>

using namespace std;
/**********************************
 *Struct: user
 *Description: contains the user's username, ID, and password
**********************************/
struct user{
	string name;
	int id;
	string password;
};

/******************************************************************
 *Struct: budget
 *Description: contains user's ID, budget balance,
 *   number of transactions, and struct of transaction descriptions
*******************************************************************/
struct budget{
	int id;
	float balance;
	int num_transactions;
	struct transactions *t;
};

/***********************************************
 *Struct: transaction
 *Description: contains transaction descriptions 
 *   i.e. cost, date, category, description
************************************************/
struct transactions{
	float amount;
	string date;
	string category;
	string description;
};

/****************************************
 *Function: create_budgets
 *Description: Creates array of n budgets
 *Input: n for size
 *Output: Array of size n
*****************************************/
budget* create_budgets(int n);

/**********************************************
 *Function: get_budget_data
 *Description: Does shit
 *Input: Budget array, size of array, text file
 *Output: Filled array with text data
***********************************************/
void get_budget_data(budget* budget, int n, ifstream &);

/****************************************
 *Function: create_transactions
 *Description: Creates array of n budgets
 *Input: n for size
 *Output: Array of size n
*****************************************/
transaction* create_transactions(int n);

/***************************************************
 *Function: get_transaction_data
 *Description: Shit
 *Input: Transaction array, size of array, text file
 *Output: Filled array of size n
 *
 *
****************************************************/
void get_transaction_data(transaction* transactions, int n, ifstream &);


/**************************************************************
 *Function: delete_info
 *Description: deletes dynamically allocates arrays from memory
 *Input: User array, size m, budget array, size n
 *Output: No mas arrays
***************************************************************/
void delete_info(user** user, int m, budget** budget, int n);

/*
 *
 *
*****************/
void order_ints(budget* budget, int n);


