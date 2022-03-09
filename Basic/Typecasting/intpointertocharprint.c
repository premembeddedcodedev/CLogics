#include <stdio.h>

int main (void)
{
	char arr[] = {'1','2','3','4','5','6','7','8','9'};
	int *ptr = (int *)arr;
	unsigned int i;

	char *check = (char *)ptr;

	for (i = 0; i < sizeof arr; i++)
		//printf (" %c", *ptr + i); //working
		printf (" %c", check[i]); //working
	//printf (" %c", (*(char *)ptr + i)); //working
	//printf (" %c", (char *)ptr[i]); // not working

	putchar ('\n');

	return 0;
}
