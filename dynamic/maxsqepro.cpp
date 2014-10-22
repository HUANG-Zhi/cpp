#include <iostream>
#include <cstdlib>
using namespace std;
void max_sqe_pro(const int * a,const int len,int& start,int& end,int& pro){
	if(len <= 0){
		start = -1;
		end = -1;//check
		pro = -1;
		return;
	}
	start = 0;
	end = 0;
	pro = a[0];

	int cas = 0, cae = 0, cap = a[0];
	int cis = 0, cie = 0, cip = a[0];
	int i = 0;
	for(i = 1; i < len; i++){
		int ta = cap * a[i];
		int ti = cip * a[i];
		
		cae = i;
		cap = ta;	
		if(cap < a[i]){
			cas = i;
			cae = i;
			cap = a[i];
		}
		if(cap < ti){
			cas = cis;	
			cae = i;
			cap = ti;
		}

		cie = i;
		cip = ti;
		if(cip > a[i]){
			cis = i;
			cie = i;
			cip = a[i];
		}
		if(cip > ta){
			cis = cas;
			cie = i;
			cip = ta;
		}

		if(pro < cap){
			start = cas;
			end = cae;
			pro = cap;
		}	
	}
}

int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	while(count > 0){
		int len;
		cin >> len;
		int * arr = (int*)malloc(len * sizeof(int));
		int i = 0;
		while(i < len){
			cin >> arr[i];
			i++;
		}
		int start,end,pro;
		max_sqe_pro(arr,len,start,end,pro);
		cout <<"--" << start << "-" << end <<":"<< pro << endl;

		free(arr);
		count -- ;
	}
	return 0;
}