// Reference: https://www.youtube.com/watch?v=Lyay4WJwXyI
// Below code will not work for negative numbers - TODO: need to change map below

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int subarraySum(int* nums, int numsSize, int k)
{
	int i = 0, sum = 0, j=0, count = 0, map[100];

	memset(map, 0, 100);

	if(numsSize == 0)
		return numsSize;

	j = 0;

	int check = 0;

	map[0] = 1;

	while(j < numsSize) {
		sum += nums[j];
		i = 0;
		while((sum -(i*i)) >= 0) {
			if(map[sum -(i*i)] == 1)
				count += map[sum-(i*i)];
			else
				map[sum-(i*i)] += 1; 
			i++;
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
