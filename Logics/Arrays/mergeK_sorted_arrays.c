#include <stdio.h>

#define N 4
int main()
{
	// Change N at the top to change number of elements
	// in an array
	int arr[][N] = { { 2, 6, 12, 34 },
		{ 1, 9, 20, 1000 },
		{ 23, 34, 90, 2000 } };
	int K = sizeof(arr) / sizeof(arr[0]);

	printf("Values : %d\n", K);

	return 0;
}
