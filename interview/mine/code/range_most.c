#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
int bubble_sort(int *a,int len){
	int exch_count = 0;
	for(int i = len; i > 0 ; i-- ){
		exch_count = 0;
		for(int j = 1; j < i; j++){
			if(a[j] < a[j-1]){
				int t = a[j];
				a[j] = a[j-1];
				a[j-1] = t;
				exch_count++;
			}
		}
		if(exch_count == 0){
			break;
		}
	}
}
bool check(int *a,int len){
	for(int i =1;i < len;i++){
		if(a[i] < a[i-1]){
			return false;
		}
	}
	return true;
}
int range_most(int *a,int len){
	int ps = 0, pl = 0,max_c,max_v;
	while(pl < len && a[++pl] == a[ps]){
		cout << " -"<<a[pl] <<"("<<pl<<")";
	};
	max_c = pl - ps;
	max_v = a[ps];

	ps = pl;//new number
	while(ps + max_c < len){
		pl = ps + max_c;
		if(a[pl] != a[ps]){
			ps = pl;
			while(--ps >= 0 && a[ps] == a[pl]){
				cout << " -"<<a[ps]<<"("<<ps<<")";
			};
			ps++;
		}
		
		while(pl < len && a[++pl] == a[ps]){
			cout << " -"<<a[pl]<<"("<<pl<<")";
		};
		if(pl - ps > max_c){
			max_c = pl - ps;
			max_v = a[ps];
			cout << " *"<<a[ps]<<"("<<ps<<")";
		}
		ps = pl;
	}
	cout << endl;
	return max_v;
}
int main(int argc, char const *argv[])
{
	int max_count = 100;
	int * a = (int *)malloc(max_count * sizeof(int));
	for(int i = 0 ; i < max_count ; i++){
		a[i] = rand() % 100 + 1;
	}
	bubble_sort(a,max_count);
	// for(int i = 0; i < 10;i++){
	// 	a[i] = 1;
	// }
	check(a,max_count);
	for(int i = 0;i < max_count;i++){
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "max cout:" << range_most(a,max_count) << endl;

	free(a);

	return 0;
}