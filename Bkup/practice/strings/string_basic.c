#include<stdio.h>
#include <stdlib.h>

int main()
{
	char str[10];

	printf("Enter the string\n");
	scanf("%s", str);

	printf("%s", str);

	char *ptr = malloc(20);

	printf("Enter the string\n");
	scanf("%s", ptr);

	printf("%s", ptr);


	return 0;
}
