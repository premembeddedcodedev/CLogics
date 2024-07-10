#include<stdio.h>

int sum_of_digits(int number)
{
	int sum = 0;

	while(number > 0) {
		sum = sum + (number % 10);
		number /= 10;
	}

	return sum;
}

int factorial_sum_of_digits(int number, int sum)
{
	if(number == 0)
		return sum;

	sum = sum + (number % 10);

	factorial_sum_of_digits(number/10, sum);
}

int main()
{
	int value;

	printf("Enter the number to add digit: \n");
	scanf("%d", &value);

	//printf("sum : %d\n", sum_of_digits(value, 0));
	printf("sum : %d\n", factorial_sum_of_digits(value, 0));

	return 0;
}
