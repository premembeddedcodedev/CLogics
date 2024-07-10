#include<stdio.h>

int main()
{
	int a = 10;

	volatile unsigned int  b = a;

	printf("%d\n", b);

	return 0;
}
