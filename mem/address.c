#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
static int sa,sb = 10;
const char * ps = "abcsd";
const int pi = 10;
int ia = 10,ib;
int foo(){
	static int sfa;
	const int cfia = 10;
	int *fdp = (int *)malloc(10);
	int fia;
	cout <<"--foo bar"<<endl;
	cout <<"sfa:\t"<< &sfa <<endl;
	cout <<"cfia:\t"<< &cfia <<endl;
	cout <<"fia:\t"<< &fia <<endl;
	cout <<"fdp:\t"<< fdp <<endl;
}
int main(int argc, char const *argv[])
{
	/* code */
	static int isa,isb = 10;
	const char * ips = "abcsd";
	const int ipi = 10;
	int iia = 10,iib;
	int *dp = (int *)malloc(10);
	cout << "--functions:"<<endl;
	printf("main:\t%p\n",&main);
	printf("foo:\t%p\n",&foo);
	printf("printf:\t%p\n",&printf);

	foo();

	cout <<"--globel var"<<endl;
	cout <<"sa:\t"<< &sa <<endl;
	cout <<"sb:\t"<< &sb <<endl;
	cout <<"ps:\t"<< &ps <<endl;
	printf("abcsd:\t%p\n",ps);
	cout <<"pi:\t"<< &pi <<endl;
	cout <<"ia:\t"<< &ia <<endl;
	cout <<"ib:\t"<< &ib <<endl;
	

	cout << "--main var"<<endl;

	cout <<"isa:\t"<< &isa <<endl;
	cout <<"isb:\t"<< &isb <<endl;
	cout <<"ips:\t"<< &ips <<endl;
	printf("abcsd:\t%p\n",ips);
	cout <<"ipi:\t"<< &ipi <<endl;
	cout <<"iia:\t"<< &iia <<endl;
	cout <<"iib:\t"<< &iib <<endl;
	cout <<"dp:\t"<< dp <<endl;
	return 0;
}