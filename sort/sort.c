/*
Interface and Implements for a set of sort algorithms
test for Int type
*/
#include "stdio.h"
#include "time.h"
#include "assert.h"
#include "stdlib.h"

/*
type special interface, for Int
*/
int intCompare(void* array,int i,int j){
	int * intArray = (int*) array;
	if(intArray[i]<intArray[j]) return -1;
	else if (intArray[i] > intArray[j]) return 1;
	else return 0;
}
void intExch(void * array,int i,int j){
	int * intArray = (int*) array;
	int temp = intArray[i];
	intArray[i] = intArray[j];
	intArray[j] = temp;
}
void intAssign(void * array1,void * array2,int i,int j){
	((int *) array1)[i] = ((int *) array2)[j];
}
void* intGetEA(void * array,int i){
	return &((int *)array)[i];
}
int intSize(void){
	return sizeof(int);
}

/*
sort module, implements for a set of sort algorithms
*/
int less(void *array,int (* compare)(void *,int,int),int i,int j){
	return compare(array,i,j) == -1;
}

void shuffle(void *array,int length,void(*exch)(void*,int,int)){
	int i,j;
	for(i = 0; i < length;i++){
		j = i + rand() / (RAND_MAX / (length-i)+1);//i~N-1
		exch(array,i,j);
	}
}

void selectionSort(void* array,int length,int(*compare)(void *,int,int),void(*exch)(void*,int,int)){
	int i,j,min;
	for(i=0;i<length;i++){
		min = i;
		for(j=i+1;j<length;j++){
			if (less(array,compare,j,min)){
				min = j;
			}
		}
		exch(array,min,i);
	}
}

void insertionSort(void* array,int length,int (*compare)(void *,int,int),void(*exch)(void*,int,int)){
	int i,j;
	for(i = 1;i<length;i++){
		for(j = i; j > 0 && less(array,compare,j,j-1); j--){
			exch(array,j,j-1);
			// save time when init array is in order, compare to selectionSort
		}
	}
}

void shellSort(void* array,int length,int (*compare)(void *,int,int),void(*exch)(void*,int,int)){
	int h = 1;
	while(h<length/3) h = 3 * h + 1;//step squence of 3x+1
	int i,j,s;
	while(h >=1){
		for(i = h;i < length;i++){
			for(j = i; j >= h && less(array,compare,j,j-h); j=j-h){
				exch(array,j,j-h);
			}
		}
		h = (h - 1)/3;
	}
}

//mergeSort:pure merge sort
void merge(void * array,void* aux,int lo,int mid,int hi,int (*compare)(void *,int,int),void(*assign)(void *,void*,int,int)){
	//copy array
	int i,j,k;
	for(i = lo; i<= hi; i++){
		assign(aux,array,i,i);
	}
	//do merge
	i = lo;
	j = mid + 1;
	for (k = lo; k <= hi; k++){
		if(i > mid) assign(array,aux,k,j++);
		else if (j > hi) assign(array,aux,k,i++);
		else if (less(aux,compare,j,i)) assign(array,aux,k,j++);
		else assign(array,aux,k,i++);
	}
}
void msort(void * array,void * aux,int lo,int hi,int (*compare)(void *,int,int),void(*assign)(void *,void*,int,int)){
	if (hi <= lo){
		return;
	}
	/*
	if (hi <= lo + CUTTOFF_MERGE_SORT -1){
		insertion sort
		return;
	}
	*/
	int mid = lo + (hi-lo) / 2;//avoid int overflow compare to (hi+lo)/2,hi+lo may overflow
	msort(array,aux,lo,mid,compare,assign);
	msort(array,aux,mid+1,hi,compare,assign);
	merge(array,aux,lo,mid,hi,compare,assign);
}
void mergeSort(void* array,int length,int (*compare)(void *,int,int),void(*assign)(void *,void*,int,int),int size(void)){
	void * aux = malloc(length * size());
	if (!aux)
	{
		perror("Could not allocate memory");
		exit(EXIT_FAILURE); // exit
	}
	msort(array,aux,0,length-1,compare,assign);
	free(aux);
}


