#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "assert.h"
int main(int argc, char const *argv[])
{
	//printf("%d,%d,%d,%d\n", NULL,'\0',0,EOF);
	int size = 0;
	sscanf(argv[1],"%d",&size);
	assert(size >0);
	assert(argc >= 3);
	srand(time(NULL));
	FILE* f = fopen(argv[2],"w+");
	assert(f);
	int i = 0;
	for(i = 0; i < size;i++){
		fprintf(f,"%d ", rand()%size);
	}
	fclose(f);
	return 0;
}