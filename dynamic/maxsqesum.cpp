#include <iostream>
#include <cstdlib>
using namespace std;
void max_seq_sum(const int* a,const int len,int &start,int &end,int &sum){
	if(len <= 0 ){
		start = -1;
		end = -1;
		sum = -1;
		return;
	}
	start = 0;
	end = 0;
	sum = a[0];

	int cs = 0, ce = 0, cm = a[0];
	int i = 0;
	for(i = 1; i < len; i++){
		if(cm + a[i] < a[i]){
			cs = i;
			ce = i;
			cm = a[i];
		}else{
			cm = cm + a[i];
			ce = i;
		}

		if(sum < cm){
			start = cs;
			end = ce;
			sum = cm;
		}
	}
}
int main(int argc, char const *argv[])
{
	int count;
	cin >> count;
	while(count >0){
		int size;
		cin >> size;
		int * arr = (int *)malloc(size * sizeof(int));
		int i = 0;
		while(i < size){
			cin >> arr[i++];
		}
		int start,end,sum;
		max_seq_sum(arr,size,start,end,sum);
		cout << "--" << start <<"-" << end << ":" << sum << endl;

		free(arr);
		//return start,end
		count--;
	}
	return 0;
}