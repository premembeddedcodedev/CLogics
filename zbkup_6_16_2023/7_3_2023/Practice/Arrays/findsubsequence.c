#include<stdio.h>

void find_sub_sequences(int array[], int start_offset, int end, int size)
{
	if(start_offset >= size) {
		for(int i = 0; i<=end; i++) {
			printf(" %d->", array[i]);
		}
		printf("\n");
		return;
	}

	find_sub_sequences(array, start_offset+1, end++, size);
	find_sub_sequences(array, start_offset+1, end--,size);
}

int main()
{
	int array[10] = {1,2,3,4,6,7,8,9,0};

	find_sub_sequences(array, 0, sizeof(array)/sizeof(int), sizeof(array)/sizeof(int));

	return 0;
}
