#include <stdio.h>
int main() 
{
	int a= -1,b = -a;
	int x,y;

	printf("b=%d ,a=%d\n", b, a);

	if(a > 0)
		printf("a is greater than 0\n");
	else
		printf("a is less than 0\n");

	x = (a> 0) && (b < 0) || (a< 0) && (b > 0);
	y = (a<= 0) || (b >= 0) && (a>= 0) || (b <= 0);
	
	printf("x:%d, y:%d\n", x, y);

	printf("%d\n",x == y);
	
	return 0;
}
