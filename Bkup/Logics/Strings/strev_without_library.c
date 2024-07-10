#include<stdio.h>

int main()
{
	char str[] = "My name is praveen";
	int len = 0, start=0;
	char temp;


	while(str[len++] != '\0');

	len -= 2;

	while(start < len) {
		temp = *(str+start);
		*(str + start) = *(str+len);
		*(str+len) = temp;
		len--; start++;
	}

	printf("String here is : %s\n", str);

	return 0;
}
