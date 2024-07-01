#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int ii;
	//bubble_sort(nums, numsSize);
	quick_sort(nums, 0, numsSize);
	*returnSize=0;
	int **arr=(int**)malloc(sizeof(int*) * numsSize);
	*returnColumnSizes=(int*)malloc(sizeof(int) * numsSize);

	int i, low, high = 0;
	int sum = 0;
	int target = 0;

	for  (i = 0; nums[i] <= 0 && i < numsSize -2;) {
		low = i + 1;
		high = numsSize - 1;

		while ( low < high) {
			sum = nums[i] + nums[low] + nums[high];
			if (sum > target)
				high--;
			else if (sum < target)
				low++;
			else {
				(*returnColumnSizes)[*returnSize]=3;
				arr[*returnSize] = (int*)malloc(sizeof(int)*3);
				arr[*returnSize][0] = nums[i];
				arr[*returnSize][1] = nums[low];
				arr[*returnSize][2] = nums[high];
				(*returnSize) += 1;
				do high--; while(nums[high] == nums[high+1] && low < high);
			}
		}
		do i++; while (nums[i]==nums[i-1] && i < numsSize-2);
	}

	return arr;
}

int** threeSum2(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
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
				returnColumnSizes[*returnSize] = malloc(sizeof(int)*3);
				returnColumnSizes[*returnSize][0] = i;
				returnColumnSizes[*returnSize][1] = j;
				returnColumnSizes[*returnSize][2] = k;
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

	return returnColumnSizes;
}

int main()
{
	int nums[] = {-1,0,1,2,-1,-4}, target = 0, returnSize = 0, *returnColumnSizes[3];
	//int nums[] = {0,1,1}, target = 0, returnSize = 0, *returnColumnSizes[4];
	//int nums[] = {0,0,0}, target = 0, returnSize = 0, *returnColumnSizes[4];

	int **result = threeSum(nums, sizeof(nums)/sizeof(int), &returnSize, returnColumnSizes);

        printf("return size: %d\n coloumn size", returnSize);
        for(int i = 0; i< returnSize; i++) {
                printf("%d, ", sizeof(*returnColumnSizes[i]));
        }

        printf("3sum is: \n \t");
        for(int i=0; i<returnSize; i++) {
                printf("[ ");
                for(int j = 0; j<3; j++)
                        printf("%d,", result[i][j]);
                //free(result[i]);
                printf(" ]\n\t");
        }
        free(*returnColumnSizes);
        printf("\n");

#if 0
	printf("return size: %d\n coloumn size", returnSize);
	for(int i = 0; i< returnSize; i++) {
		printf("%d, ", sizeof(*returnColumnSizes[i]));
	}
	printf("\n");

	printf("3sum is: \n \t");
	for(int i=0; i<returnSize; i++) {
		printf("[ ");
		for(int j = 0; j<3; j++)
			printf("%d,", nums[returnColumnSizes[i][j]]);
		free(returnColumnSizes[i]);
		//free(result[i]);
		printf(" ]\n\t");
	}
	printf("\n");

	//free(result);
#endif
	return 0;
}
