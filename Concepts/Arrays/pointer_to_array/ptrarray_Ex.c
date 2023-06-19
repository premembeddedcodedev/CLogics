#include <stdio.h>

int main()
{
	int ap[2][3] = {{1,2,3},{4,5,6}};
	int bp[2][3] = {{19,22,33},{42,52,63}};
	int (*ptrs)[3]; //single dimentional array

	ptrs = ap;

	for (int row = 0; row < 3; ++row)// Loop for coloumn
	{
		printf("%d \n", ptrs[1][row]);
	}

	ptrs += 1;

	ptrs = bp;
	
	for (int row = 0; row < 3; ++row)// Loop for coloumn
	{
		printf("%d \n", ptrs[0][row]);
	}

	return 0;
}
