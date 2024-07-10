#include<stdio.h>

void recpattern(int r, int c)
{
	if(r==0)
		return;

	if(c < r) {
		recpattern(r, c+1);
		printf("*");
	} else {
		recpattern(r-1, 0);
		printf("\n");
	}
}

int main()
{
	int i, j, m = 4, n = 4;
#if 0
	for(j=0;j<m;j++) {
		for(i=m-j;i>0;i--) {
			printf("*");
		}
		printf("\n");
	}
#endif

	recpattern(4, 0);

	printf("\n");

	return 0;
}
