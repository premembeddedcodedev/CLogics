#include<stdio.h>

#define R 10
#define C 20

int main()
{
	int (*p)[R][C];
	printf("1 ==> %d\n",  sizeof(*p));
	printf("2 ==> %d\n",  sizeof(p));
	getchar();
	return 0;
}
