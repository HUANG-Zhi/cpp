#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int randint(int k){
	return rand() % k + 1;
}
int check(int k,int max_count,int (*r_int)(int)){
	int* counts = (int *)malloc(k * sizeof(int));
	for(int i =0; i < k;i++){
		counts[i] = 0;
	}
	for(int i = 0; i < k*max_count;i++){
		counts[r_int(k)-1]++;
	}
	for (int i = 0; i < k; ++i)
	{
		cout << i + 1 << "(" << counts[i] << ") ";
	}
	cout << endl;
	free(counts);
}
int randcon(int f,int t){
	//t bucket, each with a rand number bettwen 1 and f, find the index
	// of the only one min number, repeat if there are more than one min number
	int* counts = (int *) malloc(t * sizeof(int));
	int min = 0,max = 0;
	int count = 0;
	while(true){
		min = 0;
		max = 0;
		for(int i = 0; i < t;i++){
			counts[i] = randint(f);
			if(counts[i] < counts[min]){
				min = i;
			}else if(counts[i] > counts[max]){
				max = i;
			}
		}
		count ++;
		int i = 0;
		for(i = 0; i < t ; i++){
			if(i == min) continue;
			if(counts[i] ==  counts[min]) break;
		}		
		if(i == t){
			//cout << " - "<<count;
			return min + 1;
		}else{
			for(i = 0; i < t ; i++){
				if(i == max) continue;
				if(counts[i] ==  counts[max]) break;
			}
			if(i == t){
				//cout << " - "<<count;
				return max + 1;
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	srand(time(NULL));
	check(7,10000,[](int t)->int { return randcon(5,t); });
	return 0;
}