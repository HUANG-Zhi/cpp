#include "stack.h"
template <class T>
class maxstack{
private:
	stack<T> values,maxvalues;
public:
	bool empty(){return values.empty();}
	int length(){return values.length();}
	void push(const T& elm){
		if(values.empty()){
			maxvalues.push(elm);
		}else{
			T nmax = maxvalues.top();
			nmax =  elm > nmax ? elm : nmax;
			maxvalues.push(nmax);
		}
		values.push(elm);
		//std::cout<<"----push: "<<elm<<std::endl;
	}
	T pop(){
		maxvalues.pop();
		T e = values.pop();
		//std::cout<<"----pop: "<<e<<std::endl;
		return e;
	}
	T top(){
		//std::cout<<"----top: "<<values.top()<<std::endl;
		return values.top();
	}
	T max(){
		//std::cout<<"----max: "<<maxvalues.top()<<std::endl;
		return maxvalues.top();
	}
};