#include <stdio.h>

int main()
{
	int x = 0x78654212;
	int low = 4, high = 7;

	int i = 0;
	int mask;

	int count = (high - low) + 1;

	mask = count - 1;

	x &= ~(mask << low);
	x |= 0xF << low;


	printf("Value : %X\n", x);

	return 0;
}
