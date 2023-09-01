#include <iostream>
#include <fstream>
#include "student_db.h"

using namespace std;

student* create_student(int n){
	student* students = new student[n];	

	return students;
}

void get_student_db_info(student *students, int n, ifstream& file){
	int id; string major;
	
	for(int i = 0; i < n; i++){
		file >> students[i].id >> students[i].first >> students[i].last >> major;  //reads up until a space
		//students[i].id = atoi(id.c_str());
	}
}

void delete_student_db_info(student **students, int n){
//	for(int i = 0; i < n; i++){
//		delete [] students[i];
//	}
	delete [] students;
	students = NULL;
}

void sort_num(student *students, int n){
	int temp;
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-1-i; j++){
			if(students[j].id > students[j+1].id){
				temp = students[j].id;
				students[j].id = students[j+1].id;
				students[j+1].id = temp;		
			}
		}
	}
}
















