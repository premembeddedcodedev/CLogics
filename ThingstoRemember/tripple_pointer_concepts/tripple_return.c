#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 10

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

void subparition(char *s, int index, int* returnSize, int** returnColumnSizes)
{
	int i, returnSize_value = 0;
	bool valid = false;

	if(index >= strlen(s) - 1) {
		return;
	}

	for(i=index; i<strlen(s); i++) {
		if(is_palindrome(s, index, i, &returnSize_value)) {
			for(returnSize_value = index; returnSize_value <= i; returnSize_value++)
				printf("%c", s[returnSize_value]);
			printf("\n");
		}	
	}
	subparition(s, index+1, returnSize, returnColumnSizes);

	printf("\n");

}

// Each of the coulmn size : returnColumnSizes i.e a[row][col]
// returnSize 

char ***partition(char *s, int* returnSize, int** returnColumnSizes)
{
	//*returnSize = 0;
	subparition(s, 0, returnSize, returnColumnSizes);
}

int main()
{
	char arr[SIZE] = {"aabbaa"};
	char ***result;
	int each_array;
	int *array;

	//array = (int *) malloc(sizeof(int));

	result = partition(arr, &each_array, &array);

	//printf(" String is %s\n", is_palindrome(arr, 4) ? "palindrome" : "not a palindrome");

	return 0;
}
