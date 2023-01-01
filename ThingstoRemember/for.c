#include <stdio.h>

/* just post and pre increment*/
int main()
{
	int i;

	printf("\n");
	
	printf("pre inc values are: \n");
	for(i=0; i<8; ++i)
	{
		printf("%d", i);
	}

	printf("\n");

	printf("post inc values are: \n");
	for(i=0; i<8; i++)
	{
		printf("%d", i);
	}
	printf("\n");


	return 0;
}