//mergeSortO: 3 improvements for mergesort
#define CUTTOFF_MERGE_SORT 7
//after call, aux is sorted
void mergeO(void * array,void* aux,int lo,int mid,int hi,int (*compare)(void *,int,int),void(*assign)(void *,void*,int,int)){
	//improvement 3
	//do merge
	int i,j,k;
	i = lo;
	j = mid + 1;
	for (k = lo; k <= hi; k++){
		if(i > mid) assign(aux,array,k,j++);
		else if (j > hi) assign(aux,array,k,i++);
		else if (less(array,compare,j,i)) assign(aux,array,k,j++);
		else assign(aux,array,k,i++);
	}
}

//after call, aux is sorted
void msortO(void * array,void * aux,int lo,int hi,int (*compare)(void *,int,int),void(*assign)(void *,void*,int,int),void(*exch)(void*,int,int),void*(*getea)(void*,int)){
	//improvement 1 :20 % , conflict with improvement 3
	// if (hi <= lo + CUTTOFF_MERGE_SORT -1){
	// 	insertionSort(getea(array,lo),hi-lo+1,compare,exch);
	// 	return;
	// }
	if (hi <= lo){
		return;
	}

	int mid = lo + (hi-lo) / 2;//avoid int overflow compare to (hi+lo)/2,hi+lo may overflow
	//improvement 3 , conflict with improvement 1 and 2
	// sortO(array,aux,lo,mid,compare,assign,exch,getea);
	// sortO(array,aux,mid+1,hi,compare,assign,exch,getea);
	//improvement 3 , conflict with improvement 1 and 2
	msortO(aux,array,lo,mid,compare,assign,exch,getea);
	msortO(aux,array,mid+1,hi,compare,assign,exch,getea);

	//improvement 2: slight when size = 200, conflict with improvement 3
	//if(!less(array,compare,mid+1,mid)) return;

	//improvement 3 , conflict with improvement 1 and 2
	//merge(array,aux,lo,mid,hi,compare,assign);
	mergeO(array,aux,lo,mid,hi,compare,assign);//aux is sorted
}

void mergeSortO(void* array,int length,int (*compare)(void *,int,int),void(*assign)(void *,void*,int,int),void(*exch)(void*,int,int),void*(*getea)(void*,int),int size(void)){
	void * aux = malloc(length * size());
	if (!aux)
	{
		perror("Could not allocate memory");
		exit(EXIT_FAILURE); // exit
	}
	//improvement 3 , conflict with improvement 1 and 2
	//sortO(array,aux,0,length-1,compare,assign,exch,getea);
	int i = 0;
	for(i = 0;i<length;i++){
		assign(aux,array,i,i);
	}
	msortO(aux,array,0,length-1,compare,assign,exch,getea);//sort aux to array
	free(aux);
}

//buMergeSort: bottom - up merge sort
void bumSort(void * array,void * aux,int length,int (*compare)(void *,int,int),void(*assign)(void *,void*,int,int)){
	int sz,lo,hi;
	for(sz = 1; sz < length; sz=sz+sz){
		for(lo = 0; lo < length-sz ; lo += sz+sz){
			merge(array,aux,lo,lo+sz-1,(lo+sz+sz-1 < length-1?lo+sz+sz-1:length-1),compare,assign);
		}
	}
}
void buMergeSort(void* array,int length,int (*compare)(void *,int,int),void(*assign)(void *,void*,int,int),int size(void)){
	void * aux = malloc(length * size());
	if (!aux)
	{
		perror("Could not allocate memory");
		exit(EXIT_FAILURE); // exit
	}
	bumSort(array,aux,length,compare,assign);
	free(aux);
}

