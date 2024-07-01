#include<stdio.h>
#include <stdbool.h>

bool arraysort(int a[], int length)
{
	for(int i = 0; i<length; i++) {
		if(a[i] > a[i+1])
			return false;
	}

	return true;
}

bool fact_arraysort(int a[], int start, int length)
{
	if(start > length)
		return true;

	return (a[start] < a[start+1])  && fact_arraysort(a, start+1, length);
}

int main()
{
	//int a[] = {9,2,8,6,3,1,5,0};
	int a[] = {1,2,3,4,5,0,7,8,9};

	//printf("Sorted: %s\n", arraysort(a, sizeof(a)/sizeof(int)) ? "Yes" : "No");
	printf("Sorted: %s\n", fact_arraysort(a, 0, sizeof(a)/sizeof(int)-1) ? "Yes" : "No");

	return 0;
}
