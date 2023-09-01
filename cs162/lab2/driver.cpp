#include <iostream>
#include <fstream>
#include <cstdlib>
#include "student_db.cpp"
#include "inputs.txt"

using namespace std;

int main(){
	ifstream in_file;
	in_file.open("inputs.txt");

	if(in_file.is_open()){

	}
	else{
		cout << "Error, file is already open" << endl;
		return 0;
	}

	int count;
	in_file >> count; //reads first number

	student* students = create_student(count);	
	get_student_db_info(students, count, in_file);

	int choice;
	cout << "What you wanna do?" << endl;
	cout << "1 number || 2 first name || 3 last name" << endl;
	cin >> choice;
	
	if (choice == 1){
		sort_num(students, count);
	}
	else if (choice == 2){

	}
	else if (choice == 3){

	}

	ofstream out_file("output.txt", fstream::app);

	in_file.close(); out_file.close();

	return 0;
}
