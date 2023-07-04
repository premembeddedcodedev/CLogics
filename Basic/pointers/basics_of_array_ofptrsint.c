#include <stdio.h>

#define ROWS 2
#define COLS 3

int main()
{
	int a[ROWS][COLS] = {{2,5,78}, {9, 13, 17}};
	int a_ptr[COLS];	
	int *ptr[COLS];

	//ptr = a_ptr;
#if 1
	//ptr[0] = &a[0][0];
	//ptr[0] = a[0];
	ptr[0] = &a;
	//ptr[0] = a;
	
	// Wont worki a[0] itself a pointer : ptr = &a[0];
#endif
#if 1
	printf("\nOffset:\n");
	//printf("%d\n", *ptr[0]);
	printf("%p %p\n", ptr[0], ptr[1]);
	
	printf(" &a[0][0]:%p, a[0]:%p, a:%p, &a:%p\n", &a[0][0], a[0], a, &a);
	printf(" &a[0][0]:%p, a[0]:%p, a:%p, &a:%p\n", &a[0][0]+1, a[0]+1, a+1, &a+1);

	printf("%d\n", (*ptr+1)[4]);// incrementing to 4+1 = 5 positions	


#endif	
	return 0;
}
