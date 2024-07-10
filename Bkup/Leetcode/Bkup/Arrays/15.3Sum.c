#include <stdio.h>
#include <stdlib.h>

int partition(int nums[], int lb, int ub)
{
	int start = lb;
	int end = ub;

	// Taking first offset variable as pivot
	int pivot = nums[lb];

	// After exiting this while loop pivot will be in mid and less then to pivot in left side
	// and greater than pivot will be saved in right to pivot
	while(start < end) { 
		//finding less elements from start offset by comparing pivot
		while(nums[start] <= pivot)
			start++;
		//decrement end till finding greater element end offset by comparing pivot
		while(nums[end] > pivot)
			end--;
		if(start < end) { //incase start is greater than end because of above operations then
			int temp = nums[start];
			nums[start] = nums[end];
			nums[end] = temp;
		}
	}

	int temp = nums[end];
	nums[end] = nums[lb];
	nums[lb] = temp;

	return end;
}

void quick_sort(int nums[], int start, int size)
{
	if(start < size) {
		int mid_pivot = partition(nums, start, size); 
		quick_sort(nums, start, mid_pivot-1);
		quick_sort(nums, mid_pivot+1, size); // mid_pivot+1 because we already found mid element in partition
	}
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int **result = malloc(0);

	int i=0, j = 1, k = numsSize-1;

	printf("Array order : \n");
	for(int i = 0; i < numsSize; i++) {
		printf("%d->", nums[i]);
	}
	printf("\n");
	quick_sort(nums, 0, numsSize - 1);	

	printf("Sorted order : \n");
	for(int i = 0; i < numsSize; i++) {
		printf("%d->", nums[i]);
	}
	printf("\n");

	//2 pointer approach
	// Concept : first pointer constant, 2nd and 3rd offset will move left and right respectively. 
	while(i<numsSize && j<numsSize)
	{
		if(j<k) {
			if((nums[i] + nums[j] + nums[k]) == 0) {
				returnColumnSizes[*returnSize] = malloc(sizeof(int));
				// TODO: memset to 0 onbelow returnColumnSizes
				*returnColumnSizes[*returnSize] = 3;
				result[*returnSize] = (int *)malloc(sizeof(int) * 3);
				result[*returnSize][0] = i;
				result[*returnSize][1] = j;
				result[*returnSize][2] = k;
				(*returnSize)++;
				int temp = nums[i];
				i++;
				k = numsSize - 1;
				j = i+1;
			} else if((nums[i] + nums[j] + nums[k]) < 0) {
				int temp = nums[j];
				// increase j from start towards end if the same value present we can skip
				while((++j <= numsSize) && (temp == nums[j])); 
			} else {
				int temp = nums[k];
				// decrease k from end towards start if the same value present we can skip
				while((--k <= numsSize) && (temp == nums[k]));
			}
		} else {
			i++;
			j = i+1;
			k = numsSize - 1;
		}
	}

	return result;
}

int main()
{
	int nums[] = {-1,0,1,2,-1,-4}, target = 0, returnSize = 0, *returnColumnSizes[4];
	//int nums[] = {0,1,1}, target = 0, returnSize = 0, *returnColumnSizes[4];
	//int nums[] = {0,0,0}, target = 0, returnSize = 0, *returnColumnSizes[4];

	int **result = threeSum(nums, sizeof(nums)/sizeof(int), &returnSize, returnColumnSizes);

	printf("3sum is: \n \t");
	for(int i=0; i<returnSize; i++) {
		printf("[ ");
		for(int j = 0; j<*returnColumnSizes[i]; j++)
			printf("%d,", nums[result[i][j]]);
		free(returnColumnSizes[i]);
		free(result[i]);
		printf(" ]\n\t");
	}
	printf("\n");

	free(result);

	return 0;
}
