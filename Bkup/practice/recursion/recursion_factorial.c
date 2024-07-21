#include<stdio.h>

int factorial(int data)
{
	if(data <= 1)
		return 1;

	return data * factorial(data-1);

}

int sum_of_digits(int data)
{
	if(data <= 1)
		return 1;



	return data * sum_of_digits(data-1);

}

int main()
{
	int data;

	printf("Enter the value : \n");
	scanf("%d", &data);

	printf("factorial: %d\n",factorial(data));

	return 0;
}
