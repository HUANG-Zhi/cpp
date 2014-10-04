#include <cassert>
#include "stdlib.h"
#include <iostream>
template <class T>
class stack{
private:
	T ** elems;
	int size;
	int capacity;
	bool full(){return size == capacity;}
	void resize(int nsize){
		assert(nsize > size);
		T ** telems = new T*[nsize]();
		// copy all to telems
		for(int i = 0 ; i < size ; i++){
			telems[i] = elems[i];
		}
		// free old, assign new to elems;
		delete [] elems;
		capacity = nsize;
		elems = telems;
	}
	void display(){
		std::cout<<std::endl<<"----("<<capacity<<"): ";
		for(int i = 0 ; i < capacity ; i++){
			if(i > 0){
				std::cout << ", ";
			}
			if(elems[i] == NULL){
				std::cout << "NULL";
			}else{
				std::cout << *elems[i];
			}			
		}
		std::cout << std::endl;
	}
public:
	stack():size(0),capacity(1){
		elems = new T* [capacity]();
	}
	bool empty(){return size == 0;}
	void push(const T& elm){
		if(full()){resize(size * 2);}
		elems[size++] = new T(elm);
		//display();
	}
	T top(){
		try{
			if(empty()){
				throw "can't get anything from empty stack!";
			}
		}catch (const char * e){
			std::cerr << e << std::endl;
		}		
		return *elems[size-1];
	}
	T pop(){
		T t = top();
		size--;
		delete elems[size];
		elems[size] = NULL;
		if(size > 0 && size == capacity / 4){
			resize(capacity / 2);
		}
		//display();
		return t;
	}
	int length(){
		return size;
	}
	~stack(){
		for(int i = 0; i < size; i++){
			delete elems[i];
		}
		delete [] elems;
	}
};