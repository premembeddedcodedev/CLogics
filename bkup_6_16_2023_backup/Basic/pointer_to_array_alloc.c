#include <stdio.h>
#include <stdlib.h>

int main(void){
	int nrows    = 3;
	int ncolumns = 4;
	int i, j;

	int (*array)[ncolumns];
	array = (int (*)[ncolumns])malloc(nrows * sizeof(*array));//sizeof(*array) : sizeof(int[ncolumns])

	printf("%d\n", sizeof(*array));
	printf("%d\n", sizeof(int[ncolumns]));
	printf("%d\n", sizeof(array));

	printf("\nEnter the elements:\n");

	for(i = 0; i<nrows; i++){
		for(j = 0; j<ncolumns; j++){
			scanf("%d", &array[i][j]);
		}
	}

	printf("Entered array is :\n\n");

	for(i = 0; i<nrows; i++){
		for(j = 0; j<ncolumns; j++){
			if(j != 0)
				putchar(' ');
			printf("%d", array[i][j]);
		}
		putchar('\n');
	}
	free(array);
	return 0;
}
