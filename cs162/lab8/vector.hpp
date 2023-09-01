//vector.hpp
#include <stdlib.h>
#include <iostream>
#include <exception>
#include <stdexcept>

template <class T>

class vector {
private:
	T *v;
	int s;
public:
	vector(){
		std::cout << "Constructor" << std::endl;
		s = 0;
		v = NULL;
	}
	~vector(){
		std::cout << "Destructor" << std::endl;
		delete [] v;
	}
	vector(vector<T> &other){	//copy constructor
		std::cout << "Copy Constructor" << std::endl;
		this->s = other.s;
		this->v = new T[s];
		for(int i = 0; i < s; i++){
			this->v[i] = other.v[i];
		}
	}
	void operator=(vector<T> &other){ //operator overload	
		std::cout << "operator overload" << std::endl;
		delete [] v;
		this->s = other.s;
		this->v = new T[s];
		for(int i = 0; i < s; i++){
			this->v[i] = other.v[i];
		}
	}
	void set_size(int size){
		s = size;
		for(int i = 0; i < s; i++){
			v[i] = i;
		}
	}
	int size(){
		return s;
	}

	void push_back(T ele){
		T *temp;
		temp = new T[++s];
		for(int i = 0; i < s-1; i++)
			temp[i] = v[i];
		delete [] v;
		v = temp;
		v[s-1] = ele;		
	}
	T operator[](int index){
		return this->v[index];
	}
	T at(int index){
		if((index > s) || (index < 0)){
			throw this->std::invalid_argument("U R Bad");
		}
		return this->v[index];
	}


};
