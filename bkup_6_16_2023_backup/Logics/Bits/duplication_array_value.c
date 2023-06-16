#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main(int argc, char *argv[])
{
	int a[MAX], n, i, j;

	printf("Enter the  size of the array\n");
	scanf("%d", &n);

	printf("Enter values of the array\n");
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if((a[i] ^ a[j]) == 0)
				printf("offset:i->%d and j->%d value %d is duplicated\n", i, j, a[i]);	
			else 
				printf("No Duplication....\n");	
		}
	}

	for(i=0; i<n; i++)
		printf("%d ", a[i]);

	return 0;
}
