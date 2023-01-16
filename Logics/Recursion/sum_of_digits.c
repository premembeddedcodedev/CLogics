#include<stdio.h>

int sum_of_digits(int number)
{
	if(number == 0)
		return 0;

	int div, remainder, temp;

	remainder = number % 10;
	div = number/10;
	number = div;

	return (remainder + sum_of_digits(number));

}

int main()
{
	int number;

	printf("Entet the value : \n");
	scanf("%d", &number);

	printf("sum of the digitis are : %d\n", sum_of_digits(number));

	return 0;
}
