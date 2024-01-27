#include <stdio.h>
#include <string.h>

int string_traverse_count(char ch, char *str)
{
	int len = strlen(str), res = 0, count = 0;

	printf("for ch: %c\t", ch);

	for(int i = 0; i<len; i++) {
		if(str[i] == ch) {
			res += ((count) * (count+1))/2;
			count = 0;
		} else
			count++;
		printf(" ccount : %d\n", count);
	}

	res += ((count) * (count+1))/2;

	return (len*(len+1))/2 - res;
}

int main()
{
	char *str = "abbca";
	int count = 0;

	for(char ch = 'a'; ch<='z'; ch++)
		count += string_traverse_count(ch, str);

	printf("Count : %d\n", count);

	return 0;
}
