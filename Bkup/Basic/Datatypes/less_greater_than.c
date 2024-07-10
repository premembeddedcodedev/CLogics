#include<stdio.h>
#include<string.h>

int main()
{
	char a[128];

	memset(a, 0xFF, sizeof(a));

	printf("value : %d\n", 0xff);

	if(a[90] == -1)
		printf("equal\n");
	else
		printf("not equal\n");

	int b = 9;

	if(b > 9)
		printf("greater\n");
	else
		printf("not greater\n");

	if(b < 9)
		printf("less\n");
	else
		printf("not less\n");

	return 0;
}
