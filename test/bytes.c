#include "stdio.h"
int main(int argc, char const *argv[])
{
	/* code */
	printf("char %d\n", sizeof(char));
	printf("unsigned short %d\n", sizeof(unsigned short));
	printf("short %d\n", sizeof(short));
	printf("unsigned int %d\n", sizeof(unsigned int));
	printf("int %d\n", sizeof(int));
	printf("unsigned long %d\n", sizeof(unsigned long));
	printf("long %d\n", sizeof(long));
	printf("long long %d\n", sizeof(long long));
	printf("float %d\n", sizeof(float));
	printf("double %d\n", sizeof(double));
	return 0;
}