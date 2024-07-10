#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char ***tb;
	char **db;
	char *str[12] = {"January", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "December"};

	tb = (char ***) malloc(sizeof(char **) * 1); // TODO : hole: tb = (char ***) malloc(0); // {{'j', 'a', 'n'}, {'f'}, {'m', 'a'}}

	tb[0] = (char **) malloc (sizeof(char *) * 3); //==> *tb = (char **) malloc (sizeof(char *) * 3);

	tb[0][0] = (char *) malloc (sizeof(char) * 10); // db[0] similar ==> *tb[0] = (char *) malloc (sizeof(char) * 10); // db[0] similar

	tb[0][0][0] = str[0][0]; //memcpy(tb[0][0], "praveen", sizeof("praveen")); // this is for string
	tb[0][0][1] = 'Y'; // this is for char
	tb[0][0][2] = '\0';
	
	printf("string: %s\n", tb[0][0]);
	
	return 0;
}
