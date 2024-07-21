#include<stdio.h>

void generate_pattern(int row, int col)
{
	if(row == 0)
		return;

	if(col < row) {
		generate_pattern(row, ++col);
		printf("*");
	} else {
		generate_pattern(--row, 0);
		printf("\n");
	}
}

void pattern_gen()
{
	for(int i=0;i<5;i++) {
		for(int j = 0; j < 5-i; j++) {
			printf("* ");
		}
		printf("\n");
	}
}

int main()
{
	//pattern_gen();
	
	int row, col;

	printf("Enter the row : \n");
	scanf("%d", &row);
	
	printf("Enter the col : \n");
	scanf("%d", &col);

	generate_pattern(row, col);
}
