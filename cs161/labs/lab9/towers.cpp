#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int** create_arr(int size, int start){

	int** dyn_arr = new int* [size];
	for(int i = 0; i < size; i++){
		dyn_arr[i] = new int[3]; //number of poles = 3
	}


	for(int i = 0; i < size; i++){
		for(int j = 0; j < 3; j++){
			dyn_arr[i][j] = 0;
		}
	}

	for(int i = 0; i < size; i++){
		dyn_arr[i][0] = (i+1);
	}

	return dyn_arr;
}

void print_arr(int** arr, int size){
	
	for(int i = 0; i < size; i++){
		for(int j = 0; j < 3; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void move_disk(int** arr, int s, int number_of_disk, int from_col, int to_col, int spare){

/*	cout << "disk Number: " << number_of_disk << endl;
	cout << from_col << endl;
	cout << to_col << endl;
	cout << spare << endl;
*/	
	for(int i = (s-1); i >= 0 ; i--){
		if(arr[i][to_col] == 0){
			arr[i][to_col] = number_of_disk;
			break;
		}
	}

	for(int i = 0; i < s; i++){
		if(arr[i][from_col] == number_of_disk){
			arr[i][from_col] = 0; 
		}
	}
}	

void towers(int s, int number_of_disk, int** b, int from_col, int to_col, int spare){
	if(number_of_disk >= 1){
	towers(s, number_of_disk-1, b, from_col, spare, to_col);
	move_disk(b, s, number_of_disk, from_col, to_col, spare);
	print_arr(b, s);
	towers(s, number_of_disk-1, b, spare, to_col, from_col);
	}
}



int main(){
	int num;
	cout << "Enter size: ";
	cin >> num;

	int from_col;
	cout << "Enter starting pole: ";
	cin >> from_col;
	from_col = from_col - 1;

	int to_col;
	cout << "Enter ending pole: ";
	cin >> to_col;
	to_col = to_col - 1;

	int spare;
	cout << "Enter spare (diff from last 2): ";
	cin >> spare;
	spare = spare - 1;

	int s = num;

	int** arr;

	arr = create_arr(s, from_col);

	towers(s, num, arr, from_col, to_col, spare);






	for(int i = 0; i < s; i++){
		delete [] arr[i];
	}
	delete [] arr;
	arr = NULL;

	return 0;
}
