#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *ptr = malloc(10);

	memcpy(ptr, "Xiling", 10);

	printf("\n%s\n", ptr);

	char ch[10] = "Lattice";
	char *pt = "zhexs";

	//char (*check)[10] = &ch;
	//char (*check)[10] = &pt[2];

	char (*check)[10]; // Need to see
	
	check[0] = &ch[0];

	printf("value : %c\n",(*check)[3]);

	return 0;
}


#if 0
int main()
{
	char **file;

	char *str[12]; //{"January", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "December"};

	str[0] = "float";
	str[1] = "float";
	str[2] = "float";
	str[3] = "float";
	str[4] = "float";
	str[5] = "float";

	int size = 12;
	
	file = (char **)malloc(sizeof(char *) * (100 + 1));

	int  n = 12;

	for(int i = 0; i<6; i++) {
		file[i] = (char *)malloc(sizeof(char) * (n + 1));
		memcpy(file[i], str[i], size);
	}

	for(int i = 0; i<size; i++)
		printf("%d: %s\n", i, *file[i]);

	return 0;
}
#endif
#if 0
int main()
{
	//a[][][] = {{January, february, march, april, may, june, july, august, september, october, november}, {"week-1, week-2, week-3, week-4"}};

	char ***calender;

	calender = (char ***) malloc(sizeof(char **) * 12);
	calender[i] = (char **) malloc (sizeof(char *) * 4);

	for(int j = 0; j<12; j++) {
		for(int i = 0; i<4; i++) {
			calender[][] = ;
		}
	}

	return 0;
}
#endif
