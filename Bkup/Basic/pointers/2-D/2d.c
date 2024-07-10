#include <stdio.h>

int main()
{
	int a[2][3] = {91,92,93,94,95,96};
	int *p;

	p = a[0];


	printf("%p\n", a[0]);
	printf("%p\n", &a[0][0]);
/*start -- why same explanation below*/
	printf("%p\n", a);
	printf("%p\n", &a);
	printf("inc: %p\n", a+1);
	printf("inc: %p\n", &a+1);
/*End*/	
	printf("%p\n", *a);

	return 0;
}

/*
 * Explanation: 
 * 	-------------------------------------
 *	| 4 | 5 | 6 | 7 | 8 | 9 | 1 | 2 | 3 | 
 * 	-------------------------------------
 * 	|	    |		|
 * 	a[0]	    a[1]	a[2]
 * 	<array name>
 * 	similar to 1-D array
 *	incrementing a will go to a[1]
 * 	inrementing &a will go to next memory location start of end of a[2].
 */
