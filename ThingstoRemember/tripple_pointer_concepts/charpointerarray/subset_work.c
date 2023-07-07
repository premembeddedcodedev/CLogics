#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 5

void subparition(char ***result, char *s, int index, int end, int *returnSize, int** returnColumnSizes, char *target)
{
	int i;
	static int j = 0, k = 0;

	if(index >= strlen(s)) {
		printf("Exit %d ptr: Seq %d\n", *returnSize, end);
		result[0] = (char **) realloc (result[0], sizeof(char *) * (*returnSize + 1));
		result[0][*returnSize] = malloc(end);
		returnColumnSizes[*returnSize] = malloc(sizeof(int));
#if NOTWORKING
		if(end-1 > 0)
			strncpy(result[0][*returnSize], s, end);
		else
			strncpy(result[0][*returnSize], s, 1);
#else
	
		for(i =0 ; i< end; i++) {
			result[0][*returnSize][i] = target[i];
			printf("Normal: %c->\t pointer : %c-> \t", target[i], result[0][*returnSize][i]);
		}
#endif
		result[0][*returnSize][i] = '\0';
		*returnColumnSizes[*returnSize] = end;
		*returnSize += 1;
		printf("\n");
		return;
	}
	//printf("\t\t\tBefore Recursion ===> %d\n", index);

	target[j] = s[index];
	j += 1; // call will not come here when return calls

	index += 1;

	subparition(result, s, index, j, returnSize, returnColumnSizes, target);
	//printf("\t\t\tindex ====> %d\n", index);

	// this call returns from if condition above 
	subparition(result, s, index, --j, returnSize, returnColumnSizes, target);
	//printf("\t\t\t2nd index ====> %d\n", index);

	//subset[0] = 0;

	return;
}

char ***partition(char *s, int *returnSize, int** returnColumnSizes, char *target)
{
	char ***result = (char ***) malloc (sizeof(char **)); 
	
	*returnSize = 0;
	
	result[*returnSize] = (char **) malloc (sizeof(char *));
	
	subparition(result, s, 0, 0, returnSize, returnColumnSizes, target);
	
	printf("Praveen: Return Size : %d\n", *returnSize);


	return result;
}

int main()
{
	char arr[10] = {"aba"}, target[100];
	char ***result;
	int each_array;
	int *array[10];

	result = partition(arr, &each_array, array, target);

	for(int i = 0; i<each_array; i++)
		printf("String (%d) : %s\n", i, result[0][i]);
	
	for(int i = 0; i<each_array; i++) {
		free(result[0][i]);
	}

	free(*result);
	free(result);

	return 0;
}
