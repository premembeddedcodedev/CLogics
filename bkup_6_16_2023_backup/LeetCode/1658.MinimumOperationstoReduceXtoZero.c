//Reference: https://www.youtube.com/watch?v=HddgLcq9Efs

#include <stdio.h>
//TODO: need to see the logic is proper

int minOperations(int* nums, int numsSize, int x)
{
	int i = 0, j = numsSize-1, count = 0;

	while(i<j) {
		if((nums[i] < nums[j]) && (x < nums[j])) {
			x -= nums[j];
			j--;
		} else {
			x -= nums[i];
			i++;
		}
		if(x < 0) {
			printf("count : %d\n", count);
			return -1;
		}
		count++;
	}

	return count;
}

int solve(int *nums, int x, int left, int right, int count)
{
	if(x == 0)
		return count;

	if(x < 0 || (left > right))
		return -1;

	int l = solve(nums, x-nums[left], left+1, right, count+1);
	int r = solve(nums, x-nums[right], left, right-1, count+1);

	return ((l > r) ? l : r);
}

int minOperations_1(int* nums, int numsSize, int x)
{
	int result =  solve(nums, x, 0, numsSize, 0);
	return (result == -1) ? -1 : result;
}

int main()
{
        int K,i, arraybound;

        printf("Enter the array bound : \n");
        scanf("%d", &arraybound);

        printf("Enter the K sum : \n");
        scanf("%d", &K);

        int a[arraybound];
        printf("Enter the array values : \n");
        for(i=0;i<arraybound;i++)
                scanf("%d", &a[i]);

        printf("No.of Subarrays: %d\n",minOperations_1(a, arraybound, K));


        return 0;
}

