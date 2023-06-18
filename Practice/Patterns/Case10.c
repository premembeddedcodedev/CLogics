/**
 * Problem: 
 10.     *
        * *
       * * *
      * * * *
     * * * * *
 */

#include<stdio.h>

int main()
{
	int r, c, n, m, k;

	printf("Numbe of rows : \n");
	scanf("%d", &n);

	for(r=0;r<(n);r++) {
		for(c=0;c<r;c++) {
			if(c%2 == 0) 
				printf("*");
			else
				printf(" ");
		}
		for(c=0;c<=(n-(2*r+1));c++) {
			if(c%2 == 0)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
}
