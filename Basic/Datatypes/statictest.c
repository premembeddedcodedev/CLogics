#include<stdio.h>

static int a = 10;

void func(int x[])
{
	static int a;
	printf("in fun: %d: %ld\n", a, sizeof(x));
}

int main()
{
	int a[7] = {1,2,3,4,5,6};

	func(a);

	return 0;
}
