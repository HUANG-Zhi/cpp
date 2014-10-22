#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int tn ;
	cin >> tn;
	int counts[4];
	int index = 0;
	char lch;
	while(tn > 0){
		int len;
		cin >> len;
		string s;
		cin >> s;
		const char * str = s.c_str();
		
		index = 0;
		int i = 0;
		while(++i < len){
			if(i==1){
				lch = str[0];
				counts[index] = 1;
			}
			if(str[i] == lch && str[i]>='a'&& str[i]<='z'){
				counts[index]++;
			}else if((str[i] == lch + 1)&&str[i]>='a'&& str[i]<='z'){
				//aa bbcc
				if(index == 2){
					counts[0] = counts[1];
					counts[1] = counts[2];
					index--;
				}
				counts[++index] = 1;
				lch = str[i];
			}else {//abb d
				index = 0;
				counts[index] = 1;
				lch = str[i];
			}
			if(index == 2 && counts[0]>= counts[1] && counts[1] <= counts[2] ){
				cout << "YES" << endl;
				break;
			}
		}
		if(i==len){
			cout << "NO" << endl;
			//cout <<"--"<<i<<","<<index<<","<<counts[0]<<","<<counts[1]<<","<<counts[2]<<endl;
		}
		tn--;
	}
	return 0;
}