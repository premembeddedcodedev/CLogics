#include <stdio.h>

/* As we are changing the mask FF along with the position thats the reason we are not shifting with more numbers*/

#define SWAP_BYTES(value) (((value & 0x000000FF) << 24) | \
			   ((value & 0x0000FF00) << 8) | \
			   ((value & 0x00FF0000) >> 8) |  \
			   ((value & 0xFF000000) >> 24))

void endianess_or_swap_bytes(int A)
{
	printf("Swapped bytes are : 0x%X\n", SWAP_BYTES(A));
}

int main()
{
	int A=0x11223344;
	
	endianess_or_swap_bytes(A);

	return 0;
}
