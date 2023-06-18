/**
 * Problem: 
 * 1.   *****\
	*****\
	*****\
    	*****\
    	*****\
 */

#include<stdio.h>

int main()
{
	int r, c, n, m;

	printf("Numbe of rows : \n");
	scanf("%d", &n);
	printf("Numbe of coloumns : \n");
	scanf("%d", &m);

	for(r=0;r<n;r++) {
		for(c=0;c<m;c++) {
			printf("*");
		}
		printf("\n");
	}
}
