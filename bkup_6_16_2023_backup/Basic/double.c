#include <stdio.h>

int main()
{
	int a[2][3] = {1,5,7,98,88,78};
	int *p = &a[0][0];
	//p = &a;
	//p = &a[0];
	p = *a;
	p = *(a+0);
	p = a[0];

	printf("normal: %p, %p\n", &a[0][0], &a[0][1]);
	printf("%d, %d\n", **a, *p);

	printf("%p, %p, %p\n", a, a+1, *((a+0)+1));
	printf("%p, %p, %p\n", a[0], a[1], *((a+0)+1));
	//*a, a+1, *(*(a+0)+1));
	printf("%p, %p, %p\n", &a, &a+1, *(&a+1));
	printf("%p, %p, %d\n", &a[0], &a[0]+1, **(&a[0]+1));
	printf("%p, %p, %d\n", *a, *a+1, **a);
	printf("%p, %p, %d\n", *a, *(*a+1), **a);

	printf("%p\n", p);
	printf("%p\n", p+1);

	return 0;
}
