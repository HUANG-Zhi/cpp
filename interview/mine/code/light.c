#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int lights[101];
	for(int i = 1;i < 101;i++){
		lights[i] = 1;
	}
	for(int i = 2; i < 101;i++){
		for(int j = i; j < 101; j += i){
			lights[j] = lights[j] == 1 ? 0 : 1;
		}
	}
	for (int i = 1; i < 101; ++i)
	{
		if(lights[i] == 1){
			cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}