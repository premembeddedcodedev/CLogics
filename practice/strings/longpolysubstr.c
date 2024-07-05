#include<stdio.h>

char *find_polysubstr(char *str)
{
	char *temp = malloc(26);

	int start = 1, end = 0, n = strlen(str);

	for(int i = 1; i<n; i++) {
		for(int j = i+1; j<n; j++)
	}

	return NULL;
}

int main()
{
	char *str = "babad";

	find_polysubstr(str);

	return 0;
}
