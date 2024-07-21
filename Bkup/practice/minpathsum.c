#include<stdio.h>

int minpath(int a[][3], int x, int y)
{
	int minxplus1, minyplus1;

	if(x > 3 || y > 3)
		return 0;

	minxplus1 = minpath(a, x+1, y);
	minyplus1 = minpath(a, x, y+1);

	int min = 0;

	if(minxplus1 < minyplus1)
		min = minxplus1;
	else
		min = minyplus1;

	return a[x][y] + min;
}

int main()
{
	int a[3][3] = {{1,3,1}, {2,3,2}, {4,3,1}};

	printf("minpath: %d\n", minpath(a, 0, 0));

	return 0;
}
