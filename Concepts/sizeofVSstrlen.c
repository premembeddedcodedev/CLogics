#include<stdio.h>
#include <string.h>

// Strlen always prints the sizeof the string except null character
// sizeof always prints the sizeof the pointer incase we declare as a pointer otherwise prints number of char 

void strrev(char *str)
{
	printf("char length : %ld\n", strlen(str));
	printf("char length : %ld\n", sizeof(str));
}

void callforint(int a[])
{
	printf("int length : %ld\n", sizeof(a));
}

int main()
{
	char src[] = "Qualcomm is Service based company";
	printf("char length main : %ld\n", strlen(src));
	printf("char length main : %ld\n", sizeof(src));

	strrev(src);

	int a[] = {1,2,3,4,5,6,7,8,9,0};
	printf("main int length : %ld\n", sizeof(a));

	callforint(a);

	return 0;
}
