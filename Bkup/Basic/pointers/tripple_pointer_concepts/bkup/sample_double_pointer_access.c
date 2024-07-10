#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void subparition(char *s, int index, int* returnSize, int*** returnColumnSizes)
{
	int i, returnSize_value = 0;

	for(i=index; i<10; i++) {
			*returnSize += 1;
			//TODO: **returnSize++; is not same  as **returnSize += 1
			printf("returnsize : %d\n", *returnSize);
	}

	printf("New: \n");

}

// Each of the coulmn size : returnColumnSizes i.e a[row][col]
// returnSize 

char ***partition(char *s, int* returnSize, int** returnColumnSizes)
{
	char ***result = (char ***) malloc (sizeof(char **)); 

	result[0] = (char **) malloc (sizeof(char *));

	*returnSize = 0;

	printf("Praveen: Return Size : %d\n", *returnSize);

	subparition(s, 0, returnSize, &returnColumnSizes);

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
