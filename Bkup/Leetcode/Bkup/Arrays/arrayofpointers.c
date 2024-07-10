#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
#ifdef WORKING
	int *a[3];

	int i[3] = {1,2,3}, j[3] = {4,5,6}, k[3]={7,8,9};

	a[0] = i;
	a[1] = j;
	a[2] = k;

	for(int i = 0; i<3; i++)
		printf("%d, ", a[1][i]);
#endif
        int *a[3];

        int i[3] = {1,2,3}, j[3] = {4,5,6}, k[3]={7,8,9};

        a[0] = malloc(3 * sizeof(int));
	memcpy(a[0], i, 3 * sizeof(int));
        a[1] = j;
        a[2] = k;

	printf("size: %d\n", sizeof(*a[0]));

        for(int i = 0; i<3; i++)
                printf("%d, ", a[1][i]);

	int *ptr, d;

	printf("ptr: %d, d: %d\n", sizeof(ptr), sizeof(d));

	return 0;
}
