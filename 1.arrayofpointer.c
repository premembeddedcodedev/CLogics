#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int array_print(int *a[], int e[], int len, int listarray)
{
	int i = 0, n, *d, j, count = 0;

	//printf("size: %d\n",sizeof(a)/sizeof(*a[0]));

	for(i = 0; i<=listarray; i++) {
		//printf("loop1: %d\n", i);
		for(j = 0; j<3; j++) {
			d = a[i];
			//printf("loop2: %d\n", d[j]);
			e[count++] = d[j];
		//printf("a[]: %d\t", *a[i]);
		}
	}
	//for(i = 0; i<count; i++)
	//	printf("loop: e[]: %d\t", e[i]);

	return count++;
}

int main()
{
	int *a[10], b[10] = {7,9,6}, c[10] = {5,4,3}, *d, n, i, e[10];
	n  = 3;

	/*TODO: Need to take in individual array use that array from array of pointers with the help of below code*/
	a[0] = (int *)&b;
	a[1] = (int *)&c;
	a[2] = (int *)&c;
	a[3] = (int *)&c;

	/*Here's the individual array pointing to pointer of array of pointers*/	
	d = a[1];

	//printf("start: \n");
	//for(i = 0; i<7; i++) {
	//	printf("start: d[]: %d\t", d[i]);
	//}
	//printf("\n");

	int count = array_print(a, e, 7, 1);

	printf("count in main: %d\n", count);

	printf("main: \n");
	for(i = 0; i<count; i++) {
		printf(" %d\t", e[i]);
	}
}

/*
	d = a[0];
	printf(" array of pointer size: %ld\n", sizeof(*a[0]));
	printf(" array of pointer size: %ld\n", sizeof(a[0]));
	printf(" array of pointer size: %ld\n", sizeof(a));
	printf(" pointer: %ld\n", sizeof(d));:
	for(i = 0; i<2; i++)
		printf("%d\n", d[i]);
		//printf("%d\n", *a[i]); */
