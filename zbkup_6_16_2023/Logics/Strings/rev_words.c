#include <stdio.h>

void rev_str(char *start, char *end)
{
	char temp;

	while(start < end) {
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
}	

void rev_words(char *str)
{
	/*wordboundary traverse till space and '\0/' ideally length of word*/
	char *wordboundary = str;
	/*each iteration wordbegin pointing to start of string for the word*/
	char *wordbegin = wordboundary;

	while(*wordboundary) {
		if((*(wordboundary+1) == ' ' || *(wordboundary+1) == '\0')) {
			rev_str(wordbegin, wordboundary);
			wordbegin = wordboundary+2;
		}

		wordboundary++;
	}
	rev_str(str, wordboundary-1);
}

int main()
{
	char str[100] = "This is my first program please concentrate more";

	rev_words(str);

	printf("String : %s\n", str);

	return 0;
}
