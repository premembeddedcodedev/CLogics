#include <stdio.h>
#include <stdlib.h>

//Reference: https://stackoverflow.com/questions/32561023/memory-allocation-for-pointer-to-array-and-array-of-pointer
#define NUM_ELEMENTS 3
#define NUM_ARRAY 2

int main()
{
#if 1 //LOGIC_ONE
	int (*arrays)[NUM_ARRAY][NUM_ELEMENTS];
	int i, j;

	//for(i=0;i<NUM_ARRAY;i++)
	arrays = malloc(NUM_ARRAY * NUM_ELEMENTS * 4);
	printf("starting address: %p\n", arrays);

	//printf("sizeof : %d\n", sizeof(arrays));
	//printf("sizeof : %d\n", sizeof(*arrays));

	printf("enter the elements of an array: \n");	
	for(i=0;i<NUM_ARRAY;i++) {
		for(j=0;j<NUM_ELEMENTS;j++) {
			printf("%p, %p\t", &(*arrays)[i][j],  arrays[i][j]);
			scanf("%d", &(*arrays)[i][j]);
		}
	}
	//scanf("%d", &(*(*((*arrays)+i)+j)));
	//scanf("%d", &(*((*arrays)+i))[j]);

	printf("entered elements of an array: \n");	
	for(i=0;i<NUM_ARRAY;i++)
		for(j=0;j<NUM_ELEMENTS;j++)
			printf("%d=>", (*arrays)[i][j]);

	free(arrays);

#else
#if 0
	int nrows, ncolumns, i, j;

	printf("rows:\n");
	scanf("%d", &nrows);

	printf("col:\n");
	scanf("%d", &ncolumns);

	int (*array)[nrows][ncolumns];
	array = malloc(nrows * ncolumns * sizeof(int));
	
	printf("starting address: %p\n", array);

	printf("\n Enter the elements:\n");
	for(i=0; i<nrows; i++)
	{
		for(j=0; j<ncolumns; j++)
		{
			//scanf("%d", &(*array)[i][j]); //LOGIC_ONE scan will not work
			printf("%p\t", array[i][j]);
			scanf("%d", array[i][j]);   
		}
	}

	printf("Entered array is :\n\n");

	for(i = 0;i<nrows; i++)
	{
		for(j = 0; j<ncolumns; j++)
		{
			//printf("%d=>", (*array)[i][j]); //LOGIC_ONE print will not work
			printf("%d \n", *array[i][j]);
		}
	}
#endif
#endif

#if LOGIC_2
        int nrows    = 3;
        int ncolumns = 4;
        int i, j;

        int (*array)[ncolumns];
        array = (int (*)[ncolumns])malloc(nrows * sizeof(*array));//sizeof(*array) : sizeof(int[ncolumns])

	printf("start address: %p\n", array);

	int *p;

	printf("sizeof pointer : %d\n", sizeof(p)); // 8
	printf("sizeof pointer : %d\n", sizeof(*p)); // 4

        printf("*array: %d\n", sizeof(*array));
        printf("int[coloumn]: %d\n", sizeof(int[ncolumns]));
        printf("array: %d\n", sizeof(array));

        printf("\nEnter the elements:\n");

        for(i = 0; i<nrows; i++){
                for(j = 0; j<ncolumns; j++){
			printf("%p\t", &array[i][j]);
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
#endif

	return 0;
}
