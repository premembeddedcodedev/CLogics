#include<stdio.h>

int fibonacci(int a[], int i, int n, int start, int end)
{
	if(end>n)
		return i;

	int temp = end;
	end += start;
	start = temp;

	a[i++] = start;

	return fibonacci(a, i, n, start, end);
}

int main()
{
	int n;

	printf("Enter the limit \n");
	scanf("%d", &n);
	
	int a[20], check = 0;
	
	check = fibonacci(a, 0, n, 0, 1);

	printf("value %d\n", check);
	printf("%d->", 0);
	for(int i=0;i<check;i++)
		printf("%d->", a[i]);

	return 0;
}
