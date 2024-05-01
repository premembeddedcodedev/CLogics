#include <stdio.h>
#include <stdlib.h>

void func(int a[], int count)
{
	printf("func address: %p\n", &a); //TODO: funtion arguments are stored in stack.. the passed arguments to func and arguments used in function is different address
	printf("func address: %p\n", a);
	printf("func address: %d\n", *a);

		
}

int main()
{
	int a[10] = {12, 23, 35, 46, 57, 92, 36, 50, 76, 56};
	int **pt;
	int (*ptr)[10];

	printf("address: %p\n", &a);
	printf("address: %p\n", a);

	//func(a, 10);

	pt = (int **)malloc(sizeof(int *)); // assume its 2-D array.. need to allocate memory for pt and pt[0]
	*pt = (int *) malloc (10 * sizeof(int)); // here is pt[0] need to allocate memory

	*pt = a;
	ptr = &a;

	printf("pt : %d\n", *(*(pt)+5)); // Need to rewrite this line ==> printf("%d\n", *(*ptr+5)); // Need to rewrite this line
	printf("pt : %d\n", (*pt)[5]); // Need to rewrite this line ==> printf("%d\n", *(ptr)[5]); // Wont work
	printf("pt : %d\n", pt[0][5]); // Need to rewrite this line ==> printf("%d\n", *(ptr)[5]); // Wont work

	printf("ptr : %d\n", *(*(ptr)+5)); // Need to rewrite this line ==> printf("%d\n", *(*ptr+5)); // Need to rewrite this line
	printf("ptr : %d\n", (*ptr)[5]); // Need to rewrite this line ==> printf("%d\n", *(ptr)[5]); // Wont work
	printf("ptr : %d\n", ptr[0][5]); // Need to rewrite this line ==> printf("%d\n", *(ptr)[5]); // Wont work
	
	return 0;
}
