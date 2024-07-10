#include<stdio.h>
#include <stdlib.h>
#include <string.h>
char *find_polysubstr(char *str)
{
	char *temp = malloc(26);

	int start = 1, end = 0, n = strlen(str), len = 0;

	for(int i = 0; i<n; i++) {
		for(int j = i+1; j<n; j++) {
			if(str[j-1] != str[j+1]) {
				if(str[j] != str[j+1] || str[j-1] != str[j]) {
					start = i;
					end = j;
				} else
					break;
			} else {
				start = i;
				end = j;
			}

			if(len < (end - start + 1)) {
				len = end - start + 1;
			}
		}
	}

	printf("len: %d\n", len);

	return NULL;
}

int main()
{
	//char *str = "babad";
	char *str = "cbbd";

	find_polysubstr(str);

	return 0;
}
