#include <stdio.h>
#include <malloc.h>

#define MAX 6

int subset_divide(int num[], int target[], int offset, int refseq)
{
	static int j = 0;

	if(index >= MAX) {
		for(int i =0 ; i< refseq; i++) 
			printf(" %d", target[i]);
			
		printf(",\n");
		return 0;
	}

	target[j] = num[index];
	j += 1;
	subset_divide(++index, num, target, j);
	subset_divide(index, num, target, --j);

	return 0;
}

int main()
{
	int i, arr[MAX+1] = {1, 2, 3, 4, 5, 6}, target[12];

	subset_divide(0, arr, target, 0);

	return 0;
}
