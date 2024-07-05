#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int scoreOfString(char* s)
{
	int l, h, sum = 0;

	for(int i = 0; i<strlen(s); i++) {
		l = i;
		h = i+1;
		sum += s[h] - s[l];
	}
	return sum;
}

int main()
{
	char str[10];

	printf("Enter the string\n");
	scanf("%s", str);

	printf("\nscore: %d\n",scoreOfString(str));

	return 0;
}
