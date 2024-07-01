#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char c[10] = "Hellow";
	char *p;

	char (*ptr)[10];

	p = c;

	ptr = &c; //ptr = c; will not work

	printf("1: %p -> %c : %p\n", p, *p, ptr);

	printf("\n single: %p\n", &(*ptr)[5]); //ptr[5]); address of the char array offset
	
	p++; // next character
	ptr++; // next array bound

	printf("2: %p -> %c : %p\n", p, *p, ptr);

	return 0;
}
