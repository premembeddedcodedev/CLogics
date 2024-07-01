#include<stdio.h>
#include <stdbool.h>
void fact_bubble_sort(int a[], int length, int offset)
{
	if(length == 0)
		return;

	if(offset < length) {
		if(a[offset] > a[offset+1]) {
			int temp = a[offset];
			a[offset] = a[offset+1];
			a[offset+1] = temp;	
		}
		fact_bubble_sort(a, length, offset+1);
	} else {
		fact_bubble_sort(a, --length, 0);
	}
}

void bubble_sort(int a[], int length, int offset)
{
	for(int i=0; i< length; i++) {
		int n = i+1;
		while(n < length) {
			int m = i;
			if(a[m] > a[n]) {
				int temp = a[m];
				a[m] = a[n];
				a[n] = temp;
			}
			m++;
			n++;
		}
	}
}

void swap(int *src1, int *src2)
{
	int temp = *src1;
	*src1 = *src2;
	*src2 = temp;
}

void opt_bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

int main()
{
	int a[] = {9, 8, 4, 7, 6, 1};

	//fact_bubble_sort(a, sizeof(a)/sizeof(int)-1, 0);
	//bubble_sort(a, sizeof(a)/sizeof(int), 0);
	opt_bubbleSort(a, sizeof(a)/sizeof(a[0]));
	for(int i = 0; i<sizeof(a)/sizeof(int); i++)
		printf("%d, ", a[i]);

	return 0;
}
