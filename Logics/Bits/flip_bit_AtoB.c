#include <stdio.h>

void check_flip_bits(int A, int B)
{
	int tempA = A, tempB = B, i = 0, inc = 0;

	while(i < sizeof(int)*8) {
		if(((tempA ^ tempB) != 0)) {
			inc++;
		}

		tempA >>= i;
		tempB >>= i++;
	}

	printf("flip bits are : %d\n", inc);
}

int main()
{
	int A = 8, B=7;

	check_flip_bits(A, B);

	return 0;
}
