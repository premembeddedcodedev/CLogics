#include <stdio.h>

int main()
{
	int i = 0, j, k = 5;


	while(k-- > 0) {
		j = i++;
		printf("i:%d, j:%d\n", i, j);
	}

	return 0;
}
