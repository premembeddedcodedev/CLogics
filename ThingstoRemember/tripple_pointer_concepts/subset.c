#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *s, int index, int end_offset, int *returnSize)
{
	int start = index, end = end_offset;

	while(start <= end) {
		if(s[start++] != s[end--])
			return false;
		*returnSize += 1;
	}

	return true;
}

void subparition(char ***result, char *s, int index, int end, int *returnSize, int** returnColumnSizes, char *target)
{
	int i, size = 0;
	static int j = 0, k = 0;

	if(index >= strlen(s)) {
		printf("Exit %d ptr: Seq %d\n", *returnSize, end);
		if(is_palindrome(target, 0, end-1, &size)) {
			result[0] = (char **) realloc (result[0], sizeof(char *) * (*returnSize + 1));
			result[0][*returnSize] = malloc(end);
			returnColumnSizes = realloc(returnColumnSizes, sizeof(int *) * (*returnSize + 1));
			returnColumnSizes[*returnSize] = malloc(sizeof(int));

			for(i =0 ; i< end; i++) {
				result[0][*returnSize][i] = target[i];
				printf("%c->", target[i]);
			}

			result[0][*returnSize][i] = '\0';
			*returnColumnSizes[*returnSize] = end;
			*returnSize += 1;
			printf("\n");
		}
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
	char *arr = {"aabbaa"};
	char target[strlen(arr)];
	char ***result;
	int each_array;
	int **array;

	array = malloc(0);

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
