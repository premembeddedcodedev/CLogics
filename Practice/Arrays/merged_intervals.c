#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void intsertionsort(int intervals[][2], int intervalsSize)
{
	bool status = false;
	int first = 0, second = 0;

	printf("Array order : \n");
	for(int i = 0; i < intervalsSize; i++)
		printf("(%d, %d), ", intervals[i][0], intervals[i][1]);

	printf("\n");

	for(int i = 1; i < intervalsSize; i++) {
		int  j = i - 1;
		int temp = intervals[i][0];
		first = i;
		int temp2 = intervals[i][1];
		while(j >=0 && temp <= intervals[j][0]) {
			if(temp == intervals[j][0]) {
				if(temp2 > intervals[j][1]) {
					int check = intervals[j][1];
					intervals[j][1] = temp2;
					temp2 = check;
				}
			}
			intervals[j+1][0] = intervals[j][0];
			intervals[j+1][1] = intervals[j][1];
			j--;
		}
		intervals[j+1][0] = temp;
		intervals[j+1][1] = temp2;
	}

	printf("Sorted order : \n");
	for(int i = 0; i < intervalsSize; i++)
		printf("(%d, %d), ", intervals[i][0], intervals[i][1]);

	printf("\n");
}

int** merge(int intervals[][2], int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes)
{
	int **result = malloc(0);

	intsertionsort(intervals, intervalsSize);

	int i = 1, j = 0;

	while(i < intervalsSize) {
		int start = j;
		while(intervals[i][0] <= intervals[j][1] && intervals[j][1] < intervals[i][1]) {
			i++;
			j++;
		}
		int end = i - 1;
		result[*returnSize] = malloc(sizeof(int) * 2);
		returnColumnSizes[*returnSize] = malloc(sizeof(int));
		*returnColumnSizes[*returnSize] = 2;
		result[*returnSize][0] = intervals[start][0];
		result[*returnSize][1] = intervals[end][1];
		(*returnSize)++;
		i++;
		j++;
	}

	return result;
}

int main()
{
	int intervals[8][2] = {{1,3}, {2,6}, {8,9}, {9,11}, {8,10}, {2,4}, {15,18}, {16,17}};
	int intervalsColSize = 0;
	int returnSize = 0;
	int *returnColumnSizes[10];

	printf("size: %ld\n", sizeof(intervals)/sizeof(int));

	int **result = merge(intervals, 8, &intervalsColSize, &returnSize, returnColumnSizes);

	for(int i=0; i<returnSize; i++) {
		for(int j = 0; j<*returnColumnSizes[i]; j++)
			printf("%d->", result[i][j]);
		free(returnColumnSizes[i]);
		free(result[i]);
		printf("\n");
	}

	free(result);

	return 0;
}
