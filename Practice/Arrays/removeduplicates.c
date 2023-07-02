#include<stdio.h>
#include<stdbool.h>

int removeduplicates_2ptr(int a[], int size)
{
        int i = 0, j = 1;

        while(j<size) {
                if(a[i] != a[j]) { // values comparission
			if (j > i+1) { // offsets checking not values
				a[i+1] = a[j];
			}
                        i++;
                }
                j++;
        }

	return i;
}

int main()
{
        //int a[] = {1,1,2};
        int a[10] = {0,0,1,1,1,2,2,3,3,4};

        int k = removeduplicates_2ptr(a, sizeof(a)/sizeof(int));

	printf("array elements are : ");
	for(int i = 0; i<=k; i++) // k is pure values not array bound so = used.
		printf("%d->", a[i]);
	printf("\n");

        return 0;
}
