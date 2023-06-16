#include<stdio.h>

static int a = 10;
int func2();
extern int m;
void func()
{
	static int a = 20;
	printf("in fun%d\n", a);
}

int main()
{
	func();
	printf("in fun%d\n", a);
	printf("Global: %d\n",func2());
	printf("Global_local: %d\n", m);
	return 0;
}
