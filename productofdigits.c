#include<stdio.h>

int product_of_digits(int data, int product)
{
	while(data != 0) {
		product = product * (data % 10);
		data /= 10;
	}

	return product;
}

int fact_product_of_digits(int data, int product)
{
	if(data == 0)
		return product;

	product = product * (data % 10);
	
	fact_product_of_digits(data/10, product);
}

int main()
{
	int data;

	printf("Enter the values : \n");
	scanf("%d", &data);

	//printf("product of digits : %d\n", product_of_digits(data, 1));
	printf("product of digits : %d\n", fact_product_of_digits(data, 1));

	return 0;
}
