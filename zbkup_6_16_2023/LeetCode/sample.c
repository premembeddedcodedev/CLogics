#include<stdio.h>

void func(int *off)
{
	//printf(" %d\n", ++(*off));
}

int main()
{
	int a = 4;

	func(&a);

	while(a > 0)
		printf(" %d\n", a--);
	return 0;
}
