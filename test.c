#include <stdio.h>
void my_int_func(int x)
{
    printf( "%d\n", x );
}

void intSwap(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void genericSwap(void *x, void *y, int typeSize) {
	char tmp;
	char *a = (char*) x;
	char *b = (char*) y;
	for(int i=0; i<typeSize; i++) {
		tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
}

void intInsert(int *srcArray, int *destArray, int *value, int pos, int srcArraySize) {

	int breakPt = 0;
	for(int i=0; i<srcArraySize; i++) {
		int *tmpDest = destArray+i;
		*tmpDest = *(srcArray+i);
		if(i==pos) {
			*tmpDest = *value;
			breakPt = i;
			break;
		}
	}
	for(int j=breakPt; j<srcArraySize; j++) {
		int *tmpDest = destArray+j+1;
		*tmpDest = *(srcArray+j);
	}

}

int main()
{
    void (*foo)(int);
    /* the ampersand is actually optional */
    foo = &my_int_func;

	foo(2);

	int a = 2;
	int b = 5;
	printf("Before (a,b): (%d,%d)\n",a,b);
	intSwap(&a,&b);
	printf("After (a,b): (%d,%d)\n",a,b);
	printf("sizeof(int): %lu\n", sizeof(int));

	double doubleA = 3.14;
	double doubleB = 9.81;
	printf("Before (a,b): (%f,%f)\n",doubleA, doubleB);
	genericSwap(&doubleA, &doubleB, sizeof(double));
	printf("After (a,b): (%f,%f)\n",doubleA, doubleB);

	printf("Before (a,b): (%d,%d)\n",a,b);
	genericSwap(&a,&b, sizeof(int));
	printf("After (a,b): (%d,%d)\n",a,b);

	int srcArraySize = 5;
	int srcArr[5] = {0, 1, 2, 3, 4};
	int destArr[srcArraySize+1];
	int value = 999;
	for(int i=0; i<srcArraySize; i++) {
		if(i!=srcArraySize-1) {
			printf("%d, ", srcArr[i]);
		}
		else {
			printf("%d\n", srcArr[i]);
		}
	}
	intInsert(srcArr, destArr, &value, 2, 5);
	for(int i=0; i<srcArraySize+1; i++) {
		if(i!=srcArraySize) {
			printf("%d, ", destArr[i]);
		}
		else {
			printf("%d\n", destArr[i]);
		}
	}
    return 0;
}
