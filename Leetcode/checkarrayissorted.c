#include<stdio.h>
#include <stdbool.h>
int main()
{
	int i = 1, j, a[] = {1,2,3,4,5,6};//{1,2,2,3,3,4};
	bool is_sorted = true;

	while(i<=(sizeof(a)/sizeof(int)-1)) {
		if(a[i] >= a[i-1]) {
		
		} else
			is_sorted = false;
		i++;
	}

	printf("array(%d) is : %s\n", i, (is_sorted == true) ? "sorted": "not sorted");

	return 0;
}
