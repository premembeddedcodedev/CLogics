#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_roman(char s[], int num)
{
	char *sym[100] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int val[100] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}, i;

	for(i=0; num != 0; i++)
	{
		while(num >= val[i])
		{
			num -= val[i];
			strcat(s, sym[i]);
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc != 2) {
		fprintf(stderr, "Error in providing params to  (1-4000) ./a.out\n");
		exit(-1);
	}

	char s[100];
	
	convert_roman(s, atoi(argv[1]));

	printf("Roman: %s\n", s);

	return 0;
}
