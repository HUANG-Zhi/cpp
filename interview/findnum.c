# include <stdlib.h>
# include <assert.h>
# include <stdio.h>
int findsp(int cp, int sp, int* num, const int len){
	assert(cp > 0 && sp > 0 && len % cp == sp && len > 0);
	if(sp >= cp ){
		return findsp(cp,sp%cp,num,len);
	}
	int * mask = malloc(cp * sizeof(int));
	int i = 0;
	for(i = 0; i < cp ; i ++){
		mask[i] = 0 ;
	}
	mask[0] = -1;

	printf("init\t: ");
	for(i = cp; i > 0 ; i--){
		printf("%d ",mask[i-1]);
	}
	printf("\n");

	int j = 0;
	for(j = 0 ; j < len ; j++){
		printf("%d(%d)\t: ", j,num[j]);
		int tm = mask[cp - 1];
		for(i = 0; i < cp -1 ; i++){
			mask[cp - i - 1] = (mask[(2 * cp - i - 1)% cp ] & ~num[j]) | (mask[(2 * cp - i - 2)%cp] & num[j]);
			printf("%d ", mask[cp - i - 1]);
		}
		mask[0] = (mask[0] & ~num[j])|(tm & num[j]);
		printf("%d\n",mask[0]);
	}
	int ret = mask[sp];
	free(mask);
	return ret;
}

void driver(int cp, int sp, int k){
	int i = 0;
	const int size = cp * k + sp;
	int* num = (int *) malloc( size * sizeof(int));
	int j = 0 ,cnum = 0;
	for(i = 0 ; i < k ; i++){
		for(j = 0; j < cp ; j++){
			num[i*cp + j] = i;
		}
	}

	for(j = 0; j < sp ;j++){
		num[k * cp + j] = k;
	}

	int specalnum = findsp(cp,sp,num,size);
	printf("find num: %d\n", specalnum);
	assert(specalnum == k);	
	free(num);
}
int main(int argc, char const *argv[])
{
	driver(6,4,22);
	return 0;
}