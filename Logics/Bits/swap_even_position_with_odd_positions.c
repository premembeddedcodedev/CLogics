#include <stdio.h>

int main()
{
	int number = 23;

	number = ((number & 0xAAAAAAAAAAAAAAAA) >> 1) | ((number & 0x5555555555555555) << 1);

	printf("number swap: %d\n", number);

	return 0;
}
