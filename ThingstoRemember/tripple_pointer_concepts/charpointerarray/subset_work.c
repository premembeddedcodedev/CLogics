#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 5

void subparition(char ***result, char *s, int index, int end, int *returnSize, int** returnColumnSizes, char *target)
{
	int i;
	static int j = 0, k = 0;

	if(index >= strlen(s)) {
		printf("Exit : Seq %d\n", end);
		//result[0] = (char **) realloc (result[0], sizeof(char *) * (*returnSize+1));
		result[*returnSize][0] = malloc(end);
		returnColumnSizes[*returnSize] = malloc(4);
		for(i =0 ; i< end; i++) {
			result[*returnSize][0][i] = target[i];
			printf("Normal: %c->\t pointer : %c-> \t", target[i], result[*returnSize][0][i]);
		}
		//result[*returnSize][0][i] = '\0';
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

	result[0] = (char **)malloc (sizeof(char *));
	result[1] = (char **)malloc (sizeof(char *));
	result[2] =(char **)malloc (sizeof(char *));
	result[3] =(char **)malloc (sizeof(char *));
	result[4] = (char **)malloc (sizeof(char *));
	result[5] = (char **)malloc (sizeof(char *));
	result[6] = (char **)malloc (sizeof(char *));
	result[7] = (char **)malloc (sizeof(char *));

	*returnSize = 0;

	subparition(result, s, 0, 0, returnSize, returnColumnSizes, target);

	printf("Praveen: Return Size : %d\n", *returnSize);
	
	for(int i = 0; i<*returnSize; i++)
		printf("String : %s\n", result[i][0]);

	return result;
}

int main()
{
	char arr[10] = {"aba"}, target[100];
	char ***result;
	int each_array;
	int *array[10];

	//array = (int *) malloc(sizeof(int));

	result = partition(arr, &each_array, array, target);

	return 0;
}
