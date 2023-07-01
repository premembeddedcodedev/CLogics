
// TUF
#include <stdio.h>
#include <limits.h>

int insertion_sort_with_2ndlargest(int nums[], int numsSize)
{
        printf("Array order : \n");
        for(int i = 0; i < numsSize; i++) {
                printf("%d->", nums[i]);
        }
        printf("\n");

	for(int i=1; i<numsSize; i++) {
		int temp = nums[i];
		int j = i - 1;
		while(j>=0 && nums[j] > temp) nums[j+1] = nums[j], j--;
		nums[j+1] = temp;
	}
        
	printf("Sorted order : \n");
        for(int i = 0; i < numsSize; i++) {
                printf("%d->", nums[i]);
        }
        printf("\n");

	int  i = numsSize - 2, temp = nums[numsSize-1];

	while(i>=0) {
		if(temp != nums[i]) {
			return nums[i];
		}
		i--;	
	}

	return -1;
}

int find_first_second_in_same_loop(int nums[], int numsSize)
{
	int max = nums[0], smax = INT_MIN;

	for(int i=1; i< numsSize; i++) {
		if(nums[i] > max) {
			smax = max;
			max = nums[i];
		} else if(nums[i] < max && nums[i] > smax) {
			smax = nums[i];
		}
	}

	return smax;
}

int main()
{
	//int a[] = {3,2,1,5,2};
	int a[] = {4,7,7,7,7,7,7,7};

	int max = INT_MIN;
	int smax = INT_MIN;


	for(int i = 0; i<sizeof(a)/sizeof(int); i++) {
		if(max < a[i])
			max = a[i];
	}

	printf("MAX: %d\n", max);
	smax = INT_MIN;

	for(int i = 0; i<sizeof(a)/sizeof(int); i++) {
		if(a[i] > smax && a[i] != max) // Need to see this logic once
		//if(smax < max && smax < a[i] && smax != max)
			smax = a[i];
	}

	printf("MAX: %d\n", smax);

	// 2nd method: sort and find n-1 to 0 element is not equal to n

	printf("2nd largest : %d\n", insertion_sort_with_2ndlargest(a, sizeof(a)/sizeof(int)));

	// 3rd logic : find first and second in one loop
	
	printf("2nd max is %d\n", find_first_second_in_same_loop(a, sizeof(a)/sizeof(int)));
	
	return 0;
}