//quickSort:pure quick sort
int partition(void* array,int lo,int hi,int(*compare)(void*,int,int),void(*exch)(void*,int,int)){
	int i = lo, j = hi+1;
	while(1){
		while(less(array,compare,++i,lo)){
			if(i == hi) break;
		}
		while(less(array,compare,lo,--j));
		// while(less(array,compare,lo,--j)){
			//if(j == lo) break;
		// }
		if(i>=j) break;
		exch(array,i,j);
	}
	exch(array,lo,j);
	return j;
}

void qusort(void* array,int lo,int hi,int(*compare)(void *,int,int),void(*exch)(void*,int,int)){
	if(hi < lo){
		return;
	}
	int p = partition(array,lo,hi,compare,exch);
	qusort(array,lo,p-1,compare,exch);
	qusort(array,p+1,hi,compare,exch);
}
void quickSort(void* array,int length,int (*compare)(void *,int,int),void(*exch)(void*,int,int)){
	shuffle(array,length,exch);
	qusort(array,0,length-1,compare,exch);
}

//improvements for quick sort
#define CUTTOFF_QUICK_SORT 20
int medianOf3(void* array,int i,int j,int k,int(*compare)(void *,int,int)){
	return (less(array,compare,i,j) ?
               (less(array,compare,j,k) ? j : less(array,compare,i,k) ? k : i) :
               (less(array,compare,k,j) ? j : less(array,compare,k, i) ? k : i));
}
void qusortO(void* array,int lo,int hi,int(*compare)(void *,int,int),void(*exch)(void*,int,int),void*(*getea)(void*,int)){
	//improvement 1: 8%
	if (hi <= lo + CUTTOFF_QUICK_SORT -1){
		insertionSort(getea(array,lo),hi-lo+1,compare,exch);
		return;
	}
	//improvement 3: 5%
	int m = medianOf3(array,lo,lo+(hi-lo)/2,hi,compare);//avoid overflow
	exch(array,lo,m);
	int p = partition(array,lo,hi,compare,exch);
	qusortO(array,lo,p-1,compare,exch,getea);
	qusortO(array,p+1,hi,compare,exch,getea);
}
void quickSortO(void* array,int length,int (*compare)(void *,int,int),void(*exch)(void*,int,int),void*(*getea)(void*,int)){
	shuffle(array,length,exch);
	qusortO(array,0,length-1,compare,exch,getea);
}

//sort3way for duplicate keys
void qusort3way(void* array,const int lo,const int hi,int(*compare)(void *,int,int),void(*exch)(void*,int,int),void*(*getea)(void*,int)){
	//improvement 1: 8%
	if (hi <= lo + CUTTOFF_QUICK_SORT -1){
		insertionSort(getea(array,lo),hi-lo+1,compare,exch);
		return;
	}
	int lt = lo,gt = hi,i = lo,cmp;
	while(i <= gt){//cannot modify lo,hi; for sub call
		cmp = compare(array,lt,i);
		if(cmp < 0){
			exch(array,i,gt--);
		}else if(cmp > 0){
			exch(array,lt++,i++);
		}else{
			i++;
		}
	}
	qusort3way(array,lo,lt-1,compare,exch,getea);
	qusort3way(array,gt+1,hi,compare,exch,getea);
}
void quickSort3way(void* array,int length,int (*compare)(void *,int,int),void(*exch)(void*,int,int),void*(*getea)(void*,int)){
	shuffle(array,length,exch);
	qusort3way(array,0,length-1,compare,exch,getea);
}

//heap sort
//2k+1,2k+2;(k-1)/2
void swim(void * array,int k,int (*compare)(void*,int,int),void(*exch)(void*,int,int)){
	while(k > 0 && less(array,compare,(k-1)/2,k)){
		exch(array,(k-1)/2,k);
		k = (k-1)/2;
	}
}

