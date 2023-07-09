#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool find_is_subset(char *s, char *t)
{
	int si = 0, tj = 0, i = 0;

	for(i=0;s[i]!='\0';i++) {
		while(t[tj] && t[tj] != s[i])
			tj++;
		if(t[tj] == '\0')
			return false;

		tj++;
	}
	return true;
}

int main()
{
	char t[] = "ahbgdc";
	char s[][4]= {"azc", "abc", "adz", "agc"};
	int  i = 0;

	for(i=0;i<4;i++)
		printf("its %s set\n", find_is_subset(s[i], t) ? "a": "not");

	return 0;
}
