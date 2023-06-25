//https://gist.github.com/SuryaPratapK/5a05ed7f0cf5cc409218dd89bc6ba51f
//https://www.youtube.com/watch?v=NWMcj5QFW74&t=561s

#include <stdio.h>

#define MAX 20
int max_heap_size;

void noralsort(int ar1[], int ar2[], int m, int n)
{
	// Iterate through all elements of ar2[] starting from
	// the last element
	for (int i=n-1; i>=0; i--)
	{
		/* Find the smallest element greater than ar2[i]. Move all
		   elements one position ahead till the smallest greater
		   element is not found */
		int j, last = ar1[m-1];
		for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--)
			ar1[j+1] = ar1[j];

		// If there was a greater element
		if (j != m-2 || last > ar2[i])
		{
			ar1[j+1] = ar2[i];
			ar2[i] = last;
		}
	}
}

void swap(int *src, int *dest)
{
	int temp = *src;
	*src = *dest;
	*dest = temp;
}

void heap_push(int heap[], int element, int *maxsize) // heapify or down to top approach
{
	if(*maxsize >= MAX) {
		printf("Overflow\n");
		return;
	}

	int offset = *maxsize;
	heap[offset] = element;

	while((offset > 0) && heap[(offset-1)/2] > heap[offset]) {
		swap(&heap[(offset-1)/2], &heap[offset]);
		offset = (offset-1)/2;
	}
	
	*maxsize += 1;
}

void perculate_algo(int heap[], int heapSize) // top to down approach
{
	int curr = 0;
	// Left child 2i+1, Right child = 2i+2 parent = i
	// traverse tree left to right to satisfy the max/min heap rules
	while((2*curr)+1 < heapSize) { // why curr+1 ?? this is the last element sits in heap
		int child;
		//checking only one left child is present
		if(2*curr+2 ==  heapSize) 
			child = 2*curr+1;
		else //if the left and right childs are present we need to find maximum
			child = (heap[2*curr+1] < heap[2*curr+2]) ? 2*curr+1 : 2*curr+2;

		if(heap[curr] > heap[child]) { //after finding the max of above step swapping
			swap(&heap[curr], &heap[child]);
			curr = child;
		} else
			break;
	}
}

int heap_pop(int heap[], int *heapSize)
{
	if(*heapSize <= 0) {
		printf("Heap is underflow\n");
		return -1;
	}

	int popped = heap[0]; // 1st point
	heap[0] = heap[*heapSize - 1]; //2nd point
	*heapSize -= 1;// 3rd point

	perculate_algo(heap, *heapSize);

	return popped;
}

void min_heap(int heap[], int (*ar1)[3], int m, int n, int maxsize)
{
	int k = 0;

	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			heap_push(heap, ar1[i][j], &maxsize); //Building the heap

	for(int j=0;j<maxsize;j++)
		printf("%d->", heap[j]);
	
	printf("\n");	
		k = maxsize;

	int i = maxsize-1;

	while(i-->=0) {
		printf("%d->", heap_pop(heap, &maxsize)); // pop always extract min/max element
	}
}

//3,5,7 - 1,4,9 - 2,6,8

int main()
{
	int abound, bbound;

	max_heap_size = 0;

	printf("Enter Abound and Bbound\n");
	scanf("%d%d", &abound, &bbound);

	int c[abound][bbound], heap[MAX];

	printf("Enter the array values: \n");
	for(int i=0; i<abound; i++)
		for(int j=0; j<bbound; j++)
			scanf("%d", &c[i][j]);

	printf("\n\n\nMain: Array values are: \n");
	for(int i=0; i<abound; i++)
		for(int j=0; j<bbound; j++)
			printf("%d,", c[i][j]);
	printf("\n");

	min_heap(heap, c, abound, bbound, max_heap_size);

	printf("\nMerged Sorted Array values are: \n");
	for(int i=0; i<abound; i++)
		for(int j=0; j<bbound; j++)
			printf("%d,", c[i][j]);
	printf("\n");

	return 0;
}
