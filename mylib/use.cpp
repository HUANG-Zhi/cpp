// #include "queue.h"
// #include "stackqueue.h"
#include "maxqueue.h"
int main(int argc, char const *argv[])
{
	// stack<int> is;
	// is.push(1);
	// is.push(2);
	// //std::cout <<"stack size:"<<is.length();
	// //std::cout <<", "<< is.pop() << " " << is.pop() << std::endl;

	// is.push(3);
	// is.pop();
	// is.push(4);
	// is.pop();
	// is.pop();
	// is.pop();
	// //std::cout <<"stack size:"<<is.length()<<", "<< is.pop() << " " << is.pop() << std::endl;

	// queue<int> iq;
	// iq.enqueue(5);
	// iq.enqueue(6);
	// iq.enqueue(7);
	// iq.enqueue(8);
	// iq.dequeue();
	// iq.dequeue();
	// iq.enqueue(9);
	// iq.enqueue(10);
	// iq.enqueue(11);
	// iq.enqueue(12);
	// iq.dequeue();
	// iq.dequeue();
	// iq.dequeue();
	// iq.dequeue();
	// iq.dequeue();
	// iq.dequeue();
	// //std::cout <<"queue size:"<<iq.length();
	// //std::cout <<", "<< iq.dequeue() << " " << iq.dequeue() << std::endl;

	// std::cout<<"#############"<<std::endl;
	// stackqueue<int> isq;
	// isq.enqueue(5);
	// isq.enqueue(6);
	// isq.enqueue(7);
	// isq.enqueue(8);
	// isq.dequeue();
	// isq.dequeue();
	// isq.enqueue(9);
	// isq.enqueue(10);
	// isq.enqueue(11);
	// isq.enqueue(12);
	// isq.dequeue();
	// isq.dequeue();
	// isq.dequeue();
	// isq.dequeue();
	// isq.dequeue();
	// isq.dequeue();


	// maxstack<int> ms;
	// ms.push(1);
	// ms.max();
	// ms.push(10);
	// ms.push(20);
	// ms.max();
	// ms.pop();
	// ms.max();

	maxqueue<int> imq;
	imq.enqueue(50);
	imq.max();
	imq.enqueue(6);
	imq.dequeue();
	imq.max();
	imq.enqueue(70);
	imq.enqueue(8);
	imq.dequeue();
	imq.max();	
	imq.enqueue(2);
	imq.max();
	imq.enqueue(10);
	imq.enqueue(11);
	imq.enqueue(12);
	imq.dequeue();
	imq.dequeue();
	imq.dequeue();
	imq.dequeue();
	imq.dequeue();
	imq.max();
	imq.dequeue();
	return 0;
}