#include <iostream>
using namespace std;
bool isSym(int n){
	int low_mask = 1;
	int high_mask = 10;
	while(high_mask <= n){
		high_mask *= 10;
	}
	high_mask /= 10;
	while(high_mask > low_mask){
		/*cout << "-("<<high_mask<<","<<low_mask<<"),"
		<< "-("<<(n % (high_mask*10))/high_mask<<","
		<<(n % (low_mask*10))/low_mask << ")-"<<endl;
		*/
		if((n % (high_mask*10))/high_mask != (n % (low_mask*10))/low_mask)
			return false;
		high_mask /= 10;
		low_mask *= 10;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int n;
	while(NULL != (cin>>n)){
		cout << n <<":" << (isSym(n)?"yes":"no") << endl;
	}
	return 0;
}