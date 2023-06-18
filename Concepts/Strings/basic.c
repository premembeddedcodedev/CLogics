#include<stdio.h>

void print_str(char (*str)[][20])
{
	//(*str)[2] = 'a';
	*(*(*(str))+2) = 'a';
}

int main()
{
	char *aptr[2];
	char (*a)[20];
	char (*b)[2][20];
	char *qtr;
	//char *(*c)[20];

	char *str = "TestingPrem";
	char ptr[] = "TestingPrem";

	aptr[0] = str;
	aptr[1] = ptr;

	//qtr = ptr;

	a = (char (*)[])(ptr);
	*b[0] = (char (*)[]) a;

	print_str(b);

	int i = 0;
	
	printf("sizeof: %ld, %ld\n", sizeof(ptr), sizeof(*a));
	while(ptr[i] != '\0') {
		//printf("%c, ", ptr[i++]);
		//printf("%c, ", *((*a)+i));
		//printf("%c, ", (*a)[i]);
		//printf("%c, ", *(qtr+i));
		printf("%c, ", *(*(*(b))+i));
		i++;
	}

	return 0;
}
