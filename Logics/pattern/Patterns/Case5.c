/**
 * Problem: 
 5. *
    **
    ***
    ****
    *****
    ****
    ***
    **
    *
 */

#include<stdio.h>

int main()
{
	int r, c, n, m, k;

	printf("Numbe of rows : \n");
	scanf("%d", &n);
	printf("Numbe of coloumns : \n");
	scanf("%d", &m);

	for(r=0;r<(2*n);r++) {
		k = (r > n) ? (2*n-r) : r;
		for(c=0;c<k;c++) {
			printf("*");
		}
		printf("\n");
	}
}
