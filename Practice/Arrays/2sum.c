// TUF
#include<stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int *list = malloc(2 * sizeof(int));
	
	int k = 0, l = 0, m = 0;

	for(int i = 0; i<numsSize; i++) {

		for(int j=0; j< numsSize; j++) {
			
			if(i == j)
				continue;

			if(nums[i] + nums[j] == target) {
				list[0] = i;
				list[1] = j;
				*returnSize = 2;
			}
		}
	}

	return list;
}

void selectionsort(int a[], int size)
{
	for(int i = 0; i<size; i++) {
		for(int j = i+1; j<size;j++) {
			if(a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				continue;
			}
		}
	}
}

int* twoSum2(int* nums, int numsSize, int target, int* returnSize)
{
	printf("Array order : \n");
	for(int i = 0; i < numsSize; i++) {
		printf("%d->", nums[i]);
	}
	printf("\n");
	selectionsort(nums, numsSize);

	printf("Sorted order : \n");
	for(int i = 0; i < numsSize; i++) {
		printf("%d->", nums[i]);
	}
	printf("\n");

	int left = 0, right = numsSize - 1;

	int *list = malloc(2 * sizeof(int));

	while(left < right) {
		if(nums[left] + nums[right] == target) {
			list[0] = left;
			list[1] = right;
			return list;
		} else if(nums[left] + nums[right] < target)
			left++;
		else 
			right--; // here can be write as left-- but it may go beyond 0 like -1
	}
}

int main()
{
	int arr[] = {2, 6, 5, 8, 11}, target = 14;
	int ptr = 0, list[2], *list2;

	list2 = twoSum(arr, sizeof(arr)/sizeof(int), target, &ptr);

	printf("find_2sum : %d %d --> %d %d\n", list2[0], list2[1], arr[list2[1]], arr[list2[0]]);
	free(list2);

	list2 = NULL;

	list2 = twoSum2(arr, sizeof(arr)/sizeof(int), target, &ptr);
	
	printf("find_2sum : %d %d --> %d %d\n", list2[0], list2[1], arr[list2[1]], arr[list2[0]]);
	free(list2);

	return 0;
}
