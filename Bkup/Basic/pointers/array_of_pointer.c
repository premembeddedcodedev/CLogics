#include <stdio.h>
#include <stdlib.h>

int main(void){
	int nrows   = 3;
	int ncolumns = 4;
	int i, j;

#ifdef LOGIC_ONE

	int *array[nrows][ncolumns];
	int *src = (int*)malloc(nrows * ncolumns * sizeof(int));//no need (int*)

	printf("Enter elements:\n");

	for(i = 0; i<nrows; i++){
		for(j = 0; j<ncolumns;j++){
			array[i][j] = &src[ i * ncolumns + j];//pointer pointed to entity (src[ i * ncolumns + j])
			scanf("%d", array[i][j]);//type of array[i][j] is int *
		}
	}

	printf("Entered array is: \n");
	for(i = 0; i<nrows; i++){
		for(j = 0; j<ncolumns; j++){
			if(j != 0)
				putchar(' ');
			printf("%d", *array[i][j]);//need * for dereference
		}
		putchar('\n');
	}

	free(src);
#else
	int *array[nrows][ncolumns];
	array[nrows][ncolumns] = (int*)malloc(nrows * ncolumns * sizeof(int));

	printf("Enter elements:\n");

	for(i = 0; i<nrows; i++)
	{
		for(j = 0; j<ncolumns;j++)
		{
			scanf("%d",&array[i][j]);


		}
	}


	printf("Entered array is: \n");
	for(i = 0; i<nrows; i++)
	{
		for(j = 0; j<ncolumns;j++)
		{
			if(j == ncolumns-1)
			{
				printf("%d \n",array[i][j]);
			}
			else
			{
				printf("%d \t",array[i][j]);
			}


		}
	}
#endif
	return 0;
}
