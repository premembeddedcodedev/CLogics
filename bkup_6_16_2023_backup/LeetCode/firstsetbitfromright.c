#include<stdio.h>
#if 0
unsigned int getFirstSetBit(int n)
{
	int result = n & ~(n-1);
	return result;
}
#endif
unsigned int getFirstSetBit(int n)
{
	int temp = 0;

	for(int i=0; i<32; i++) {
		if((n >> i) & 0x1) {
			return i+1;
		}
	}

	return temp;
}

int main()
{
	int n;

	printf("enter the number:\n");
	scanf("%d", &n);

	printf("set bit from right is : %d\n",getFirstSetBit(n));

	return 0;
}
