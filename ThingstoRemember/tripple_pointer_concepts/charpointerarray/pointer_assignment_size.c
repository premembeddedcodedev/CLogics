#include <stdio.h>
#include <stdlib.h>

#define  SIZE 5

int main()
{
	char *a[10];
	
	a[0] = malloc(73);
	printf("0 -> %p\n", a[0]);
	a[1] = malloc(0);
	printf("1 -> %p\n", a[1]);

	//a[0] = realloc(a[0], 25);
	//printf("0 -> %p\n", a[0]);

	for(int i = 0; i<10; i++) {
		//a[i] = i+90;
		//printf("%d->", a[i]);
	}

	return 0;
}
