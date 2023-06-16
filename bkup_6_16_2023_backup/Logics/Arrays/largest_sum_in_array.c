#include <stdio.h>
#include <limits.h>

#define N 8

int brute_force_method(int a[])
{
	int max_sum = -32767, msum = 0, sum = 0, i, j;
	
	for(i=0; i<N; i++) {
		for(j=i; j<N; j++ ) {
			sum = sum + a[j];
			if(msum < sum) {
				msum = sum;
			}
		}
		//printf("\nIteration : %d, sum is: %d\n", i, msum);
		if(msum > max_sum) {
			//printf("%d\t", max_sum);
			max_sum = msum;
		}
		sum = 0;
	}

	return max_sum;
}

int modified_kadanes_algo(int a[])
{
	int i, curr_max = a[0], max_sofar = a[0];
	//int i, curr_max = 0, max_sofar = INT_MIN;

	for(i=0;i<N;i++) {
	
	/*	curr_max = a[i] + curr_max;
		if(curr_max < a[i])
			curr_max = a[i];
		if(max_sofar < curr_max)
			max_sofar = curr_max;	
	*/
		curr_max = (a[i] + curr_max) < a[i] ? a[i] : (a[i] + curr_max);
		max_sofar = max_sofar < curr_max ? curr_max: max_sofar;
	}

	return max_sofar;
}

int main()
{
	int a[N] = {-2, -3, 4, -1, -2, 1, 5, -3}, max_sum = -32767, msum = 0, sum = 0, i, j;

	printf("BF: Max sum : %d\n", brute_force_method(a));
	printf("KA: Max sum : %d\n", modified_kadanes_algo(a));

	return 0;
}