void sink(void * array,int length,int k,int (*compare)(void*,int,int),void(*exch)(void*,int,int)){
	int ch = 0;
	while(2*k+1<length){
		ch = 2*k+1;
		if(2*k+2<length && less(array,compare,2*k+1,2*k+2)){
			ch ++;
		}
		if(less(array,compare,k,ch)){
			exch(array,k,ch);
			k = ch;
		}else{
			break;
		}
	}
}
void construct(void * array,int length,int (*compare)(void*,int,int),void(*exch)(void*,int,int)){
	int k = 0;
	for(k = (length-2)/2;k >=0;k--){
		sink(array,length,k,compare,exch);
	}
}
int popmax(void * array,int length,int (*compare)(void*,int,int),void(*exch)(void*,int,int)){
	exch(array,0,length-1);
	sink(array,length-1,0,compare,exch);
	return length-1;
}

void heapSort(void * array,int length,int (*compare)(void*,int,int),void(*exch)(void*,int,int)){
	construct(array,length,compare,exch);
	while(popmax(array,length--,compare,exch) > 1);
}

/*
functions for debuging and testing
*/
void printArr(int *array,int len){
	int i;
	for(i = 0; i < len;i++){
		printf("%d ",array[i] );
	}
	printf("\n");
}
void intcpy(int * des,int*src,int len){
	int i;
	for(i = 0 ;i < len;i++){
		des[i] = src[i];
	}
}

int inOrder(int * array,int len){
	if(len <=1) return 1;
	int i;
	for(i = 1; i < len; i++){
		if(array[i-1] > array[i]){
			return 0;
		}
	}
	return 1;
}

int testsort(int max_int_len, int* squ);
int testheap(int max_int_len, int* squ);
int main(int argc, char const *argv[])
{
	assert(argc > 1);
	int max_int_len = 0;
	sscanf(argv[1],"%d",&max_int_len);
	//printf("max_int_len:%d\n", max_int_len);
	fflush(stdout); 
	int* squ;
	squ = malloc(max_int_len * sizeof(int));
	testsort(max_int_len,squ);
	//testheap(max_int_len,squ);
	return 0;
}
int testheap(int max_int_len, int* squ){
	int i = 0 ;
	int len = 60;
	for(i=0;i<len;i++){
		squ[i]=len-i;
	}
	squ[7]=100;
	printArr(squ,len);
	swim(squ,7,intCompare,intExch);
	printArr(squ,len);
	squ[3]=-100;
	printArr(squ,len);
	sink(squ,len,3,intCompare,intExch);
	printArr(squ,len);
	popmax(squ,len,intCompare,intExch);
	printArr(squ,len);
	construct(squ,len,intCompare,intExch);
	printArr(squ,len);
	heapSort(squ,len,intCompare,intExch);
	printArr(squ,len);
	return 0;
}

