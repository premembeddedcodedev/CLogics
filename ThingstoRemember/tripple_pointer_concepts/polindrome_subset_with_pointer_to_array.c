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

char **subparition(const char *s, int index, int* returnSize, char** returnColumnSizes)
{
	int i, returnSize_value = 0;
	bool valid = false;

	if(index >= strlen(s) - 1) {
		return returnColumnSizes;
		//return *returnColumnSizes;
	}

	for(i=index; i<strlen(s); i++) {
		if(is_palindrome(s, index, i, &returnSize_value)) {
			returnColumnSizes[*returnSize] = (char *)malloc(returnSize_value + 1);
			strncpy(returnColumnSizes[*returnSize], s, returnSize_value);
			printf("\nStored : %s\n", returnColumnSizes[*returnSize]);
			*returnSize += 1;
			returnColumnSizes=realloc(returnColumnSizes, ((*returnSize +1 )*sizeof (char *)));
		}	
	}
	subparition(s, index+1, returnSize, returnColumnSizes);

}

char ***partition(char *s, int* returnSize, char** returnColumnSizes)
{
	char ***result = (char ***) malloc (sizeof(char **)); 

	*returnSize = 0;

	//printf("Praveen: Return Size : %d\n", *returnSize);

	returnColumnSizes = (char **) malloc (sizeof(char *));

	*result = subparition(s, 0, returnSize, returnColumnSizes);

	//printf("%s : \n", returnColumnSizes[0][0]);

	//*result = returnColumnSizes;

	return result;
}

int main()
{
	char arr[] = {"aabbaa"};
	char ***result;
	int each_array;
	char *array;

	result = partition(arr, &each_array, &array);

	int i = 0;

	printf("each array : %d\n", each_array);

	for(i=0; i<each_array; i++)
		printf("\nResult %s \n", result[0][i]);

	//printf(" String is %s\n", is_palindrome(arr, 4) ? "palindrome" : "not a palindrome");

	return 0;
}
