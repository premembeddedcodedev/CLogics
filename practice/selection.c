#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

void swap(int *src1, int *src2)
{
	int temp = *src1;
	*src1 = *src2;
	*src2 = temp;
}

// recusion
void rec_selectionsort(int a[], int n, int offset, int max)
{
	if(n == 0)
		return;

	if(offset < n) {
		if(a[offset] > a[max])
			rec_selectionsort(a, n, offset+1, offset);
		else
			rec_selectionsort(a, n, offset+1, max);
	} else {
		swap(&a[n-1], &a[max]);
		// reducing bound value with offset 0 to switch to first if condition end of each iteration
		rec_selectionsort(a, n-1, 0, 0); 
	}
}

// min selection
void min_offset_selectionsort(int a[], int n)
{
	int min = 0;

	for(int i=0; i<n; i++) {
		bool flag = false;
		for(int j=i; j< n; j++) {
			if(a[min] > a[j]) {
				min = j;
				flag = true;
			}
		}
		if(true) {
			swap(&a[i], &a[min]);
			min = -1; // next iteration select from this element so make it default
		}
		
	}
}

// min selection
void min_val_selectionsort(int a[], int n)
{
	int min = INT_MAX;
	int offset = 0;

	for(int i=0; i<n; i++) {
		bool flag = false;
		for(int j=i; j< n; j++) {
			if(min > a[j]) {
				offset = j;
				min = a[j];
				flag = true;
			}
		}
		if(true) {
			swap(&a[i], &a[offset]);
			min = INT_MAX; // next iteration select from this element so make it default
		}
		
	}
}

// max selection
void selectionsort(int a[], int n)
{
	int max = INT_MIN;
	int offset = 0;

	for(int i=0; i<n; i++) {
		bool flag = false;
		for(int j=0; j< n-i; j++) {
			if(max < a[j]) {
				offset = j;
				max = a[j];
				flag = true;
			}
		}
		if(true) {
			swap(&a[n-i-1], &a[offset]);
			max = INT_MIN;
		}
		
	}
}

int main()
{
	int a[] = {4,8,3,7,5,2};

	min_offset_selectionsort(a, sizeof(a)/sizeof(a[0]));
	//rec_selectionsort(a, sizeof(a)/sizeof(a[0]), 0, 0);

	printf("Sorted: \t");
	for(int i = 0; i<sizeof(a)/sizeof(a[0]); i++)
		printf("%d, ", a[i]);

	printf("\n");

	return 0;
}
