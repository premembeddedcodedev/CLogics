#include<stdio.h>

int m = 10;

int func2()
{
	static int k = 10;

	printf("k value is : %d\n", k);

	return m;
}
