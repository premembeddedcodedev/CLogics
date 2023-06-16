/*
 * https://www.youtube.com/watch?v=oWyRhlpnCU8&list=PL7ersPsTyYt2prN058WfA_j3ElgwD1bht&index=25
 * https://www.youtube.com/watch?v=hWhMAoBhi7M
 *
 * */



#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void pattern2()
{
	int i, j;

	for(i=1;i<MAX; i++) {
		for(j=0;j<i;j++) {
			printf("*");
		}
		printf("\n");
	}
}

void pattern5()
{
	int i = 0, j = 0, k = 0;

	for(i=1;i<MAX; i++) {
		for(j=MAX;j>i;j--) {
			printf(" ");
		}

		for(k = 0; k<i; k++)
			printf("*");

		printf("\n");
	}
}

void pattern6()
{
	int i, j;

	for(i=1;i<MAX; i++) {
		for(j=MAX;j>i;j--) {
			printf("*");
		}
		printf("\n");
	}
}


void pattern1()
{
	int i, j;

	for(i=1;i<MAX; i++) {
		for(j=MAX;j>i;j--) {
			printf("*");
		}
		printf("\n");
	}
}

void pattern4()
{
#if 0
	int i, j;

	for(i=1;i<MAX; i++) {
		if(i >= MAX/2)
			for(j=1;j<=MAX-i;j++)
				printf("*");
		else
			for(j=1;(j<=i && j<=MAX/2);j++)
				printf("*");
		printf("\n");
	}
#else
	int row, col, totalrows;

	for(row=1; row<2*MAX; row++) {
		totalrows = row >  MAX ?  (2*MAX - row): row;
		for(col=1; col<=totalrows; col++)
			printf("* ");

		printf("\n");
	}
#endif
}

void pattern3()
{
	int i, j;

	for(i=1;i<MAX; i++) {
		for(j=1;j<=i;j++) {
			printf("%d",j);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	if(argc !=2) {
		fprintf(stderr, "./a.out missing arguments (1-9): %d", argc);
		exit(-1);
	}

	switch (atoi(argv[1])) {
		case 1:
			pattern1();
			break;
		case 2:
			pattern2();
			break;
		case 3:
			pattern3();
			break;	
		case 4:
			pattern4();
			break;
		case 5:
			pattern5();
			break;
		case 6:
			pattern6();
			break;	
		case 7:
			pattern1();
			break;
		case 8:
			pattern1();
			break;
		case 9:
			pattern1();
			break;	
		default:
			pattern1();
			break;
	};

	return 0;
}
