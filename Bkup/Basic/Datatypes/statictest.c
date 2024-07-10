#include<stdio.h>

static int a = 10;

void func(int x[])
{
	static int a;
	printf("in fun: %d: %ld\n", a, sizeof(x));
}

int main()
{
	int a[20] = {1,2,3,4,5,6, 8, 3,4,5,6,7,8};

	func(a);

	return 0;
}
