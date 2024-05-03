#include <stdio.h>
#include <stdlib.h>

int *caller(int b[])
{
	printf("func: b array: %p\n", b);
	
	int *ptr = malloc(40);
	
	printf("after allocation: ptr : %p\n", ptr);

	*ptr = 30;

	return ptr;

}

int main()
{
	int *a, b[10] = {};
	
	printf("main: A ptr: %p, b array: %p\n", a, b);

	a = caller(b);

	printf("After: A address : %p\n", a);
	printf("After: A value : %d\n", *a);

	free(a);

	printf("after free value : %d\n", *a);

	return 0;
}
