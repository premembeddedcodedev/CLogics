#include<stdio.h>
#include <string.h>
#include <stdlib.h>

char *find_lcss(char *str)
{
	char *temp = malloc(26);
	char hash[26];

	memset(hash, -1, 26);

	int start = 0, end = 0, n = strlen(str), l = 0, r = 0, maxlen = 0;

	while(r<n) {
		if(hash[str[r] - 'a'] != -1) {
			if(hash[str[r] - 'a'] >= l){
				l = hash[str[r] - 'a'] + 1;
			}

		}
		if(maxlen < (r-l+1)) {
			start = l;
			end = r;
			maxlen = r-l+1;
		}

		hash[str[r] - 'a'] = r;
		r += 1;
	}

	int k = 0;
	for(int i = start; i < start+maxlen; i++) {
		temp[k++] = str[i];
	}

	temp[k] = '\0';

	return temp;
}

int main()
{
	char *str = "pwwkew";

	printf("string is : %s\n",find_lcss(str));

	return 0;
}
