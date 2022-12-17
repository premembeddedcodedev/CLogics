#include <stdio.h>

void swap_odd_even(int A)
{
	int number = ((A & 0x55555555) << 1) | ((A & 0xAAAAAAAA) >> 1);

	printf("Swapped number : %d\n", number);

}

int main()
{
	int A=10;

	swap_odd_even(A);

	return 0;
}
