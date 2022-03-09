#include <stdio.h>

int main()
{
	int *ptr[2];
	char *arr = "This is to test";
	char *arr2 = "praveen testing";
	char *pt[2];
	
	pt[0] = arr;
	pt[1] = arr2;

	ptr[0] = arr;

	//char c = *(++arr);
	//printf("\n%c %c ", *(++arr), ++(*arr));// second print throwing seg fault
	
	//printf("\n%c \n", arr[2]); //working
	//printf("\n%c \n", *(arr+2)); // working

	int i;

	for(i = 0; i<strlen(arr); i++)
		printf("%c", pt[0][i]); // workng in for loop
		//printf("%c", *(*(pt+0)+i)); // workng in for loop
		//printf("%c", *(pt[0]+i)); // workng in for loop
		//printf("%c", *pt[0]++); // workng in for loop

	printf("\n");

	for(i = 0; i<strlen(arr); i++)
		printf("%c", *pt[1]++); // workng in for loop
	
	for(i = 0; i<strlen(arr); i++)
		printf("%c", *(char*)ptr[0]++); // workng in for loop

	printf("\n");

	return 0;
}
