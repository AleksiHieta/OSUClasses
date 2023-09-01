#ifndef STUDENT_DB
#define STUDENT_DB

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct student{
	int id;
	string first;
	string last;
	string major;
};

student* create_student(int n);

void get_student_db_info(student* students, int n, ifstream& file);

void delete_student_db_info(student** students, int n);

void sort_num(student *students, int n);

#endif
