//try_vector.cpp
#include "./vector.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <exception>

//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main(){
	vector<int> v; //our vector
	vector<int> v2; 

	vector<int> v3 = v;

	v2 = v;
	//v.set_size(4);



	std::vector<int> stdv; //standard vector

	//compare operation of our vector to std
	v.push_back(23);
	stdv.push_back(23); 

	cout << "Our vector size: " << v.size() << endl;
	cout << "STL vector size: " << stdv.size() << endl;
	
	cout << "v at 0 (using []): " << v[0] << endl;
	cout << "v at 0 (using .at()): " << v.at(0) << endl;

	cout << "error catching with v.at(-1)" << endl;
	try{
		v.at(-1);
	}catch(std::out_of_range e){
		cout << "Bad stuff" << endl;
	}


	return 0;
}	
