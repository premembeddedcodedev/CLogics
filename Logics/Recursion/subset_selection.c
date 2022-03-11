#include <stdio.h>
#include <malloc.h>

#define MAX 3

int subset_divide(int index, int num[], int target[], int seq, int *subset)
{
	//printf("Function starts: \n");

	int i;
	static int j = 0, k = 0;

	if(index > MAX) {
		//printf("\t\t");
		for(i =0 ; i< seq; i++) {
			//subset[k] = target[i];
			//printf(" %d", subset[i]);
			//k++;
			printf(" %d", target[i]);
		}
			
		printf(",\n");
		return 0;
	}
	//printf("\t\t\tBefore Recursion ===> %d\n", index);

	target[j] = num[index];
	j += 1; // call will not come here when return calls

	subset_divide(++index, num, target, j, subset);
	//printf("\t\t\tindex ====> %d\n", index);

	// this call returns from if condition above 
	subset_divide(index, num, target, --j, subset);
	//printf("\t\t\t2nd index ====> %d\n", index);

	return 0;
}

int main()
{
	int i, arr[4] = {1, 2, 3, 4}, target[12] = {}, index = 0, subset[16];

	//FIXME: if i use static array coming stack smash
	//int *subset = malloc(sizeof(int) * 20); //allocation memory also not giving proper results.

	subset_divide(index, arr, target, 0, subset);

//	for(i = 0; i<16; i++)
//		printf(" %d", subset[i]);

	return 0;
}
