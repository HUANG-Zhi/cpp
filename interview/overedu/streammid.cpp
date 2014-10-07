#include <iostream>
#include <queue>
#include <vector>
#include <cassert>
using namespace std;
class IntComparor{
private:
	bool isasc;
public:
	IntComparor(bool _isasc){isasc = _isasc;}
	bool operator ()(const int &li, const int &hi) const{
		if(isasc) return li > hi;
		else return li < hi;
	}
};
int main(int argc, char const *argv[])
{
	/* code */
	priority_queue<int,vector<int>,IntComparor> maxqueue(IntComparor(false)),minqueue(IntComparor(true));
	vector<int> squ;
	int input = 0;
	while(cin >> input){
		//store
		if(maxqueue.size() == minqueue.size()){
			if(minqueue.size() > 0 && input > minqueue.top()){
				maxqueue.push(minqueue.top());
				minqueue.pop();
				minqueue.push(input);
			}else{
				maxqueue.push(input);
			}
		}else{
			assert(maxqueue.size()== minqueue.size()+1);
			if(input < maxqueue.top()){
				minqueue.push(maxqueue.top());
				maxqueue.pop();
				maxqueue.push(input);
			}else{
				minqueue.push(input);
			}
		}

		//get middle
		for(vector<int>::const_iterator i = squ.begin(); i != squ.end(); ++i){
			cout << *i << " ";
		}
		cout << ":";
		if(maxqueue.size() > minqueue.size()){
			assert(maxqueue.size()== minqueue.size()+1);
			cout << maxqueue.top();
		}else{
			assert(maxqueue.size()== minqueue.size());
			cout << ((maxqueue.top() + minqueue.top()) / 2.0) << " ";
		}
		cout <<endl;
	}
	cout << " end"<<endl;
	return 0;
}