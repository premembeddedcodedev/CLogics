#include<stdio.h>

int func(int (*ptr)[4])
{
	printf("%p %p %p\n", ptr, ptr + 1, ptr + 2);
	printf("%p %p %p\n", *ptr, *(ptr + 1), *(ptr + 2));
	printf("%p %p %p\n", ptr[0], ptr[1], ptr[2]);

	printf("%d %d %d\n", ptr[0][0], ptr[1][2], ptr[2][3]);
	printf("%d %d %d\n", *ptr[0], *ptr[1], *ptr[2]);
	printf("%d %d %d\n", **ptr, *(*(ptr + 1) + 2), *(*(ptr + 2) + 3));

	return 0;
}

int main()
{
	int arr[3][4] = {
		{30, 31, 32, 13},
		{40, 41, 22, 23},
		{50, 51, 32, 33}
	};
	int (*ptr)[4];
	ptr = arr;

	func(ptr);

	return 0;
}
