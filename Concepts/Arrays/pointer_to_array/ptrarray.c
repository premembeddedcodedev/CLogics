#include <stdio.h>


void ptr_multi_c(int A[][2][3])
{


}

int main()
{
	int a[5], *b[10], *c[10][2];
	
	int ap[5], bp[2][5], cp[3][2][2];

	int (*ptrs)[5]; //single dimentional array
	
	int (*ptr)[5]; // 2 Dimentional
	int *(*ptrb)[10]; // 2 DImentional
	
	int (*p)[2][2]; // multi dimentional array
	int *(*ptrc)[10][2]; // multi DImentional array

	ptrs = &a;
	ptr = &a;
	ptr = bp;
	p = cp;
	ptrb = &b;
	ptrc = &c;

	//*((*ptr)+1) = b;
	//(*ptr[1]) = b;
	

#if 0
	printf("a: %p a+1: %p\n", a, a+1); // this will point to next address
	printf("a: %p a+1: %p\n", &a, &a+1); // this will point to next segment
	printf("&ptr: %p, ptr:%p, *ptr:%p, ptr+1: %p\n", &ptr, ptr, *ptr, ptr[1]); // ptr+1 = &a+1
#endif
	return 0;
}
