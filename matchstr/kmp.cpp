#include <iostream>
#include <string>
using namespace std;
int kmp(string s,string m){
	const int R = 256;
	//allocate dfa
	int len = m.length();
	char ** dfa = new char* [R];
	for(int i = 0 ; i < R ; i ++){
		dfa[i] = new char[len]();
	}
	//construct dfa
	dfa[m.at(0)][0] = 1;
	int k = 0;//k is s[1:i-1] state and i is s[0:i-1] state
	for(int i = 1; i < len; i++){
		for(int j = 0; j < R ; j++){//now on current state!!!
			dfa[j][i] = dfa[j][k];//copy mismatch cases
		}
		dfa[m.at(i)][i] = i + 1;//set match cases
		k = dfa[m.at(i)][k] ;// update restart state
	}
	//search string
	int ml = 0, pos = -1;
	for(int i = 0; i < s.length(); i++){
		ml = dfa[s.at(i)][ml];
		if(ml == len){
			pos = i + 1 - len;
			break;
		}
	}
	//free dfa
	for(int i = 0 ; i < R ; i ++){
		delete [] dfa[i];
	}
	delete [] dfa;
	return pos;
}
int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	string p;
	cin >> p;
	cout << " search " << p << " in " << s << " , start from "<<kmp(s,p);
	return 0;
}