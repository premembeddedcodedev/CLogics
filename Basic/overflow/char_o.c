#include<stdio.h>
#include <stdlib.h>

void func(char *buf)
{
	for(int i= 0; i< 5; i++)
		printf("%s, ", buf[i]);

	printf("\n");
}

int main()
{
	char *temp;

	//temp = malloc(5);
	temp = calloc(5, 5);

	temp[0] = "premch";
	temp[1] = "qualcomm";
	temp[2] = "xilinx";
	temp[3] = "lattice";
	temp[4] = "silicon image";

	func(temp);

	return 0;
}
