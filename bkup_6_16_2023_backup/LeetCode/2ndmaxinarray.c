#include<stdio.h>
#include<limits.h>

int main()
{
	int i, j, fmax = INT_MIN, smax, a[] = {1,1,1,1,1,1,5};//{2,5,6,3,4,7,9};

	for(i=0;i<sizeof(a)/sizeof(int);i++) {
		if(fmax < a[i])
			fmax = a[i];
	}

	printf("fmax: %d\n", fmax);

	smax = a[0];

	for(i=0;i<sizeof(a)/sizeof(int);i++) {
		if((smax < a[i]) && (a[i] < fmax))
			smax = a[i];

	}
	
	printf("smax: %d\n", smax);

	return 0;
}
