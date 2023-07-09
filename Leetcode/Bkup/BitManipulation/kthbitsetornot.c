#include<stdio.h>
#if 0
unsigned int getFirstSetBit(int n)
{
	int result = n & ~(n-1);
	return result;
}
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

#endif
#include <stdbool.h>
bool checkKthBit(int n, int k)
    {
        if(((n>>k) & 0x1) != 0)
            return true;
        else
            return false;
    }

int main()
{
	int n, k;

	printf("enter the number:\n");
	scanf("%d", &n);
	
	printf("enter the number:\n");
	scanf("%d", &k);

	printf("set bit from right is : %d\n",checkKthBit(n, k));

	return 0;
}
