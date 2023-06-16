#include<stdio.h>
int fun()
{
	static int num = 40;
	return num--;
}

int main()
{
	// refer : https://www.educba.com/for-loop-in-c/ ==? for(first expression:conditional expression:loop expression) => statement
	for(fun(); fun(); fun())
	{
		printf("%d ", fun());
	}
	getchar();
	return 0;
}
