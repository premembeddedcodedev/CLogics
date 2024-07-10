#include<stdio.h>
#include <string.h>

int main()
{
	int int_type = 0x89787680;
	char check = 0;
	check = (char) int_type;

	char *chk = (char*) &int_type;

	printf("char value : %X\n", check);

	printf("value : %x\n", (*(chk+3) & 0xFF));

	int test = *(chk+0);
	printf("test without : %x\n",test);
	
	test = *(chk+0) & 0xFF;
	printf("test with: %x\n",test);

	char ptr[] = "abcdefgh";

	printf(" %c \n", ptr[0]);

	//memset(intptr, 0, 8);
	
	//int *intptr = (int *)ptr;
	int *intptr = (int *) ptr;

	printf("value : %x\n", *intptr);

	char *pt = (char *) intptr;

	printf("opt: %c\n", pt[0]);
	printf("opt: %c\n", pt[1]);
	printf("opt: %c\n", pt[2]);
	printf("opt: %c\n", pt[3]);
	printf("opt: %c\n", pt[4]);
	printf("opt: %c\n", pt[5]);
	printf("opt: %c\n", pt[6]);
	printf("opt: %c\n", pt[7]);

	return 0;
}
