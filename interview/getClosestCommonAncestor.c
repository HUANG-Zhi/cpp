#include <iostream>
#include <cassert>
using namespace std;
// caculate count and first node ID of level of node
int initFC(int node,int &f,int &c){
	f = 0;
	c = 1;
	while(f < node){
		c *= 3;
		f += c;
	}
	f -= c;
}

int getClosestCommonAncestor(int node1,int node2){
	assert(node1 >=0 && node2>=0);
	int f1,c1,f2,c2;
	// caculate count and first node of (level of node1)
	initFC(node1,f1,c1);

	// caculate count and first node of (level of node2)
	initFC(node2,f2,c2);
	while(node1 != node2){
		if(node2 > node1){
			c2 /= 3;
			f2 -= c2;
			// set node2 to its parent
			node2 = 2*f2 + c2 + 1 - (node2-1) / 3;
		}else if(node1 > node2){
			c1 /= 3;
			f1 -= c1;
			// set node1 to its parent
			node1 = 2*f1 + c1 + 1 - (node1-1) / 3;
		}
	}
	return node1;
}

int main(int argc, char const *argv[])
{
	int f,c;
	cout << getClosestCommonAncestor(0,10)<<endl;
	cout << getClosestCommonAncestor(3,1)<<endl;
	cout << getClosestCommonAncestor(1,4)<<endl;
	cout << getClosestCommonAncestor(13,9)<<endl;
	cout << getClosestCommonAncestor(13,15)<<endl;
	cout << getClosestCommonAncestor(10,16)<<endl;
	return 0;
}