#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
int const MAX_STRING_LEN = 1000;
int remaxsqu(int fn,int sn,char* fs,char* ss,int** mem,int debug){

	if (fn < 0 || sn < 0){
		return 0;
	}

	if (mem[fn][sn] != -1){
		return mem[fn][sn];
	}

	int max = remaxsqu(fn,sn-1,fs,ss,mem,debug);

	int temp = remaxsqu(fn-1,sn,fs,ss,mem,debug);
	if(max < temp){
		max = temp;
	}

	temp = remaxsqu(fn-1,sn-1,fs,ss,mem,debug);
	if (fs[fn]==ss[sn]){
		temp += 1;
		if(max < temp){
			max = temp;
		}
	}	

	return mem[fn][sn] = max;
}
int getsqu(int fn,int sn,int count,char* squ,char* fs,char* ss,int** mem,int debug){
	if(debug){
		printf("**(%d,%d)**",fn,sn);
	}
	if(fn <0 || sn <0){
		return 0;
	}
	if(fn >0 && mem[fn][sn]==mem[fn-1][sn]){
		getsqu(fn-1,sn,count,squ,fs,ss,mem,debug);
	}else if(sn >0 && mem[fn][sn]==mem[fn][sn-1]){
		getsqu(fn,sn-1,count,squ,fs,ss,mem,debug);
	}else if (fs[fn]==ss[sn]){
		squ[--count] = fs[fn];
		if (debug){
			printf("--%c",fs[fn] );
		}		
		if(fn >0 && sn >0){
			getsqu(fn-1,sn-1,count,squ,fs,ss,mem,debug);
		}		
	}
}
void findmaxsqu(char* fs,char* ss,int debug){
	int fl = strlen(fs);
	int sl = strlen(ss);
	int i,j;
	assert(debug == 0 || debug == 1);
	if(debug==1){
		printf("first string(%d):%s\n",fl,fs);
		printf("second string(%d):%s\n",sl,ss);
	}
	int **mem =(int **) malloc(fl*sizeof(int*));
	for(i = 0; i < fl;i++){
		mem[i] = (int*) malloc(sl*sizeof(int));
		for(j = 0;j < sl;j++){
			mem[i][j]=-1;
		}
	}
	int maxsqu = remaxsqu(fl-1,sl-1,fs,ss,mem,debug);
	printf("%d\n",maxsqu);
	int squlen = maxsqu+1;
	char* squ = (char *) malloc(squlen * sizeof(char));
	squ[maxsqu] = '\0';

	if (debug)
	{
		for (i = 0; i < fl; ++i)
		{
			for(j = 0; j< sl ; j++)
			{
				printf("%d\t", mem[i][j]);
			}
			printf("\n");
		}
	}

	getsqu(fl-1,sl-1,maxsqu,squ,fs,ss,mem,0);
	//printf("\n%s\n",squ);
	for (i = 0; i < fl; ++i)
	{
		free(mem[i]);
	}
	free(mem);
	free(squ);
}
int main(int argc, char const *argv[])
{
	char fs[MAX_STRING_LEN],ss[MAX_STRING_LEN];
	while(scanf("%s",fs) != EOF){
		scanf("%s",ss);
		findmaxsqu(fs,ss,0);
	}	
	return 0;
}