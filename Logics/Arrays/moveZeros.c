#include <stdio.h>

void swap(int *dest, int *src)
{
	int temp = *dest;
	*dest = *src;
	*src = temp;
}

void bruteforce(int a[], int b[], int size)
{
	int i, j=0, k = 0;

	for(i=0; i<size; i++) {
		if(a[i] == 0)
			j++;
		else {
			b[k] = a[i];
			k++;
		}
	}

	while(j--)
	{
		b[k++] = 0;
	}

}

int *algo_1(int a[], int size)
{
	int i, first = 0, last = 0;

	while(last < size) {
		if(a[last] == 0)
			last++;
		else {
			swap(&a[last], &a[first]);
			last++;
			first++;
		}
	}

	return a;
}

int main()
{
	int a[5] = {0,1,0,2,3};
	int b[5], i;

	//b = algo_1(a, 5);
	
	// you cant return array from caller function
	//b = bruteforce(a, b, 5);
	bruteforce(a, b, 5);

	for(i=0; i<5; i++)
		printf("%d\t",b[i]);
	
	printf("\n");

	return 0;
}
