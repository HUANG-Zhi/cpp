#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/*
* get a postive number from [const char * ps] start from [const int start] split by '.',
number store in {int& value}
* return value:
    -1 no more number
    next position to read from;
*/
int get_number(const char * ps, const int len,const int start, int& value){
	if(NULL == ps | len <= start) return -1;
	value = 0;
	int i = start;
	while(i < len){
		if(ps[i] == '.') break;
		else {
			value += value * 10 + (ps[i] - '0');
			i++;
		}		
	}
	return i+1;
}

int compare_version(const char * a,const char * b){
	int la = strlen(a);
	int lb = strlen(b);
	int na,nb;
	int posa = 0 ;
	int posb = 0 ;
	while((posa = get_number(a,la,posa,na)) != -1){
		posb = get_number(b,lb,posb,nb);
		if(-1 == posb){
			//b end, check remain numbers of a
			if(na > 0) return 1;
			else{
				while((posa = get_number(a,la,posa,na)) != -1){
					if(na > 0) return 1;
				}
				//remain number of a are all 0s
				return 0;
			}			
		}else if(na == nb) continue;
		else return na > nb ? 1 : -1;
	}

	//a end, check remain numbers of b
	while((posb = get_number(b,lb,posb,nb)) != -1){
		if(nb > 0) return -1;
	}

	//all numbers are equal
	return 0;
}

int main(int argc, char const *argv[])
{
	string v1;
	string v2;
	while(true){
		cin >> v1;
		cin >> v2;
		cout << v1 << "," << v2 << endl;
		cout << compare_version(v1.c_str(),v2.c_str()) << endl;
	}	
	return 0;
}