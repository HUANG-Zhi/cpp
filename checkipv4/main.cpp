#include <stdio.h>
#include <string.h>
#include <stdlib.h>
bool is_ipv4(const char * str);
int main(int argc,const char ** args){
	int len = 0;
	char * str = NULL;
	while(scanf("%d",&len)!=EOF){
		printf("\n%d:", len);
		str = (char *) malloc((len+1)*sizeof(char));
		//realloc((void*) str,sizeof(len+1));
		scanf("%s",str);
		printf("%s,%d\n", str,strlen(str));
		if(is_ipv4(str)){
			printf("%s is a vaild ipv4 adress\n",str );
		}else{
			printf("%s is an invaild ipv4 address\n",str );
		}
		if(str != NULL){
			free(str);
		}
		
	}
	return 0;
}
bool is_ipv4(const char * str){
	if(str == NULL) return false;
	int len = strlen(str);
	if(len < 7 || len > 17) return false;
	int i=0,bcount=0,ncount=0,cnum=0;
	while(i < len){
		//printf("%d\n", i);
		if(str[i] != '.' && !(str[i] <= '9' && str[i] >= '0') ) return false;
		else if (str[i] != '.'){
			if(bcount > 0 && cnum == 0) return false;
			bcount++;
			cnum = cnum * 10 + (str[i]-'0');
			if(cnum > 255) return false;
		} else {
			ncount++;
			if(ncount == 4) return false;
			bcount = 0;
			cnum = 0;
		}
		i++;
	}
	ncount++;
	if(ncount !=4 ) return false;
	return true;
}