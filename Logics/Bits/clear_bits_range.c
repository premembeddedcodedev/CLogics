#include <stdio.h>

void clear_bit_range(int A, int range)
{
	int mask = ((1 << range) - 1);

	A &= ~mask;

	printf(" Clear range %d is: 0x%X\n", range, A);
}

int main()
{
	int A = 0xAABBCCDD;

	clear_bit_range(A, 8);

	return 0;
}
