#include <stdio.h>

#define MAX 10

int min_max(int a[], int len)
{
	int i, max = a[0];

	for(i=0; i<len; i++)
		if(max < a[i])
			max = a[i];

	return max;
}

int main()
{
	int a[10], n, i;

	printf("Enter the number of array elements \n");
	scanf("%d", &n);

	printf("Enter the array elements \n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	printf("Max Value: %d\n", min_max(a, n));

	for(i=0; i<n; i++)
		printf("%d ", a[i]);

	return 0;
}
