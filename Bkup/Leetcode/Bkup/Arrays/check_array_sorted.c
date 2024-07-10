#include<stdio.h>
#include<stdbool.h>

bool check_array_sorted(int a[], int size)
{
	// going backward (a-1) comparission to avoid array bound issue
	for(int i=1;i<size;i++) {
		if(a[i-1] > a[i])
			return false;
	}

	return true;
}

int main()
{
	//int a[10] = {1,5,3,2,4,9,7,6,8,0};
	int a[4] = {1,5,8,9};

	printf("Sorted ? %s\n", check_array_sorted(a, sizeof(a)/sizeof(int)) ? "Yes" : "No");

	return 0;
}
