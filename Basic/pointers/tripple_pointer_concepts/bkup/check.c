#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char *s, int index, int len, int *returnSize)
{
	int start = index, end = len;

	while(start <= end) {
		if(s[start++] != s[end--])
			return false;
		*returnSize += 1;
	}

	return true;
}

void subparition(char *s, char ***result, int *cindex, int sindex, int* returnSize, int** returnColumnSizes)
{
	int i, returnSize_value = 0;

	if(sindex == strlen(s))
		return;

	for(int i = 0; i < strlen(s), *returnSize < strlen(s); i++) {
		if(is_palindrome(s, sindex, i, &returnSize_value)) {
			result[*returnSize] = realloc(result[*returnSize], (*returnColumnSizes[*cindex]+1) * 4);
			result[*returnSize][*returnColumnSizes[*cindex]] = malloc(sizeof(returnSize_value));
			for(int j = sindex, k=0; j <= i; j++)
				result[*returnSize][*returnColumnSizes[*cindex]][k++] = s[j];
			printf("%d %d : %s\n", *returnSize, *returnColumnSizes[*cindex], result[*returnSize][*returnColumnSizes[*cindex]]);
			*returnColumnSizes[*cindex] += 1;
			subparition(s, result, cindex, sindex+1, returnSize, returnColumnSizes);
			(*returnSize)++;
			(*cindex)++;
		}	
	}

}

//char ***partition(char *s, int* returnSize, char** returnColumnSizes)
char *** partition(char * s, int* returnSize, int** returnColumnSizes)
{
	int coloumnsize = 0;
	char ***result = malloc (0); 

	printf("string length: %ld\n", strlen(s));

	for(int i=0; i<strlen(s); i++) {
		returnColumnSizes[i] = malloc(1);
		*returnColumnSizes[i] = 0;
		result[i] = malloc(1);
	}
	
	subparition(s, result, &coloumnsize, 0, returnSize, returnColumnSizes);

	printf("result 0 0: %c\n", result[0][0][1]);

	return result;
}

int main()
{
	char *arr = "aab";
	char ***result;
	int each_array = 0;
	int *array[10];

	result = partition(arr, &each_array, array);

	int i = 0;

	printf("each array : %d\n", each_array);

	for(i=0; i<2; i++)
		printf("\nResult %s \n", result[0][i]);
	
	return 0;
}
