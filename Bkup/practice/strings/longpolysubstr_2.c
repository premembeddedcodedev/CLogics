//https://www.youtube.com/watch?v=QfZvw8_jz1w
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

int expand(char *str, int left, int right)
{
	while((left >= 0) && (right < strlen(str)) && (str[left] == str[right])) {
		left--;
		right++;
	}

	printf("left %d, right %d\n", left, right);

	return right - left - 1;
}

char *longpolysubstr(char *str)
{
	char *temp = malloc(20);
	int start = 0, end = 0, len = 0;

	for(int i=0; i<strlen(str); i++) {
		printf("\nOdd : ");
		int odd = expand(str, i, i);
		printf("\neven : ");
		int even = expand(str, i, i+1);
	
		len = odd > even ? odd: even;

		if(len > end - start) {
			start = i - (len-1)/2;
			end = i + len/2;
		}

	}

	int k = 0;

	for(int i = start; i<end+1; i++){
		temp[k] = str[i];
		k++;
	}

	temp[k] = '\0';

	return temp;
}

int main()
{
	//char *str = "babad";
	//char *str = "cbb";
	//char *str = "aac";
	//char *str = "abcba";
	//char *str = "abccba";
	char *str = "abaccabe";
	//char *str = "a";

	printf("\nstring : %s\n", longpolysubstr(str));

	return 0;
}
