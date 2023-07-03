/**
 * Problem: 
4.  1
    1 2
    1 2 3
    1 2 3 4
    1 2 3 4 5
 */

#include<stdio.h>

int main()
{
	int r, c, n, m, temp = 1;

	printf("Numbe of rows : \n");
	scanf("%d", &n);
	printf("Numbe of coloumns : \n");
	scanf("%d", &m);

	for(r=0;r<n;r++) {
		for(c=r;c>=0;c--) {
			printf("%d", temp++);
		}
		temp = 1;
		printf("\n");
	}
}
