#include <stdio.h>
int main()
{
	int a = 10, b = 20, c = 30;
	if (c > b > a)
	{
		printf("TRUE");
	}
	else
	{
		printf("FALSE");
	}

	printf("\nvalue : %d\n", (10 > 30)); // ==? this is the reason everytime we will get false condition evaluate as ((c>b)>a)
					     // c>b gives 1, 1>a gives false;

	getchar();
	return 0;
}
