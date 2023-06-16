#include <stdio.h>
#include <stdlib.h>

int *caller(int a[])
{
	printf("func: ibefore: ptr : %p\n", a);
	
	int *ptr = malloc(40);
	
	printf("func: after: ptr : %p\n", a);
	
	return ptr;

}

int main()
{
	int *a, b[10] = {};
	
	printf("iBefore: A: %p\n", a);

	a = caller(b);

	printf("After: A: %p\n", a);

	free(a);

	return 0;
}
