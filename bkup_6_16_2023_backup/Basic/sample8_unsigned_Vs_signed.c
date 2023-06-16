#include<stdio.h>
int main() 
{
	unsigned int x = -1;
	int z = -1;

	printf("x: %x\n", x);
	printf("z: %x\n", z);

	int y = ~0;
	if(x == y)
		printf("same");
	else
		printf("not same");
	printf("\n x is %u, y is %u", x, y);
	getchar();
	return 0;
}
