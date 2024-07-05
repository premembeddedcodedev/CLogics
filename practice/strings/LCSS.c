#include<stdio.h>
#include <string.h>
#include <stdlib.h>
char *find_lcss(char *str)
{
	char ascii[26];
	char *temp = malloc(26);
	int start_off = 0, end_off = 0, max = 0;

	for(int i = 0; i<strlen(str); i++) {
		memset(ascii, 0, 26);
		int len = 0;
		for(int j=i;j<strlen(str);j++) {
			len++;
			if(ascii[(str[j] - 'a')] == 1) {
				if(max < (j - i + 1)) {
					start_off = i;
					end_off = j;
					max = (end_off - start_off + 1);
				}
				break;
			}
			ascii[(str[j] - 'a')] += 1;
		}
	}
	int k = 0;
	for(int i = start_off; i<end_off; i++) {
		temp[k++] = str[i];
	}

	temp[k] = '\0';	

	return temp;
}

int main()
{
	//char *str = "abcabcbb";
	//char *str = "bbbbb";
	char *str = "pwwkew";

	printf("LCSS: %s\n", find_lcss(str));

	return 0;
}
