#include <stdio.h>

#define ROWS 2
#define COLS 3

int main()
{
	int a[ROWS][COLS] = {{2,5,78}, {9, 13, 17}};
	int (*arr_ptr)[COLS];

	int a_ptr[COLS];	
	int *ptr[COLS];

	//ptr = a_ptr;

	ptr[0] = &a[0][0];
	ptr[0] = a[0];
	
	// Wont work : ptr = &a[0];

#if 1
	arr_ptr = a;

	// main logic is arr_ptr pointing to base address, how much you will increment, that much will be noved forward eventhough its in second bracket below

	printf("%d\n", *(arr_ptr)[1]);
	printf("%d\n", *arr_ptr[1]);
	printf("=>%d\n", *(*(arr_ptr+1)+0));
	printf("=>%d\n", *(*(arr_ptr+1)+1));
	printf("=>%d\n", *(*(arr_ptr+1)+2));
	
	printf("%d\n", *(arr_ptr)[0]);
	printf("%d\n", *arr_ptr[0]);
	printf("=>%d\n", *(*(arr_ptr+0)+0));
	printf("=>%d\n", *(*(arr_ptr+0)+1));
	printf("=>%d\n", *(*(arr_ptr+0)+2));
	
	printf("%d\n", *(arr_ptr)[2]);
	printf("%d\n", *arr_ptr[2]);
	
	printf("\n1th offset:\n");
	printf("%d\n", (*arr_ptr+0)[1]);
	printf("%d\n", (*arr_ptr+1)[1]);
	printf("%d\n", (*arr_ptr+2)[1]);
	printf("%d\n", (*arr_ptr+3)[1]);
	printf("%d\n", (*arr_ptr+4)[1]);

	printf("\n0th offset:\n");
	printf("%d\n", (*arr_ptr+0)[0]);
	printf("%d\n", (*arr_ptr+1)[0]);
	printf("%d\n", (*arr_ptr+2)[0]);
	printf("%d\n", (*arr_ptr+3)[0]);
	printf("%d\n", (*arr_ptr+4)[0]);
	printf("%d\n", (*arr_ptr+5)[0]);
	
	printf("\n2th offset:\n");
	printf("%d\n", (*arr_ptr+0)[0]);
	printf("%d\n", (*arr_ptr+0)[1]);
	printf("%d\n", (*arr_ptr+0)[2]);
	printf("%d\n", (*arr_ptr+0)[3]);
	printf("%d\n", (*arr_ptr+0)[4]);
	printf("%d\n", (*arr_ptr+0)[5]);
	
	printf("\n3rd offset:\n");
	printf("%d\n", (*arr_ptr+0)[2]);
	printf("%d\n", (*arr_ptr+1)[2]);
	printf("%d\n", (*arr_ptr+2)[2]);
	printf("%d\n", (*arr_ptr+3)[2]);
	printf("%d\n", (*arr_ptr+4)[2]);
	printf("%d\n", (*arr_ptr+5)[2]);
	
	printf("\nremaining offset:\n");
	printf("%d\n", (*arr_ptr+4)[0]);
	printf("%d\n", (*arr_ptr+5)[0]);
#endif	
	return 0;
}
