#include<stdio.h>
#include <stdlib.h>
#include <string.h>
char *find_polysubstr(char *str)
{
	char *temp = malloc(26);

	int start = 1, end = 0, n = strlen(str), len = 0, soff = 0, eoff=0;

	printf("strlen : %d\n", n);

	while(start < n) {
		int check = start, boundary = start;
		
		while((((check-1) >= 0) && ((boundary+1) < n) && (str[check] == str[boundary]))) {
			check -= 1;
			boundary += 1;	
		}
	

		while(((check) >= 0) && (((boundary+1) < n) && (str[check] == str[boundary]))) {
			check += 1;
			boundary = check + 1;	
		}

		
		if(even_len && ((boundary+1) == n)) {
			if(len < boundary-start+1) {
				soff = start;
				eoff = boundary;
				len = boundary-start+1;	
			}
			break;
		}

		
		if(even_len && (len < (boundary-check+1))) {
			soff = check;
			eoff = boundary;
			len = boundary-check+1;
		}

		start++;
	}

	printf("len: %d\n", len);

	int k = 0;
	for(int i = soff; i<=eoff; i++) {
		temp[k] = str[i];
		printf("%c ", temp[k]);
		k++;
	}

	temp[k] = '\0';

	return temp;
}

int main()
{
	//char *str = "babad";
	char *str = "cbbd";
	//char *str = "abb";
	//char *str = "baa";

	printf("String: %s\n",find_polysubstr(str));

	return 0;
}
