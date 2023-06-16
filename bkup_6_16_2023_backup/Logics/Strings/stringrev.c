#include <stdio.h>
#include <string.h>

#define MAX 10


void strrev(char a[], int len, char dst[])
{
	static int i = 0;

	if(len < 0) {
		printf("len: %d\n", len);
		return;
	}
	
	printf("%c \t", a[len]);
	dst[i++] = a[len];

	strrev(a, --len, dst);

	++len;

	printf("%c \t", a[len]);
}

int main()
{
	char str[MAX] = "Praveen", dst[MAX]; 

	strrev(str, strlen(str) - 1, dst);

	dst[strlen(str)] = '\0';

	printf("%s\n", dst);

	return 0;
}
