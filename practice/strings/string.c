#include<stdio.h>
#include <string.h>
#include <stdlib.h>

void func_rec(char *str, char *dest, int src_off, int dest_off)
{
	if(src_off >= strlen(str)) {
		printf("\n \t return: src: %d, dest:%d \t", src_off,dest_off);	
		for(int i =0 ; i< dest_off; i++) {
			printf(" %c", dest[i]);
		}	
		printf(" \n");	
		return;
	}
	dest[dest_off++] = str[src_off++];
	printf("1st pass: src: %d, dest:%d ==> ", src_off,dest_off);	

	func_rec(str, dest, src_off, dest_off);
	printf("2nd pass: src: %d, dest:%d ==> ", src_off,dest_off);	
	func_rec(str, dest, src_off, --dest_off);
}

void leefunc_rec(char **result, char *str, char *dest, int src_off, int dest_off, int* returnSize, int** returnColumnSizes)
{
	if(src_off >= strlen(str)) {
		returnColumnSizes[*returnSize] = (int *) malloc (sizeof(int)); //Allocating each and every int then it worked.
		result[*returnSize] = (char *) malloc (sizeof(char) * (dest_off + 1));
		printf("\n \t return: src: %d, dest:%d \t", src_off,dest_off);	
		for(int i =0 ; i< dest_off; i++) {
			//printf(" %c", dest[i]);
			result[*returnSize][i] = dest[i];
			printf(" %c", result[*returnSize][i]);
		}
		result[*returnSize][dest_off] = '\0';
		printf(" \n");	
		(*returnColumnSizes)[*returnSize] = dest_off + 1;
		printf("returnSize: %d, colsize: %d\n", *returnSize, (*returnColumnSizes)[*returnSize]);	
		(*returnSize) += 1;
		return;
	}
	dest[dest_off++] = str[src_off++];

	leefunc_rec(result, str, dest, src_off, dest_off, returnSize, returnColumnSizes);
	leefunc_rec(result, str, dest, src_off, --dest_off, returnSize, returnColumnSizes);
}

char** groupAnagrams(char* strs, char *dest, int strsSize, int* returnSize, int** returnColumnSizes)
{
	char **result = (char **) malloc(sizeof(char **) * strsSize);

	returnColumnSizes[0] = (int *) malloc (sizeof(int));

	leefunc_rec(result, strs, dest, 0, 0, returnSize, returnColumnSizes);

	return result;
}

#if 0
char*** groupAnagramshelper(char ***result, char* strs, char *dest, int src_off, int dest_off, int strsSize, int* returnSize, int** returnColumnSizes)
{
        if(src_off >= strlen(strs)) {
		(*result)[*returnSize] = (char *) malloc(sizeof(char) * dest_off);
		for(int i =0 ; i< dest_off; i++)
			(*result)[*returnSize][i] = dest[i];
		(*returnColumnSizes)[(*returnSize++)] = dest_off;;
                return result;
        }

        dest[dest_off++] = strs[src_off++];
	groupAnagramshelper(result, strs, dest, src_off, dest_off, strsSize, returnSize, returnColumnSizes);
	groupAnagramshelper(result, strs, dest, src_off, --dest_off, strsSize, returnSize, returnColumnSizes);
}

char*** groupAnagrams(char* strs, int strsSize, int* returnSize, int** returnColumnSizes)
{
	char ***result = (char ***) malloc(sizeof(char) * 100);
	char dest[strlen(strs)];
	if(!result)
		return NULL;

	returnColumnSizes = (int **) malloc (sizeof(int *) * 100);

	result = groupAnagramshelper(result, strs, dest, 0, 0, strsSize, returnSize, returnColumnSizes);
}
#endif
int main()
{
	char *str = "ABC";

	printf("string length: %ld\n", strlen(str));
	char dest[strlen(str)];

	//func_rec(str, dest, 0, 0);

	int returnSize = 0, *returnColumnSizes[20];
	//int returnSize = 0, **returnColumnSizes;

	char **result = groupAnagrams(str, dest, strlen(str), &returnSize, returnColumnSizes);
		
//	printf("main: returnSize: %d, colsize: %d\n", returnSize, (*returnColumnSizes)[0]);	

	for(int i = 0; i<returnSize-1; i++) {
		for(int j = 0; j<(*returnColumnSizes)[i]; j++) {
			//printf("%s", result[i]);
			printf("%c", result[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");

	return 0;
}
