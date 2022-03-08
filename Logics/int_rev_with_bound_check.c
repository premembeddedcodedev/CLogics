// Not working but need to check bound checking because we are multiplying the temp here

#include <stdio.h>

int reverse(int num)
{
	int temp = 0, remainder;

	if (num == 0)
		return num;

	while(num != 0){
		remainder = num%10;//5
		temp = temp*10 + remainder;
		if(temp >= 2147483647 || temp<= -2147483648)
			return 0;
		num = num/10;//324
	}

	return temp;
}

int main()
{	
	int num = 1534236469;

	printf("%d\n", reverse(num));

	return 0;
}
