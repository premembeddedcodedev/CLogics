#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int ***A, **B, *c, D;

	printf(" size of tripple pointer %d\n", sizeof(int ***));
	printf(" size of tripple pointer %d\n", sizeof(int **));
	printf(" size of tripple pointer %d\n", sizeof(int *));
#if 0
	int ***X = (int ***) malloc(sizeof(int**) * n); //FIX 1
	for(i = 0; i < n; i++){
		printf("h\n");
		X[i] = (int **) malloc(sizeof(int*) * n);  // FIX 2
		for(j = 0; j < n; j++){
			printf("j\n");
			X[i][j] = (int *) malloc(sizeof(int) * n);
		}
	}
#endif
	return 0;
}
