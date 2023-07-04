#include <stdio.h>

void clear_bit_range(int A, int Lrange, int Hrange)
{
	int mask_cnt = (Hrange - Lrange) + 1;

	int mask = (1 << mask_cnt) - 1;

	A &= ~(mask << mask_cnt);

	printf(" Clear range %d is: 0x%X\n", Lrange, A);
}

int main()
{
	int A = 0xAABBCCDD;

	clear_bit_range(A, 4, 7);

	return 0;
}
