#include<stdio.h>
#include <stdlib.h>

int main()
{
	int *dab[10];

	dab[0] = malloc(10); // array of pointers 

	dab[0][4] = 10;
	
	printf("1: %d\n", (*dab)[4]);
	printf("3: %d\n", dab[0][4]);

	int **db;

	db = malloc(1);

	db[0] = malloc(0);

	db[0][0] = 10;
	db[0][1] = 10;
	db[0][2] = 10;
	db[0][3] = 10;
	db[0][4] = 10;
	db[0][5] = 10;
	//db[0][6] = 10;
	

	db[1] = malloc(0);
	db[1][0] = 20;
	
	printf("2: %d\n", db[1][0]);

	return 0;
}
