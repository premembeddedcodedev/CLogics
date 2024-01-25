#include <stdio.h>

int main()
{
	int x, y, cnt = 0, xor = 0, i = 0;

	printf("Enter the value for x :\n");	
	scanf("%d", &x);

	printf("Enter the value for y : \n");
	scanf("%d", &y);

	xor = x ^ y;

	while(xor) {
		if(xor & 0x1) {
			cnt++;
		}
		xor >>= 1;
	}
/* //working
	for(int i = (sizeof(int) * 8) - 1; i >=0; i--) {
		if((x & (1<<i)) ^ (y & (1<<i)))
			cnt++;
	}
*/
	printf("Hamming distance : %d\n", cnt);

	return 0;
}
