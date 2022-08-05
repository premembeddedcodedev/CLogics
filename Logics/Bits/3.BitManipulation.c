/* atoi is not working for hex values*/

#include <stdio.h>
#include <stdlib.h>

void FindMask(int *mask, int low, int high)
{
	//high postion subtracting with low value will get number of positions to be modified
	//and then -1 will keep the upper 2^n position set to '0'
	// 8-5 = 3 but asked for 4 positions so kept +1 at the end
	// 1<<4 = 16 to -1 to 15 all the positions make 1's
	// since we have to start from 5, we are shifting low position times
	*mask = ((1<<((high-low)+1)) - 1) << low;

	printf("Mask: %X\n", *mask);
}

void ClearValueAt(int num, int low, int high)
{
	int mask = 0, temp = 0;

	printf("Original Value : %X\n", num);

	FindMask(&mask, low, high);

	//clearing the range position to '0' here
	num = (num & (~mask));

	printf("ClearValue: %X\n", num);
}

void SetValueAt(int num, int low, int high, int value)
{
	int mask = 0, temp = 0;

	printf("Original Value : %X\n", num);

	FindMask(&mask, low, high);

	//clearing the range position to '0' here
	temp = (num & (~mask));

	num |= (value << low);
	
	printf("SetValue: %X\n", num);
}

void Extractbits(int num, int low, int high)
{
	int mask = 0;

	printf("Original Value : %X\n", num);

	FindMask(&mask, low, high);

	num = (num & mask) >> low;
	
	printf("Extracted: %d\n", num);
}

void CountSetBits(int n)
{
	int count = 0;

	while(n != 0) {
		count += n & 1;
		n = n >> 1;
	}
	printf("Value: %d\n", count);
}

int main(int argc, char *argv[])
{
	int choice = 0, num = 0, value = 0;
	int low, high;

	if(argc != 2) {
		fprintf(stderr, "./a.out missing arguments (1-9): %d", argc);
		exit(-1);
	}

	while(1) {
		printf("\nOptions are as follows: \n");
		printf("1.Extract bits.\n");
		printf("2.Set Range of bits\n");
		printf("3.Clear Range of bits\n");
		printf("4.Count setbits\n");
		printf("Enter the choice: \t");
		scanf("%d", &choice);

		switch(choice) {
			case 1:
				printf("Enter the low position: \n");
				scanf("%d", &low);
				printf("Enter the high position: \n");
				scanf("%d", &high);
				Extractbits(atoi(argv[1]), low, high);
				break;
			case 2:
				printf("Enter the low position: \n");
				scanf("%d", &low);
				printf("Enter the high position: \n");
				scanf("%d", &high);
				printf("Enter the value to keep in the position: \n");
				scanf("%d", &value);
				SetValueAt(atoi(argv[1]), low, high, value);
				break;
			case 3:
				printf("Enter the low position: \n");
				scanf("%d", &low);
				printf("Enter the high position: \n");
				scanf("%d", &high);
				ClearValueAt(atoi(argv[1]), low, high);
				break;
			case 4:
				CountSetBits(atoi(argv[1]));
				break;
			default:
				break;
		};
		getchar();
	}
}
