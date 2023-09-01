
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

void merge(int* list, int start, int mid, int end){
	int i = start;
	int k = 0;
	int j = mid+1;
	int temp[end-start+1];

	while(i <= mid && j <= end){
		if(list[i] < list[j]){
			temp[k] = list[i];
			k++;
			i++;
		}
		else{
			temp[k] = list[j];
			k++;
			j++;
		}
	}
	while(i <= mid){
		temp[k] = list[i];
		k++;
		i++;
	}
	while(j <= end){
		temp[k] = list[j];
		k++;
		j++;
	}
	for(i = start; i <= end; i++){
		list[i] = temp[i-start];
	}
}

void merge_sort(int* list, int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		merge_sort(list, start, mid);
		merge_sort(list, mid+1, end);

		merge(list, start, mid, end);
	}
}

int main(){
	srand(time(NULL));

	string length;
	int size;

	bool test;
	do{
	cout << "Enter the length of the array: ";
	cin >> length;
	if(!(istringstream(length) >> size)){
		test = false;
	}
	else{
		if(size <= 0 || size > 25){	
			test = false;
		}
		else{
			test = true;
		}
	}
	}while(!test);	


	int* arr;
	arr = new int[size];

	//SET VALS
	for(int i = 0; i < size; i++){
		arr[i] = rand() % 100 + 1;
	}	
	//PRINT
	cout << "=============" << endl;
	cout << "Unsorted List" << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}	
	cout << endl;
	//NEW ARRAY
	int* arr2 = new int[size];
	//COPY
	for(int i = 0; i < size; i++){
		arr2[size] = 0;
	}	
	for(int i = 0; i < size; i++){
		arr2[size] = arr[size];
	}
/*
	//PRINT 2nd array
	for(int i = 0; i < size; i++){
		cout << arr2[i] << " ";
	}	
	cout << endl;
*/

	//SORT
	merge_sort(arr, 0, size-1);	

	//PRINT
	cout << "=============" << endl;
	cout << " Sorted List " << endl;
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}	
	cout << endl;

	//PRIME
	cout << "=============" << endl;
	cout << "Prime Numbers" << endl;
	for(int i = 0; i < size; i++){
		bool is_prime = true;
		int j = 2;
		float j2 = 2.0;
		do{
		//cout << "Num: " << arr[i] << endl;
		//cout << "Int Div: " << arr[i]/j << endl;
		//cout << "Float Div: " << arr[i]/j2 << endl;
		if(arr[i]/j == arr[i]/j2){
			//PRIME
			is_prime = false;
		}
		j++;
		j2 = j2 + 1.0;
		}while(j < arr[i]);
		if(is_prime){
			cout << arr[i] << " ";
		}
	}
	cout << endl;
	cout << "=============" << endl;



	//free mem
	delete [] arr;
	delete [] arr2;
	arr = NULL;
	arr2 = NULL;

	return 0;
}
