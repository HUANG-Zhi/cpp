#include <iostream>
#include <cassert>
template <class T>
class queue{
private:
	int N;
	int capacity;
	T** elems;
	int first,last;
	bool full(){return N == capacity;}
	void resize(int newsize){
		assert(newsize > N);
		T** telems = new T*[newsize]();
		for(int i = 0; i < N; i ++){
			telems[i] = elems[(first + i) % capacity];
		}
		delete [] elems;
		elems = telems;
		capacity = newsize;
		first = 0;
		last = N;
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
	queue():N(0),capacity(1),first(0),last(0){
		elems = new T*[capacity]();
	}
	~queue(){
		for(int i = 0; i < N; i ++){
			delete elems[(first + i) % capacity];
		}
		delete [] elems;
	}
	bool empty(){return N == 0;}
	T front(){
		try{
			if(empty()){
				throw " you can't get anything from empty queue!";
			}
		}catch (const char * estr){
			std::cerr << estr << std::endl;
		}
		return *elems[first];
	}
	T dequeue(){
		T e = front();
		delete elems[first];
		elems[first] = NULL;
		N--;

		first++;
		if(first == capacity) first = 0;
		if(N > 0 && N == capacity / 4) resize( capacity / 2);
		display();
		return e;
	}
	void enqueue(const T& elem){
		if(full()) resize(capacity * 2);
		elems[last] = new T(elem);
		N++;

		last++;
		if(last == capacity) last = 0;
		display();
	}
	int length(){return N;}
};