int testsort(int max_int_len, int* squ)
{
	int len = 0;
	int *squ1;
	squ1 = malloc(max_int_len * sizeof(int));
	if(!squ||!squ1){
		perror("Could not allocate memory !");
		exit(EXIT_FAILURE);
	}

	//printf(".....input start\n");
	//fflush(stdout); 
	while(scanf("%d",&squ[len++])!=EOF);
	len--;
	//printf(".....input end---squ size:%d\n", len);
	//fflush(stdout); 

	// //debug shuffle
	// printArr(squ,len);
	// printf("-----shuffle beg\n");
	// shuffle(squ,len,intExch);
	// printArr(squ,len);
	// printf("-----shuffle end\n");
	
	clock_t begin, end;

	// intcpy(squ1,squ,len);
	// //printf("\n---before selectionSort :");
	// //printArr(squ1,len);
	// //assert(!inOrder(squ1,len));
	// begin = clock();
	// selectionSort(squ1,len,intCompare,intExch);
	// end = clock();
	// assert(inOrder(squ1,len));
	// printf("%15s:%20.15fs\n","selectionSort",(double)(end - begin) / CLOCKS_PER_SEC);
	// //printArr(squ1,len);

	// intcpy(squ1,squ,len);
	// //printf("\n---before insertionSort :");
	// //printArr(squ1,len);
	// //assert(!inOrder(squ1,len));
	// begin = clock();
	// insertionSort(squ1,len,intCompare,intExch);
	// end = clock();
	// assert(inOrder(squ1,len));
	// printf("%15s:%20.15fs\n","insertionSort",(double)(end - begin) / CLOCKS_PER_SEC);
	// //printArr(squ1,len);

	intcpy(squ1,squ,len);
	//printf("\n---before shellSort :");
	//printArr(squ1,len);
	//assert(!inOrder(squ1,len));
	begin = clock();
	shellSort(squ1,len,intCompare,intExch);
	end = clock();
	assert(inOrder(squ1,len));
	printf("%15s:%20.15fs\n","shellSort",(double)(end - begin) / CLOCKS_PER_SEC);
	//printArr(squ1,len);

	intcpy(squ1,squ,len);
	//printf("\n---before shellSort :");
	//printArr(squ1,len);
	//assert(!inOrder(squ1,len));
	begin = clock();
	mergeSort(squ1,len,intCompare,intAssign,intSize);
	end = clock();
	assert(inOrder(squ1,len));
	printf("%15s:%20.15fs\n","mergeSort",(double)(end - begin) / CLOCKS_PER_SEC);
	//printArr(squ1,len);

	intcpy(squ1,squ,len);
	//printf("\n---before shellSort :");
	//printArr(squ1,len);
	//assert(!inOrder(squ1,len));
	begin = clock();
	mergeSortO(squ1,len,intCompare,intAssign,intExch,intGetEA,intSize);
	end = clock();
	assert(inOrder(squ1,len));
	printf("%15s:%20.15fs\n","mergeSortO3",(double)(end - begin) / CLOCKS_PER_SEC);
	//printArr(squ1,len);

	intcpy(squ1,squ,len);
	//printf("\n---before shellSort :");
	//printArr(squ1,len);
	//assert(!inOrder(squ1,len));
	begin = clock();
	buMergeSort(squ1,len,intCompare,intAssign,intSize);
	end = clock();
	assert(inOrder(squ1,len));
	printf("%15s:%20.15fs\n","buMergeSort",(double)(end - begin) / CLOCKS_PER_SEC);
	//printArr(squ1,len);

	intcpy(squ1,squ,len);
	//printf("\n---before shellSort :");
	//printArr(squ1,len);
	//assert(!inOrder(squ1,len));
	begin = clock();
	quickSort(squ1,len,intCompare,intExch);
	end = clock();
	assert(inOrder(squ1,len));
	printf("%15s:%20.15fs\n","quickSort",(double)(end - begin) / CLOCKS_PER_SEC);
	//printArr(squ1,len);

	intcpy(squ1,squ,len);
	//printf("\n---before shellSort :");
	//printArr(squ1,len);
	//assert(!inOrder(squ1,len));
	begin = clock();
	quickSortO(squ1,len,intCompare,intExch,intGetEA);
	end = clock();
	assert(inOrder(squ1,len));
	printf("%15s:%20.15fs\n","quickSortO",(double)(end - begin) / CLOCKS_PER_SEC);
	//printArr(squ1,len);

	intcpy(squ1,squ,len);
	//printf("\n---before shellSort :");
	//printArr(squ1,len);
	//assert(!inOrder(squ1,len));
	begin = clock();
	//duplickeys
	quickSort3way(squ1,len,intCompare,intExch,intGetEA);
	end = clock();
	//assert(inOrder(squ1,len));
	printf("%15s:%20.15fs\n","qusort3way",(double)(end - begin) / CLOCKS_PER_SEC);
	//printArr(squ1,len);

	intcpy(squ1,squ,len);
	//printf("\n---before shellSort :");
	//printArr(squ1,len);
	//assert(!inOrder(squ1,len));
	begin = clock();
	//duplickeys
	heapSort(squ1,len,intCompare,intExch);
	end = clock();
	//assert(inOrder(squ1,len));
	printf("%15s:%20.15fs\n","heapSort",(double)(end - begin) / CLOCKS_PER_SEC);
	//printArr(squ1,len);

	free(squ);
	free(squ1);
	return 0;
}