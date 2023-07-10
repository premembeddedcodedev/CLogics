#include<stdio.h>
#include <stdlib.h>

int* rearrangeArray(int* nums, int numsSize, int* returnSize)
{
	int *result = malloc(0), i = 0, even = 0, odd = 0;
	
	while(i<numsSize) {
		result = realloc(result, (i+1) * 4);
		if(nums[i] >= 0) {
			result[2*odd] = nums[i];
			odd += 1;
		} else {
			result[2*even+1] = nums[i];
			even += 1;
		}
		i++;
	}

	*returnSize = i;

	return result;
}

int main()
{
	int *result, array[] = {3,1,-2,-5,2,-4}, returnSize = 0;

	result = rearrangeArray(array, sizeof(array)/sizeof(int), &returnSize);

	printf("End result: \n");
	
	for(int i=0;i<returnSize; i++) {
		printf("%d->", result[i]);
	}

	printf("\n");

	free(result);

	return 0;
}
