#include<stdio.h>

int main()
{
	int i =0 , j =1, count = 0, a[] = {1,2,3,3,4,5,6,6,7,7};

	for(j=1;j<sizeof(a)/sizeof(int);j++) {
		if(a[j] != a[i]) {
			a[i+1] = a[j];
			i++;
		} else {
			if((a[j] ^ a[i]) == 0)
				count++;
		}
	}
	
	printf("There is %d elements duplicated in the array\n", count);

	for(j=0;j<sizeof(a)/sizeof(int)-count;j++)
		printf("%d,", a[j]);

	return 0;
}
