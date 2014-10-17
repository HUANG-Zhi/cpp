#include <iostream>
#include <vector>
using namespace std;
class ugly
{
private:
	static int prim_num;
	static int prims[];
	static int lastps[];
	static vector<int> uglys;
public:
	static int getK(int k){
		if(uglys.size() <= k){
			//generate to Kth ugly number
			for(int i = uglys.size() - 1; i < k ; i++){
				int np = 0;
				int nu = uglys.at(lastps[np]) * prims[np];
				for(int j = 1; j < prim_num; j++){
					int cu = uglys.at(lastps[j]) * prims[j];
					if(cu < nu){
						nu = cu;
						np = j;
					}
				}				
				//update last ugly points
				for(int j = 0; j < prim_num; j++){
					if(uglys.at(lastps[j]) * prims[j] == nu){
						lastps[j]++;
					}
				}
				cout << "- " <<nu;
				//push new ugly number
				uglys.push_back(nu);
			}
		}
		return uglys.at(k-1);
	}
};
int ugly::prim_num = 3;
int ugly::prims[] = {2,3,5};
int ugly::lastps[] = {0,0,0};
vector<int> ugly::uglys = []()->vector<int>{
    vector<int> v;
    v.push_back(1);
    return v;
}();

int main(int argc, char const *argv[])
{
	cout <<endl <<"#" << ugly::getK(2) <<endl;
	cout <<endl <<"#" << ugly::getK(5) <<endl;
	cout <<endl <<"#" << ugly::getK(20) <<endl;
	return 0;
}