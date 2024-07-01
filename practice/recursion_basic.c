#include<stdio.h>

void recursion(int a[], int start, int limit)
{
	if(start >= limit)
		return;
	
	start++;
	recursion(a, start, limit);
	printf(" value : %d\n",  a[start]);
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};

	recursion(a, -1, 9);

	return 0;
}
