#include <stdio.h>

int subarraySum(int* nums, int numsSize, int k)
{
	int i = 0, sum[numsSize], j=0, count = 0;

	if(numsSize == 0)
		return numsSize;

	sum[j] = nums[i];

	//1. Finding the sum of the offsets @ at each position

	for(i=1; i< numsSize; i++) {
		sum[i] = sum[i-1] + nums[i];
	}

	j = 0;

	int check = 0;

	while(j < numsSize) {
		//2. here directly checking sum of offsets are equal to k
		if((sum[j] == k)) {
			printf(" Array started from : %d to %d\n", check, j);
			count += 1;
			check++;
		}
	
		//3. this is the corner logic, checking if the sum of offsets are greater than k and if we already
		// calculated/found the same sum. then its like found sum offset already giving k right
		// so immediate after finding the sum the k sum starts till current offset
		if((sum[j]  > k)) {
			i = 0;
			while(i<j) {
				if(sum[j] - k == sum[i]) {
					count +=1;
					printf(" Array started from : %d to %d\n", i+1, j);
					check = 0;
				}
				i++;
			}
		}
			
		j++;
	}

	return count;
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

	printf("No.of Subarrays: %d\n",subarraySum(a, arraybound, K));


	return 0;
}
