#include "maxstack.h"
template <class T>
class maxqueue{
private:
	maxstack<T> in,out;
public:
	int length(){return in.length()+out.length();}
	void enqueue(const T& elm){
		in.push(elm);
		std::cout<<"----enqueue: "<<elm<<std::endl;
	};
	T top(){
		if(!out.empty()) return out.top();
		else{
			while(!in.empty()){
				out.push(in.pop());
			}
			return out.top();
		}
	}
	T dequeue(){
		T e = top();
		out.pop();
		std::cout<<"----dequeue: "<<e<<std::endl;
		return e;
	}
	bool empty(){
		return in.empty() && out.empty();
	}
	T max(){
		T tmax ;
		if(in.empty()) tmax =  out.max();
		else if(out.empty()) tmax = in.max();
		else tmax = in.max() > out.max()? in.max():out.max();
		std::cout<<"----max: "<<tmax<<std::endl;
		return tmax;
	}
};