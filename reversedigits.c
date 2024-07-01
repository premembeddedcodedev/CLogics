#include<stdio.h>

int reverse_digits(int data, int reverse)
{
	while(data != 0) {
		reverse = (reverse * 10) + (data % 10);
		data /= 10;
	}

	return reverse;
}

int fact_reverse_digits(int data, int reverse)
{
	if(data == 0)
		return reverse;

	reverse = reverse * 10 + (data % 10);

	fact_reverse_digits(data/10, reverse);
}

int main()
{
	int data;
	
	printf("Enter the values: \n");
	scanf("%d", &data);

	//printf(" Reverse number is : %d\n", reverse_digits(data, 0));
	printf(" Reverse number is : %d\n", fact_reverse_digits(data, 0));

	return 0;
}
