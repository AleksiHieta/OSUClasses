#include <iostream>
#include <cstdlib>
#include "budget.h"


using namespace std;

int main(){
	return 0;
}

budget* create_budgets(int n){
	budget* budget = new budget[n];

	return budget;
}

void get_budget_data(budget* budget, int n, ifstream& file){
	
	for(int i = 0; i < n; i++){
		file >> budget[i].id >> budget[i].balance >> budget[i].num_transactions >> budget[i].transactions;
	}
}

transaction* create_transactions(int n){
	transaction* transactions = new transactions[n];

	return transactions;
}

void get_transaction_data(transactions* transactions, int n, ifstream& file){

	for(int i = 0; i < n; i++){
		file >> transactions[i].amount >> transactions[i].date >> transactions[i].category >> transactions[i].description;
	}
}

void delete_info(user** user, int m, budget** budget, int n){
//	for(int i = 0; i < m; i++){
//		delete [] user[i];
//	}
	delete [] user;
	user = NULL;
	
//	for(int i = 0; i < n; i++){
//		delete [] budget[i];
//	}
	delete [] budget;
	budget = NULL;
}

void order_ints(budget* budget, int n){
	int temp;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1-i; j++){
			if(budget[j].id > budget[j+1].id){
				temp = budget[j].id;
				budget[j].id = budget[j+1].id;
				budget[j+1].id = temp;
			}
		}
	}

	
}
