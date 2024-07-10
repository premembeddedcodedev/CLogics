#include<stdio.h>
#include <stdlib.h>

void memory_alloc(int **a, int i)
{
	*a = malloc(10 * 4);

	printf("in func: \n");

	for(int i = 0; i < 10; i++) {
		(*a)[i] = i * 10;
		printf("%d, ", (*a)[i]);
	}
}

int main()
{
	int *a[10];

	memory_alloc(a);
	
	printf("Main: \n");
	for(int i = 0; i < 10; i++) {
		printf("%d, ", (*a)[i]);
	}

	printf("\n");

	return 0;
}
