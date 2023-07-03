#include <stdio.h>

void print_spiral_matrix(int a[][4], int n, int m)
{
	int top = 0, left = 0, sizerow = n-1, sizecol = m-1;

	int loop = 0;

	while(loop < n/2) {

		int i = 0;

		for(i = left; i<=sizecol; i++)
			printf("%d->", a[top][i]);
		
		printf("\n");

		left = i - 1;

		top = top + 1;

		for(i = top; i<=sizerow; i++)
			printf("%d->", a[i][left]);
		
		printf("\n");
		left = left - 1;
		top = i - 1;
	
		for(i = left; i>=loop; i--)
			printf("%d->", a[top][i]);
		
		printf("\n");
		top = top - 1;
		left = i + 1;

		for(i = top; i>loop; i--)
			printf("%d->", a[i][left]);
	
		top = i-1;

		printf("\n");

		top += 2;
		left+= 1;
		sizerow -=1;
		sizecol -=1;
		loop++;
	}	
}

int main()
{
	int matrix[5][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 16}, {17, 18, 19, 20}};

	print_spiral_matrix(matrix, 5, 4);

	return 0;
}
