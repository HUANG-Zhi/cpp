#include <iostream>
using namespace std;
int count(int n,int weight){
	if(n < 1) return 0;
	else if( n < 10) return 1;

	//min weight = 1
	while(weight > n){
		weight /= 10;
	}

	// cout << "#("<<n<<","<<weight <<") ";
	int sum = 0;
	//0 - (n/weight-1):0-99..
	int w = count(weight - 1,weight / 10);
	// cout << "w"<< n <<"-("<<w<<","<< n / weight<<") ";
	sum += w * (n / weight);

	// n/weight：abc
	int remain = count(n % weight, weight / 10);
	// cout <<"r"<< n << "-("<<remain<<","<< n % weight<<") ";
	sum += remain;

	// 1：abc or 1:0-99..
	int oneall =(n / weight) > 1? weight: n % weight + 1;
	// cout <<"o"<< n << "-("<<oneall<<","<< n / weight<<") ";

	sum+= oneall;
	return sum;
}

int main(int argc, char const *argv[])
{
	//cout << count(1,1);
	int n;
	while((cin >> n)!= NULL){
		int weight = 1;
		while(weight <= n){
			weight *= 10;
		}
		weight /= 10;
		cout << count(n,weight)<<endl;
	}
	return 0;
}
