#include<stdio.h>

int fibonacci(int n, int start, int end)
{
	if(end>n)
		return 1;

	int temp = end;
	end += start;
	start = temp;

	printf("%d,", start);

	return fibonacci(n, start, end);
}

int main()
{
	int n;

	printf("Enter the limit \n");
	scanf("%d", &n);

	printf("%d,", 0);
	fibonacci(n, 0, 1);

	return 0;
}
