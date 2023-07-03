#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *s = "ABC";
	char *t = "DEF";
	char *u = "GHI";

	//char ***ptr = (char***)malloc(sizeof(char**));
	char ***ptr = malloc(0);

	ptr[0] = malloc(0);
	ptr[1] = malloc(0);
	
	ptr[0][0] = (char *)malloc(sizeof(char) * 4);
	ptr[0][1] = (char *)malloc(sizeof(char) * 4);
	ptr[0][2] = (char *)malloc(sizeof(char) * 4);

	strncpy(ptr[0][0], s, 1/* strlen(s)*/);
	strncpy(ptr[0][1], t, 1/* strlen(t)*/);
	strncpy(ptr[0][2], u, 1/* strlen(u)*/);

	//ptr[0] = realloc(ptr[0], sizeof(char *) * 2);

	//ptr[0][0][2] = '\0';
	//ptr[0][1][2] = '\0';
	//ptr[0][2][2] = '\0';

	printf("00 - String : %c\n", ptr[0][0][0]);
	printf("01 - String : %c\n", ptr[0][1][0]);
	printf("01 - String : %c\n", ptr[0][2][0]);
	
	printf("00 - String : %s\n", ptr[0][0]);
	printf("01 - String : %s\n", ptr[0][1]);
	printf("01 - String : %s\n", ptr[0][2]);

	ptr[1][0] = (char *)malloc(sizeof(char) * 4);
	ptr[1][1] = (char *)malloc(sizeof(char) * 4);
	ptr[1][2] = (char *)malloc(sizeof(char) * 4);
	
	strncpy(ptr[1][0], s, strlen(s));
	strncpy(ptr[1][1], t, strlen(t));
	strncpy(ptr[1][2], u, strlen(u));
	
	printf("10 - String : %c\n", ptr[1][0][0]);
	printf("11 - String : %c\n", ptr[1][1][0]);
	printf("11 - String : %c\n", ptr[1][2][0]);
	
	printf("10 - String : %s\n", ptr[1][0]);
	printf("11 - String : %s\n", ptr[1][1]);
	printf("11 - String : %s\n", ptr[1][2]);

#if 0	
	printf("00 - String : %c\n", *ptr[0][0][0]);
	printf("00 - String : %c\n", *ptr[0][1][2]);
	
	printf("00 - String : %c\n", *ptr[0][0][0]);
	printf("00 - String : %c\n", *ptr[0][1][2]);
#endif
	return 0;
}
