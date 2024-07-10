#include <stdio.h>

//Logic: to find sum of max and min : it is just sum everything and substract from min will get maximum sum
//if we substract from max will get minimum of array sum

#define MAX 10

void min_max(int a[], int len)
{
	int i, sum = 0, max = a[0], min = a[0];

	for(i=0; i<len; i++) {
		sum += a[i];

		if(max < a[i])
			max = a[i];
		if(min > a[i])
			min = a[i];
	}

	printf("Max = %d, Min=%d\n", max, min);

	printf("sum_min = %d, sum_max=%d\n", sum-max, sum-min);
}

int main()
{
	int a[10], n, i;

	printf("Enter the number of array elements \n");
	scanf("%d", &n);

	printf("Enter the array elements \n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	min_max(a, n);

	return 0;
}
