#include<stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	char **db;
	char *str[12] = {"January", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "December"};

	db = (char **) malloc (sizeof(char *) * 3);

	db[0] = (char *) malloc (sizeof(char) * 10);
	db[1] = (char *) malloc (sizeof(char) * 10);
	db[2] = (char *) malloc (sizeof(char) * 10);

	//memcpy(db[0], "praveen", sizeof("praveen"));
	//memcpy(db[0], str[0], sizeof(str[0]));
	//db[0][0] = 'A'; db[0][1] = 'B'; db[0][2] = '\0';
	//db[0][0] = str[0][0]; db[0][1] = '\0';;
	memcpy(db[1], "xpraveen", sizeof("xpraveen"));
	memcpy(db[2], "ypraveen", sizeof("ypraveen"));

	printf("string: %s\n", db[0]);
	printf("string: %s\n", db[1]);
	printf("string: %s\n", db[2]);
	return 0;
}
