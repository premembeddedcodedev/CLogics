#include<stdio.h>

int main()
{
	// Pointer to an integer
	int *p; 

	// Pointer to an array of 5 integers
	int (*ptr)[5]; 
	int arr[5] = {91,92,93,94,95};

	// Points to 0th element of the arr.
	//p = arr;

	// Points to the whole array arr.
	ptr = &arr; 

	//printf("p = %p, ptr = %p\n", p, ptr);

	//p++; 
	//ptr++;

	//printf("p = %p, ptr = %p\n", p, ptr);

	printf("(*ptr)[3] : %d", (*ptr)[3]);

	return 0;
}
