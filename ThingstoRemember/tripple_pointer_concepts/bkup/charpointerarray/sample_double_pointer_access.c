#include <stdio.h>
#include <stdlib.h>
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

void subparition(int ***result, char *s, int index, int end, int* returnSize, int** returnColumnSizes)
{
        int i, returnSize_value = 0;

	if(*s[index] == '\0')
		return;

	if(is_palindrome(s, index, &returnSize_value)) {
		result[*returnSize][index] = realloc(result[*returnSize][index], returnSize_value + 1);
		strncpy(result[*returnSize][index], s, returnSize_value);
		returnColumnSizes[*returnSize] = malloc(1);
		(*returnColumnSizes[*returnSize]) += 1;
	}

	subparition(s, index++, end, returnSize, returnColumnSizes);
	*returnSize += 1;
	result[*returnSize] = malloc (sizeof(char *));
	subparition(s, index, end--, returnSize, returnColumnSizes);
}

// Each of the coulmn size : returnColumnSizes i.e a[row][col]
// returnSize 

char ***partition(char *s, int* returnSize, int** returnColumnSizes)
{
	char ***result = (char ***) malloc (sizeof(char **)); 

	result[0] = malloc (0);
	result[0][0] = malloc (0);
	returnColumnSizes[0] = malloc(0);

	*returnSize = 0;
	
	subparition(result, s, 0, 0, returnSize, returnColumnSizes);
	
	printf("Praveen: Return Size : %d\n", *returnSize);

	return result;
}

int main()
{
	char arr[10] = {"aabbaa"};
	char ***result;
	int each_array;
	int *array;

	//array = (int *) malloc(sizeof(int));

	result = partition(arr, &each_array, &array);

	//printf(" String is %s\n", is_palindrome(arr, 4) ? "palindrome" : "not a palindrome");

	return 0;
}
