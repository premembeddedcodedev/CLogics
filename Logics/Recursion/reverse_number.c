#include<stdio.h>

int reverse_of_number(int number)
{
	if(number == 0)
		return 0;

	int div, remainder, temp;

	remainder = number % 10;
	div = number/10;
	number = div;

	//TODO: Logic is wrong
	return (remainder * 10 + reverse_of_number(number));
}

int main()
{
	int number;

	printf("Entet the value : \n");
	scanf("%d", &number);

	printf("Reverse the number is : %d\n", reverse_of_number(number));

	return 0;
}
