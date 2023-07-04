#include <stdio.h>
#include <string.h>

void string_rev(char *str, int start, int length)
{
	int len = 0, i=start;
	char c;

	while(len++ <= (length-start)/2) {
		c= str[length];
		str[length--] = str[i];
		str[i++] = c;
	}
}

void word_reverse(char *str)
{
	int i=0, start = 0;// strlen(str);
	char c;

	printf("len: %d\n", strlen(str));

	string_rev(str, start, strlen(str)-1);
	
	printf("%s", str);
	printf("\n");
#if 0
	start = 0; i=0;

	while(str[i] != '\0') {
		if(str[i] == ' ') {
			string_rev(str, start, i-1);
			start = i+1;
		}
		i++;
	}

	printf("%s", str);
	printf("\n");
#endif
}

int main()
{
	char str[100] = "THis is my first program you need to concentrate much";

	word_reverse(str);

	return 0;
}
