/**
 * Problem: 
9.  *********
     *******
      *****
       ***
        *
 */

#include<stdio.h>

int main()
{
	int r, c, n, m, k;

	printf("Numbe of rows : \n");
	scanf("%d", &n);

	for(r=0;r<(n);r++) {
		for(c=0;c<r;c++)
			printf(" ");
		for(c=0;c<=(n-(2*r+1));c++)
			printf("*");
		printf("\n");
	}
}
