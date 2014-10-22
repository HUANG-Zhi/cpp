#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <ctime>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	stack<string> fss;
	map<string,int> lasttime;
	map<string,int> times;
	cin >> n;
	char fs[256];
	char cmd[10];
	int h,m,s;
	while(n>0){
		//FuncA 00:00:01 START
		scanf("%s %d:%d:%d %s",fs,&h,&m,&s,cmd);
		string sfs = string(fs);
		string scmd = string(cmd);
		if(scmd == "START"){
			fss.push(sfs);
			lasttime[sfs] = (h*60+m)*60+s;
		}else {
			if(fss.top() != sfs){
				cout <<"Incorrect performance log"<<endl;
				break;
			}else{
				//
				if(times.count(sfs) > 0){
					times[sfs] = times[sfs]+(h*60+m)*60+s-lasttime[sfs];
				}else{
					times[sfs] = (h*60+m)*60+s-lasttime[sfs];
				}
				fss.pop();
			}
		}
		n--;
	}
	for(auto key:times){
		cout << key << " "<<times[key]/3600<<":"<<(times[key]/60 % 60)<<times[key]%60<<endl;
	}
	return 0;
}