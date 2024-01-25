#include <stdio.h>

int main()
{
	int x = 1, y = 4, cnt = 0;

	printf("Enter the 2 Numbers x: \n");
	scanf("%d", &x);
	printf("Y:");
	scanf("%d", &y);

	for(int i = ((sizeof(int) * 8) - 1); i>=0; i--) {
		if((((x & (1<<i)) == 0) && ((y & (1<<i)) > 0)) || (((x & (1<<i)) > 0) && ((y & (1<<i)) == 0)))
			cnt++;
	}

	printf("Hamming distance : %d\n", cnt);

	return 0;
}
