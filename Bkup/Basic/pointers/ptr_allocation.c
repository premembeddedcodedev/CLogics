#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a[4] = {10, 11, 12, 13};
	int *ptr = malloc(sizeof(4));

	memcpy(ptr, a, sizeof(a));

	int i;

	for(i=0; i<8092; i++)
		printf("%d,", ptr[i]);

	printf("i: %d\n", i);

	//printf("%p\n", ptr);

	free(ptr);

	//printf("%p\n", ptr);

	//ptr[0] = 19;
	
	//printf("%d\n", ptr[0]);
}
