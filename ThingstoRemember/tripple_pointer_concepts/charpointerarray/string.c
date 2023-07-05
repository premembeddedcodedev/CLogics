#include<stdio.h>
#include <string.h>

void print(char *st)
{
	printf("%ld\n", strlen(st));
}

int main()
{
	int *sr = "Praveen";

	print(sr);
}
