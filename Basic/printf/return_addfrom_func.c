#include <stdio.h>


int* multiply(int *a, int *b)
{
	int c = *a * *b;
	return &c;
}

int main()
{
	int a= 3, b = 5;
	int *c = multiply (&a,&b);
	printf("Product = %d",*c);

	return 0;
}
