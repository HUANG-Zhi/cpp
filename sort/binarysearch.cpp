#include <iostream>
#include <cassert>
#include <deque>
using namespace std;
bool checkorder(int * a,int len){
	for(int i = 1; i < len; i++){
		if(a[i] < a[i-1]) return false;
	}
	return true;
}
int binary_search(int * a,int low,int high,int v){
	if(high < low) return -1;

	int mid = (high - low) / 2 + low;
	while(low <= high){
		// // find a position
		//mid = (high - low) / 2 + low; 
		//if(a[mid] < v){
		// 	low = mid + 1;
		// }		
		// else if(a[mid] > v){
		// 	high = mid - 1;
		// }
		// else return mid;

		//find first position
		mid = (high - low) / 2 + low; 
		if(a[mid] < v){
			low = mid + 1;
		}	
		else{
			high = mid;
			if(high == low){
				mid = low;
				break;
			}
		}

		// //find last position
		// mid = (high - low + 1) / 2 + low; 
		// if(a[mid] <= v){
		// 	low = mid;
		// 	if(high == low){
		// 		mid = low;
		// 		break;
		// 	}
		// }	
		// else{
		// 	high = mid-1;
		// }
	}
	return mid;
}

int binary_search_upper(int * a,int low,int high,int v){
	assert(high >= low);
	int mid = (high - low) / 2 + low;
	while(low <= high){
		//find insert position
		mid = (high - low) / 2 + low; 
		if(a[mid] <= v){
			low = mid + 1;
		}	
		else{
			high = mid;
			if(high == low){
				break;
			}
		}
	}
	return low;
}

int binary_search_upper2(int * a,int low,int high,int v){
	assert(high >= low);
	int mid = (high - low) / 2 + low;
	while(low <= high){
		//find insert position
		mid = (high - low) / 2 + low; 
		if(a[mid] < v){
			low = mid + 1;
		}	
		else{
			high = mid;
			if(high == low){
				break;
			}
		}
	}
	return low;
}

deque<int> lis(const int* a,const int len){
	assert(len > 0);
	int* squ = new int[len];
	squ[0] = a[0];
	int pos;
	int bestl = 0,slen = 1;
	for(int i = 1; i < len; i++){
		// equal-increase
		//pos = binary_search_upper(squ,0,slen-1,a[i]);
		//strict increase
		pos = binary_search_upper2(squ,0,slen-1,a[i]);
		squ[pos]=a[i];
		if(slen < pos + 1){
			slen = pos+1;
			bestl = i;
		}
	}
	int last = squ[slen-1];
	deque<int> ss;
	ss.push_front(last);
	for(int i = len - 1 , j = slen-2; i >= 0 && j >=0 ; i--){
		// equal-increase
		//if(a[i] >= squ[j] && a[i] <= last){
		//strict increase
		if(a[i] >= squ[j] && a[i] < last){
			last = a[i];
			ss.push_front(last);
			j--;
		}
	}
	delete [] squ;
	return ss;
}

int main(int argc, char const *argv[])
{
	/* code     0,1,2,3,4,5,6,7,8,9,10,11 */
	int a[12] ={1,1,2,2,4,4,4,4,5,5,6, 7};
	int b[12] ={1,1,2,8,4,7,4,4,5,5,1, 7};
	int value;
	// assert(checkorder(a,12));
	// while(cin >> value){
	// 	cout << binary_search_upper2(a,0,11,value)<<endl;
	// }

	for(auto e : lis(b,12)){
		cout << e <<" ";
	}
	cout << endl;
	return 0;
}