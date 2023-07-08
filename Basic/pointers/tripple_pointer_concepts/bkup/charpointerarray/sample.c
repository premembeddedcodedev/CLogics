#include <stdlib.h>
#include <stdio.h>

int *function(int *data, int size)
{
	int *pdata = malloc(20);

	pdata[0] = 10;
	pdata[1] = 20;
	pdata[2] = 40;
	pdata[3] = 30;
	pdata[4] = 60;

	return pdata;
}

int main()
{
	int *data, size = 10;

	data = function(data, size);

	printf("data: %d\n", data[0]);

	return 0;
}
