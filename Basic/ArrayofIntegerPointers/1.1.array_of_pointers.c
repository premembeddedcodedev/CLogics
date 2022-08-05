#include <stdio.h>

void ieextract_and_chnage_values(int *ptr)
{
	printf("value at address = %d\n", *ptr);
	printf("value at address = %d\n", *(ptr+1));
	printf("value at address = %d\n", *(ptr+2));

	*ptr = 232;
	*(ptr+1) = 442;
	*(ptr+2) = 976;
}

void extract_and_chnage_values(int *ptr)
{
	printf("value at address = %d\n", *ptr);
	printf("value at address = %d\n", *(ptr+1));
	printf("value at address = %d\n", *(ptr+2));

	*ptr = 123;
	*(ptr+1) = 898;
	*(ptr+2) = 373;

	ieextract_and_chnage_values(ptr);

	printf("2Return: value at address = %d\n", *ptr);
	printf("2Return: value at address = %d\n", *(ptr+1));
	printf("2Return: value at address = %d\n", *(ptr+2));
}

void extract_arrayptr(int **ptr, int max) //working
//void extract_arrayptr(int *ptr[], int max) //working
{
	int i;

	printf("arrayptr extraction: \n");
	
	for(i=0; i<max; i++)
		printf("values at address : %d\n", *ptr[i]);

	max = max -1;

	*(ptr[max]+max) = 897;
}

int main()
{
	int *a[3], b = 10, c = 11, d[3] = {8,4,2};

	a[0] = &b;
	a[1] = &c;
	a[2] = &d[0];

	printf("Address of a = %p\n", a[0]);
	printf("Address of b = %p\n", &b);
	printf("value at address = %d\n", *a[0]);

	printf("Address of a[1] = %p\n", a[1]);
	printf("Address of c = %p\n", &c);
	printf("value at address = %d\n", *a[1]);

	printf("Address of a[2] = %p\n", a[2]);
	printf("Address of df = %p\n", &d[0]);
	printf("Address of da = %p\n", &d);
	printf("value at address = %d\n", *a[2]);
	printf("value at address = %d\n", *(a[2]+1));
	printf("value at address = %d\n", *(a[2]+2));

	extract_and_chnage_values(a[2]);
	
	extract_arrayptr(a, 3);
	
	printf("MReturn: value at address = %d\n", *a[2]);
	printf("MReturn: value at address = %d\n", *(a[2]+1));
	printf("MReturn: value at address = %d\n", *(a[2]+2));

	return 0;
}
