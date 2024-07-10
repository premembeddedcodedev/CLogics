#include <stdio.h>

int factorial(int n)
{
	if(n <= 0)
		return 1;

	return (n*factorial(n-1));
}

int main()
{
	int n;

	printf("Enter the number for factorial\n");
	scanf("%d", &n);

	printf("factorial is %d\n", factorial(n));

	return 0;
}
