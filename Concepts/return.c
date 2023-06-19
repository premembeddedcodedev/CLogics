#include<stdio.h>

int fibonacci(int a[], int *offset, int n, int start, int end)
{
	n++;

	return n; // because of return modified values persist. if there is no return values is not persistent
}

int main()
{
	int n;

	printf("Enter the limit \n");
	scanf("%d", &n);

	printf("%d,", 0);
	
	int a[20], check;
	
	check = fibonacci(a, a, n, 0, 1);

	printf("value %d\n", check);

	return 0;
}
